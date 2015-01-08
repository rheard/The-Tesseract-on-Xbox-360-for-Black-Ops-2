#include <xtl.h>
#include <xboxmath.h>
#include <xbox.h>
#include <stdio.h>
#include "Hooking.h"

#ifdef _DEBUG
#include <xbdm.h>
#endif

short alwaysBranchPatch = 0x4800;
int NOP = 0x60000000,
	returnFalse = 0x38600000,
	returnTrue = 0x38600001,
	liR40 = 0x38800000,
	liR50 = 0x38A00000,
	liR60 = 0x38C00000,
	liR70 = 0x38E00000,
	liR90 = 0x39200000,
	BLR = 0x4E800020;
bool thisIsTrue = true,
	thisIsFalse = false;

extern "C"
{
  VOID KeSweepIcacheRange( PVOID Address, DWORD cbBytes );
}

void CreateDirectoryB(char * name)
{
	int numOfSlashes = 0;
	char tempChar;
	for(int q = 0; ; q++)
	if(name[q] == '\\') {
		if((++numOfSlashes) > 1)
		{
			tempChar = name[q+1];
			name[q+1] = 0;
			CreateDirectory(name, NULL);
			name[q+1] = tempChar;
		}
	}
	else if(!name[q]) break;
}

char assetFileNameBuff[0xA0];
//We CANNOT overwrite asset names. You NEED an output buff so we don't overwrite anything
char * ConvertAssetNameToFileName(char * assetName, char * outputBuff)
{
	if(!assetName || !outputBuff) return 0;

	int fileNameOffset = 0;
	for(int i = 0;; i++)
	{
		if(assetName[i] =='/')
			outputBuff[i] = '\\';
		else if(assetName[i] == '+')
			outputBuff[i] = '_';
		else
			outputBuff[i] = assetName[i];

		if(assetName[i] == 0x00)
			break;
	}

	return outputBuff;
}

char * ConvertAssetNameToFileName(char * assetName)
{
	return ConvertAssetNameToFileName(assetName, assetFileNameBuff);
}

char * ConvertAssetNameToFileName(const char * assetName)
{
	return ConvertAssetNameToFileName((char*)assetName, assetFileNameBuff);
}

char * va( char *format,...)
{
    va_list arglist;
    va_start(arglist,format);
    vsprintf(MasterCharBuffer,format,arglist);
    va_end(arglist);
	return MasterCharBuffer;
}

char *improved_strtok(char *buf, const char *delim) 
{
	char *p;
	static char *secret_state;

	p = buf ? buf : secret_state;
	if (p == NULL)
		return (NULL);

	secret_state = p + strcspn(p, delim);
	if (*secret_state)
		*secret_state++ = 0;
	else
		secret_state = NULL;
	return (p);
}

char *improved_strtok2(char *buf, const char *delim) 
{
	char *p;
	static char *secret_state2;

	p = buf ? buf : secret_state2;
	if (p == NULL)
		return (NULL);

	secret_state2 = p + strcspn(p, delim);
	if (*secret_state2)
		*secret_state2++ = 0;
	else
		secret_state2 = NULL;
	return (p);
}

VOID DoPatches( PDWORD pBuffer, DWORD dwLength )
{
  PDWORD pdwData = pBuffer;

  // Sanity check
  if ( pdwData[ ( dwLength / 4 ) - 1 ] != -1 )
    return;

  for(;;)
  {
    DWORD dwAddress = *pdwData++;

    if ( dwAddress == -1 )
      break;

    DWORD dwPatchCount = *pdwData++;

    for ( DWORD i = 0; i < dwPatchCount; i++ )
    {
      DWORD dwAddrToPatch = dwAddress + ( i * 4 );

      *( DWORD* )( dwAddrToPatch ) = *pdwData++;
    }

    KeSweepIcacheRange( ( PVOID )dwAddress, dwPatchCount * 4 );
  }
}

HRESULT returnResult;
DWORD WriteMemory(LPVOID address, DWORD size, LPCVOID data, HRESULT * optionalOutput)
{
	DWORD outInt;
#ifdef _DEBUG
	returnResult = DmSetMemory(address, size, data, &outInt);
#endif
#ifdef NDEBUG
	returnResult = memcpy(address, data, size) == address ? ERROR_SUCCESS : TYPE_E_UNDEFINEDTYPE;
	outInt = size;
#endif

	if(optionalOutput != 0)
		optionalOutput = &returnResult;

	return outInt;
}

__declspec(naked) void patchMemory(DWORD addr, DWORD sourceAddr, int size)
{
	__asm
	{
		mtctr   r5
loopstart:
		lwz	r5, 0(r4)
		stw	r5, 0(r3)
		addi	r4, r4, 4
		addi	r3, r3, 4
		bdnz	loopstart
		blr
	}
}