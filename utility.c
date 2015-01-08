#include <xtl.h>
#include <stdio.h>
#include "kernel.h"

#ifdef _DEBUG
#include <xbdm.h>
#endif

#define SYS_STRING "\\System??\\%s"
#define USR_STRING "\\??\\%s"

DWORD __declspec(naked) HvxSetState(DWORD mode)
{ 
	__asm {
		li      r0, 0x76
		sc
		blr
	}
}

HRESULT doMountPath(const char* szDrive, const char* szDevice, const char* sysStr)
{
	STRING DeviceName, LinkName;
	CHAR szDestinationDrive[MAX_PATH];
	sprintf_s(szDestinationDrive, MAX_PATH, sysStr, szDrive);
	RtlInitAnsiString(&DeviceName, szDevice);
	RtlInitAnsiString(&LinkName, szDestinationDrive);
	ObDeleteSymbolicLink(&LinkName);
	return (HRESULT)ObCreateSymbolicLink(&LinkName, &DeviceName);
}

float UnpackShortFloat(unsigned short value)
{
	unsigned int num3;
	if ((value & -33792) == 0)
	{
		if ((value & 0x3ff) != 0)
		{
			unsigned int num2 = 0xfffffff2;
			unsigned int num = (unsigned int)(value & 0x3ff);
			while ((num & 0x400) == 0)
			{
				num2--;
				num = num << 1;
			}
			num &= 0xfffffbff;
			num3 = ((unsigned int)(((value & 0x8000) << 0x10) | ((num2 + 0x7f) << 0x17))) | (num << 13);
		}
		else
		{
			num3 = (unsigned int)((value & 0x8000) << 0x10);
		}
	}
	else
	{
		num3 = (unsigned int)((((value & 0x8000) << 0x10) | (((((value >> 10) & 0x1f) - 15) + 0x7f) << 0x17)) | ((value & 0x3ff) << 13));
	}
	return *(((float*)&num3));
}

HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both)
{
	HRESULT res;
	if(both)
	{
		res = doMountPath(szDrive, szDevice, SYS_STRING);
		res = doMountPath(szDrive, szDevice, USR_STRING);
	}
	else
	{
		if(KeGetCurrentProcessType() == SYSTEM_PROC)
			res = doMountPath(szDrive, szDevice, SYS_STRING);
		else
			res = doMountPath(szDrive, szDevice, USR_STRING);
	}
	return res;
}

PIMAGE_EXPORT_ADDRESS_TABLE getModuleEat(char* modName)
{
	PLDR_DATA_TABLE_ENTRY moduleHandle = (PLDR_DATA_TABLE_ENTRY)GetModuleHandle(modName);
	if(moduleHandle != NULL)
	{
		DWORD ret;
		PIMAGE_XEX_HEADER xhead = (PIMAGE_XEX_HEADER)moduleHandle->XexHeaderBase;
		ret = (DWORD)RtlImageXexHeaderField(xhead, 0xE10402);
		if(ret == 0)
		{
			return xhead->SecurityInfo->ExportTableAddress;
		}
	}
	return NULL;
}

DWORD resolveFunct(PCHAR modname, DWORD ord)
{
	DWORD ptr2=0;
	HANDLE hand;
	if(NT_SUCCESS(XexGetModuleHandle(modname, &hand)))
		XexGetProcedureAddress(hand, ord, &ptr2);
	return ptr2; // function not found
}

// this is how xam does it...
BOOL fileExists(PCHAR path)
{
	OBJECT_ATTRIBUTES obAtrib;
	FILE_NETWORK_OPEN_INFORMATION netInfo;
	STRING filePath;
	RtlInitAnsiString(&filePath, path); //  = 0x10
	InitializeObjectAttributes(&obAtrib, &filePath, 0x40, NULL);
	if(path[0] != '\\')
		obAtrib.RootDirectory = (HANDLE)0xFFFFFFFD;
	if(NT_SUCCESS(NtQueryFullAttributesFile(&obAtrib, &netInfo)))
	{
		// filter out directories from the result
		if((netInfo.FileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
			return TRUE;
	}
	return FALSE;
}

// this one was fixed to allow busy files to be detected as existing
//BOOL fileExists(PCHAR path)
//{
//	HANDLE = CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
//	if(file == INVALID_HANDLE_VALUE)
//	{
//		if(GetLastError() != 5) // inaccessible means it exists but is probably open somewhere else
//			return FALSE;
//	}
//	CloseHandle(file);
//	return TRUE;
//}

VOID patchInJump(PDWORD addr, DWORD dest, BOOL linked)
{
	DWORD writeBuffer;
	DWORD outInt;
	writeBuffer = 0x3D600000 + (((dest >> 16) & 0xFFFF) + (dest & 0x8000 ? 1 : 0)); // lis %r11, dest>>16 + 1
#ifdef _DEBUG
	DmSetMemory(&addr[0], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
	addr[0] = writeBuffer;
#endif

	writeBuffer = 0x396B0000 + (dest & 0xFFFF); // addi %r11, %r11, dest&0xFFFF
#ifdef _DEBUG
	DmSetMemory(&addr[1], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
	addr[1] = writeBuffer;
#endif

	writeBuffer = 0x7D6903A6; // mtctr %r11
#ifdef _DEBUG
	DmSetMemory(&addr[2], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
	addr[2] = writeBuffer;
#endif

	writeBuffer = 0x4E800420 | (linked ? 1 : 0); // bctr
#ifdef _DEBUG
	DmSetMemory(&addr[3], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
	addr[3] = writeBuffer;
#endif

	__dcbst(0, addr);
	__sync();
	__isync();
}

DWORD hookExportOrd(char* modName, DWORD ord, DWORD dstFun)
{
	PIMAGE_EXPORT_ADDRESS_TABLE expbase = getModuleEat(modName);
	if(expbase != NULL)
	{
		DWORD modOffset = (expbase->ImageBaseAddress)<<16;
		DWORD origOffset = (expbase->ordOffset[ord-1])+modOffset;
		expbase->ordOffset[ord-1] = dstFun-modOffset;
		__dcbst(0, &expbase->ordOffset[ord-1]);
		__sync();
		__isync();
		return origOffset;
	}
	return 0;
}

BOOL hookImpStub(char* modname, char* impmodname, DWORD ord, DWORD patchAddr)
{
	DWORD orgAddr;
	PLDR_DATA_TABLE_ENTRY ldat;
	int i, j;
	BOOL ret = FALSE;
	// get the address of the actual function that is jumped to
	orgAddr = resolveFunct(impmodname, ord);
	if(orgAddr != 0)
	{
		// find where kmod info is stowed
		ldat = (PLDR_DATA_TABLE_ENTRY)GetModuleHandle(modname);
		if(ldat != NULL)
		{
			// use kmod info to find xex header in memory
			PXEX_IMPORT_DESCRIPTOR imps = (PXEX_IMPORT_DESCRIPTOR)RtlImageXexHeaderField(ldat->XexHeaderBase, 0x000103FF);
			if(imps != NULL)
			{
				char* impName = (char*)(imps+1);
				PXEX_IMPORT_TABLE impTbl = (PXEX_IMPORT_TABLE)(impName + imps->NameTableSize);
				for(i = 0; i < (int)(imps->ModuleCount); i++)
				{
					// use import descriptor strings to refine table
					for(j = 0; j < impTbl->ImportCount; j++)
					{
						PDWORD add = (PDWORD)impTbl->ImportStubAddr[j];
						if(add[0] == orgAddr)
						{
							//DbgPrint("%s %s tbl %d has ord %x at tstub %d location %08x\n", modname, impName, i, ord, j, impTbl->ImportStubAddr[j+1]);
							patchInJump((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							j = impTbl->ImportCount;
							ret = TRUE;
						}
					}
					impTbl = (PXEX_IMPORT_TABLE)((BYTE*)impTbl+impTbl->TableSize);
					impName = impName+strlen(impName);
					while((impName[0]&0xFF) == 0x0)
						impName++;
				}
			}		
			//else DbgPrint("could not find import descriptor for mod %s\n", modname);
		}
		//else DbgPrint("could not find data table for mod %s\n", modname);
	}
	//else DbgPrint("could not find ordinal %d in mod %s\n", ord, impmodname);

	return ret;
}

BYTE* getModBaseSize(char* modName, PDWORD size)
{
	PLDR_DATA_TABLE_ENTRY ldat;
	ldat = (PLDR_DATA_TABLE_ENTRY)GetModuleHandle(modName);
	if(ldat != NULL)
	{
		if(ldat->EntryPoint > ldat->ImageBase)
			size[0] = ((DWORD)ldat->EntryPoint-(DWORD)ldat->ImageBase);
		else
			size[0] = ldat->SizeOfFullImage;
		return (BYTE*)ldat->ImageBase;
	}
	return NULL;
}

VOID __declspec(naked) GLPR_FUN(VOID)
{
	__asm{
		std     r14, -0x98(sp)
		std     r15, -0x90(sp)
		std     r16, -0x88(sp)
		std     r17, -0x80(sp)
		std     r18, -0x78(sp)
		std     r19, -0x70(sp)
		std     r20, -0x68(sp)
		std     r21, -0x60(sp)
		std     r22, -0x58(sp)
		std     r23, -0x50(sp)
		std     r24, -0x48(sp)
		std     r25, -0x40(sp)
		std     r26, -0x38(sp)
		std     r27, -0x30(sp)
		std     r28, -0x28(sp)
		std     r29, -0x20(sp)
		std     r30, -0x18(sp)
		std     r31, -0x10(sp)
		stw     r12, -0x8(sp)
		blr
	}
}

DWORD relinkGPLR(int offset, PDWORD saveStubAddr, PDWORD orgAddr)
{
	DWORD inst = 0, repl;
	int i;
	PDWORD saver = (PDWORD)GLPR_FUN;
	// if the msb is set in the instruction, set the rest of the bits to make the int negative
	if(offset&0x2000000)
		offset = offset|0xFC000000;
	//DbgPrint("frame save offset: %08x\n", offset);
	repl = orgAddr[offset/4];
	//DbgPrint("replacing %08x\n", repl);
	for(i = 0; i < 20; i++)
	{
		if(repl == saver[i])
		{
			int newOffset = (int)&saver[i]-(int)saveStubAddr;
			inst = 0x48000001|(newOffset&0x3FFFFFC);
			//DbgPrint("saver addr: %08x savestubaddr: %08x\n", &saver[i], saveStubAddr);
		}
	}
	//DbgPrint("new instruction: %08x\n", inst);
	return inst;
}

VOID hookFunctionStart(PDWORD addr, PDWORD saveStub, DWORD dest)
{
	if((saveStub != NULL)&&(addr != NULL))
	{
		int i;
		DWORD addrReloc = (DWORD)(&addr[4]);// replacing 4 instructions with a jump, this is the stub return address
		//DbgPrint("hooking addr: %08x savestub: %08x dest: %08x addreloc: %08x\n", addr, saveStub, dest, addrReloc);
		// build the stub
		// make a jump to go to the original function start+4 instructions
		DWORD writeBuffer;
		DWORD outInt;

		writeBuffer = 0x3D600000 + (((addrReloc >> 16) & 0xFFFF) + (addrReloc & 0x8000 ? 1 : 0)); // lis %r11, dest>>16 + 1
#ifdef _DEBUG
		DmSetMemory(&saveStub[0], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
		saveStub[0] = writeBuffer;
#endif

		writeBuffer = 0x396B0000 + (addrReloc & 0xFFFF); // addi %r11, %r11, dest&0xFFFF
#ifdef _DEBUG
		DmSetMemory(&saveStub[1], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
		saveStub[1] = writeBuffer;
#endif

		writeBuffer = 0x7D6903A6; // mtctr %r11
#ifdef _DEBUG
		DmSetMemory(&saveStub[2], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
		saveStub[2] = writeBuffer;
#endif

		// instructions [3] through [6] are replaced with the original instructions from the function hook
		// copy original instructions over, relink stack frame saves to local ones
		for(i = 0; i<4; i++)
		{
			writeBuffer = ((addr[i]&0x48000003) == 0x48000001) ? relinkGPLR((addr[i]&~0x48000003), &saveStub[i+3], &addr[i]) : addr[i];
#ifdef _DEBUG
				DmSetMemory(&saveStub[i+3], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
				saveStub[i+3] = writeBuffer;
#endif
		}
		writeBuffer = 0x4E800420; // bctr
#ifdef _DEBUG
		DmSetMemory(&saveStub[7], 4, &writeBuffer, &outInt);
#elif defined(NDEBUG)
		saveStub[7] = writeBuffer;
#endif
		__dcbst(0, saveStub);
		__sync();
		__isync();

		//DbgPrint("savestub:\n");
		//for(i = 0; i < 8; i++)
		//{
		//	DbgPrint("PatchDword(0x%08x, 0x%08x);\n", &saveStub[i], saveStub[i]);
		//}
		// patch the actual function to jump to our replaced one
		patchInJump(addr, dest, FALSE);
	}
}

PDWORD hookFunctionStartOrd(char* modName, DWORD ord, PDWORD saveStub, DWORD dest)
{
	PDWORD addr = (PDWORD)resolveFunct(modName, ord);
	if(addr != NULL)
		hookFunctionStart(addr, saveStub, dest);
	return addr;
}

