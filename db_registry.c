#include "db_load.h"
#include "AddressReverser.h"
#include "Hooking.h"
#include "utility.h"
#include "db_registry.h"
#include "bg_weapons_attachment.h"
#include "stringed_hooks.h"
#include <io.h>
char dumpFileName[0xA0];

#pragma optimize("", off)
__declspec(naked) void Load_PhysPresetAssetSaveStub(PhysPreset ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 1	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_PhysConstraintsAssetSaveStub(PhysConstraints ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 2	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_DestructibleDefAssetSaveStub(DestructibleDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 3	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_GfxImageAssetSaveStub(GfxImage ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 9	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_MapEntsAssetSaveStub(MapEnts ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x11	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_GfxLightDefAssetSaveStub(GfxLightDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x13	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_LocalizeEntryAssetSaveStub(LocalizeEntry ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x19	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_WeaponVariantDefAssetSaveStub(WeaponVariantDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x1A	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_WeaponAttachmentAssetSaveStub(WeaponAttachment ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x1E	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_WeaponAttachmentUniqueAssetSaveStub(WeaponAttachmentUnique ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x1F	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_RawFileAssetSaveStub(RawFile ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x2A	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_StringTableAssetSaveStub(StringTable ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x2B	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_ddlRoot_tAssetSaveStub(ddlRoot_t ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x2E	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_ScriptParseTreeAssetSaveStub(ScriptParseTree ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x32
	}
}

__declspec(naked) void Load_VehicleDefAssetSaveStub(VehicleDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x34	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_TracerDefAssetSaveStub(TracerDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x37	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_QdbAssetSaveStub(Qdb ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x39	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_SlugAssetSaveStub(Slug ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x3A	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_FootstepTableDefAssetSaveStub(FootstepTableDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x3B	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_FootstepFXTableDefAssetSaveStub(FootstepFXTableDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x3C	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Load_ZBarrierDefAssetSaveStub(ZBarrierDef ** input)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r3, 0x3D	//Make sure to change something to prevent optimizations
	}
}

__declspec(naked) void Scr_GetGSCObjSaveStub(scriptInstance_t inst, const char *name, bool appendExtension, bool errorIfMissing)
{
		__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r4, 0x0
	}
}

__declspec(naked) void Scr_LoadScriptInternalSaveStub(scriptInstance_t inst, const char *filename)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li r4, 0x90
	}
}

__declspec(naked) void DB_FindXAssetHeader_Signature() {
	__asm {
		mr        r28, r3
		mr        r23, r5
		li        r5, 8
	}
}

__declspec(naked) void DB_XAssetPools_Signature() {
	__asm {
		lwz       r10, 0(r3)
		lwz       r4, 4(r3)
		mr        r31, r3
	}
}
#pragma optimize("", on)

DB_FindXAssetHeader_t DB_FindXAssetHeader = (DB_FindXAssetHeader_t)FindFunctionStart(AlignedMemorySearch(".text", DB_FindXAssetHeader_Signature, 0xC));

//Takes input string, checks to see if string has been allocated before...
//If it has, use the pre-allocated string
//If it hasn't, allocate and add to string allocation pool.
int stringAllocCount = 2;
char * stringAllocPool[0x1000] = {"", "0"}; //Predefine these 2, they are very common and I want to find them very fast.
char * AllocateString(char *inputStr)
{
	for(int i = 0; i < stringAllocCount; i++)
		if(!strcmp(stringAllocPool[i], inputStr))
			return stringAllocPool[i];

	char * newString = new char[strlen(inputStr)+1];
	strcpy(newString,inputStr);
	stringAllocPool[stringAllocCount++] = newString;
	return newString;
}

#pragma optimize("", off)
bool WriteAssetEntry(AssetEntry * currentEntries, char * tokenName, char * tokenValue, void * assetHeader, const char * parentName, bool parentReversed)
{
	AssetEntry * thisEntry = 0;

	bool hasFoundEntry = false;
	if(currentEntries && tokenName && assetHeader)
	for(int i = 0; currentEntries[i].name; i++)
	{
		if(currentEntries[i].type == ASSET_ENTRY_EMBEDDED)
			hasFoundEntry = WriteAssetEntry(currentEntries[i].next, tokenName, tokenValue, (void*)((unsigned int)assetHeader + currentEntries[i].offset), currentEntries[i].name, false);
		else if(currentEntries[i].type == ASSET_ENTRY_EMBEDDED_REVERSED)
			hasFoundEntry = WriteAssetEntry(currentEntries[i].next, tokenName, tokenValue, (void*)((unsigned int)assetHeader + currentEntries[i].offset), currentEntries[i].name, true);
		else if(currentEntries[i].type != ASSET_ENTRY_CONTAINED && currentEntries[i].type != ASSET_ENTRY_CONTAINED_REVERSED)
		{
			if((!parentReversed && *parentName && !strnicmp(parentName, tokenName, strlen(parentName)) && !stricmp(currentEntries[i].name, tokenName + strlen(parentName))) ||
				(*parentName && !strnicmp(currentEntries[i].name, tokenName, strlen(currentEntries[i].name)) && !stricmp(parentName, tokenName + strlen(currentEntries[i].name))) ||
				!stricmp(currentEntries[i].name, tokenName))
			{
				thisEntry = &currentEntries[i];
				break;
			}
		}
		else if(*(void**)((unsigned int)assetHeader + currentEntries[i].offset))
			hasFoundEntry = WriteAssetEntry(currentEntries[i].next, tokenName, tokenValue, *(void**)((unsigned int)assetHeader + currentEntries[i].offset), currentEntries[i].name, (currentEntries[i].type == ASSET_ENTRY_CONTAINED_REVERSED));

		if(hasFoundEntry) break;
	}

	int sizeToCopy = 0, possibleIntValue = 0;
	short possibleShortValue = 0;
	float possibleFloatValue = 0.f;
	byte possibleByteValue = 0;
	void * assetPointerToWrite = 0;
	char * possibleStringValue = 0;
	void * dataToWrite = 0;

	if(!hasFoundEntry && thisEntry && tokenValue)
	{

	switch(thisEntry->type)
	{
		case ASSET_ENTRY_BYTE:
		case ASSET_ENTRY_BOOL:
			sizeToCopy = 1;
			possibleByteValue = (byte)atoi(tokenValue);
			dataToWrite = &possibleByteValue;
			break;
		case ASSET_ENTRY_SHORT:
		case ASSET_ENTRY_UNSIGNED_SHORT:
			sizeToCopy = 2;
			possibleShortValue = (short)atoi(tokenValue);
			dataToWrite = &possibleShortValue;
			break;
		case ASSET_ENTRY_BOOL_AS_INT:
			possibleIntValue = (atoi(tokenValue) != 0);
			goto COPY_INT;
		case ASSET_ENTRY_INT:
			possibleIntValue = atoi(tokenValue);
			goto COPY_INT;
		case ASSET_ENTRY_UNSIGNED_INT:
			possibleIntValue = strtoul(tokenValue, NULL, 10);
			goto COPY_INT;
		case ASSET_ENTRY_TIME_AS_INT:
			possibleIntValue = (int)(atof(tokenValue) * 1000);
			goto COPY_INT;
		case ASSET_ENTRY_FLOAT:
			possibleFloatValue = atof(tokenValue);
			if(abs(*(float*)((unsigned int)assetHeader + thisEntry->offset) - possibleFloatValue) > 0.15)
			{
				dataToWrite= &possibleFloatValue;
				goto COPY_4;
			}
			hasFoundEntry = true;
			break;
		case ASSET_ENTRY_STRING:
			{
			char * stringToReplace = *(char**)((unsigned int)assetHeader + thisEntry->offset);
			if(!*tokenValue && !stringToReplace) { }
			else if(strcmp(tokenValue, stringToReplace) != 0)
			{
				possibleStringValue = AllocateString(tokenValue);
				dataToWrite = &possibleStringValue;
				goto COPY_4;
			}
			hasFoundEntry = true;
			}
			break;
		case ASSET_ENTRY_SCRIPT_STRING:
			{
			const char * oldValue = SL_ConvertToString(*(unsigned short*)((unsigned int)assetHeader + thisEntry->offset));
			if(!*tokenValue && !oldValue) { }
			else if(strcmp(tokenValue, oldValue) != 0)
			{
				sizeToCopy = 2;
				possibleShortValue = (unsigned short)SL_FindString(tokenValue);
				dataToWrite = &possibleShortValue;
			}
			hasFoundEntry = true;
			}
			break;
		case ASSET_ENTRY_ASSET_PTR:
			assetPointerToWrite = *tokenValue ? 
				DB_FindXAssetHeader((XAssetType)((int)(thisEntry->next)), tokenValue, true, -1).data
				: 0;
			dataToWrite = &assetPointerToWrite;
			goto COPY_4;
		case ASSET_ENTRY_ENUM_SHORT:
			for(int i = 0; *(char**)((int)(thisEntry->next) + (4*i)) && i < thisEntry->enumCount; i++)
			if(!strcmpi(*(char**)((int)(thisEntry->next) + (4*i)), tokenValue))
			{
				possibleShortValue = i;
				sizeToCopy = 2;
				dataToWrite = &possibleShortValue;
			}
			hasFoundEntry = true;
			break;
		case ASSET_ENTRY_ENUM:
			for(int i = 0; *(char**)((int)(thisEntry->next) + (4*i)) && i < thisEntry->enumCount; i++)
			if(!strcmpi(*(char**)((int)(thisEntry->next) + (4*i)), tokenValue))
			{
				possibleIntValue = i;
				goto COPY_INT;
			}
		COPY_INT:
			dataToWrite = &possibleIntValue;
			goto COPY_4;
		COPY_4:
			sizeToCopy = 4;
			break;
		default: break;
	}

	if(dataToWrite)
	{
		if(memcmp((void*)(thisEntry->offset + (unsigned int)assetHeader), dataToWrite, sizeToCopy))
			WriteMemory((void*)(thisEntry->offset + (unsigned int)assetHeader), sizeToCopy, dataToWrite);

		hasFoundEntry = true;
	}
	}

	return hasFoundEntry;
}
#pragma optimize("", on)

bool DumpAssetEntry(FILE * writeLog, AssetEntryType currentEntryType, const char * currentEntryName, void * assetData, AssetEntry * containedItems, int enumCount, const char * parentName)
{
	if(!writeLog || !currentEntryName || !assetData)
		return false;

	if(currentEntryType != ASSET_ENTRY_CONTAINED && currentEntryType != ASSET_ENTRY_EMBEDDED &&
		currentEntryType != ASSET_ENTRY_CONTAINED_REVERSED && currentEntryType != ASSET_ENTRY_EMBEDDED_REVERSED)
		fprintf(writeLog, "\\%s%s", parentName, currentEntryName);

	switch(currentEntryType)
	{
		case ASSET_ENTRY_BYTE:
		case ASSET_ENTRY_BOOL:
			fprintf(writeLog, "\\%i", *(byte*)assetData);
			break;
		case ASSET_ENTRY_SHORT:
			fprintf(writeLog, "\\%hd", *(short*)assetData);
			break;
		case ASSET_ENTRY_UNSIGNED_SHORT:
			fprintf(writeLog, "\\%hu", *(unsigned short*)assetData);
			break;
		case ASSET_ENTRY_BOOL_AS_INT:
			fprintf(writeLog, "\\%i", *(int*)assetData != 0);
			break;
		case ASSET_ENTRY_INT:
			fprintf(writeLog, "\\%i", *(int*)assetData);
			break;
		case ASSET_ENTRY_UNSIGNED_INT:
			fprintf(writeLog, "\\%u", *(unsigned int*)assetData);
			break;
		case ASSET_ENTRY_TIME_AS_INT:
			fprintf(writeLog, "\\%g", ((float)*(unsigned int*)assetData) / 1000);
			break;
		case ASSET_ENTRY_FLOAT:
			fprintf(writeLog, "\\%g", *(float*)assetData);
			break;
		case ASSET_ENTRY_STRING:
			fprintf(writeLog, "\\%s", *(char**)assetData ? *(char**)assetData : "");
			break;
		case ASSET_ENTRY_SCRIPT_STRING:
			{
				const char * stringVal = SL_ConvertToString(*(unsigned short*)assetData);
				fprintf(writeLog, "\\%s", stringVal ? stringVal : "");
			}
			break;
		case ASSET_ENTRY_ASSET_PTR:
			fprintf(writeLog, "\\%s", *(char***)assetData ? (**(char***)assetData) : "");
			break;
		case ASSET_ENTRY_ENUM:
			fprintf(writeLog, "\\%s", *(int*)assetData < enumCount ? *(char**)((int)(containedItems) + (4*(*(int*)assetData))) : "");
			break;
		case ASSET_ENTRY_ENUM_SHORT:
			fprintf(writeLog, "\\%s", *(short*)assetData < enumCount ? *(char**)((int)(containedItems) + (4*(*(short*)assetData))) : "");
			break;
		case ASSET_ENTRY_EMBEDDED:
			if(containedItems)
			for(int i = 0; containedItems[i].name; i++)
				DumpAssetEntry(writeLog, containedItems[i].type, containedItems[i].name, (void*)((int)assetData + containedItems[i].offset), containedItems[i].next, containedItems[i].enumCount, currentEntryName);
			break;
		case ASSET_ENTRY_EMBEDDED_REVERSED:
			if(containedItems)
			for(int i = 0; containedItems[i].name; i++)
				DumpAssetEntry(writeLog, containedItems[i].type, currentEntryName, (void*)((int)assetData + containedItems[i].offset), containedItems[i].next, containedItems[i].enumCount, containedItems[i].name);
			break;
		case ASSET_ENTRY_CONTAINED_REVERSED:
			if(containedItems && *(int*)assetData)
			for(int i = 0; containedItems[i].name; i++)
				DumpAssetEntry(writeLog, containedItems[i].type, currentEntryName, (void*)(*(int*)assetData + containedItems[i].offset), containedItems[i].next, containedItems[i].enumCount, containedItems[i].name);
			break;
		case ASSET_ENTRY_CONTAINED:
			if(containedItems && *(int*)assetData)
			for(int i = 0; containedItems[i].name; i++)
				DumpAssetEntry(writeLog, containedItems[i].type, containedItems[i].name, (void*)(*(int*)assetData + containedItems[i].offset), containedItems[i].next, containedItems[i].enumCount, currentEntryName);
		default: 
			break;
	}

	return true;
}

AssetEntry VectorEntry[] = {
	{"Forward",	0, ASSET_ENTRY_FLOAT,0,0},
	{"Right",	4, ASSET_ENTRY_FLOAT,0,0},
	{"Up",		8, ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry AngleEntry[] = {
	{"Pitch",	0, ASSET_ENTRY_FLOAT,0,0},
	{"Yaw",		4, ASSET_ENTRY_FLOAT,0,0},
	{"Roll",	8, ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry OffsetEntry[] = {
	{"X",	0, ASSET_ENTRY_FLOAT,0,0},
	{"Y",	4, ASSET_ENTRY_FLOAT,0,0},
	{"Z",	8, ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry MinMax_FloatEntry[] = {
	{"Min",	0,	ASSET_ENTRY_FLOAT,0,0},
	{"Max",	4,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry MinMax_IntEntry[] = {
	{"Min",					0,					ASSET_ENTRY_INT,0,0},
	{"Max",					4,					ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

#pragma region physpreset (0x01)
AssetEntry PhysPresetEntries[] = {
	{"flags",					offsetof(PhysPreset, flags),					ASSET_ENTRY_INT,0,0},
	{"mass",					offsetof(PhysPreset, mass),						ASSET_ENTRY_FLOAT,0,0},
	{"bounce",					offsetof(PhysPreset, bounce),					ASSET_ENTRY_FLOAT,0,0},
	{"friction",				offsetof(PhysPreset, friction),					ASSET_ENTRY_FLOAT,0,0},
	{"bulletForceScale",		offsetof(PhysPreset, bulletForceScale),			ASSET_ENTRY_FLOAT,0,0},
	{"explosiveForceScale",		offsetof(PhysPreset, explosiveForceScale),		ASSET_ENTRY_FLOAT,0,0},
	{"sndAliasPrefix",			offsetof(PhysPreset, sndAliasPrefix),			ASSET_ENTRY_STRING,0,0},
	{"piecesSpreadFraction",	offsetof(PhysPreset, piecesSpreadFraction),		ASSET_ENTRY_FLOAT,0,0},
	{"piecesUpwardVelocity",	offsetof(PhysPreset, piecesUpwardVelocity),		ASSET_ENTRY_FLOAT,0,0},
	{"canFloat",				offsetof(PhysPreset, canFloat),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"gravityScale",			offsetof(PhysPreset, gravityScale),				ASSET_ENTRY_FLOAT,0,0},
	{"centerOfMassOffset",		offsetof(PhysPreset, centerOfMassOffset),		ASSET_ENTRY_EMBEDDED,				OffsetEntry,0},
	{"buoyancyBoxMin",			offsetof(PhysPreset, buoyancyBoxMin),			ASSET_ENTRY_EMBEDDED,				OffsetEntry,0},
	{"buoyancyBoxMax",			offsetof(PhysPreset, buoyancyBoxMax),			ASSET_ENTRY_EMBEDDED,				OffsetEntry,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_PhysPresetAsset_t Load_PhysPresetAsset = (Load_PhysPresetAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x24)) + 0xA4));

int PhysPreset::dumpPhysPreset()
{
	CreateDirectoryB(va("game:\\dump\\physic\\%s", (char*)name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "physpreset", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog, "PHYSIC\\isFrictionInfinity\\%i", friction >= 340282346638528860000000000000000000000.f);

	for(int i = 0; PhysPresetEntries[i].name; i++)
	if(PhysPresetEntries[i].offset == offsetof(PhysPreset, friction) && friction >= 340282346638528860000000000000000000000.f)
		fprintf(writeLog,"\\friction\\0.5");
	else
		DumpAssetEntry(writeLog, PhysPresetEntries[i].type, PhysPresetEntries[i].name, (void*)((int)(this) + PhysPresetEntries[i].offset), PhysPresetEntries[i].next);

	fclose(writeLog);

	return ERROR_SUCCESS;
}

void Load_PhysPresetAssetHook(PhysPreset ** input)
{
	PhysPreset * currentPhysPreset = *input;

	//(*input)->dumpPhysPreset();
	//Can we load this physpreset custom?
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\physic\\%s", (char*)currentPhysPreset->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE physicsFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead;
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		if(physicsFile != INVALID_HANDLE_VALUE && ReadFile(physicsFile, theAssetBuffer, GetFileSize(physicsFile, NULL), (LPDWORD)&numberOfBytesRead, 0))
		{
			CloseHandle(physicsFile);
			char * currentToken = improved_strtok(theAssetBuffer,"\\");
			if(!strcmp(currentToken, "PHYSIC"))
			{
				bool isFrictionInfinity = false;
				float readFriction = FLT_MIN;
				for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
				{
					char * currentName = currentToken,
						* currentValue = improved_strtok(NULL, "\\");

					if(!strcmpi(currentName, "isFrictionInfinity"))
					{
						isFrictionInfinity = atoi(currentValue) == 1;
						if(isFrictionInfinity)
							currentPhysPreset->friction = 340282346638528860000000000000000000000.f;
						else if(readFriction != FLT_MIN)
							currentPhysPreset->friction = readFriction;
					}
					else if(!strcmpi(currentName, "friction"))
					{
						if(!isFrictionInfinity)
							currentPhysPreset->friction = readFriction = atof(currentValue);
					}
					else if(!WriteAssetEntry(PhysPresetEntries, currentName, currentValue, currentPhysPreset)) 
						printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "physpreset", currentPhysPreset->name);
				}
			}
			else
				printf("%s is not a %s file\n", currentPhysPreset->name, "physpreset");
		}
	}
	usingAssetBuffer = false;

	Load_PhysPresetAssetSaveStub(input);
}
#pragma endregion

#pragma region physconstraints (0x02)
AssetEntry PhysConstraintEntries[] = {
	{"targetname",				offsetof(PhysConstraint, targetname),			ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"type",					offsetof(PhysConstraint, type),					ASSET_ENTRY_ENUM,				(AssetEntry*)s_constraintTypeNames,		NUM_CONSTRAINT_TYPES},
	{"attach_point_type1",		offsetof(PhysConstraint, attach_point_type1),	ASSET_ENTRY_ENUM,				(AssetEntry*)s_attachPointTypeNames,	ATTACH_POINT_BONE+1},
	{"target_index1",			offsetof(PhysConstraint, target_index1),		ASSET_ENTRY_INT,0,0},
	{"target_ent1",				offsetof(PhysConstraint, target_ent1),			ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"target_bone1",			offsetof(PhysConstraint, target_bone1),			ASSET_ENTRY_STRING,0,0},
	{"attach_point_type2",		offsetof(PhysConstraint, attach_point_type2),	ASSET_ENTRY_ENUM,				(AssetEntry*)s_attachPointTypeNames,	ATTACH_POINT_BONE+1},
	{"target_index2",			offsetof(PhysConstraint, target_index2),		ASSET_ENTRY_INT,0,0},
	{"target_ent2",				offsetof(PhysConstraint, target_ent2),			ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"target_bone2",			offsetof(PhysConstraint, target_bone2),			ASSET_ENTRY_STRING,0,0},
	{"offset_x",				offsetof(PhysConstraint, offset),				ASSET_ENTRY_FLOAT,0,0},
	{"offset_y",				offsetof(PhysConstraint, offset) + 4,			ASSET_ENTRY_FLOAT,0,0},
	{"offset_z",				offsetof(PhysConstraint, offset) + 8,			ASSET_ENTRY_FLOAT,0,0},
	{"pos_x",					offsetof(PhysConstraint, pos),					ASSET_ENTRY_FLOAT,0,0},
	{"pos_y",					offsetof(PhysConstraint, pos) + 4,				ASSET_ENTRY_FLOAT,0,0},
	{"pos_z",					offsetof(PhysConstraint, pos) + 8,				ASSET_ENTRY_FLOAT,0,0},
	{"pos2_x",					offsetof(PhysConstraint, pos2),					ASSET_ENTRY_FLOAT,0,0},
	{"pos2_y",					offsetof(PhysConstraint, pos2) + 4,				ASSET_ENTRY_FLOAT,0,0},
	{"pos2_z",					offsetof(PhysConstraint, pos2) + 8,				ASSET_ENTRY_FLOAT,0,0},
	{"dir_x",					offsetof(PhysConstraint, dir),					ASSET_ENTRY_FLOAT,0,0},
	{"dir_y",					offsetof(PhysConstraint, dir) + 4,				ASSET_ENTRY_FLOAT,0,0},
	{"dir_z",					offsetof(PhysConstraint, dir) + 8,				ASSET_ENTRY_FLOAT,0,0},
	{"flags",					offsetof(PhysConstraint, flags),				ASSET_ENTRY_INT,0,0},
	{"timeout",					offsetof(PhysConstraint, timeout),				ASSET_ENTRY_INT,0,0},
	{"min_health",				offsetof(PhysConstraint, min_health),			ASSET_ENTRY_INT,0,0},
	{"max_health",				offsetof(PhysConstraint, max_health),			ASSET_ENTRY_INT,0,0},
	{"distance",				offsetof(PhysConstraint, distance),				ASSET_ENTRY_FLOAT,0,0},
	{"damp",					offsetof(PhysConstraint, damp),					ASSET_ENTRY_FLOAT,0,0},
	{"power",					offsetof(PhysConstraint, power),				ASSET_ENTRY_FLOAT,0,0},
	{"scale_x",					offsetof(PhysConstraint, scale),				ASSET_ENTRY_FLOAT,0,0},
	{"scale_y",					offsetof(PhysConstraint, scale) + 4,			ASSET_ENTRY_FLOAT,0,0},
	{"scale_z",					offsetof(PhysConstraint, scale) + 8,			ASSET_ENTRY_FLOAT,0,0},
	{"spin_scale",				offsetof(PhysConstraint, spin_scale),			ASSET_ENTRY_FLOAT,0,0},
	{"minAngle",				offsetof(PhysConstraint, minAngle),				ASSET_ENTRY_FLOAT,0,0},
	{"maxAngle",				offsetof(PhysConstraint, maxAngle),				ASSET_ENTRY_FLOAT,0,0},
	{"material",				offsetof(PhysConstraint, material),				ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"constraintHandle",		offsetof(PhysConstraint, constraintHandle),		ASSET_ENTRY_INT,0,0},
	{"rope_index",				offsetof(PhysConstraint, rope_index),			ASSET_ENTRY_INT,0,0},
	{"centity_num1",			offsetof(PhysConstraint, centity_num[0]),		ASSET_ENTRY_INT,0,0},
	{"centity_num2",			offsetof(PhysConstraint, centity_num[1]),		ASSET_ENTRY_INT,0,0},
	{"centity_num3",			offsetof(PhysConstraint, centity_num[2]),		ASSET_ENTRY_INT,0,0},
	{"centity_num4",			offsetof(PhysConstraint, centity_num[3]),		ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry PhysConstraintsEntries[] = {
	{"count",	offsetof(PhysConstraints, count),		ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"c1_",		offsetof(PhysConstraints, data[0]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c2_",		offsetof(PhysConstraints, data[1]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c3_",		offsetof(PhysConstraints, data[2]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c4_",		offsetof(PhysConstraints, data[3]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c5_",		offsetof(PhysConstraints, data[4]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c6_",		offsetof(PhysConstraints, data[5]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c7_",		offsetof(PhysConstraints, data[6]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c8_",		offsetof(PhysConstraints, data[7]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c9_",		offsetof(PhysConstraints, data[8]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c10_",	offsetof(PhysConstraints, data[9]),		ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c11_",	offsetof(PhysConstraints, data[10]),	ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c12_",	offsetof(PhysConstraints, data[11]),	ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c13_",	offsetof(PhysConstraints, data[12]),	ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c14_",	offsetof(PhysConstraints, data[13]),	ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c15_",	offsetof(PhysConstraints, data[14]),	ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{"c16_",	offsetof(PhysConstraints, data[15]),	ASSET_ENTRY_EMBEDDED,	PhysConstraintEntries,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_PhysConstraintsAsset_t Load_PhysConstraintsAsset = (Load_PhysConstraintsAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x40)) + 0xA4));

int PhysConstraints::dumpPhysConstraints()
{
	CreateDirectoryB(va("game:\\dump\\physconstraints\\%s", (char*)name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "physconstraint", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog, "PHYSCONSTRAINTS\\count\\%u", count);
	
	for(int j = 0; j < count; j++)
	{
		char tempBuff[10];
		sprintf(tempBuff, "c%i_", j+1);
		for(int i = 0; PhysConstraintEntries[i].name; i++)
			DumpAssetEntry(writeLog, PhysConstraintEntries[i].type, PhysConstraintEntries[i].name, (void*)((int)&data[j] + PhysConstraintEntries[i].offset), PhysConstraintEntries[i].next, PhysConstraintEntries[i].enumCount, tempBuff);
	}

	fclose(writeLog);

	return ERROR_SUCCESS;
}

void Load_PhysConstraintsAssetHook(PhysConstraints ** input)
{
	PhysConstraints * currentPhysConstraints = *input;

	//(*input)->dumpPhysConstraints();
	//Can we load this physpreset custom?
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\physconstraints\\%s", (char*)currentPhysConstraints->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE physConstraintsFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead;
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		if(physConstraintsFile != INVALID_HANDLE_VALUE && ReadFile(physConstraintsFile, theAssetBuffer, GetFileSize(physConstraintsFile, NULL), (LPDWORD)&numberOfBytesRead, 0))
		{
			CloseHandle(physConstraintsFile);
			char * currentToken = improved_strtok(theAssetBuffer,"\\");
			if(!strcmp(currentToken, "PHYSCONSTRAINTS"))
			{
				for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
				{
					char * currentName = currentToken,
						* currentValue = improved_strtok(NULL, "\\");

					if(!WriteAssetEntry(PhysConstraintsEntries, currentName, currentValue, currentPhysConstraints)) 
						printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "physconstraint", currentPhysConstraints->name);
				}

			}
			else
				printf("%s is not a %s file\n", currentPhysConstraints->name, "physconstraint");
		}
	}
	usingAssetBuffer = false;

	Load_PhysConstraintsAssetSaveStub(input);
}
#pragma endregion

#pragma region destructibledef (0x03)
AssetEntry DestructibleDefEntries[] = {
	{"model",				offsetof(DestructibleDef, model),				ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"pristineModel",		offsetof(DestructibleDef, pristineModel),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"numPieces",			offsetof(DestructibleDef, numPieces),			ASSET_ENTRY_INT,0,0},
	{"clientOnly",			offsetof(DestructibleDef, clientOnly),			ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry DestructibleStageEntries[] = {
	{"showBone",			offsetof(DestructibleStage, showBone),				ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"breakHealth",			offsetof(DestructibleStage, breakHealth),			ASSET_ENTRY_FLOAT,0,0},
	{"maxTime",			offsetof(DestructibleStage, maxTime),			ASSET_ENTRY_FLOAT,0,0},
	{"flags",			offsetof(DestructibleStage, flags),			ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"breakEffect",		offsetof(DestructibleStage, breakEffect),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_FX,0},
	{"breakSound",			offsetof(DestructibleStage, breakSound),				ASSET_ENTRY_STRING,0,0},
	{"breakNotify",			offsetof(DestructibleStage, breakNotify),				ASSET_ENTRY_STRING,0,0},
	{"loopSound",			offsetof(DestructibleStage, loopSound),				ASSET_ENTRY_STRING,0,0},
	{"spawnModel1",		offsetof(DestructibleStage, spawnModel[0]),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"spawnModel2",		offsetof(DestructibleStage, spawnModel[1]),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"spawnModel3",		offsetof(DestructibleStage, spawnModel[2]),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"physPreset",		offsetof(DestructibleStage, physPreset),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_PHYSPRESET,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry DestructiblePieceEntries[] = {
	{"",				offsetof(DestructiblePiece, stages[0]),				ASSET_ENTRY_EMBEDDED_REVERSED,		DestructibleStageEntries,0},
	{"D1",				offsetof(DestructiblePiece, stages[1]),				ASSET_ENTRY_EMBEDDED_REVERSED,		DestructibleStageEntries,0},
	{"D2",				offsetof(DestructiblePiece, stages[2]),				ASSET_ENTRY_EMBEDDED_REVERSED,		DestructibleStageEntries,0},
	{"D3",				offsetof(DestructiblePiece, stages[3]),				ASSET_ENTRY_EMBEDDED_REVERSED,		DestructibleStageEntries,0},
	{"D4",				offsetof(DestructiblePiece, stages[4]),				ASSET_ENTRY_EMBEDDED_REVERSED,		DestructibleStageEntries,0},
	{"parentPiece",		offsetof(DestructiblePiece, parentPiece),			ASSET_ENTRY_BYTE,0,0},
	{"parentDamagePercent",			offsetof(DestructiblePiece, parentDamagePercent),			ASSET_ENTRY_FLOAT,0,0},
	{"bulletDamageScale",			offsetof(DestructiblePiece, bulletDamageScale),			ASSET_ENTRY_FLOAT,0,0},
	{"explosiveDamageScale",			offsetof(DestructiblePiece, explosiveDamageScale),			ASSET_ENTRY_FLOAT,0,0},
	{"meleeDamageScale",			offsetof(DestructiblePiece, meleeDamageScale),			ASSET_ENTRY_FLOAT,0,0},
	{"impactDamageScale",			offsetof(DestructiblePiece, impactDamageScale),			ASSET_ENTRY_FLOAT,0,0},
	{"entityDamageTransfer",			offsetof(DestructiblePiece, entityDamageTransfer),			ASSET_ENTRY_FLOAT,0,0},
	{"physConstraints",		offsetof(DestructiblePiece, physConstraints),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_PHYSCONSTRAINTS,0},
	{"health",			offsetof(DestructiblePiece, health),			ASSET_ENTRY_INT,0,0},
	{"damageSound",			offsetof(DestructiblePiece, damageSound),				ASSET_ENTRY_STRING,0,0},
	{"burnEffect",		offsetof(DestructiblePiece, burnEffect),		ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_FX,0},
	{"burnSound",			offsetof(DestructiblePiece, burnSound),				ASSET_ENTRY_STRING,0,0},
	{"enableLabel",			offsetof(DestructiblePiece, enableLabel),				ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"hideBone1",			offsetof(DestructiblePiece, hideBones[0]),			ASSET_ENTRY_INT,0,0},
	{"hideBone2",			offsetof(DestructiblePiece, hideBones[1]),			ASSET_ENTRY_INT,0,0},
	{"hideBone3",			offsetof(DestructiblePiece, hideBones[2]),			ASSET_ENTRY_INT,0,0},
	{"hideBone4",			offsetof(DestructiblePiece, hideBones[3]),			ASSET_ENTRY_INT,0,0},
	{"hideBone5",			offsetof(DestructiblePiece, hideBones[4]),			ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_DestructibleDefAsset_t Load_DestructibleDefAsset = (Load_DestructibleDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x5C)) + 0xA4));

int DestructiblePiece::dumpDestructiblePiece(const char * parentName, int pieceIndex)
{
	CreateDirectoryB(va("game:\\dump\\destructiblepiece\\%s_%i", (char*)parentName, pieceIndex));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "destructiblepiece", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog, "DESTRUCTIBLEPIECE");

	for(int i = 0; DestructiblePieceEntries[i].name; i++)
		DumpAssetEntry(writeLog, DestructiblePieceEntries[i].type, DestructiblePieceEntries[i].name, (void*)((int)(this) + DestructiblePieceEntries[i].offset), DestructiblePieceEntries[i].next, DestructiblePieceEntries[i].enumCount);

	fclose(writeLog);

	return ERROR_SUCCESS;
}

int DestructibleDef::dumpDestructibleDef()
{
	CreateDirectoryB(va("game:\\dump\\destructibledef\\%s", (char*)name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "destructibledef", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog, "DESTRUCTIBLEDEF");

	for(int i = 0; DestructibleDefEntries[i].name; i++)
		DumpAssetEntry(writeLog, DestructibleDefEntries[i].type, DestructibleDefEntries[i].name, (void*)((int)(this) + DestructibleDefEntries[i].offset), DestructibleDefEntries[i].next, DestructibleDefEntries[i].enumCount);
	
	for(int i = 0; i < numPieces; i++)
	{
		fprintf(writeLog, "\\piece%i\\%s_%i", i, name, i);
		pieces[i].dumpDestructiblePiece(name, i);
	}

	fclose(writeLog);

	return ERROR_SUCCESS;
}

int currentlyAllocatedDestructiblePieceArrayCount = 0;
char destructibleDefNames[0x20][0x30];
DestructiblePiece * allocatedDestructiblePieceArrays[0x20];
DestructiblePiece * AllocateDestructiblePieceArray(const char * destructibleDefName, int count)
{
	for(int i = 0; i < currentlyAllocatedDestructiblePieceArrayCount; i++)
	{
		if(!strcmp(destructibleDefName, destructibleDefNames[i]))
			return allocatedDestructiblePieceArrays[i];
	}

	allocatedDestructiblePieceArrays[currentlyAllocatedDestructiblePieceArrayCount] = new DestructiblePiece[count];
	strcpy(destructibleDefNames[currentlyAllocatedDestructiblePieceArrayCount], destructibleDefName);
	currentlyAllocatedDestructiblePieceArrayCount++;
	return allocatedDestructiblePieceArrays[currentlyAllocatedDestructiblePieceArrayCount-1];
}

void Load_DestructibleDefAssetHook(DestructibleDef ** input)
{
	DestructibleDef * currentDestructibleDef = *input;

	//(*input)->dumpDestructibleDef();
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\destructibledef\\%s", (char*)currentDestructibleDef->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE destructibleDefFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead;
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		if(destructibleDefFile != INVALID_HANDLE_VALUE && ReadFile(destructibleDefFile, theAssetBuffer, GetFileSize(destructibleDefFile, NULL), (LPDWORD)&numberOfBytesRead, 0))
		{
			CloseHandle(destructibleDefFile);
			char * currentToken = improved_strtok(theAssetBuffer,"\\");
			if(!strcmp(currentToken, "DESTRUCTIBLEDEF"))
			{
				for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
				{
					char * currentName = currentToken,
						* currentValue = improved_strtok(NULL, "\\");
					
					int pieceIndex;
					if(!strcmp("numPieces", currentName))
					{
						int newNumPieces = atoi(currentValue);
						if(newNumPieces > currentDestructibleDef->numPieces)
						{
							DestructiblePiece * newArray = AllocateDestructiblePieceArray((*input)->name, newNumPieces);
							memcpy(newArray, currentDestructibleDef->pieces, currentDestructibleDef->numPieces*sizeof(DestructiblePiece));
							currentDestructibleDef->pieces = newArray;
						}
						currentDestructibleDef->numPieces = newNumPieces;
					}
					else if(sscanf(currentName, "piece%i", &pieceIndex))
					{
						sprintf(MasterCharBuffer, "game:\\raw\\destructiblepiece\\%s_%i", (char*)currentDestructibleDef->name, pieceIndex);
						if(fileExists(MasterCharBuffer))
						{
							HANDLE destructiblePieceFile = CreateFile(MasterCharBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
							ZeroMemory(MasterCharBuffer, sizeof(MasterCharBuffer));
							if(destructiblePieceFile != INVALID_HANDLE_VALUE && ReadFile(destructiblePieceFile, MasterCharBuffer, GetFileSize(destructiblePieceFile, NULL), (LPDWORD)&numberOfBytesRead, 0))
							{
								CloseHandle(destructiblePieceFile);
								char * currentToken2 = improved_strtok2(MasterCharBuffer,"\\");
								if(!stricmp(currentToken2, "DESTRUCTIBLEPIECE"))
								{
									for(currentToken2 = improved_strtok2(NULL,"\\"); currentToken2; currentToken2 = improved_strtok2(NULL,"\\"))
									{
										char * currentName2 = currentToken2,
											* currentValue2 = improved_strtok2(NULL, "\\");

										if(!WriteAssetEntry(DestructiblePieceEntries, currentName2, currentValue2, &currentDestructibleDef->pieces[pieceIndex])) 
											printf("Couldn't recognize '%s' setting with '%s' value in %s %s_%i.\n", currentName, currentValue, "destructiblepiece", currentDestructibleDef->name, pieceIndex);
									}
								}
								else 
									printf("%s_%i is not a %s file\n", currentDestructibleDef->name, pieceIndex, "destructiblepiece");
							}
						}
						else
							printf("Piece %i was mentioned in %s but was not found in \\raw\\destructiblepiece\\ so no settings for it were loaded\n", pieceIndex, currentDestructibleDef->name);
					}
					else if(!WriteAssetEntry(DestructibleDefEntries, currentName, currentValue, currentDestructibleDef)) 
						printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "destructibledef", currentDestructibleDef->name);
				}

			}
			else
				printf("%s is not a %s file\n", currentDestructibleDef->name, "destructibledef");
		}
	}
	usingAssetBuffer = false;

	Load_DestructibleDefAssetSaveStub(input);
}
#pragma endregion

/* A Note About the Image Dumper: 
 * This is incomplete. Lots of bugs are to be expected. 
 * Do not judge me for this unfinished and messy code
 * Any actual Xbox/CoD devs, turn away now in horror! */
#pragma region image (0x09)
#define DDSCAPS2_CUBEMAP			0x200
#define DDSCAPS2_CUBEMAP_POSITIVEX	0x400
#define DDSCAPS2_CUBEMAP_NEGATIVEX	0x800
#define DDSCAPS2_CUBEMAP_POSITIVEY	0x1000
#define DDSCAPS2_CUBEMAP_NEGATIVEY	0x2000
#define DDSCAPS2_CUBEMAP_POSITIVEZ	0x4000
#define DDSCAPS2_CUBEMAP_NEGATIVEZ	0x8000
#define DDSCAPS2_VOLUME				0x200000

#include <xgraphics.h>
#include <d3dx9.h>
int GfxImage::dumpGfxImageAsset()
{
	//TODO: Implement dumping from streamed textures, in .pak files. 
	if(streaming) {
		printf("Couldn't dump image %s because its being streamed from a .pak\n", name);
		return ERROR_CALL_NOT_IMPLEMENTED;
	}
	
	if(basemap.Format.Type != GPUCONSTANTTYPE_TEXTURE) {
		printf("Couldn't dump image %s because its type is %i\n", name, basemap.Format.Type);
		return ERROR_CALL_NOT_IMPLEMENTED;
	}

	//Types needing implementation: 
	if(basemap.Format.DataFormat != GPUTEXTUREFORMAT_DXT1 && 
		basemap.Format.DataFormat != GPUTEXTUREFORMAT_DXT2_3 && 
		basemap.Format.DataFormat != GPUTEXTUREFORMAT_DXT4_5 &&
		basemap.Format.DataFormat != GPUTEXTUREFORMAT_DXN &&
		basemap.Format.DataFormat != GPUTEXTUREFORMAT_8_8_8_8 &&
		basemap.Format.DataFormat != GPUTEXTUREFORMAT_8_8 &&
		basemap.Format.DataFormat != GPUTEXTUREFORMAT_8) {
		printf("Couldn't dump image %s because its format value is %i\n", name, basemap.Format.DataFormat);
		return ERROR_CALL_NOT_IMPLEMENTED;
	}

	//Types needing implementation: 
	if(basemap.Format.Dimension != GPUDIMENSION_2D &&
		basemap.Format.Dimension != GPUDIMENSION_CUBEMAP) {
		printf("Couldn't dump image %s because its dimension value is %i\n", name, basemap.Format.Dimension);
		return ERROR_CALL_NOT_IMPLEMENTED;
	}

	CreateDirectoryB(va("game:\\dump\\images\\%.28s.dds", ConvertAssetNameToFileName((char*)name)));
	if(fileExists(MasterCharBuffer)) {
		//printf("Couldn't dump image %s because it has been dumped already\n", name);
		return ERROR_DUP_NAME;
	}
	
	int vWidth = width, vHeight = height, padAmount = 128;
	if(vWidth % padAmount != 0) vWidth += (padAmount - vWidth % padAmount);
	if(vHeight % padAmount != 0) vHeight += (padAmount - vHeight % padAmount);

	char * outputBuff = (char*)malloc(cardMemory.platform[0]);
	if(outputBuff) {
		ZeroMemory(outputBuff, cardMemory.platform[0]);
		FILE * writeLog = fopen(MasterCharBuffer, "wb");

		if(!writeLog) {
			printf("Couldn't dump image %s because its name contains characters that are incompatible with FATX\n", name);
			free(outputBuff);
			return ERROR_BAD_NETPATH;
		}

		int dwMagic = 0x44445320;
		fwrite(&dwMagic, 4, 1, writeLog);
		int dwSize = _byteswap_ulong(124);
		fwrite(&dwSize, 4, 1, writeLog);
		int dwFlags = (DDSD_CAPS|DDSD_HEIGHT|DDSD_WIDTH|DDSD_PIXELFORMAT);
		int dwPitchOrLinearSize;
		
		XGTEXTURE_DESC SourceDesc;
		XGGetTextureDesc( &basemap, 0, &SourceDesc );
		if(basemap.Format.DataFormat == GPUTEXTUREFORMAT_8_8_8_8 ||
			basemap.Format.DataFormat == GPUTEXTUREFORMAT_8_8 ||
			basemap.Format.DataFormat == GPUTEXTUREFORMAT_8)
		{
			dwFlags |= DDSD_PITCH;
			dwPitchOrLinearSize = _byteswap_ulong(width * SourceDesc.BitsPerPixel / 8);
		}
		else
		{
			dwFlags |= DDSD_LINEARSIZE;
			dwPitchOrLinearSize = _byteswap_ulong(baseSize);
		}
		int Levels = levelCount;
		int dwMipMapCount = 0;
		if(Levels > 1)
		{
			dwMipMapCount = Levels;
			dwFlags |= DDSD_MIPMAPCOUNT;
		}
		dwFlags = _byteswap_ulong(dwFlags);
		fwrite(&dwFlags, 4, 1, writeLog);
		int dwHeight = _byteswap_ulong(height);
		int dwWidth = _byteswap_ulong(width);
		fwrite(&dwHeight, 4, 1, writeLog);
		fwrite(&dwWidth, 4, 1, writeLog);
		fwrite(&dwPitchOrLinearSize, 4, 1, writeLog);
		int nullOut = 0;
		fwrite(&nullOut, 4, 1, writeLog);
		dwMipMapCount = _byteswap_ulong(dwMipMapCount);
		fwrite(&dwMipMapCount, 4, 1, writeLog);
		for(int i = 0; i < 11; i++)
			fwrite(&nullOut, 4, 1, writeLog);
		int dwSize2 = _byteswap_ulong(32);
		fwrite(&dwSize2, 4, 1, writeLog);
		int dwFlags2 = 0, dwFourCC = 0;
		switch(basemap.Format.DataFormat) {
		case GPUTEXTUREFORMAT_DXT1: dwFourCC = 0x31545844; dwFlags2 |= 4; break;
		case GPUTEXTUREFORMAT_DXT2_3: dwFourCC = 0x33545844; dwFlags2 |= 4; break;
		case GPUTEXTUREFORMAT_DXT4_5: dwFourCC = 0x35545844; dwFlags2 |= 4; break;
		case GPUTEXTUREFORMAT_DXN: dwFourCC = 0x35545844; dwFlags2 |= 4; break;
		case GPUTEXTUREFORMAT_8: dwFlags2 |= 0x2; break;
		case GPUTEXTUREFORMAT_8_8: dwFlags2 |= 0x20001; break;
		case GPUTEXTUREFORMAT_8_8_8_8: dwFlags2 |= 0x41; break;
		default: break;
		}
		
		int dwCaps1 = 0,	dwCaps2 = 0;
		dwCaps1 |= 0x00001000;
		if(Levels > 1)
			dwCaps1 |= 0x00400008;
		if(basemap.Format.Dimension == GPUDIMENSION_CUBEMAP) {
			dwCaps1 |= 2;
			dwCaps2 |= (DDSCAPS2_CUBEMAP|DDSCAPS2_CUBEMAP_POSITIVEX|DDSCAPS2_CUBEMAP_NEGATIVEX|DDSCAPS2_CUBEMAP_POSITIVEY|DDSCAPS2_CUBEMAP_NEGATIVEY|DDSCAPS2_CUBEMAP_POSITIVEZ|DDSCAPS2_CUBEMAP_NEGATIVEZ);
		}
		dwFlags2 = _byteswap_ulong(dwFlags2);
		fwrite(&dwFlags2, 4, 1, writeLog);
		dwFourCC = _byteswap_ulong(dwFourCC);
		fwrite(&dwFourCC, 4, 1, writeLog);
		int dwRGBBitCount, dwRBitMask, dwGBitMask, dwBBitMask, dwRGBAlphaBitMask;
		if (basemap.Format.DataFormat == GPUTEXTUREFORMAT_8_8_8_8)
		{
			dwRGBBitCount = _byteswap_ulong(SourceDesc.BitsPerPixel);
			dwRBitMask = _byteswap_ulong(0x00ff0000);
			dwGBitMask = _byteswap_ulong(0x0000ff00);
			dwBBitMask = _byteswap_ulong(0x000000ff);
			dwRGBAlphaBitMask = _byteswap_ulong(0xff000000);
		}
		else if (basemap.Format.DataFormat == GPUTEXTUREFORMAT_8_8)
		{
			dwRGBBitCount = _byteswap_ulong(SourceDesc.BitsPerPixel);
			dwRBitMask = _byteswap_ulong(0x00ff);
			dwGBitMask = 0x00000000;
			dwBBitMask = 0x00000000;
			dwRGBAlphaBitMask = _byteswap_ulong(0xff00);
		}
		else if (basemap.Format.DataFormat == GPUTEXTUREFORMAT_8)
		{
			dwRGBBitCount = _byteswap_ulong(SourceDesc.BitsPerPixel);
			dwRBitMask = 0x00000000;
			dwGBitMask = 0x00000000;
			dwBBitMask = 0x00000000;
			dwRGBAlphaBitMask = _byteswap_ulong(0xff);
		}
		else
		{
			dwRGBBitCount = 0x00000000;
			dwRBitMask = 0x00000000;
			dwGBitMask = 0x00000000;
			dwBBitMask = 0x00000000;
			dwRGBAlphaBitMask = 0x00000000;
		}
		fwrite(&dwRGBBitCount, 4, 1, writeLog);
		fwrite(&dwRBitMask, 4, 1, writeLog);
		fwrite(&dwGBitMask, 4, 1, writeLog);
		fwrite(&dwBBitMask, 4, 1, writeLog);
		fwrite(&dwRGBAlphaBitMask, 4, 1, writeLog);

		dwCaps1 = _byteswap_ulong(dwCaps1);
		fwrite(&dwCaps1, 4, 1, writeLog);
		dwCaps2 = _byteswap_ulong(dwCaps2);
		fwrite(&dwCaps2, 4, 1, writeLog);
		for(int i = 0; i < 3; i++)
			fwrite(&nullOut, 4, 1, writeLog);
		
		int texelPitch;
		int blockSizeRow, blockSizeColumn;
		
		//Using memcpy, don't detile
		//memcpy(outputBuff, pixels, cardMemory.platform[0]);

		//Using XGUntileTextureLevel
		BOOL IsBorderTexture = XGIsBorderTexture(&basemap);
		UINT MipMapTailLevel = XGGetMipTailBaseLevel(SourceDesc.Width, SourceDesc.Height, IsBorderTexture);
		UINT Slices = (basemap.Format.Dimension == GPUDIMENSION_CUBEMAP) ? 6 : 1;
		char * outBuff = outputBuff,* inBuff = pixels;
		UINT BaseSize;
		XGGetTextureLayout(&basemap, 0, &BaseSize, 0,0,0,0,0,0,0,0);
		if(basemap.Format.Dimension == GPUDIMENSION_CUBEMAP) BaseSize /= 6;

		for(int Slice = 0; Slice < Slices && inBuff < pixels + cardMemory.platform[0] && outBuff < outputBuff + cardMemory.platform[0]; Slice++) {
			UINT MipMapOffset = XGGetMipLevelOffset(&basemap, Slice, 0);
			outBuff = outputBuff + (Slice * SourceDesc.SlicePitch);
			inBuff = pixels + MipMapOffset;

			for(int Level = 0; Level < Levels && inBuff < pixels + cardMemory.platform[0] && outBuff < outputBuff + cardMemory.platform[0]; Level++) {
				DWORD CalculatedRowPitch = (SourceDesc.WidthInBlocks * SourceDesc.BytesPerBlock) / (1 << Level);

				if(CalculatedRowPitch < SourceDesc.BytesPerBlock)
					CalculatedRowPitch = SourceDesc.BytesPerBlock;

				XGUntileTextureLevel( SourceDesc.Width, \
					SourceDesc.Height, \
					Level, \
					XGGetGpuFormat(SourceDesc.Format), \
					(XGIsPackedTexture(&basemap) ? 0 : XGTILE_NONPACKED) | (IsBorderTexture ? XGTILE_BORDER : 0), \
					outBuff, \
					CalculatedRowPitch, \
					NULL, \
					inBuff, \
					NULL);

				UINT CurrentMipMapSize = BaseSize / (1 << (2 * Level));

				if(CurrentMipMapSize < SourceDesc.BytesPerBlock)
					CurrentMipMapSize = SourceDesc.BytesPerBlock;
			
				outBuff += CurrentMipMapSize;
				MipMapOffset = XGGetMipLevelOffset(&basemap, Slice, Level + 1);
				inBuff = pixels + BaseSize + MipMapOffset;
			}
		}

		switch(basemap.Format.Endian)
		{
			case GPUENDIAN_8IN16:
				XGEndianSwapMemory(outputBuff, outputBuff, XGENDIAN_8IN16, 2, cardMemory.platform[0] / 2);
			break;
			case GPUENDIAN_8IN32:
				XGEndianSwapMemory(outputBuff, outputBuff, XGENDIAN_8IN32, 4, cardMemory.platform[0] / 4);
			break;
			case GPUENDIAN_16IN32:
				XGEndianSwapMemory(outputBuff, outputBuff, XGENDIAN_16IN32, 4, cardMemory.platform[0] / 4);
			break;
			default:break;
		}

		fwrite(outputBuff, cardMemory.platform[0], 1, writeLog);
		fclose(writeLog);

		free(outputBuff);
	}
	else {
		printf("Couldn't dump image %s because there is not enough memory\n", name);
		return ERROR_NOT_ENOUGH_MEMORY;
	}

	return ERROR_SUCCESS;
}

Load_GfxImageAsset_t Load_GfxImageAsset = (Load_GfxImageAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x104)) + 0xA4));

void Load_GfxImageAssetHook(GfxImage ** input)
{
	(*input)->dumpGfxImageAsset();
	Load_GfxImageAssetSaveStub(input);
}
#pragma endregion

#pragma region map_ents (0x11)
Load_MapEntsAsset_t Load_MapEntsAsset = (Load_MapEntsAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x1BC)) + 0xA4));

int MapEnts::dumpMapEntities()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
	
	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if (!writeLog)
		return ERROR_BAD_NETPATH;
	
	fwrite(entityString, strlen(entityString), 1, writeLog);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

char * previouslyLoadedMapEnts;
int previouslyLoadedSize;
void Load_MapEntsAssetHook(MapEnts ** input)
{
	//(*input)->dumpMapEntities();
	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName((*input)->name));
	if(fileExists(theAssetBuffer))
	{
		HANDLE mapEntsFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(mapEntsFile, NULL);

		if(previouslyLoadedSize == numberOfBytesRead)
		{
			ReadFile(mapEntsFile, (*input)->entityString, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);
			(*input)->entityString = previouslyLoadedMapEnts;
		}
		else
		{
			if(previouslyLoadedSize)
			{
				delete[] previouslyLoadedMapEnts;
				previouslyLoadedSize = 0;
				previouslyLoadedMapEnts = 0;
			}
			if(mapEntsFile != INVALID_HANDLE_VALUE)
			{
				if(numberOfBytesRead <= (*input)->numEntityChars-1)
				{
					ZeroMemory((*input)->entityString, (*input)->numEntityChars);
					ReadFile(mapEntsFile, (*input)->entityString, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);
					(*input)->numEntityChars = numberOfBytesRead+1;
				}
				else
				{
					char * newStringBuffer = new char[numberOfBytesRead+1];

					if(newStringBuffer)
					{
						ZeroMemory(newStringBuffer, numberOfBytesRead+1);
						ReadFile(mapEntsFile, newStringBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);
						previouslyLoadedMapEnts = (*input)->entityString = newStringBuffer;
						previouslyLoadedSize = numberOfBytesRead;
						(*input)->numEntityChars = numberOfBytesRead+1;
					}
				}
			}
		}

		CloseHandle(mapEntsFile);

	}
	usingAssetBuffer = false;

	Load_MapEntsAssetSaveStub(input);
}
#pragma endregion

#pragma region lightdef (0x13)
int GfxLightDef::dumpGfxLightDef()
{
	CreateDirectoryB(va("game:\\dump\\lights\\%s", name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
	
	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if (!writeLog)
		return ERROR_BAD_NETPATH;
	
	fprintf(writeLog, "%c", attenuation.samplerState);
	fwrite(attenuation.image->name, 1, strlen(attenuation.image->name) + 1, writeLog);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

Load_GfxLightDefAsset_t Load_GfxLightDefAsset = (Load_GfxLightDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x1F4)) + 0xA4));

void Load_GfxLightDefAssetHook(GfxLightDef ** input)
{
	//(*input)->dumpGfxLightDef();
	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\lights\\%s", (*input)->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE gfxLightDefFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(gfxLightDefFile, NULL);
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		ReadFile(gfxLightDefFile, theAssetBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);
		CloseHandle(gfxLightDefFile);
		(*input)->attenuation.samplerState = theAssetBuffer[0];
		(*input)->attenuation.image = DB_FindXAssetHeader(ASSET_TYPE_IMAGE, theAssetBuffer + 1, true, -1).image;

	}
	usingAssetBuffer = false;

	Load_GfxLightDefAssetSaveStub(input);
}
#pragma endregion

#pragma region localize (0x19)
//This dumper takes along time, but I wanted it to be as perfect as possible... despite this, this is still quite ghetto...
int LocalizeEntry::DumpLocalizedString()
{
	const char * languageName = SEH_GetLanguageName(SEH_GetCurrentLanguage());
	char strName[0x18];
	char strNameCap[0x18];
	char languageNameCap[0x10];
	ZeroMemory(strName, sizeof(strName));
	ZeroMemory(strNameCap, sizeof(strNameCap));
	ZeroMemory(languageNameCap, sizeof(languageNameCap));

	for(int i = 0; name[i] && name[i] != '_'; i++) {
		strName[i] = tolower(name[i]);
		strNameCap[i] = toupper(name[i]);
	}

	for(int i = 0; languageName[i]; i++)
		languageNameCap[i] = toupper(languageName[i]);

	CreateDirectoryB(va("game:\\dump\\%s\\%s.str", languageName, strName));

	FILE * writeLog;
	if(!fileExists(MasterCharBuffer)) {
		writeLog = fopen(MasterCharBuffer, "wb+");
		if (!writeLog)
			return ERROR_BAD_NETPATH;

		fprintf(writeLog, "VERSION             \"1\"\r\n");
		fprintf(writeLog, "CONFIG              \"C:\\trees\\activision2\\activision2\\bin\\StringEd.cfg\"\r\n");
		fprintf(writeLog, "FILENOTES           \"Dumped by The Tesseract, CraigChrist8239\"\r\n\r\n");
	}
	else {
		writeLog = fopen(MasterCharBuffer, "rb+");
		if (!writeLog)
			return ERROR_BAD_NETPATH;

		char * bufferToUse;
		fseek(writeLog, 0, SEEK_END);
		long sizeOfFile = ftell(writeLog);
		fseek(writeLog, 0, SEEK_SET);
		if(sizeOfFile > sizeof(theAssetBuffer) - 1)
			bufferToUse = new char[sizeOfFile + 1];
		else {
			while(usingAssetBuffer) Sleep(0);
			usingAssetBuffer = true;
			bufferToUse = theAssetBuffer;
		}

		ZeroMemory(bufferToUse, sizeOfFile + 1);
		//bufferToUse[
			fread(bufferToUse, 1, sizeOfFile, writeLog);
		//] = 0;
		for(char * token = improved_strtok(bufferToUse, "\r\n"); token; token = improved_strtok(NULL, "\r\n")) {
LABEL_RESTART:
			if(!*token) continue;
			if(!strnicmp(token, "VERSION", strlen("VERSION"))) continue;
			if(!strnicmp(token, "CONFIG", strlen("CONFIG"))) continue;
			if(!strnicmp(token, "FILENOTES", strlen("FILENOTES"))) continue;
			if(!strnicmp(token, "NOTES", strlen("NOTES"))) continue;
			if(!strnicmp(token, "FLAGS", strlen("FLAGS"))) continue;
			if(!strnicmp(token, "LANG_", strlen("LANG_"))) {
				int tokenLen = strlen(token);
				if(token[tokenLen - 1] == '\"')
					continue;
				else
				{
					fseek(writeLog, token - bufferToUse + tokenLen, SEEK_SET);
					fread(token + tokenLen, 1, 1, writeLog);
					while(token[0] != '\"' || (token[1] != '\r' && token[1] != '\n')) token++;
					token = improved_strtok(token + 1, "\r\n");
					goto LABEL_RESTART;
				}
			}
			if(!strnicmp(token, "ENDMARKER", strlen("ENDMARKER"))) {
				fseek(writeLog, token - bufferToUse, SEEK_SET);
				break;
			}
			if(!strnicmp(token, "REFERENCE", strlen("REFERENCE"))) {
				token += 10;
				while(*token == ' ') token++;
				if(!strcmp(token, name + strlen(strName) + 1)) {
					fclose(writeLog);

					if(usingAssetBuffer)
						usingAssetBuffer = false;
					else
						delete[] bufferToUse;
					return ERROR_DUP_NAME;
				}
				else continue;
			}
		}

		if(usingAssetBuffer)
			usingAssetBuffer = false;
		else
			delete[] bufferToUse;
	}

	fseek(writeLog, ftell(writeLog), SEEK_SET);
	fprintf(writeLog,  "REFERENCE           %s\r\nLANG_%s", name + strlen(strName) + 1, languageNameCap);
	fprintf(writeLog, "               " + strlen(languageNameCap));
	fprintf(writeLog,  "\"%s\"\r\n\r\nENDMARKER", value ? value : "");
	fclose(writeLog);
	return ERROR_SUCCESS;
}

Load_LocalizeEntryAsset_t Load_LocalizeEntryAsset = (Load_LocalizeEntryAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x280)) + 0xA4));

//Alot of unneccesarry strings in the .str file will slow this down.
//Make sure you only include the strings you wish to edit.
void Load_LocalizeEntryAssetHook(LocalizeEntry ** input)
{
	//oldEntry->DumpLocalizedString();
	LocalizeEntry * oldEntry = *input;
	const char * languageName = SEH_GetLanguageName(SEH_GetCurrentLanguage());
	char strName[0x18];
	char strNameCap[0x18];
	char languageNameCap[0x10];
	ZeroMemory(strName, sizeof(strName));
	ZeroMemory(strNameCap, sizeof(strNameCap));
	ZeroMemory(languageNameCap, sizeof(languageNameCap));

	for(int i = 0; oldEntry->name[i] && oldEntry->name[i] != '_'; i++) {
		strName[i] = tolower(oldEntry->name[i]);
		strNameCap[i] = toupper(oldEntry->name[i]);
	}

	for(int i = 0; languageName[i]; i++)
		languageNameCap[i] = toupper(languageName[i]);

	va("game:\\raw\\%s\\%s.str", languageName, strName);

	FILE * writeLog;
	if(fileExists(MasterCharBuffer)) {
		writeLog = fopen(MasterCharBuffer, "rb");

		char * bufferToUse;
		fseek(writeLog, 0, SEEK_END);
		long sizeOfFile = ftell(writeLog);
		fseek(writeLog, 0, SEEK_SET);
		if(sizeOfFile > sizeof(theAssetBuffer) - 1)
			bufferToUse = new char[sizeOfFile + 1];
		else {
			while(usingAssetBuffer) Sleep(0);
			usingAssetBuffer = true;
			bufferToUse = theAssetBuffer;
		}

		ZeroMemory(bufferToUse, sizeOfFile + 1);
		//bufferToUse[
			fread(bufferToUse, 1, sizeOfFile, writeLog);
		//] = 0;
		bool hasFoundThisEntry = false;
		for(char * token = improved_strtok(bufferToUse, "\r\n"); token; token = improved_strtok(NULL, "\r\n")) {
LABEL_RESTART:
			if(!*token) continue;
			if(!strnicmp(token, "VERSION", strlen("VERSION"))) {
				token += 8;
				while(*token == ' ') token++;
				if(token[0] != '\"' && token[1] != '1' && token[2] != '\"')
					printf("Unexpected version number, expecting \"1\"!\n");
			}
			if(!strnicmp(token, "CONFIG", strlen("CONFIG"))) continue;
			if(!strnicmp(token, "FILENOTES", strlen("FILENOTES"))) continue;
			if(!strnicmp(token, "NOTES", strlen("NOTES"))) continue;
			if(!strnicmp(token, "FLAGS", strlen("FLAGS"))) continue;
			if(!strnicmp(token, "LANG_", strlen("LANG_"))) {
				int tokenLen = strlen(token);

				if(!hasFoundThisEntry || strncmp(token + strlen("LANG_"), languageNameCap, strlen(languageNameCap))) {
					if(token[tokenLen - 1] == '\"')
						continue;
					else
					{
						fseek(writeLog, token - bufferToUse + tokenLen, SEEK_SET);
						fread(token + tokenLen, 1, 1, writeLog);
						while(token[0] != '\"' || (token[1] != '\r' && token[1] != '\n')) token++;
						token = improved_strtok(token + 1, "\r\n");
						goto LABEL_RESTART;
					}
				}
				else {
					if(token[tokenLen - 1] != '\"')
					{
						fseek(writeLog, token - bufferToUse + tokenLen, SEEK_SET);
						fread(token + tokenLen, 1, 1, writeLog);
					}
					token[strlen(token) - 1] = 0;
					while(token[0] != '\"') token++;
					token++;
					oldEntry->value = AllocateString(token);
					break;
				}
			}
			if(!strnicmp(token, "ENDMARKER", strlen("ENDMARKER"))) {
				break;
			}
			if(!strnicmp(token, "REFERENCE", strlen("REFERENCE"))) {
				token += 10;
				while(*token == ' ') token++;
				if(!strcmp(token, oldEntry->name + strlen(strName) + 1))
					hasFoundThisEntry = true;
				else continue;
			}
		}
		fclose(writeLog);

		if(usingAssetBuffer)
			usingAssetBuffer = false;
		else
			delete[] bufferToUse;
	}
	Load_LocalizeEntryAssetSaveStub(input);
}
#pragma endregion

#pragma region weapon (0x1A)
AssetEntry BobEntry[] = {
	{"Horiz",	0,	ASSET_ENTRY_FLOAT,0,0},
	{"Vert",	4,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry GunModelEntries[] = {
	{"",	0,		ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"1",	4,		ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"2",	8,		ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"3",	0xC,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"4",	0x10,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"5",	0x14,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"6",	0x18,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"7",	0x1C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"8",	0x20,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"9",	0x24,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"10",	0x28,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"11",	0x2C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"12",	0x30,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"13",	0x34,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"14",	0x38,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"15",	0x3C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry BounceSoundEntries[] = {
	{"default",			0,		ASSET_ENTRY_STRING,0,0},
	{"bark",			4,		ASSET_ENTRY_STRING,0,0},
	{"brick",			8,		ASSET_ENTRY_STRING,0,0},
	{"carpet",			0xC,	ASSET_ENTRY_STRING,0,0},
	{"cloth",			0x10,	ASSET_ENTRY_STRING,0,0},
	{"concrete",		0x14,	ASSET_ENTRY_STRING,0,0},
	{"dirt",			0x18,	ASSET_ENTRY_STRING,0,0},
	{"flesh",			0x1C,	ASSET_ENTRY_STRING,0,0},
	{"foliage",			0x20,	ASSET_ENTRY_STRING,0,0},
	{"glass",			0x24,	ASSET_ENTRY_STRING,0,0},
	{"grass",			0x28,	ASSET_ENTRY_STRING,0,0},
	{"gravel",			0x2C,	ASSET_ENTRY_STRING,0,0},
	{"ice",				0x30,	ASSET_ENTRY_STRING,0,0},
	{"metal",			0x34,	ASSET_ENTRY_STRING,0,0},
	{"mud",				0x38,	ASSET_ENTRY_STRING,0,0},
	{"paper",			0x3C,	ASSET_ENTRY_STRING,0,0},
	{"plaster",			0x40,	ASSET_ENTRY_STRING,0,0},
	{"rock",			0x44,	ASSET_ENTRY_STRING,0,0},
	{"sand",			0x48,	ASSET_ENTRY_STRING,0,0},
	{"snow",			0x4C,	ASSET_ENTRY_STRING,0,0},
	{"water",			0x50,	ASSET_ENTRY_STRING,0,0},
	{"wood",			0x54,	ASSET_ENTRY_STRING,0,0},
	{"asphalt",			0x58,	ASSET_ENTRY_STRING,0,0},
	{"ceramic",			0x5C,	ASSET_ENTRY_STRING,0,0},
	{"plastic",			0x60,	ASSET_ENTRY_STRING,0,0},
	{"rubber",			0x64,	ASSET_ENTRY_STRING,0,0},
	{"cushion",			0x68,	ASSET_ENTRY_STRING,0,0},
	{"fruit",			0x6C,	ASSET_ENTRY_STRING,0,0},
	{"paintedMetal",	0x70,	ASSET_ENTRY_STRING,0,0},
	{"player",			0x74,	ASSET_ENTRY_STRING,0,0},
	{"tallgrass",		0x78,	ASSET_ENTRY_STRING,0,0},
	{"riotshield",		0x7C,	ASSET_ENTRY_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry BounceFloatEntries[] = {
	{"default",			0,		ASSET_ENTRY_FLOAT,0,0},
	{"bark",			4,		ASSET_ENTRY_FLOAT,0,0},
	{"brick",			8,		ASSET_ENTRY_FLOAT,0,0},
	{"carpet",			0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"cloth",			0x10,	ASSET_ENTRY_FLOAT,0,0},
	{"concrete",		0x14,	ASSET_ENTRY_FLOAT,0,0},
	{"dirt",			0x18,	ASSET_ENTRY_FLOAT,0,0},
	{"flesh",			0x1C,	ASSET_ENTRY_FLOAT,0,0},
	{"foliage",			0x20,	ASSET_ENTRY_FLOAT,0,0},
	{"glass",			0x24,	ASSET_ENTRY_FLOAT,0,0},
	{"grass",			0x28,	ASSET_ENTRY_FLOAT,0,0},
	{"gravel",			0x2C,	ASSET_ENTRY_FLOAT,0,0},
	{"ice",				0x30,	ASSET_ENTRY_FLOAT,0,0},
	{"metal",			0x34,	ASSET_ENTRY_FLOAT,0,0},
	{"mud",				0x38,	ASSET_ENTRY_FLOAT,0,0},
	{"paper",			0x3C,	ASSET_ENTRY_FLOAT,0,0},
	{"plaster",			0x40,	ASSET_ENTRY_FLOAT,0,0},
	{"rock",			0x44,	ASSET_ENTRY_FLOAT,0,0},
	{"sand",			0x48,	ASSET_ENTRY_FLOAT,0,0},
	{"snow",			0x4C,	ASSET_ENTRY_FLOAT,0,0},
	{"water",			0x50,	ASSET_ENTRY_FLOAT,0,0},
	{"wood",			0x54,	ASSET_ENTRY_FLOAT,0,0},
	{"asphalt",			0x58,	ASSET_ENTRY_FLOAT,0,0},
	{"ceramic",			0x5C,	ASSET_ENTRY_FLOAT,0,0},
	{"plastic",			0x60,	ASSET_ENTRY_FLOAT,0,0},
	{"rubber",			0x64,	ASSET_ENTRY_FLOAT,0,0},
	{"cushion",			0x68,	ASSET_ENTRY_FLOAT,0,0},
	{"fruit",			0x6C,	ASSET_ENTRY_FLOAT,0,0},
	{"paintedMetal",	0x70,	ASSET_ENTRY_FLOAT,0,0},
	{"player",			0x74,	ASSET_ENTRY_FLOAT,0,0},
	{"tallgrass",		0x78,	ASSET_ENTRY_FLOAT,0,0},
	{"riotshield",		0x7C,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry NoteTrackSoundMapEntries[] = {
	{"1",	0,		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"2",	2,		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"3",	4,		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"4",	6,		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"5",	8,		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"6",	0xA,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"7",	0xC,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"8",	0xE,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"9",	0x10,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"10",	0x12,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"11",	0x14,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"12",	0x16,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"13",	0x18,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"14",	0x1A,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"15",	0x1C,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"16",	0x1E,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"17",	0x20,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"18",	0x22,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"19",	0x24,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"20",	0x26,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

const char * AnimationType_s[] = {
	"none",
	"default",
	"other",
	"sniper",
	"m203",
	"hold",
	"briefcase",
	"reviver",
	"radio",
	"dualwield",
	"remotecontrol",
	"crossbow",
	"minigun",
	"beltfed",
	"g11",
	"rearclip",
	"handleclip",
	"rearclipsniper",
	"ballisticknife",
	"singleknife",
	"nopump",
	"hatchet",
	"grimreaper",
	"zipline",
	"riotshield",
	"tablet",
	"turned",
	"screecher"
};

AssetEntry ClientSideSoundEntry[] = {
	{"",		0,	ASSET_ENTRY_STRING,0,0},
	{"Player",	4,	ASSET_ENTRY_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry IconEntry[] = {
	{"",		0,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"Ratio",	4,	ASSET_ENTRY_ENUM,		(AssetEntry*)weapIconRatioNames,	WEAPON_ICON_RATIO_MAX},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry HipSpreadSettings[] = {
	{"StandMin",	0,		ASSET_ENTRY_FLOAT,0,0},
	{"DuckedMin",	4,		ASSET_ENTRY_FLOAT,0,0},
	{"ProneMin",	8,		ASSET_ENTRY_FLOAT,0,0},
	{"StandMax",	0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"DuckedMax",	0x10,	ASSET_ENTRY_FLOAT,0,0},
	{"ProneMax",	0x14,	ASSET_ENTRY_FLOAT,0,0},
	{"DecayRate",	0x18,	ASSET_ENTRY_FLOAT,0,0},
	{"FireAdd",		0x1C,	ASSET_ENTRY_FLOAT,0,0},
	{"TurnAdd",		0x20,	ASSET_ENTRY_FLOAT,0,0},
	{"MoveAdd",		0x24,	ASSET_ENTRY_FLOAT,0,0},
	{"DuckedDecay",	0x28,	ASSET_ENTRY_FLOAT,0,0},
	{"ProneDecay",	0x2C,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

const char * meansOfDeath_s[] = {
  "MOD_UNKNOWN",
  "MOD_PISTOL_BULLET",
  "MOD_RIFLE_BULLET",
  "MOD_GRENADE",
  "MOD_GRENADE_SPLASH",
  "MOD_PROJECTILE",
  "MOD_PROJECTILE_SPLASH",
  "MOD_MELEE",
  "MOD_BAYONET",
  "MOD_HEAD_SHOT",
  "MOD_CRUSH",
  "MOD_TELEFRAG",
  "MOD_FALLING",
  "MOD_SUICIDE",
  "MOD_TRIGGER_HURT",
  "MOD_EXPLOSIVE",
  "MOD_IMPACT",
  "MOD_BURNED",
  "MOD_HIT_BY_OBJECT",
  "MOD_DROWN",
  "MOD_GAS"
};

AssetEntry NVRemoveTimeEntries[] = {
	{"",			0,	ASSET_ENTRY_TIME_AS_INT,0,0},
	{"PowerDown",	4,	ASSET_ENTRY_TIME_AS_INT,0,0},
	{"FadeInStart",	8,	ASSET_ENTRY_TIME_AS_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry NVWearTimeEntries[] = {
	{"",			0,	ASSET_ENTRY_TIME_AS_INT,0,0},
	{"FadeOutEnd",	4,	ASSET_ENTRY_TIME_AS_INT,0,0},
	{"PowerUp",		8,	ASSET_ENTRY_TIME_AS_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

const char * weapOverlayInterface_s[] = {
  "WEAPOVERLAYINTERFACE_NONE",
  "WEAPOVERLAYINTERFACE_JAVELIN",
  "WEAPOVERLAYINTERFACE_TURRETSCOPE"
};

AssetEntry ProjExplosionEntry[] = {
	{"",				0,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"ForceNormalUp",	4,	ASSET_ENTRY_BOOL,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry GunKickSettings[] = {
	{"ReducedKickPercent",	0,		ASSET_ENTRY_FLOAT,0,0},
	{"PitchMin",			4,		ASSET_ENTRY_FLOAT,0,0},
	{"PitchMax",			8,		ASSET_ENTRY_FLOAT,0,0},
	{"YawMin",				0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"YawMax",				0x10,	ASSET_ENTRY_FLOAT,0,0},
	{"Accel",				0x14,	ASSET_ENTRY_FLOAT,0,0},
	{"SpeedMax",			0x18,	ASSET_ENTRY_FLOAT,0,0},
	{"SpeedDecay",			0x1C,	ASSET_ENTRY_FLOAT,0,0},
	{"StaticDecay",			0x20,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry LocationDamageEntries[] = {
	{"locNone",				0,		ASSET_ENTRY_FLOAT,0,0},
	{"locHelmet",			4,		ASSET_ENTRY_FLOAT,0,0},
	{"locHead",				8,		ASSET_ENTRY_FLOAT,0,0},
	{"locNeck",				0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"locTorsoUpper",		0x10,	ASSET_ENTRY_FLOAT,0,0},
	{"locTorsoMid",			0x14,	ASSET_ENTRY_FLOAT,0,0},
	{"locTorsoLower",		0x18,	ASSET_ENTRY_FLOAT,0,0},
	{"locRightArmUpper",	0x1C,	ASSET_ENTRY_FLOAT,0,0},
	{"locLeftArmUpper",		0x20,	ASSET_ENTRY_FLOAT,0,0},
	{"locRightArmLower",	0x24,	ASSET_ENTRY_FLOAT,0,0},
	{"locLeftArmLower",		0x28,	ASSET_ENTRY_FLOAT,0,0},
	{"locRightHand",		0x2C,	ASSET_ENTRY_FLOAT,0,0},
	{"locLeftHand",			0x30,	ASSET_ENTRY_FLOAT,0,0},
	{"locRightLegUpper",	0x34,	ASSET_ENTRY_FLOAT,0,0},
	{"locLeftLegUpper",		0x38,	ASSET_ENTRY_FLOAT,0,0},
	{"locRightLegLower",	0x3C,	ASSET_ENTRY_FLOAT,0,0},
	{"locLeftLegLower",		0x40,	ASSET_ENTRY_FLOAT,0,0},
	{"locRightFoot",		0x44,	ASSET_ENTRY_FLOAT,0,0},
	{"locLeftFoot",			0x48,	ASSET_ENTRY_FLOAT,0,0},
	{"locGun",				0x4C,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry AntiQuickScopeEntries[] = {
	{"Time",				0,		ASSET_ENTRY_FLOAT,0,0},
	{"Scale",				4,		ASSET_ENTRY_FLOAT,0,0},
	{"SpreadMultiplier",	8,		ASSET_ENTRY_FLOAT,0,0},
	{"SpreadMax",			0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"SwayFactor",			0x10,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry CameraShakeEntries[] = {
	{"Scale",		0,	ASSET_ENTRY_FLOAT,0,0},
	{"Duration",	4,	ASSET_ENTRY_INT,0,0},
	{"Radius",		8,	ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponDefEntries[] = {
	{"szOverlayName",						offsetof(WeaponDef, szOverlayName),							ASSET_ENTRY_STRING,0,0},
	{"gunXModel",							offsetof(WeaponDef, gunXModel),								ASSET_ENTRY_CONTAINED,			GunModelEntries,0},
	{"handXModel",							offsetof(WeaponDef, handXModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"szModeName",							offsetof(WeaponDef, szModeName),							ASSET_ENTRY_STRING,0,0},
	{"noteTrackSoundMapKeys",				offsetof(WeaponDef, noteTrackSoundMapKeys),					ASSET_ENTRY_CONTAINED,			NoteTrackSoundMapEntries,0},
	{"notetrackSoundMapValues",				offsetof(WeaponDef, notetrackSoundMapValues),				ASSET_ENTRY_CONTAINED,			NoteTrackSoundMapEntries,0},
	{"playerAnimType",						offsetof(WeaponDef, playerAnimType),						ASSET_ENTRY_ENUM,				(AssetEntry*)AnimationType_s,				PLAYER_ANIM_TYPE_MAX},
	{"weaponType",							offsetof(WeaponDef, weaponType),							ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapTypeNames,				WEAPTYPE_MAX},
	{"weaponClass",							offsetof(WeaponDef, weaponClass),							ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapClassNames,				WEAPCLASS_MAX},
	{"penetrateType",						offsetof(WeaponDef, penetrateType),							ASSET_ENTRY_ENUM,				(AssetEntry*)penetrateTypeNames,			PENETRATE_TYPE_MAX},
	{"impactType",							offsetof(WeaponDef, impactType),							ASSET_ENTRY_ENUM,				(AssetEntry*)impactTypeNames_0,				IMPACT_TYPE_MAX},
	{"inventoryType",						offsetof(WeaponDef, inventoryType),							ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapInventoryTypeNames,		WEAPINVENTORY_MAX},
	{"fireType",							offsetof(WeaponDef, fireType),								ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapFireTypeNames,			WEAPON_FIRETYPE_MAX},
	{"clipType",							offsetof(WeaponDef, clipType),								ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapClipTypeNames,			WEAPON_CLIPTYPECOUNT},
	{"barrelType",							offsetof(WeaponDef, barrelType),							ASSET_ENTRY_ENUM,				(AssetEntry*)barrelTypeNames,				BARREL_TYPE_COUNT},
	{"itemIndex",							offsetof(WeaponDef, itemIndex),								ASSET_ENTRY_INT,0,0},
	{"parentWeaponName",					offsetof(WeaponDef, parentWeaponName),						ASSET_ENTRY_STRING,0,0},
	{"iJamFireTime",						offsetof(WeaponDef, iJamFireTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"overheatWeapon",						offsetof(WeaponDef, overheatWeapon),						ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"overheatRate",						offsetof(WeaponDef, overheatRate),							ASSET_ENTRY_FLOAT,0,0},
	{"cooldownRate",						offsetof(WeaponDef, cooldownRate),							ASSET_ENTRY_FLOAT,0,0},
	{"overheatEndVal",						offsetof(WeaponDef, overheatEndVal),						ASSET_ENTRY_FLOAT,0,0},
	{"coolWhileFiring",						offsetof(WeaponDef, coolWhileFiring),						ASSET_ENTRY_BOOL,0,0},
	{"fuelTankWeapon",						offsetof(WeaponDef, fuelTankWeapon),						ASSET_ENTRY_BOOL,0,0},
	{"iTankLifeTime",						offsetof(WeaponDef, iTankLifeTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"offhandClass",						offsetof(WeaponDef, offhandClass),							ASSET_ENTRY_ENUM,				(AssetEntry*)offhandClassNames,				OFFHAND_CLASS_COUNT},
	{"offhandSlot",							offsetof(WeaponDef, offhandSlot),							ASSET_ENTRY_ENUM,				(AssetEntry*)offhandSlotNames,				OFFHAND_SLOT_COUNT},
	{"stance",								offsetof(WeaponDef, stance),								ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapStanceNames,				WEAPSTANCE_MAX},
	{"viewFlashEffect",						offsetof(WeaponDef, viewFlashEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"worldFlashEffect",					offsetof(WeaponDef, worldFlashEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"barrelCooldownEffect",				offsetof(WeaponDef, barrelCooldownEffect),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"barrelCooldownMinCount",				offsetof(WeaponDef, barrelCooldownMinCount),				ASSET_ENTRY_INT,0,0},
	{"vViewFlashOffset",					offsetof(WeaponDef, vViewFlashOffset),						ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"vWorldFlashOffset",					offsetof(WeaponDef, vWorldFlashOffset),						ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"pickupSound",							offsetof(WeaponDef, pickupSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"ammoPickupSound",						offsetof(WeaponDef, ammoPickupSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"projectileSound",						offsetof(WeaponDef, projectileSound),						ASSET_ENTRY_STRING,0,0},
	{"pullbackSound",						offsetof(WeaponDef, pullbackSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"fireSound",							offsetof(WeaponDef, fireSound),								ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"loopFireSound",						offsetof(WeaponDef, loopFireSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"loopFireEndSound",					offsetof(WeaponDef, loopFireEndSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"startFireSound",						offsetof(WeaponDef, startFireSound),						ASSET_ENTRY_STRING,0,0},
	{"stopFireSound",						offsetof(WeaponDef, stopFireSound),							ASSET_ENTRY_STRING,0,0},
	{"killcamStartFireSound",				offsetof(WeaponDef, killcamStartFireSound),					ASSET_ENTRY_STRING,0,0},
	{"startFireSoundPlayer",				offsetof(WeaponDef, startFireSoundPlayer),					ASSET_ENTRY_STRING,0,0},
	{"stopFireSoundPlayer",					offsetof(WeaponDef, stopFireSoundPlayer),					ASSET_ENTRY_STRING,0,0},
	{"killcamStartFireSoundPlayer",			offsetof(WeaponDef, killcamStartFireSoundPlayer),			ASSET_ENTRY_STRING,0,0},
	{"lastShotSound",						offsetof(WeaponDef, lastShotSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"emptyFireSound",						offsetof(WeaponDef, emptyFireSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"crackSound",							offsetof(WeaponDef, crackSound),							ASSET_ENTRY_STRING,0,0},
	{"whizbySound",							offsetof(WeaponDef, whizbySound),							ASSET_ENTRY_STRING,0,0},
	{"meleeSwipeSound",						offsetof(WeaponDef, meleeSwipeSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"meleeHitSound",						offsetof(WeaponDef, meleeHitSound),							ASSET_ENTRY_STRING,0,0},
	{"meleeMissSound",						offsetof(WeaponDef, meleeMissSound),						ASSET_ENTRY_STRING,0,0},
	{"rechamberSound",						offsetof(WeaponDef, rechamberSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"reloadSound",							offsetof(WeaponDef, reloadSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"reloadEmptySound",					offsetof(WeaponDef, reloadEmptySound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"reloadStartSound",					offsetof(WeaponDef, reloadStartSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"reloadEndSound",						offsetof(WeaponDef, reloadEndSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"rotateLoopSound",						offsetof(WeaponDef, rotateLoopSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"rotateStopSound",						offsetof(WeaponDef, rotateStopSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"deploySound",							offsetof(WeaponDef, deploySound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"finishDeploySound",					offsetof(WeaponDef, finishDeploySound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"breakdownSound",						offsetof(WeaponDef, breakdownSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"finishBreakdownSound",				offsetof(WeaponDef, finishBreakdownSound),					ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"detonateSound",						offsetof(WeaponDef, detonateSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"nightVisionWearSound",				offsetof(WeaponDef, nightVisionWearSound),					ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"nightVisionRemoveSound",				offsetof(WeaponDef, nightVisionRemoveSound),				ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"altSwitchSound",						offsetof(WeaponDef, altSwitchSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"raiseSound",							offsetof(WeaponDef, raiseSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"firstRaiseSound",						offsetof(WeaponDef, firstRaiseSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"adsRaiseSoundPlayer",					offsetof(WeaponDef, adsRaiseSoundPlayer),					ASSET_ENTRY_STRING,0,0},
	{"adsLowerSoundPlayer",					offsetof(WeaponDef, adsLowerSoundPlayer),					ASSET_ENTRY_STRING,0,0},
	{"putawaySound",						offsetof(WeaponDef, putawaySound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"overheatSound",						offsetof(WeaponDef, overheatSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"adsZoomSound",						offsetof(WeaponDef, adsZoomSound),							ASSET_ENTRY_STRING,0,0},
	{"shellCasing",							offsetof(WeaponDef, shellCasing),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"BounceSound",							offsetof(WeaponDef, bounceSounds),							ASSET_ENTRY_CONTAINED_REVERSED,	BounceSoundEntries,0},
	{"standMountedWeapdef",					offsetof(WeaponDef, standMountedWeapdef),					ASSET_ENTRY_STRING,0,0},
	{"crouchMountedWeapdef",				offsetof(WeaponDef, crouchMountedWeapdef),					ASSET_ENTRY_STRING,0,0},
	{"proneMountedWeapdef",					offsetof(WeaponDef, proneMountedWeapdef),					ASSET_ENTRY_STRING,0,0},
	{"viewShellEjectEffect",				offsetof(WeaponDef, viewShellEjectEffect),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"worldShellEjectEffect",				offsetof(WeaponDef, worldShellEjectEffect),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"viewLastShotEjectEffect",				offsetof(WeaponDef, viewLastShotEjectEffect),				ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"worldLastShotEjectEffect",			offsetof(WeaponDef, worldLastShotEjectEffect),				ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"vViewShellEjectOffset",				offsetof(WeaponDef, vViewShellEjectOffset),					ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vWorldShellEjectOffset",				offsetof(WeaponDef, vWorldShellEjectOffset),				ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vViewShellEjectRotation",				offsetof(WeaponDef, vViewShellEjectRotation),				ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vWorldShellEjectRotation",			offsetof(WeaponDef, vWorldShellEjectRotation),				ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"reticleCenter",						offsetof(WeaponDef, reticleCenter),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"reticleSide",							offsetof(WeaponDef, reticleSide),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"iReticleCenterSize",					offsetof(WeaponDef, iReticleCenterSize),					ASSET_ENTRY_INT,0,0},
	{"iReticleSideSize",					offsetof(WeaponDef, iReticleSideSize),						ASSET_ENTRY_INT,0,0},
	{"iReticleMinOfs",						offsetof(WeaponDef, iReticleMinOfs),						ASSET_ENTRY_INT,0,0},
	{"activeReticleType",					offsetof(WeaponDef, activeReticleType),						ASSET_ENTRY_ENUM,				(AssetEntry*)activeReticleNames,			VEH_ACTIVE_RETICLE_COUNT},
	{"vStandMove",							offsetof(WeaponDef, vStandMove),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vStandRot",							offsetof(WeaponDef, vStandRot),								ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vDuckedOfs",							offsetof(WeaponDef, vDuckedOfs),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vDuckedMove",							offsetof(WeaponDef, vDuckedMove),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vDuckedSprintOfs",					offsetof(WeaponDef, vDuckedSprintOfs),						ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vDuckedSprintRot",					offsetof(WeaponDef, vDuckedSprintRot),						ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vDuckedSprintBob",					offsetof(WeaponDef, vDuckedSprintBob),						ASSET_ENTRY_EMBEDDED,			BobEntry,0},
	{"fDuckedSprintCycleScale",				offsetof(WeaponDef, fDuckedSprintCycleScale),				ASSET_ENTRY_FLOAT,0,0},
	{"vSprintOfs",							offsetof(WeaponDef, vSprintOfs),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vSprintRot",							offsetof(WeaponDef, vSprintRot),							ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vSprintBob",							offsetof(WeaponDef, vSprintBob),							ASSET_ENTRY_EMBEDDED,			BobEntry,0},
	{"fSprintCycleScale",					offsetof(WeaponDef, fSprintCycleScale),						ASSET_ENTRY_FLOAT,0,0},
	{"vLowReadyOfs",						offsetof(WeaponDef, vLowReadyOfs),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vLowReadyRot",						offsetof(WeaponDef, vLowReadyRot),							ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vRideOfs",							offsetof(WeaponDef, vRideOfs),								ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vRideRot",							offsetof(WeaponDef, vRideRot),								ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vDtpOfs",								offsetof(WeaponDef, vDtpOfs),								ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vDtpRot",								offsetof(WeaponDef, vDtpRot),								ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vDtpBob",								offsetof(WeaponDef, vDtpBob),								ASSET_ENTRY_EMBEDDED,			BobEntry,0},
	{"fDtpCycleScale",						offsetof(WeaponDef, fDtpCycleScale),						ASSET_ENTRY_FLOAT,0,0},
	{"vMantleOfs",							offsetof(WeaponDef, vMantleOfs),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vMantleRot",							offsetof(WeaponDef, vMantleRot),							ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vSlideOfs",							offsetof(WeaponDef, vSlideOfs),								ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vSlideRot",							offsetof(WeaponDef, vSlideRot),								ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vDuckedRot",							offsetof(WeaponDef, vDuckedRot),							ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vProneOfs",							offsetof(WeaponDef, vProneOfs),								ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vProneMove",							offsetof(WeaponDef, vProneMove),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vProneRot",							offsetof(WeaponDef, vProneRot),								ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"vStrafeMove",							offsetof(WeaponDef, vStrafeMove),							ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"vStrafeRot",							offsetof(WeaponDef, vStrafeRot),							ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"fPosMoveRate",						offsetof(WeaponDef, fPosMoveRate),							ASSET_ENTRY_FLOAT,0,0},
	{"fPosProneMoveRate",					offsetof(WeaponDef, fPosProneMoveRate),						ASSET_ENTRY_FLOAT,0,0},
	{"fStandMoveMinSpeed",					offsetof(WeaponDef, fStandMoveMinSpeed),					ASSET_ENTRY_FLOAT,0,0},
	{"fDuckedMoveMinSpeed",					offsetof(WeaponDef, fDuckedMoveMinSpeed),					ASSET_ENTRY_FLOAT,0,0},
	{"fProneMoveMinSpeed",					offsetof(WeaponDef, fProneMoveMinSpeed),					ASSET_ENTRY_FLOAT,0,0},
	{"fPosRotRate",							offsetof(WeaponDef, fPosRotRate),							ASSET_ENTRY_FLOAT,0,0},
	{"fPosProneRotRate",					offsetof(WeaponDef, fPosProneRotRate),						ASSET_ENTRY_FLOAT,0,0},
	{"fStandRotMinSpeed",					offsetof(WeaponDef, fStandRotMinSpeed),						ASSET_ENTRY_FLOAT,0,0},
	{"fDuckedRotMinSpeed",					offsetof(WeaponDef, fDuckedRotMinSpeed),					ASSET_ENTRY_FLOAT,0,0},
	{"fProneRotMinSpeed",					offsetof(WeaponDef, fProneRotMinSpeed),						ASSET_ENTRY_FLOAT,0,0},
	{"worldModel",							offsetof(WeaponDef, worldModel),							ASSET_ENTRY_CONTAINED,			GunModelEntries,0},
	{"worldClipModel",						offsetof(WeaponDef, worldClipModel),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"rocketModel",							offsetof(WeaponDef, rocketModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"mountedModel",						offsetof(WeaponDef, mountedModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"additionalMeleeModel",				offsetof(WeaponDef, additionalMeleeModel),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"fireTypeIcon",						offsetof(WeaponDef, fireTypeIcon),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"hudIcon",								offsetof(WeaponDef, hudIcon),								ASSET_ENTRY_EMBEDDED,			IconEntry,0},
	{"indicatorIcon",						offsetof(WeaponDef, indicatorIcon),							ASSET_ENTRY_EMBEDDED,			IconEntry,0},
	{"ammoCounterIcon",						offsetof(WeaponDef, ammoCounterIcon),						ASSET_ENTRY_EMBEDDED,			IconEntry,0},
	{"ammoCounterClip",						offsetof(WeaponDef, ammoCounterClip),						ASSET_ENTRY_ENUM,				(AssetEntry*)ammoCounterClipNames,			AMMO_COUNTER_CLIP_MAX},
	{"iStartAmmo",							offsetof(WeaponDef, iStartAmmo),							ASSET_ENTRY_INT,0,0},
	{"iMaxAmmo",							offsetof(WeaponDef, iMaxAmmo),								ASSET_ENTRY_INT,0,0},
	{"shotCount",							offsetof(WeaponDef, shotCount),								ASSET_ENTRY_INT,0,0},
	{"szSharedAmmoCapName",					offsetof(WeaponDef, szSharedAmmoCapName),					ASSET_ENTRY_STRING,0,0},
	{"iSharedAmmoCapIndex",					offsetof(WeaponDef, iSharedAmmoCapIndex),					ASSET_ENTRY_INT,0,0},
	{"iSharedAmmoCap",						offsetof(WeaponDef, iSharedAmmoCap),						ASSET_ENTRY_INT,0,0},
	{"unlimitedAmmo",						offsetof(WeaponDef, unlimitedAmmo),							ASSET_ENTRY_BOOL,0,0},
	{"ammoCountClipRelative",				offsetof(WeaponDef, ammoCountClipRelative),					ASSET_ENTRY_BOOL,0,0},
	{"damage",								offsetof(WeaponDef, damage[0]),								ASSET_ENTRY_INT,0,0},
	{"damage2",								offsetof(WeaponDef, damage[1]),								ASSET_ENTRY_INT,0,0},
	{"damage3",								offsetof(WeaponDef, damage[2]),								ASSET_ENTRY_INT,0,0},
	{"damage4",								offsetof(WeaponDef, damage[3]),								ASSET_ENTRY_INT,0,0},
	{"damage5",								offsetof(WeaponDef, damage[4]),								ASSET_ENTRY_INT,0,0},
	{"minDamage",							offsetof(WeaponDef, damage[5]),								ASSET_ENTRY_INT,0,0},
	{"maxDamageRange",						offsetof(WeaponDef, damageRange[0]),						ASSET_ENTRY_FLOAT,0,0},
	{"damageRange2",						offsetof(WeaponDef, damageRange[1]),						ASSET_ENTRY_FLOAT,0,0},
	{"damageRange3",						offsetof(WeaponDef, damageRange[2]),						ASSET_ENTRY_FLOAT,0,0},
	{"damageRange4",						offsetof(WeaponDef, damageRange[3]),						ASSET_ENTRY_FLOAT,0,0},
	{"damageRange5",						offsetof(WeaponDef, damageRange[4]),						ASSET_ENTRY_FLOAT,0,0},
	{"minDamageRange",						offsetof(WeaponDef, damageRange[5]),						ASSET_ENTRY_FLOAT,0,0},
	{"minPlayerDamage",						offsetof(WeaponDef, minPlayerDamage),						ASSET_ENTRY_INT,0,0},
	{"damageDuration",						offsetof(WeaponDef, damageDuration),						ASSET_ENTRY_FLOAT,0,0},
	{"damageInterval",						offsetof(WeaponDef, damageInterval),						ASSET_ENTRY_FLOAT,0,0},
	{"playerDamage",						offsetof(WeaponDef, playerDamage),							ASSET_ENTRY_INT,0,0},
	{"iMeleeDamage",						offsetof(WeaponDef, iMeleeDamage),							ASSET_ENTRY_INT,0,0},
	{"iDamageType",							offsetof(WeaponDef, iDamageType),							ASSET_ENTRY_ENUM,				(AssetEntry*)meansOfDeath_s,				MOD_NUM},
	{"explosionTag",						offsetof(WeaponDef, explosionTag),							ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"iFireDelay",							offsetof(WeaponDef, iFireDelay),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iMeleeDelay",							offsetof(WeaponDef, iMeleeDelay),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"meleeChargeDelay",					offsetof(WeaponDef, meleeChargeDelay),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iDetonateDelay",						offsetof(WeaponDef, iDetonateDelay),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iSpinUpTime",							offsetof(WeaponDef, iSpinUpTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iSpinDownTime",						offsetof(WeaponDef, iSpinDownTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"spinRate",							offsetof(WeaponDef, spinRate),								ASSET_ENTRY_FLOAT,0,0},
	{"spinLoopSound",						offsetof(WeaponDef, spinLoopSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"startSpinSound",						offsetof(WeaponDef, startSpinSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"stopSpinSound",						offsetof(WeaponDef, stopSpinSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"applySpinPitch",						offsetof(WeaponDef, applySpinPitch),						ASSET_ENTRY_BOOL,0,0},
	{"iFireTime",							offsetof(WeaponDef, iFireTime),								ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iLastFireTime",						offsetof(WeaponDef, iLastFireTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iRechamberTime",						offsetof(WeaponDef, iRechamberTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iRechamberBoltTime",					offsetof(WeaponDef, iRechamberBoltTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iHoldFireTime",						offsetof(WeaponDef, iHoldFireTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iDetonateTime",						offsetof(WeaponDef, iDetonateTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iMeleeTime",							offsetof(WeaponDef, iMeleeTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iBurstDelayTime",						offsetof(WeaponDef, iBurstDelayTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"meleeChargeTime",						offsetof(WeaponDef, meleeChargeTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadTimeRight",					offsetof(WeaponDef, iReloadTimeRight),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadTimeLeft",						offsetof(WeaponDef, iReloadTimeLeft),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"reloadShowRocketTime",				offsetof(WeaponDef, reloadShowRocketTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadEmptyTimeLeft",				offsetof(WeaponDef, iReloadEmptyTimeLeft),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadAddTime",						offsetof(WeaponDef, iReloadAddTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadEmptyAddTime",					offsetof(WeaponDef, iReloadEmptyAddTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadQuickAddTime",					offsetof(WeaponDef, iReloadQuickAddTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadQuickEmptyAddTime",			offsetof(WeaponDef, iReloadQuickEmptyAddTime),				ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadStartTime",					offsetof(WeaponDef, iReloadStartTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadStartAddTime",					offsetof(WeaponDef, iReloadStartAddTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadEndTime",						offsetof(WeaponDef, iReloadEndTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iDropTime",							offsetof(WeaponDef, iDropTime),								ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iRaiseTime",							offsetof(WeaponDef, iRaiseTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iAltDropTime",						offsetof(WeaponDef, iAltDropTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"quickDropTime",						offsetof(WeaponDef, quickDropTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"quickRaiseTime",						offsetof(WeaponDef, quickRaiseTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iFirstRaiseTime",						offsetof(WeaponDef, iFirstRaiseTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iEmptyRaiseTime",						offsetof(WeaponDef, iEmptyRaiseTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iEmptyDropTime",						offsetof(WeaponDef, iEmptyDropTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"sprintInTime",						offsetof(WeaponDef, sprintInTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"sprintLoopTime",						offsetof(WeaponDef, sprintLoopTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"sprintOutTime",						offsetof(WeaponDef, sprintOutTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"lowReadyInTime",						offsetof(WeaponDef, lowReadyInTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"lowReadyLoopTime",					offsetof(WeaponDef, lowReadyLoopTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"lowReadyOutTime",						offsetof(WeaponDef, lowReadyOutTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"contFireInTime",						offsetof(WeaponDef, contFireInTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"contFireLoopTime",					offsetof(WeaponDef, contFireLoopTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"contFireOutTime",						offsetof(WeaponDef, contFireOutTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"dtpInTime",							offsetof(WeaponDef, dtpInTime),								ASSET_ENTRY_TIME_AS_INT,0,0},
	{"dtpLoopTime",							offsetof(WeaponDef, dtpLoopTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"dtpOutTime",							offsetof(WeaponDef, dtpOutTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlInTime",							offsetof(WeaponDef, crawlInTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlForwardTime",					offsetof(WeaponDef, crawlForwardTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlBackTime",						offsetof(WeaponDef, crawlBackTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlRightTime",						offsetof(WeaponDef, crawlRightTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlLeftTime",						offsetof(WeaponDef, crawlLeftTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlOutFireTime",					offsetof(WeaponDef, crawlOutFireTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"crawlOutTime",						offsetof(WeaponDef, crawlOutTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"slideInTime",							offsetof(WeaponDef, slideInTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"deployTime",							offsetof(WeaponDef, deployTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"breakdownTime",						offsetof(WeaponDef, breakdownTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iFlourishTime",						offsetof(WeaponDef, iFlourishTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"nightVisionWearTime",					offsetof(WeaponDef, nightVisionWearTime),					ASSET_ENTRY_EMBEDDED,			NVWearTimeEntries,0},
	{"nightVisionRemoveTime",				offsetof(WeaponDef, nightVisionRemoveTime),					ASSET_ENTRY_EMBEDDED,			NVRemoveTimeEntries,0},
	{"fuseTime",							offsetof(WeaponDef, fuseTime),								ASSET_ENTRY_TIME_AS_INT,0,0},
	{"aiFuseTime",							offsetof(WeaponDef, aiFuseTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"lockOnRadius",						offsetof(WeaponDef, lockOnRadius),							ASSET_ENTRY_INT,0,0},
	{"lockOnSpeed",							offsetof(WeaponDef, lockOnSpeed),							ASSET_ENTRY_INT,0,0},
	{"requireLockonToFire",					offsetof(WeaponDef, requireLockonToFire),					ASSET_ENTRY_BOOL,0,0},
	{"noAdsWhenMagEmpty",					offsetof(WeaponDef, noAdsWhenMagEmpty),						ASSET_ENTRY_BOOL,0,0},
	{"avoidDropCleanup",					offsetof(WeaponDef, avoidDropCleanup),						ASSET_ENTRY_BOOL,0,0},
	{"stackFire",							offsetof(WeaponDef, stackFire),								ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"stackFireSpread",						offsetof(WeaponDef, stackFireSpread),						ASSET_ENTRY_FLOAT,0,0},
	{"stackFireAccuracyDecay",				offsetof(WeaponDef, stackFireAccuracyDecay),				ASSET_ENTRY_FLOAT,0,0},
	{"stackSound",							offsetof(WeaponDef, stackSound),							ASSET_ENTRY_STRING,0,0},
	{"autoAimRange",						offsetof(WeaponDef, autoAimRange),							ASSET_ENTRY_FLOAT,0,0},
	{"aimAssistRange",						offsetof(WeaponDef, aimAssistRange),						ASSET_ENTRY_FLOAT,0,0},
	{"mountableWeapon",						offsetof(WeaponDef, mountableWeapon),						ASSET_ENTRY_BOOL,0,0},
	{"aimPadding",							offsetof(WeaponDef, aimPadding),							ASSET_ENTRY_FLOAT,0,0},
	{"enemyCrosshairRange",					offsetof(WeaponDef, enemyCrosshairRange),					ASSET_ENTRY_FLOAT,0,0},
	{"crosshairColorChange",				offsetof(WeaponDef, crosshairColorChange),					ASSET_ENTRY_BOOL,0,0},
	{"moveSpeedScale",						offsetof(WeaponDef, moveSpeedScale),						ASSET_ENTRY_FLOAT,0,0},
	{"adsMoveSpeedScale",					offsetof(WeaponDef, adsMoveSpeedScale),						ASSET_ENTRY_FLOAT,0,0},
	{"sprintDurationScale",					offsetof(WeaponDef, sprintDurationScale),					ASSET_ENTRY_FLOAT,0,0},
	{"adsOverlayReticle",					offsetof(WeaponDef, adsOverlayReticle),						ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapOverlayReticleNames,		WEAPOVERLAYRETICLE_MAX},
	{"adsOverlayInterface",					offsetof(WeaponDef, adsOverlayInterface),					ASSET_ENTRY_ENUM,				(AssetEntry*)weapOverlayInterface_s,		WEAPOVERLAYINTERFACE_MAX},
	{"overlayWidth",						offsetof(WeaponDef, overlayWidth),							ASSET_ENTRY_FLOAT,0,0},
	{"overlayHeight",						offsetof(WeaponDef, overlayHeight),							ASSET_ENTRY_FLOAT,0,0},
	{"fAdsBobFactor",						offsetof(WeaponDef, fAdsBobFactor),							ASSET_ENTRY_FLOAT,0,0},
	{"fAdsViewBobMult",						offsetof(WeaponDef, fAdsViewBobMult),						ASSET_ENTRY_FLOAT,0,0},
	{"bHoldBreathToSteady",					offsetof(WeaponDef, bHoldBreathToSteady),					ASSET_ENTRY_BOOL,0,0},
	{"fHipSpread",							offsetof(WeaponDef, fHipSpreadStandMin),					ASSET_ENTRY_EMBEDDED,			HipSpreadSettings,0},
	{"fHipReticleSidePos",					offsetof(WeaponDef, fHipReticleSidePos),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsIdleAmount",						offsetof(WeaponDef, fAdsIdleAmount),						ASSET_ENTRY_FLOAT,0,0},
	{"fHipIdleAmount",						offsetof(WeaponDef, fHipIdleAmount),						ASSET_ENTRY_FLOAT,0,0},
	{"adsIdleSpeed",						offsetof(WeaponDef, adsIdleSpeed),							ASSET_ENTRY_FLOAT,0,0},
	{"hipIdleSpeed",						offsetof(WeaponDef, hipIdleSpeed),							ASSET_ENTRY_FLOAT,0,0},
	{"fIdleCrouchFactor",					offsetof(WeaponDef, fIdleCrouchFactor),						ASSET_ENTRY_FLOAT,0,0},
	{"fIdleProneFactor",					offsetof(WeaponDef, fIdleProneFactor),						ASSET_ENTRY_FLOAT,0,0},
	{"fGunMaxPitch",						offsetof(WeaponDef, fGunMaxPitch),							ASSET_ENTRY_FLOAT,0,0},
	{"fGunMaxYaw",							offsetof(WeaponDef, fGunMaxYaw),							ASSET_ENTRY_FLOAT,0,0},
	{"swayMaxAngle",						offsetof(WeaponDef, swayMaxAngle),							ASSET_ENTRY_FLOAT,0,0},
	{"swayLerpSpeed",						offsetof(WeaponDef, swayLerpSpeed),							ASSET_ENTRY_FLOAT,0,0},
	{"swayPitchScale",						offsetof(WeaponDef, swayPitchScale),						ASSET_ENTRY_FLOAT,0,0},
	{"swayYawScale",						offsetof(WeaponDef, swayYawScale),							ASSET_ENTRY_FLOAT,0,0},
	{"swayHorizScale",						offsetof(WeaponDef, swayHorizScale),						ASSET_ENTRY_FLOAT,0,0},
	{"swayVertScale",						offsetof(WeaponDef, swayVertScale),							ASSET_ENTRY_FLOAT,0,0},
	{"swayShellShockScale",					offsetof(WeaponDef, swayShellShockScale),					ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayMaxAngle",						offsetof(WeaponDef, adsSwayMaxAngle),						ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayLerpSpeed",					offsetof(WeaponDef, adsSwayLerpSpeed),						ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayPitchScale",					offsetof(WeaponDef, adsSwayPitchScale),						ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayYawScale",						offsetof(WeaponDef, adsSwayYawScale),						ASSET_ENTRY_FLOAT,0,0},
	{"sharedAmmo",							offsetof(WeaponDef, sharedAmmo),							ASSET_ENTRY_BOOL,0,0},
	{"bRifleBullet",						offsetof(WeaponDef, bRifleBullet),							ASSET_ENTRY_BOOL,0,0},
	{"armorPiercing",						offsetof(WeaponDef, armorPiercing),							ASSET_ENTRY_BOOL,0,0},
	{"bAirburstWeapon",						offsetof(WeaponDef, bAirburstWeapon),						ASSET_ENTRY_BOOL,0,0},
	{"bBoltAction",							offsetof(WeaponDef, bBoltAction),							ASSET_ENTRY_BOOL,0,0},
	{"bUseAltTagFlash",						offsetof(WeaponDef, bUseAltTagFlash),						ASSET_ENTRY_BOOL,0,0},
	{"bUseAntiLagRewind",					offsetof(WeaponDef, bUseAntiLagRewind),						ASSET_ENTRY_BOOL,0,0},
	{"bIsCarriedKillstreakWeapon",			offsetof(WeaponDef, bIsCarriedKillstreakWeapon),			ASSET_ENTRY_BOOL,0,0},
	{"aimDownSight",						offsetof(WeaponDef, aimDownSight),							ASSET_ENTRY_BOOL,0,0},
	{"bRechamberWhileAds",					offsetof(WeaponDef, bRechamberWhileAds),					ASSET_ENTRY_BOOL,0,0},
	{"bReloadWhileAds",						offsetof(WeaponDef, bReloadWhileAds),						ASSET_ENTRY_BOOL,0,0},
	{"adsViewError",						offsetof(WeaponDef, adsViewErrorMin),						ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"bCookOffHold",						offsetof(WeaponDef, bCookOffHold),							ASSET_ENTRY_BOOL,0,0},
	{"bClipOnly",							offsetof(WeaponDef, bClipOnly),								ASSET_ENTRY_BOOL,0,0},
	{"bCanUseInVehicle",					offsetof(WeaponDef, bCanUseInVehicle),						ASSET_ENTRY_BOOL,0,0},
	{"bNoDropsOrRaises",					offsetof(WeaponDef, bNoDropsOrRaises),						ASSET_ENTRY_BOOL,0,0},
	{"adsFireOnly",							offsetof(WeaponDef, adsFireOnly),							ASSET_ENTRY_BOOL,0,0},
	{"cancelAutoHolsterWhenEmpty",			offsetof(WeaponDef, cancelAutoHolsterWhenEmpty),			ASSET_ENTRY_BOOL,0,0},
	{"suppressAmmoReserveDisplay",			offsetof(WeaponDef, suppressAmmoReserveDisplay),			ASSET_ENTRY_BOOL,0,0},
	{"laserSight",							offsetof(WeaponDef, laserSight),							ASSET_ENTRY_BOOL,0,0},
	{"laserSightDuringNightvision",			offsetof(WeaponDef, laserSightDuringNightvision),			ASSET_ENTRY_BOOL,0,0},
	{"bHideThirdPerson",					offsetof(WeaponDef, bHideThirdPerson),						ASSET_ENTRY_BOOL,0,0},
	{"bHasBayonet",							offsetof(WeaponDef, bHasBayonet),							ASSET_ENTRY_BOOL,0,0},
	{"bDualWield",							offsetof(WeaponDef, bDualWield),							ASSET_ENTRY_BOOL,0,0},
	{"bExplodeOnGround",					offsetof(WeaponDef, bExplodeOnGround),						ASSET_ENTRY_BOOL,0,0},
	{"bThrowBack",							offsetof(WeaponDef, bThrowBack),							ASSET_ENTRY_BOOL,0,0},
	{"bRetrievable",						offsetof(WeaponDef, bRetrievable),							ASSET_ENTRY_BOOL,0,0},
	{"bDieOnRespawn",						offsetof(WeaponDef, bDieOnRespawn),							ASSET_ENTRY_BOOL,0,0},
	{"bNoThirdPersonDropsOrRaises",			offsetof(WeaponDef, bNoThirdPersonDropsOrRaises),			ASSET_ENTRY_BOOL,0,0},
	{"bContinuousFire",						offsetof(WeaponDef, bContinuousFire),						ASSET_ENTRY_BOOL,0,0},
	{"bNoPing",								offsetof(WeaponDef, bNoPing),								ASSET_ENTRY_BOOL,0,0},
	{"bForceBounce",						offsetof(WeaponDef, bForceBounce),							ASSET_ENTRY_BOOL,0,0},
	{"bUseDroppedModelAsStowed",			offsetof(WeaponDef, bUseDroppedModelAsStowed),				ASSET_ENTRY_BOOL,0,0},
	{"bNoQuickDropWhenEmpty",				offsetof(WeaponDef, bNoQuickDropWhenEmpty),					ASSET_ENTRY_BOOL,0,0},
	{"bKeepCrosshairWhenADS",				offsetof(WeaponDef, bKeepCrosshairWhenADS),					ASSET_ENTRY_BOOL,0,0},
	{"bUseOnlyAltWeaoponHideTagsInAltMode",	offsetof(WeaponDef, bUseOnlyAltWeaoponHideTagsInAltMode),	ASSET_ENTRY_BOOL,0,0},
	{"bAltWeaponAdsOnly",					offsetof(WeaponDef, bAltWeaponAdsOnly),						ASSET_ENTRY_BOOL,0,0},
	{"bAltWeaponDisableSwitching",			offsetof(WeaponDef, bAltWeaponDisableSwitching),			ASSET_ENTRY_BOOL,0,0},
	{"killIcon",							offsetof(WeaponDef, killIcon),								ASSET_ENTRY_EMBEDDED,			IconEntry,0},
	{"flipKillIcon",						offsetof(WeaponDef, flipKillIcon),							ASSET_ENTRY_BOOL,0,0},
	{"bNoPartialReload",					offsetof(WeaponDef, bNoPartialReload),						ASSET_ENTRY_BOOL,0,0},
	{"bSegmentedReload",					offsetof(WeaponDef, bSegmentedReload),						ASSET_ENTRY_BOOL,0,0},
	{"bNoADSAutoReload",					offsetof(WeaponDef, bNoADSAutoReload),						ASSET_ENTRY_BOOL,0,0},
	{"iReloadAmmoAdd",						offsetof(WeaponDef, iReloadAmmoAdd),						ASSET_ENTRY_INT,0,0},
	{"iReloadStartAdd",						offsetof(WeaponDef, iReloadStartAdd),						ASSET_ENTRY_INT,0,0},
	{"szSpawnedGrenadeWeaponName",			offsetof(WeaponDef, szSpawnedGrenadeWeaponName),			ASSET_ENTRY_STRING,0,0},
	{"szDualWieldWeaponName",				offsetof(WeaponDef, szDualWieldWeaponName),					ASSET_ENTRY_STRING,0,0},
	{"dualWieldWeaponIndex",				offsetof(WeaponDef, dualWieldWeaponIndex),					ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"iDropAmmo",							offsetof(WeaponDef, iDropAmmoMin),							ASSET_ENTRY_EMBEDDED,			MinMax_IntEntry,0},
	{"iDropClipAmmo",						offsetof(WeaponDef, iDropClipAmmoMin),						ASSET_ENTRY_EMBEDDED,			MinMax_IntEntry,0},
	{"iShotsBeforeRechamber",				offsetof(WeaponDef, iShotsBeforeRechamber),					ASSET_ENTRY_INT,0,0},
	{"blocksProne",							offsetof(WeaponDef, blocksProne),							ASSET_ENTRY_BOOL,0,0},
	{"bShowIndicator",						offsetof(WeaponDef, bShowIndicator),						ASSET_ENTRY_BOOL,0,0},
	{"isRollingGrenade",					offsetof(WeaponDef, isRollingGrenade),						ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"useBallisticPrediction",				offsetof(WeaponDef, useBallisticPrediction),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"isValuable",							offsetof(WeaponDef, isValuable),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"isTacticalInsertion",					offsetof(WeaponDef, isTacticalInsertion),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"isReviveWeapon",						offsetof(WeaponDef, isReviveWeapon),						ASSET_ENTRY_BOOL,0,0},
	{"bUseRigidBodyOnVehicle",				offsetof(WeaponDef, bUseRigidBodyOnVehicle),				ASSET_ENTRY_BOOL,0,0},
	{"iExplosionRadius",					offsetof(WeaponDef, iExplosionRadius),						ASSET_ENTRY_INT,0,0},
	{"iExplosionRadiusMin",					offsetof(WeaponDef, iExplosionRadiusMin),					ASSET_ENTRY_INT,0,0},
	{"iIndicatorRadius",					offsetof(WeaponDef, iIndicatorRadius),						ASSET_ENTRY_INT,0,0},
	{"iExplosionInnerDamage",				offsetof(WeaponDef, iExplosionInnerDamage),					ASSET_ENTRY_INT,0,0},
	{"iExplosionOuterDamage",				offsetof(WeaponDef, iExplosionOuterDamage),					ASSET_ENTRY_INT,0,0},
	{"damageConeAngle",						offsetof(WeaponDef, damageConeAngle),						ASSET_ENTRY_FLOAT,0,0},
	{"iProjectileSpeed",					offsetof(WeaponDef, iProjectileSpeed),						ASSET_ENTRY_INT,0,0},
	{"iProjectileSpeedUp",					offsetof(WeaponDef, iProjectileSpeedUp),					ASSET_ENTRY_INT,0,0},
	{"iProjectileSpeedRelativeUp",			offsetof(WeaponDef, iProjectileSpeedRelativeUp),			ASSET_ENTRY_INT,0,0},
	{"iProjectileSpeedForward",				offsetof(WeaponDef, iProjectileSpeedForward),				ASSET_ENTRY_INT,0,0},
	{"fProjectileTakeParentVelocity",		offsetof(WeaponDef, fProjectileTakeParentVelocity),			ASSET_ENTRY_FLOAT,0,0},
	{"iProjectileActivateDist",				offsetof(WeaponDef, iProjectileActivateDist),				ASSET_ENTRY_INT,0,0},
	{"projLifetime",						offsetof(WeaponDef, projLifetime),							ASSET_ENTRY_FLOAT,0,0},
	{"timeToAccelerate",					offsetof(WeaponDef, timeToAccelerate),						ASSET_ENTRY_FLOAT,0,0},
	{"projectileCurvature",					offsetof(WeaponDef, projectileCurvature),					ASSET_ENTRY_FLOAT,0,0},
	{"projectileModel",						offsetof(WeaponDef, projectileModel),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"projExplosion",						offsetof(WeaponDef, projExplosion),							ASSET_ENTRY_ENUM,				(AssetEntry*)szProjectileExplosionNames,	WEAPPROJEXP_NUM},
	{"projExplosionEffect1",				offsetof(WeaponDef, projExplosionEffect[0]),				ASSET_ENTRY_EMBEDDED,			ProjExplosionEntry,0},
	{"projExplosionEffect2",				offsetof(WeaponDef, projExplosionEffect[1]),				ASSET_ENTRY_EMBEDDED,			ProjExplosionEntry,0},
	{"projExplosionEffect3",				offsetof(WeaponDef, projExplosionEffect[2]),				ASSET_ENTRY_EMBEDDED,			ProjExplosionEntry,0},
	{"projExplosionEffect4",				offsetof(WeaponDef, projExplosionEffect[3]),				ASSET_ENTRY_EMBEDDED,			ProjExplosionEntry,0},
	{"projExplosionEffect5",				offsetof(WeaponDef, projExplosionEffect[4]),				ASSET_ENTRY_EMBEDDED,			ProjExplosionEntry,0},
	{"projDudEffect",						offsetof(WeaponDef, projDudEffect),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"projExplosionSound",					offsetof(WeaponDef, projExplosionSound),					ASSET_ENTRY_STRING,0,0},
	{"projDudSound",						offsetof(WeaponDef, projDudSound),							ASSET_ENTRY_STRING,0,0},
	{"mortarShellSound",					offsetof(WeaponDef, mortarShellSound),						ASSET_ENTRY_STRING,0,0},
	{"tankShellSound",						offsetof(WeaponDef, tankShellSound),						ASSET_ENTRY_STRING,0,0},
	{"bProjImpactExplode",					offsetof(WeaponDef, bProjImpactExplode),					ASSET_ENTRY_BOOL,0,0},
	{"bProjSentientImpactExplode",			offsetof(WeaponDef, bProjSentientImpactExplode),			ASSET_ENTRY_BOOL,0,0},
	{"bProjExplodeWhenStationary",			offsetof(WeaponDef, bProjExplodeWhenStationary),			ASSET_ENTRY_BOOL,0,0},
	{"bBulletImpactExplode",				offsetof(WeaponDef, bBulletImpactExplode),					ASSET_ENTRY_BOOL,0,0},
	{"stickiness",							offsetof(WeaponDef, stickiness),							ASSET_ENTRY_ENUM,				(AssetEntry*)stickinessNames,				WEAPSTICKINESS_COUNT},
	{"rotateType",							offsetof(WeaponDef, rotateType),							ASSET_ENTRY_ENUM,				(AssetEntry*)rotateTypeNames,				WEAPROTATE_COUNT},
	{"plantable",							offsetof(WeaponDef, plantable),								ASSET_ENTRY_BOOL,0,0},
	{"hasDetonator",						offsetof(WeaponDef, hasDetonator),							ASSET_ENTRY_BOOL,0,0},
	{"timedDetonation",						offsetof(WeaponDef, timedDetonation),						ASSET_ENTRY_BOOL,0,0},
	{"noCrumpleMissile",					offsetof(WeaponDef, noCrumpleMissile),						ASSET_ENTRY_BOOL,0,0},
	{"rotate",								offsetof(WeaponDef, rotate),								ASSET_ENTRY_BOOL,0,0},
	{"keepRolling",							offsetof(WeaponDef, keepRolling),							ASSET_ENTRY_BOOL,0,0},
	{"holdButtonToThrow",					offsetof(WeaponDef, holdButtonToThrow),						ASSET_ENTRY_BOOL,0,0},
	{"offhandHoldIsCancelable",				offsetof(WeaponDef, offhandHoldIsCancelable),				ASSET_ENTRY_BOOL,0,0},
	{"freezeMovementWhenFiring",			offsetof(WeaponDef, freezeMovementWhenFiring),				ASSET_ENTRY_BOOL,0,0},
	{"lowAmmoWarningThreshold",				offsetof(WeaponDef, lowAmmoWarningThreshold),				ASSET_ENTRY_FLOAT,0,0},
	{"bDisallowAtMatchStart",				offsetof(WeaponDef, bDisallowAtMatchStart),					ASSET_ENTRY_BOOL,0,0},
	{"meleeChargeRange",					offsetof(WeaponDef, meleeChargeRange),						ASSET_ENTRY_FLOAT,0,0},
	{"bUseAsMelee",							offsetof(WeaponDef, bUseAsMelee),							ASSET_ENTRY_BOOL,0,0},
	{"isCameraSensor",						offsetof(WeaponDef, isCameraSensor),						ASSET_ENTRY_BOOL,0,0},
	{"isAcousticSensor",					offsetof(WeaponDef, isAcousticSensor),						ASSET_ENTRY_BOOL,0,0},
	{"isLaserSensor",						offsetof(WeaponDef, isLaserSensor),							ASSET_ENTRY_BOOL,0,0},
	{"isHoldUseGrenade",					offsetof(WeaponDef, isHoldUseGrenade),						ASSET_ENTRY_BOOL,0,0},
	{"_parallelBounce",						offsetof(WeaponDef, parallelBounce),						ASSET_ENTRY_CONTAINED_REVERSED,	BounceFloatEntries,0},
	{"_perpendicularBounce",				offsetof(WeaponDef, perpendicularBounce),					ASSET_ENTRY_CONTAINED_REVERSED,	BounceFloatEntries,0},
	{"projTrailEffect",						offsetof(WeaponDef, projTrailEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"projectileRed",						offsetof(WeaponDef, vProjectileColor),						ASSET_ENTRY_FLOAT,0,0},
	{"projectileGreen",						offsetof(WeaponDef, vProjectileColor) + 4,					ASSET_ENTRY_FLOAT,0,0},
	{"projectileBlue",						offsetof(WeaponDef, vProjectileColor) + 8,					ASSET_ENTRY_FLOAT,0,0},
	{"guidedMissileType",					offsetof(WeaponDef, guidedMissileType),						ASSET_ENTRY_ENUM,				(AssetEntry*)guidedMissileNames,			MISSILE_GUIDANCE_MAX},
	{"maxSteeringAccel",					offsetof(WeaponDef, maxSteeringAccel),						ASSET_ENTRY_FLOAT,0,0},
	{"projIgnitionDelay",					offsetof(WeaponDef, projIgnitionDelay),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"projIgnitionEffect",					offsetof(WeaponDef, projIgnitionEffect),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"projIgnitionSound",					offsetof(WeaponDef, projIgnitionSound),						ASSET_ENTRY_STRING,0,0},
	{"fAdsAimPitch",						offsetof(WeaponDef, fAdsAimPitch),							ASSET_ENTRY_FLOAT,0,0},
	{"fAdsCrosshairInFrac",					offsetof(WeaponDef, fAdsCrosshairInFrac),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsCrosshairOutFrac",				offsetof(WeaponDef, fAdsCrosshairOutFrac),					ASSET_ENTRY_FLOAT,0,0},
	{"adsGunKickReducedKickBullets",		offsetof(WeaponDef, adsGunKickReducedKickBullets),			ASSET_ENTRY_INT,0,0},
	{"fAdsGunKick",							offsetof(WeaponDef, adsGunKickReducedKickPercent),			ASSET_ENTRY_EMBEDDED,			GunKickSettings,0},
	{"fAdsViewKickPitch",					offsetof(WeaponDef, fAdsViewKickPitchMin),					ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"fAdsViewKickMinMagnitude",			offsetof(WeaponDef, fAdsViewKickMinMagnitude),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsViewKickYaw",						offsetof(WeaponDef, fAdsViewKickYawMin),					ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"fAdsRecoilReductionRate",				offsetof(WeaponDef, fAdsRecoilReductionRate),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsRecoilReductionLimit",			offsetof(WeaponDef, fAdsRecoilReductionLimit),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsRecoilReturnRate",				offsetof(WeaponDef, fAdsRecoilReturnRate),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsSpread",							offsetof(WeaponDef, fAdsSpread),							ASSET_ENTRY_FLOAT,0,0},
	{"hipGunKickReducedKickBullets",		offsetof(WeaponDef, hipGunKickReducedKickBullets),			ASSET_ENTRY_INT,0,0},
	{"fHipGunKick",							offsetof(WeaponDef, hipGunKickReducedKickPercent),			ASSET_ENTRY_EMBEDDED,			GunKickSettings,0},
	{"fHipViewKickPitch",					offsetof(WeaponDef, fHipViewKickPitchMin),					ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"fHipViewKickMinMagnitude",			offsetof(WeaponDef, fHipViewKickMinMagnitude),				ASSET_ENTRY_FLOAT,0,0},
	{"fHipViewKickYaw",						offsetof(WeaponDef, fHipViewKickYawMin),					ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"fHipViewScatter",						offsetof(WeaponDef, fHipViewScatterMin),					ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"fAdsViewKickCenterDuckedScale",		offsetof(WeaponDef, fAdsViewKickCenterDuckedScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fAdsViewKickCenterProneScale",		offsetof(WeaponDef, fAdsViewKickCenterProneScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fAntiQuickScope",						offsetof(WeaponDef, fAntiQuickScopeTime),					ASSET_ENTRY_EMBEDDED,			AntiQuickScopeEntries,0},
	{"fightDist",							offsetof(WeaponDef, fightDist),								ASSET_ENTRY_FLOAT,0,0},
	{"maxDist",								offsetof(WeaponDef, maxDist),								ASSET_ENTRY_FLOAT,0,0},
	{"aiVsAiAccuracyGraphName",				offsetof(WeaponDef, aiVsAiAccuracyGraphName),				ASSET_ENTRY_STRING,0,0},
	{"aiVsPlayerAccuracyGraphName",			offsetof(WeaponDef, aiVsPlayerAccuracyGraphName),			ASSET_ENTRY_STRING,0,0},
	{"iPositionReloadTransTime",			offsetof(WeaponDef, iPositionReloadTransTime),				ASSET_ENTRY_INT,0,0},
	{"leftArc",								offsetof(WeaponDef, leftArc),								ASSET_ENTRY_FLOAT,0,0},
	{"rightArc",							offsetof(WeaponDef, rightArc),								ASSET_ENTRY_FLOAT,0,0},
	{"topArc",								offsetof(WeaponDef, topArc),								ASSET_ENTRY_FLOAT,0,0},
	{"bottomArc",							offsetof(WeaponDef, bottomArc),								ASSET_ENTRY_FLOAT,0,0},
	{"accuracy",							offsetof(WeaponDef, accuracy),								ASSET_ENTRY_FLOAT,0,0},
	{"aiSpread",							offsetof(WeaponDef, aiSpread),								ASSET_ENTRY_FLOAT,0,0},
	{"playerSpread",						offsetof(WeaponDef, playerSpread),							ASSET_ENTRY_FLOAT,0,0},
	{"maxVertTurnSpeed",					offsetof(WeaponDef, maxTurnSpeed[0]),						ASSET_ENTRY_FLOAT,0,0},
	{"maxHorTurnSpeed",						offsetof(WeaponDef, maxTurnSpeed[1]),						ASSET_ENTRY_FLOAT,0,0},
	{"minVertTurnSpeed",					offsetof(WeaponDef, minTurnSpeed[0]),						ASSET_ENTRY_FLOAT,0,0},
	{"minHorTurnSpeed",						offsetof(WeaponDef, minTurnSpeed[1]),						ASSET_ENTRY_FLOAT,0,0},
	{"pitchConvergenceTime",				offsetof(WeaponDef, pitchConvergenceTime),					ASSET_ENTRY_FLOAT,0,0},
	{"yawConvergenceTime",					offsetof(WeaponDef, yawConvergenceTime),					ASSET_ENTRY_FLOAT,0,0},
	{"suppressTime",						offsetof(WeaponDef, suppressTime),							ASSET_ENTRY_FLOAT,0,0},
	{"maxRange",							offsetof(WeaponDef, maxRange),								ASSET_ENTRY_FLOAT,0,0},
	{"fAnimHorRotateInc",					offsetof(WeaponDef, fAnimHorRotateInc),						ASSET_ENTRY_FLOAT,0,0},
	{"fPlayerPositionDist",					offsetof(WeaponDef, fPlayerPositionDist),					ASSET_ENTRY_FLOAT,0,0},
	{"szUseHintString",						offsetof(WeaponDef, szUseHintString),						ASSET_ENTRY_STRING,0,0},
	{"dropHintString",						offsetof(WeaponDef, dropHintString),						ASSET_ENTRY_STRING,0,0},
	{"iUseHintStringIndex",					offsetof(WeaponDef, iUseHintStringIndex),					ASSET_ENTRY_INT,0,0},
	{"dropHintStringIndex",					offsetof(WeaponDef, dropHintStringIndex),					ASSET_ENTRY_INT,0,0},
	{"horizViewJitter",						offsetof(WeaponDef, horizViewJitter),						ASSET_ENTRY_FLOAT,0,0},
	{"vertViewJitter",						offsetof(WeaponDef, vertViewJitter),						ASSET_ENTRY_FLOAT,0,0},
	{"cameraShake",							offsetof(WeaponDef, cameraShakeScale),						ASSET_ENTRY_EMBEDDED,			CameraShakeEntries,0},
	{"explosionCameraShake",				offsetof(WeaponDef, explosionCameraShakeScale),				ASSET_ENTRY_EMBEDDED,			CameraShakeEntries,0},
	{"szScript",							offsetof(WeaponDef, szScript),								ASSET_ENTRY_STRING,0,0},
	{"destabilizationRateTime",				offsetof(WeaponDef, destabilizationRateTime),				ASSET_ENTRY_FLOAT,0,0},
	{"destabilizationCurvatureMax",			offsetof(WeaponDef, destabilizationCurvatureMax),			ASSET_ENTRY_FLOAT,0,0},
	{"destabilizeDistance",					offsetof(WeaponDef, destabilizeDistance),					ASSET_ENTRY_INT,0,0},
	{"",									offsetof(WeaponDef, locationDamageMultipliers),				ASSET_ENTRY_CONTAINED,			LocationDamageEntries,0},
	{"fireRumble",							offsetof(WeaponDef, fireRumble),							ASSET_ENTRY_STRING,0,0},
	{"meleeImpactRumble",					offsetof(WeaponDef, meleeImpactRumble),						ASSET_ENTRY_STRING,0,0},
	{"reloadRumble",						offsetof(WeaponDef, reloadRumble),							ASSET_ENTRY_STRING,0,0},
	{"explosionRumble",						offsetof(WeaponDef, explosionRumble),						ASSET_ENTRY_STRING,0,0},
	{"tracerType",							offsetof(WeaponDef, tracerType),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_TRACER,0},
	{"enemyTracerType",						offsetof(WeaponDef, enemyTracerType),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_TRACER,0},
	{"adsDofStart",							offsetof(WeaponDef, adsDofStart),							ASSET_ENTRY_FLOAT,0,0},
	{"adsDofEnd",							offsetof(WeaponDef, adsDofEnd),								ASSET_ENTRY_FLOAT,0,0},
	{"hipDofStart",							offsetof(WeaponDef, hipDofStart),							ASSET_ENTRY_FLOAT,0,0},
	{"hipDofEnd",							offsetof(WeaponDef, hipDofEnd),								ASSET_ENTRY_FLOAT,0,0},
	{"scanSpeed",							offsetof(WeaponDef, scanSpeed),								ASSET_ENTRY_FLOAT,0,0},
	{"scanAccel",							offsetof(WeaponDef, scanAccel),								ASSET_ENTRY_FLOAT,0,0},
	{"scanPauseTime",						offsetof(WeaponDef, scanPauseTime),							ASSET_ENTRY_TIME_AS_INT,0,0},
	{"flameTableFirstPerson",				offsetof(WeaponDef, flameTableFirstPerson),					ASSET_ENTRY_STRING,0,0},
	{"flameTableThirdPerson",				offsetof(WeaponDef, flameTableThirdPerson),					ASSET_ENTRY_STRING,0,0},
	{"doGibbing",							offsetof(WeaponDef, doGibbing),								ASSET_ENTRY_BOOL,0,0},
	{"maxGibDistance",						offsetof(WeaponDef, maxGibDistance),						ASSET_ENTRY_FLOAT,0,0},
	{"altScopeADSTransInTime",				offsetof(WeaponDef, altScopeADSTransInTime),				ASSET_ENTRY_FLOAT,0,0},
	{"altScopeADSTransOutTime",				offsetof(WeaponDef, altScopeADSTransOutTime),				ASSET_ENTRY_FLOAT,0,0},
	{"iIntroFireTime",						offsetof(WeaponDef, iIntroFireTime),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iIntroFireLength",					offsetof(WeaponDef, iIntroFireLength),						ASSET_ENTRY_TIME_AS_INT,0,0},
	{"meleeSwipeEffect",					offsetof(WeaponDef, meleeSwipeEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"meleeImpactEffect",					offsetof(WeaponDef, meleeImpactEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"meleeImpactNoBloodEffect",			offsetof(WeaponDef, meleeImpactNoBloodEffect),				ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"throwBackType",						offsetof(WeaponDef, throwBackType),							ASSET_ENTRY_STRING,0,0},
	{"camo",								offsetof(WeaponDef, camo),									ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_WEAPON_CAMO,0},
	{"customFloat1",						offsetof(WeaponDef, customFloat[0]),						ASSET_ENTRY_FLOAT,0,0},
	{"customFloat2",						offsetof(WeaponDef, customFloat[1]),						ASSET_ENTRY_FLOAT,0,0},
	{"customFloat3",						offsetof(WeaponDef, customFloat[2]),						ASSET_ENTRY_FLOAT,0,0},
	{"customBool1",							offsetof(WeaponDef, customBool[0]),							ASSET_ENTRY_INT,0,0},
	{"customBool2",							offsetof(WeaponDef, customBool[1]),							ASSET_ENTRY_INT,0,0},
	{"customBool3",							offsetof(WeaponDef, customBool[2]),							ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponAttachmentDefEntries[] = {
	{"1",	0*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"2",	1*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"3",	2*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"4",	3*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"5",	4*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"6",	5*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"7",	6*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"8",	7*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"9",	8*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"10",	9*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"11",	10*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"12",	11*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"13",	12*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"14",	13*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"15",	14*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"16",	15*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"17",	16*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"18",	17*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"19",	18*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"20",	19*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"21",	20*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"22",	21*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"23",	22*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"24",	23*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"25",	24*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"26",	25*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"27",	26*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"28",	27*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"29",	28*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"30",	29*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"31",	30*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"32",	31*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"33",	32*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"34",	33*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"35",	34*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"36",	35*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"37",	36*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"38",	37*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"39",	38*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"40",	39*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"41",	40*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"42",	41*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"43",	42*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"44",	43*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"45",	44*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"46",	45*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"47",	46*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"48",	47*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"49",	48*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"50",	49*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"51",	50*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"52",	51*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"53",	52*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"54",	53*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"55",	54*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"56",	55*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"57",	56*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"58",	57*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"59",	58*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"60",	59*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"61",	60*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"62",	61*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{"63",	62*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponUniqueAttachmentDefEntries[] = {
	{"1",	0*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"2",	1*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"3",	2*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"4",	3*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"5",	4*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"6",	5*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"7",	6*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"8",	7*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"9",	8*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"10",	9*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"11",	10*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"12",	11*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"13",	12*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"14",	13*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"15",	14*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"16",	15*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"17",	16*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"18",	17*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"19",	18*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"20",	19*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"21",	20*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"22",	21*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"23",	22*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"24",	23*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"25",	24*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"26",	25*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"27",	26*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"28",	27*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"29",	28*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"30",	29*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"31",	30*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"32",	31*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"33",	32*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"34",	33*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"35",	34*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"36",	35*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"37",	36*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"38",	37*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"39",	38*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"40",	39*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"41",	40*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"42",	41*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"43",	42*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"44",	43*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"45",	44*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"46",	45*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"47",	46*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"48",	47*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"49",	48*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"50",	49*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"51",	50*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"52",	51*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"53",	52*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"54",	53*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"55",	54*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"56",	55*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"57",	56*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"58",	57*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"59",	58*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"60",	59*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"61",	60*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"62",	61*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"63",	62*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"64",	63*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"65",	64*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"66",	65*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"67",	66*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"68",	67*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"69",	68*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"70",	69*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"71",	70*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"72",	71*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"73",	72*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"74",	73*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"75",	74*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"76",	75*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"77",	76*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"78",	77*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"79",	78*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"80",	79*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"81",	80*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"82",	81*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"83",	82*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"84",	83*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"85",	84*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"86",	85*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"87",	86*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"88",	87*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"89",	88*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"90",	89*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"91",	90*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"92",	91*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"93",	92*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"94",	93*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{"95",	94*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_ATTACHMENT_UNIQUE,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponXAnimsEntries[] = {
	{"root",				0*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"idle",				1*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"empty_idle",			2*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"fire_intro",			3*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"fire",				4*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"hold_fire",			5*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"lastshot",			6*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"finalshot",			7*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"rechamber",			8*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee",				9*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee1",				10*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee2",				11*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee3",				12*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee_empty",			13*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee_charge",		14*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"melee_charge_empty",	15*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload",				16*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_right",		17*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_empty",		18*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_start",		19*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_end",			20*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_quick",		21*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_quick_empty",	22*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"raise",				23*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"first_raise",			24*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"drop",				25*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"alt_raise",			26*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"alt_drop",			27*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"quick_raise",			28*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"quick_drop",			29*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"empty_raise",			30*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"empty_drop",			31*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"sprint_in",			32*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"sprint_loop",			33*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"sprint_out",			34*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"sprint_empty_in",		35*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"sprint_empty_loop",	36*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"sprint_empty_out",	37*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"lowready_in",			38*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"lowready_loop",		39*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"lowready_out",		40*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"cont_fire_in",		41*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"cont_fire_loop",		42*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"cont_fire_out",		43*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_in",			44*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_forward",		45*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_back",			46*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_right",			47*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_left",			48*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_out",			49*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_empty_in",		50*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_empty_forward",	51*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_empty_back",	52*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_empty_right",	53*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_empty_left",	54*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"crawl_empty_out",		55*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"deploy",				56*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"breakdown",			57*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"detonate",			58*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"nightvision_wear",	59*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"nightvision_remove",	60*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_fire",			61*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_lastshot",		62*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_fire_intro",		63*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_rechamber",		64*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"dtp_in",				65*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"dtp_loop",			66*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"dtp_out",				67*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"dtp_empty_in",		68*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"dtp_empty_loop",		69*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"dtp_empty_out",		70*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"slide_in",			71*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"mantle",				72*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"camera_sprint_loop",	73*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"camera_dtp_in",		74*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"camera_dtp_loop",		75*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"camera_dtp_out",		76*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"camera_mantle",		77*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"fire_left",			78*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"lastshot_left",		79*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"finalshot_left",		80*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"idle_left",			81*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"empty_idle_left",		82*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_empty_left",	83*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"reload_left",			84*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_up",				85*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_down",			86*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{"ads_up_other_scope",	87*sizeof(void*),	ASSET_ENTRY_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponHideTagEntries[] = {
	{"1",	0*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"2",	1*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"3",	2*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"4",	3*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"5",	4*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"6",	5*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"7",	6*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"8",	7*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"9",	8*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"10",	9*sizeof(ScriptString),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"11",	10*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"12",	11*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"13",	12*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"14",	13*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"15",	14*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"16",	15*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"17",	16*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"18",	17*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"19",	18*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"20",	19*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"21",	20*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"22",	21*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"23",	22*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"24",	23*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"25",	24*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"26",	25*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"27",	26*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"28",	27*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"29",	28*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"30",	29*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"31",	30*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"32",	31*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponAttachModelEntries[] = {
	{"1",	0*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"2",	1*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"3",	2*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"4",	3*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"5",	4*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"6",	5*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"7",	6*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"8",	7*sizeof(void*),	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponAttachModelTagEntries[] = {
	{"1",	0*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"2",	1*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"3",	2*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"4",	3*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"5",	4*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"6",	5*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"7",	6*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"8",	7*sizeof(ScriptString),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry WeaponVariantDefEntries[] = {
	{"iVariantCount",				offsetof(WeaponVariantDef, iVariantCount),					ASSET_ENTRY_INT,0,0},
	{"",							offsetof(WeaponVariantDef, weapDef),						ASSET_ENTRY_CONTAINED,		(AssetEntry*)WeaponDefEntries,0},
	{"szDisplayName",				offsetof(WeaponVariantDef, szDisplayName),					ASSET_ENTRY_STRING,0,0},
	{"szAltWeaponName",				offsetof(WeaponVariantDef, szAltWeaponName),				ASSET_ENTRY_STRING,0,0},
	{"szAttachmentUnique",			offsetof(WeaponVariantDef, szAttachmentUnique),				ASSET_ENTRY_STRING,0,0},
	{"attachment",					offsetof(WeaponVariantDef, attachments),					ASSET_ENTRY_CONTAINED,		WeaponAttachmentDefEntries,0},
	{"uniqueAttachment",			offsetof(WeaponVariantDef, attachmentUniques),				ASSET_ENTRY_CONTAINED,		WeaponUniqueAttachmentDefEntries,0},
	{"szXAnim_",					offsetof(WeaponVariantDef, szXAnims),						ASSET_ENTRY_CONTAINED,		WeaponXAnimsEntries,0},
	{"hideTag",						offsetof(WeaponVariantDef, hideTags),						ASSET_ENTRY_CONTAINED,		WeaponHideTagEntries,0},
	{"attachViewModel",				offsetof(WeaponVariantDef, attachViewModel),				ASSET_ENTRY_CONTAINED,		WeaponAttachModelEntries,0},
	{"attachWorldModel",			offsetof(WeaponVariantDef, attachWorldModel),				ASSET_ENTRY_CONTAINED,		WeaponAttachModelEntries,0},
	{"attachViewModelTag",			offsetof(WeaponVariantDef, attachViewModelTag),				ASSET_ENTRY_CONTAINED,		WeaponAttachModelTagEntries,0},
	{"attachWorldModelTag",			offsetof(WeaponVariantDef, attachWorldModelTag),			ASSET_ENTRY_CONTAINED,		WeaponAttachModelTagEntries,0},
	{"attachViewModelOffset1",		offsetof(WeaponVariantDef, attachViewModelOffset[0]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset2",		offsetof(WeaponVariantDef, attachViewModelOffset[1]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset3",		offsetof(WeaponVariantDef, attachViewModelOffset[2]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset4",		offsetof(WeaponVariantDef, attachViewModelOffset[3]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset5",		offsetof(WeaponVariantDef, attachViewModelOffset[4]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset6",		offsetof(WeaponVariantDef, attachViewModelOffset[5]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset7",		offsetof(WeaponVariantDef, attachViewModelOffset[6]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelOffset8",		offsetof(WeaponVariantDef, attachViewModelOffset[7]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset1",		offsetof(WeaponVariantDef, attachWorldModelOffset[0]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset2",		offsetof(WeaponVariantDef, attachWorldModelOffset[1]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset3",		offsetof(WeaponVariantDef, attachWorldModelOffset[2]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset4",		offsetof(WeaponVariantDef, attachWorldModelOffset[3]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset5",		offsetof(WeaponVariantDef, attachWorldModelOffset[4]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset6",		offsetof(WeaponVariantDef, attachWorldModelOffset[5]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset7",		offsetof(WeaponVariantDef, attachWorldModelOffset[6]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachWorldModelOffset8",		offsetof(WeaponVariantDef, attachWorldModelOffset[7]),		ASSET_ENTRY_EMBEDDED,		OffsetEntry,0},
	{"attachViewModelRotation1",	offsetof(WeaponVariantDef, attachViewModelRotation[0]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation2",	offsetof(WeaponVariantDef, attachViewModelRotation[1]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation3",	offsetof(WeaponVariantDef, attachViewModelRotation[2]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation4",	offsetof(WeaponVariantDef, attachViewModelRotation[3]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation5",	offsetof(WeaponVariantDef, attachViewModelRotation[4]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation6",	offsetof(WeaponVariantDef, attachViewModelRotation[5]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation7",	offsetof(WeaponVariantDef, attachViewModelRotation[6]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachViewModelRotation8",	offsetof(WeaponVariantDef, attachViewModelRotation[7]),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation1",	offsetof(WeaponVariantDef, attachWorldModelRotation[0]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation2",	offsetof(WeaponVariantDef, attachWorldModelRotation[1]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation3",	offsetof(WeaponVariantDef, attachWorldModelRotation[2]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation4",	offsetof(WeaponVariantDef, attachWorldModelRotation[3]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation5",	offsetof(WeaponVariantDef, attachWorldModelRotation[4]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation6",	offsetof(WeaponVariantDef, attachWorldModelRotation[5]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation7",	offsetof(WeaponVariantDef, attachWorldModelRotation[6]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"attachWorldModelRotation8",	offsetof(WeaponVariantDef, attachWorldModelRotation[7]),	ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"stowedModelOffset",			offsetof(WeaponVariantDef, stowedModelOffsets),				ASSET_ENTRY_EMBEDDED,		VectorEntry,0},
	{"stowedModelRotation",			offsetof(WeaponVariantDef, stowedModelRotations),			ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"altWeaponIndex",				offsetof(WeaponVariantDef, altWeaponIndex),					ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"iAttachments",				offsetof(WeaponVariantDef, iAttachments),					ASSET_ENTRY_INT,0,0},
	{"bIgnoreAttachments",			offsetof(WeaponVariantDef, bIgnoreAttachments),				ASSET_ENTRY_BOOL,0,0},
	{"iClipSize",					offsetof(WeaponVariantDef, iClipSize),						ASSET_ENTRY_INT,0,0},
	{"iReloadTime",					offsetof(WeaponVariantDef, iReloadTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadEmptyTime",			offsetof(WeaponVariantDef, iReloadEmptyTime),				ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadQuickTime",			offsetof(WeaponVariantDef, iReloadQuickTime),				ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iReloadQuickEmptyTime",		offsetof(WeaponVariantDef, iReloadQuickEmptyTime),			ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iAdsTransInTime",				offsetof(WeaponVariantDef, iAdsTransInTime),				ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iAdsTransOutTime",			offsetof(WeaponVariantDef, iAdsTransOutTime),				ASSET_ENTRY_TIME_AS_INT,0,0},
	{"iAltRaiseTime",				offsetof(WeaponVariantDef, iAltRaiseTime),					ASSET_ENTRY_TIME_AS_INT,0,0},
	{"szAmmoDisplayName",			offsetof(WeaponVariantDef, szAmmoDisplayName),				ASSET_ENTRY_STRING,0,0},
	{"szAmmoName",					offsetof(WeaponVariantDef, szAmmoName),						ASSET_ENTRY_STRING,0,0},
	{"iAmmoIndex",					offsetof(WeaponVariantDef, iAmmoIndex),						ASSET_ENTRY_INT,0,0},
	{"szClipName",					offsetof(WeaponVariantDef, szClipName),						ASSET_ENTRY_STRING,0,0},
	{"iClipIndex",					offsetof(WeaponVariantDef, iClipIndex),						ASSET_ENTRY_INT,0,0},
	{"fAimAssistRangeAds",			offsetof(WeaponVariantDef, fAimAssistRangeAds),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsSwayHorizScale",			offsetof(WeaponVariantDef, fAdsSwayHorizScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsSwayVertScale",			offsetof(WeaponVariantDef, fAdsSwayVertScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsViewKickCenterSpeed",		offsetof(WeaponVariantDef, fAdsViewKickCenterSpeed),		ASSET_ENTRY_FLOAT,0,0},
	{"fHipViewKickCenterSpeed",		offsetof(WeaponVariantDef, fHipViewKickCenterSpeed),		ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomFov1",				offsetof(WeaponVariantDef, fAdsZoomFov[0]),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomFov2",				offsetof(WeaponVariantDef, fAdsZoomFov[1]),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomFov3",				offsetof(WeaponVariantDef, fAdsZoomFov[2]),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomInFrac",				offsetof(WeaponVariantDef, fAdsZoomInFrac),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomOutFrac",				offsetof(WeaponVariantDef, fAdsZoomOutFrac),				ASSET_ENTRY_FLOAT,0,0},
	{"fOverlayAlphaScale",			offsetof(WeaponVariantDef, fOverlayAlphaScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fOOPosAnimLength1",			offsetof(WeaponVariantDef, fOOPosAnimLength[0]),			ASSET_ENTRY_FLOAT,0,0},
	{"fOOPosAnimLength2",			offsetof(WeaponVariantDef, fOOPosAnimLength[1]),			ASSET_ENTRY_FLOAT,0,0},
	{"bSilenced",					offsetof(WeaponVariantDef, bSilenced),						ASSET_ENTRY_BOOL,0,0},
	{"bDualMag",					offsetof(WeaponVariantDef, bDualMag),						ASSET_ENTRY_BOOL,0,0},
	{"bInfraRed",					offsetof(WeaponVariantDef, bInfraRed),						ASSET_ENTRY_BOOL,0,0},
	{"bTVGuided",					offsetof(WeaponVariantDef, bTVGuided),						ASSET_ENTRY_BOOL,0,0},
	{"perks1",						offsetof(WeaponVariantDef, perks[0]),						ASSET_ENTRY_INT,0,0},
	{"perks2",						offsetof(WeaponVariantDef, perks[1]),						ASSET_ENTRY_INT,0,0},
	{"bAntiQuickScope",				offsetof(WeaponVariantDef, bAntiQuickScope),				ASSET_ENTRY_BOOL,0,0},
	{"overlayMaterial",				offsetof(WeaponVariantDef, overlayMaterial),				ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"overlayMaterialLowRes",		offsetof(WeaponVariantDef, overlayMaterialLowRes),			ASSET_ENTRY_ASSET_PTR,		(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"dpadIcon",					offsetof(WeaponVariantDef, dpadIcon),						ASSET_ENTRY_EMBEDDED,		IconEntry,0},
	{"noAmmoOnDpadIcon",			offsetof(WeaponVariantDef, noAmmoOnDpadIcon),				ASSET_ENTRY_BOOL,0,0},
	{"mmsWeapon",					offsetof(WeaponVariantDef, mmsWeapon),						ASSET_ENTRY_BOOL,0,0},
	{"mssInScope",					offsetof(WeaponVariantDef, mmsInScope),						ASSET_ENTRY_BOOL,0,0},
	{"mmsFOV",						offsetof(WeaponVariantDef, mmsFOV),							ASSET_ENTRY_FLOAT,0,0},
	{"mmsAspect",					offsetof(WeaponVariantDef, mmsAspect),						ASSET_ENTRY_FLOAT,0,0},
	{"mmsMaxDist",					offsetof(WeaponVariantDef, mmsMaxDist),						ASSET_ENTRY_FLOAT,0,0},
	{"ikLeftHandIdlePos",			offsetof(WeaponVariantDef, ikLeftHandIdlePos),				ASSET_ENTRY_EMBEDDED,		VectorEntry,0},
	{"ikLeftHandOffset",			offsetof(WeaponVariantDef, ikLeftHandOffset),				ASSET_ENTRY_EMBEDDED,		VectorEntry,0},
	{"ikLeftHandRotation",			offsetof(WeaponVariantDef, ikLeftHandRotation),				ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"bUsingLeftHandProneIK",		offsetof(WeaponVariantDef, bUsingLeftHandProneIK),			ASSET_ENTRY_BOOL,0,0},
	{"ikLeftHandProneOffset",		offsetof(WeaponVariantDef, ikLeftHandProneOffset),			ASSET_ENTRY_EMBEDDED,		VectorEntry,0},
	{"ikLeftHandProneRotation",		offsetof(WeaponVariantDef, ikLeftHandProneRotation),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{"ikLeftHandUiViewerOffset",	offsetof(WeaponVariantDef, ikLeftHandUiViewerOffset),		ASSET_ENTRY_EMBEDDED,		VectorEntry,0},
	{"ikLeftHandUiViewerRotation",	offsetof(WeaponVariantDef, ikLeftHandUiViewerRotation),		ASSET_ENTRY_EMBEDDED,		AngleEntry,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_WeaponVariantDefAsset_t Load_WeaponVariantDefAsset = (Load_WeaponVariantDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x29C)) + 0xA4));

int WeaponVariantDef::dumpWeaponVariantDef()
{
	CreateDirectoryB(va("game:\\dump\\weapons\\mp\\%s", szInternalName));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "weapon", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog,"WEAPONFILE");

	for(int i = 0; WeaponVariantDefEntries[i].name; i++)
		DumpAssetEntry(writeLog, WeaponVariantDefEntries[i].type, WeaponVariantDefEntries[i].name, (void*)((int)(this) + WeaponVariantDefEntries[i].offset), WeaponVariantDefEntries[i].next, WeaponVariantDefEntries[i].enumCount);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

void Load_WeaponVariantDefAssetHook(WeaponVariantDef ** input)
{
	WeaponVariantDef * currentWeaponVariantDef = *input;
	//currentWeaponVariantDef->dumpWeaponVariantDef();

	//Can we load this weapon custom?
	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
	sprintf(theAssetBuffer, "game:\\raw\\weapons\\mp\\%s", currentWeaponVariantDef->szInternalName);
	if(fileExists(theAssetBuffer))
	{
		HANDLE weaponDefFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(weaponDefFile, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (numberOfBytesRead + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[numberOfBytesRead + 1];

		ZeroMemory(myBuffer, numberOfBytesRead + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(weaponDefFile != INVALID_HANDLE_VALUE && ReadFile(weaponDefFile, myBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0))
		{
			char * currentName = 0, * currentValue = 0;

			CloseHandle(weaponDefFile);
			char * currentToken = improved_strtok(myBuffer,"\\");

			if(!strcmp(currentToken, "WEAPONFILE"))
			for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
			{
				currentName = currentToken;
				currentValue = improved_strtok(NULL,"\\");

				if(!WriteAssetEntry((AssetEntry*)WeaponVariantDefEntries, currentName, currentValue, currentWeaponVariantDef))
					printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "weapon", currentWeaponVariantDef->szInternalName);
			}
			else
				printf("%s is not a %s file\n", currentWeaponVariantDef->szInternalName, "weapon");
		}

		if(allocatedBuffer) delete[] myBuffer;
	}
	usingAssetBuffer = false;

	Load_WeaponVariantDefAssetSaveStub(input);
}
#pragma endregion

#pragma region attachment (0x1E)
AssetEntry WeaponAttachmentEntries[] = {
	{"szDisplayName",					offsetof(WeaponAttachment, szDisplayName),					ASSET_ENTRY_STRING,0,0},
	{"attachmentType",					offsetof(WeaponAttachment, attachmentType),					ASSET_ENTRY_ENUM,				(AssetEntry*)s_attachmentNames,			ATTACHMENT_TYPE_COUNT},
	{"attachmentPoint",					offsetof(WeaponAttachment, attachmentPoint),					ASSET_ENTRY_ENUM,				(AssetEntry*)s_attachmentPointNames,	ATTACHMENT_POINT_COUNT},
	{"penetrateType",					offsetof(WeaponAttachment, penetrateType),					ASSET_ENTRY_ENUM,				(AssetEntry*)penetrateTypeNames,		PENETRATE_TYPE_MAX},
	{"fireType",						offsetof(WeaponAttachment, fireType),						ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapFireTypeNames,		WEAPON_FIRETYPE_MAX},
	{"firstRaisePriority",				offsetof(WeaponAttachment, firstRaisePriority),				ASSET_ENTRY_INT,0,0},
	{"fHipIdleAmount",					offsetof(WeaponAttachment, fHipIdleAmount),					ASSET_ENTRY_FLOAT,0,0},
	{"bAltWeaponAdsOnly",				offsetof(WeaponAttachment, bAltWeaponAdsOnly),				ASSET_ENTRY_BOOL,0,0},
	{"bAltWeaponDisableSwitching",		offsetof(WeaponAttachment, bAltWeaponDisableSwitching),		ASSET_ENTRY_BOOL,0,0},
	{"altScopeADSTransInTime",			offsetof(WeaponAttachment, altScopeADSTransInTime),			ASSET_ENTRY_INT,0,0},
	{"altScopeADSTransOutTime",			offsetof(WeaponAttachment, altScopeADSTransOutTime),		ASSET_ENTRY_INT,0,0},
	{"bSilenced",						offsetof(WeaponAttachment, bSilenced),						ASSET_ENTRY_BOOL,0,0},
	{"bDualMag",						offsetof(WeaponAttachment, bDualMag),						ASSET_ENTRY_BOOL,0,0},
	{"laserSight",						offsetof(WeaponAttachment, laserSight),						ASSET_ENTRY_BOOL,0,0},
	{"bInfraRed",						offsetof(WeaponAttachment, bInfraRed),						ASSET_ENTRY_BOOL,0,0},
	{"bUseAsMelee",						offsetof(WeaponAttachment, bUseAsMelee),					ASSET_ENTRY_BOOL,0,0},
	{"bDualWield",						offsetof(WeaponAttachment, bDualWield),						ASSET_ENTRY_BOOL,0,0},
	{"sharedAmmo",						offsetof(WeaponAttachment, sharedAmmo),						ASSET_ENTRY_BOOL,0,0},
	{"fDamageRangeScale",				offsetof(WeaponAttachment, fDamageRangeScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomFov1",					offsetof(WeaponAttachment, fAdsZoomFov[0]),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomFov2",					offsetof(WeaponAttachment, fAdsZoomFov[1]),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomFov3",					offsetof(WeaponAttachment, fAdsZoomFov[2]),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomInFrac",					offsetof(WeaponAttachment, fAdsZoomInFrac),					ASSET_ENTRY_FLOAT,0,0},
	{"fAdsZoomOutFrac",					offsetof(WeaponAttachment, fAdsZoomOutFrac),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsTransInTimeScale",			offsetof(WeaponAttachment, fAdsTransInTimeScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fAdsTransOutTimeScale",			offsetof(WeaponAttachment, fAdsTransOutTimeScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fAdsRecoilReductionRate",			offsetof(WeaponAttachment, fAdsRecoilReductionRate),		ASSET_ENTRY_FLOAT,0,0},
	{"fAdsRecoilReductionLimit",		offsetof(WeaponAttachment, fAdsRecoilReductionLimit),		ASSET_ENTRY_FLOAT,0,0},
	{"fAdsViewKickCenterSpeedScale",	offsetof(WeaponAttachment, fAdsViewKickCenterSpeedScale),	ASSET_ENTRY_FLOAT,0,0},
	{"fAdsIdleAmountScale",				offsetof(WeaponAttachment, fAdsIdleAmountScale),			ASSET_ENTRY_FLOAT,0,0},
	{"swayOverride",					offsetof(WeaponAttachment, swayOverride),					ASSET_ENTRY_BOOL,0,0},
	{"swayMaxAngle",					offsetof(WeaponAttachment, swayMaxAngle),					ASSET_ENTRY_FLOAT,0,0},
	{"swayLerpSpeed",					offsetof(WeaponAttachment, swayLerpSpeed),					ASSET_ENTRY_FLOAT,0,0},
	{"swayPitchScale",					offsetof(WeaponAttachment, swayPitchScale),					ASSET_ENTRY_FLOAT,0,0},
	{"swayYawScale",					offsetof(WeaponAttachment, swayYawScale),					ASSET_ENTRY_FLOAT,0,0},
	{"swayHorizScale",					offsetof(WeaponAttachment, swayHorizScale),					ASSET_ENTRY_FLOAT,0,0},
	{"swayVertScale",					offsetof(WeaponAttachment, swayVertScale),					ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayOverride",					offsetof(WeaponAttachment, adsSwayOverride),				ASSET_ENTRY_BOOL,0,0},
	{"adsSwayMaxAngle",					offsetof(WeaponAttachment, adsSwayMaxAngle),				ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayLerpSpeed",				offsetof(WeaponAttachment, adsSwayLerpSpeed),				ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayPitchScale",				offsetof(WeaponAttachment, adsSwayPitchScale),				ASSET_ENTRY_FLOAT,0,0},
	{"adsSwayYawScale",					offsetof(WeaponAttachment, adsSwayYawScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsSwayHorizScale",				offsetof(WeaponAttachment, fAdsSwayHorizScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fAdsSwayVertScale",				offsetof(WeaponAttachment, fAdsSwayVertScale),				ASSET_ENTRY_FLOAT,0,0},
	{"adsMoveSpeedScale",				offsetof(WeaponAttachment, adsMoveSpeedScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fHipSpreadMinScale",				offsetof(WeaponAttachment, fHipSpreadMinScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fHipSpreadMaxScale",				offsetof(WeaponAttachment, fHipSpreadMaxScale),				ASSET_ENTRY_FLOAT,0,0},
	{"strafeRotR",						offsetof(WeaponAttachment, strafeRotR),						ASSET_ENTRY_FLOAT,0,0},
	{"standMoveF",						offsetof(WeaponAttachment, standMoveF),						ASSET_ENTRY_FLOAT,0,0},
	{"vStandRot",						offsetof(WeaponAttachment, vStandRot),						ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"fFireTimeScale",					offsetof(WeaponAttachment, fFireTimeScale),					ASSET_ENTRY_FLOAT,0,0},
	{"fReloadTimeScale",				offsetof(WeaponAttachment, fReloadTimeScale),				ASSET_ENTRY_FLOAT,0,0},
	{"fReloadEmptyTimeScale",			offsetof(WeaponAttachment, fReloadEmptyTimeScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fReloadAddTimeScale",				offsetof(WeaponAttachment, fReloadAddTimeScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fReloadQuickTimeScale",			offsetof(WeaponAttachment, fReloadQuickTimeScale),			ASSET_ENTRY_FLOAT,0,0},
	{"fReloadQuickEmptyTimeScale",		offsetof(WeaponAttachment, fReloadQuickEmptyTimeScale),		ASSET_ENTRY_FLOAT,0,0},
	{"fReloadQuickAddTimeScale",		offsetof(WeaponAttachment, fReloadQuickAddTimeScale),		ASSET_ENTRY_FLOAT,0,0},
	{"mmsWeapon",						offsetof(WeaponAttachment, mmsWeapon),						ASSET_ENTRY_BOOL,0,0},
	{"mmsInScope",						offsetof(WeaponAttachment, mmsInScope),						ASSET_ENTRY_BOOL,0,0},
	{"mmsFOV",							offsetof(WeaponAttachment, mmsFOV),							ASSET_ENTRY_FLOAT,0,0},
	{"mmsAspect",						offsetof(WeaponAttachment, mmsAspect),						ASSET_ENTRY_FLOAT,0,0},
	{"mmsMaxDist",						offsetof(WeaponAttachment, mmsMaxDist),						ASSET_ENTRY_FLOAT,0,0},
	{"clipSizeScale",					offsetof(WeaponAttachment, clipSizeScale),					ASSET_ENTRY_FLOAT,0,0},
	{"iClipSize",						offsetof(WeaponAttachment, iClipSize),						ASSET_ENTRY_INT,0,0},
	{"stackFire",						offsetof(WeaponAttachment, stackFire),						ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"stackFireSpread",					offsetof(WeaponAttachment, stackFireSpread),				ASSET_ENTRY_FLOAT,0,0},
	{"stackFireAccuracyDecay",			offsetof(WeaponAttachment, stackFireAccuracyDecay),			ASSET_ENTRY_FLOAT,0,0},
	{"perks1",							offsetof(WeaponAttachment, perks[0]),						ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"perks2",							offsetof(WeaponAttachment, perks[1]),						ASSET_ENTRY_UNSIGNED_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_WeaponAttachmentAsset_t Load_WeaponAttachmentAsset = (Load_WeaponAttachmentAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x2B8)) + 0xA4));

int WeaponAttachment::dumpWeaponAttachment()
{
	CreateDirectoryB(va("game:\\dump\\attachments\\mp\\%s", name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "weapon", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog,"ATTACHMENTFILE");

	for(int i = 0; WeaponAttachmentEntries[i].name; i++)
		DumpAssetEntry(writeLog, WeaponAttachmentEntries[i].type, WeaponAttachmentEntries[i].name, (void*)((int)(this) + WeaponAttachmentEntries[i].offset), WeaponAttachmentEntries[i].next, WeaponAttachmentEntries[i].enumCount);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

void Load_WeaponAttachmentAssetHook(WeaponAttachment ** input)
{
	WeaponAttachment * currentWeaponAttachment = *input;
	//currentWeaponAttachment->dumpWeaponAttachment();

	//Can we load this weapon custom?
	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
	sprintf(theAssetBuffer, "game:\\raw\\attachments\\mp\\%s", currentWeaponAttachment->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE weaponAttachmentFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(weaponAttachmentFile, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (numberOfBytesRead + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[numberOfBytesRead + 1];

		ZeroMemory(myBuffer, numberOfBytesRead + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(weaponAttachmentFile != INVALID_HANDLE_VALUE && ReadFile(weaponAttachmentFile, myBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0))
		{
			char * currentName = 0, * currentValue = 0;

			CloseHandle(weaponAttachmentFile);
			char * currentToken = improved_strtok(myBuffer,"\\");

			if(!strcmp(currentToken, "ATTACHMENTFILE"))
			for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
			{
				currentName = currentToken;
				currentValue = improved_strtok(NULL,"\\");

				if(!WriteAssetEntry((AssetEntry*)WeaponAttachmentEntries, currentName, currentValue, currentWeaponAttachment))
					printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "attachment", currentWeaponAttachment->name);
			}
			else
				printf("%s is not a %s file\n", currentWeaponAttachment->name, "attachment");
		}

		if(allocatedBuffer) delete[] myBuffer;
	}
	usingAssetBuffer = false;

	Load_WeaponAttachmentAssetSaveStub(input);
}
#pragma endregion

#pragma region attachmentunique (0x1F)
AssetEntry WeaponAttachmentUniqueEntries[] = {
	{"attachmentType",						offsetof(WeaponAttachmentUnique, attachmentType),						ASSET_ENTRY_ENUM,				(AssetEntry*)s_attachmentNames,			ATTACHMENT_TYPE_COUNT},
	{"siblingLink",							offsetof(WeaponAttachmentUnique, siblingLink),							ASSET_ENTRY_INT,0,0},
	{"childLink",							offsetof(WeaponAttachmentUnique, childLink),							ASSET_ENTRY_INT,0,0},
	{"combinedAttachmentTypeMask",			offsetof(WeaponAttachmentUnique, combinedAttachmentTypeMask),			ASSET_ENTRY_INT,0,0},
	{"szAltWeaponName",						offsetof(WeaponAttachmentUnique, szAltWeaponName),						ASSET_ENTRY_STRING,0,0},
	{"altWeaponIndex",						offsetof(WeaponAttachmentUnique, altWeaponIndex),						ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"szDualWieldWeaponName",				offsetof(WeaponAttachmentUnique, szDualWieldWeaponName),				ASSET_ENTRY_STRING,0,0},
	{"dualWieldWeaponIndex",				offsetof(WeaponAttachmentUnique, dualWieldWeaponIndex),					ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"hideTag",								offsetof(WeaponAttachmentUnique, hideTags),								ASSET_ENTRY_CONTAINED,			WeaponHideTagEntries,0},
	{"viewModel",							offsetof(WeaponAttachmentUnique, viewModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"viewModelAdditional",					offsetof(WeaponAttachmentUnique, viewModelAdditional),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"viewModelADS",						offsetof(WeaponAttachmentUnique, viewModelADS),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"worldModel",							offsetof(WeaponAttachmentUnique, worldModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"worldModelAdditional",				offsetof(WeaponAttachmentUnique, worldModelAdditional),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"viewModelTag",						offsetof(WeaponAttachmentUnique, viewModelTag),							ASSET_ENTRY_STRING,0,0},
	{"worldModelTag",						offsetof(WeaponAttachmentUnique, worldModelTag),						ASSET_ENTRY_STRING,0,0},
	{"viewModelOffsets",					offsetof(WeaponAttachmentUnique, viewModelOffsets),						ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"worldModelOffsets",					offsetof(WeaponAttachmentUnique, worldModelOffsets),					ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"viewModelRotations",					offsetof(WeaponAttachmentUnique, viewModelRotations),					ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"worldModelRotations",					offsetof(WeaponAttachmentUnique, worldModelRotations),					ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"viewModelAddOffsets",					offsetof(WeaponAttachmentUnique, viewModelAddOffsets),					ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"worldModelAddOffsets",				offsetof(WeaponAttachmentUnique, worldModelAddOffsets),					ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"viewModelAddRotations",				offsetof(WeaponAttachmentUnique, viewModelAddRotations),				ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"worldModelAddRotations",				offsetof(WeaponAttachmentUnique, worldModelAddRotations),				ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"weaponCamo",							offsetof(WeaponAttachmentUnique, weaponCamo),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_WEAPON_CAMO,0},
	{"disableBaseWeaponAttachment",			offsetof(WeaponAttachmentUnique, disableBaseWeaponAttachment),			ASSET_ENTRY_BOOL,0,0},
	{"disableBaseWeaponClip",				offsetof(WeaponAttachmentUnique, disableBaseWeaponClip),				ASSET_ENTRY_BOOL,0,0},
	{"overrideBaseWeaponAttachmentOffsets",	offsetof(WeaponAttachmentUnique, overrideBaseWeaponAttachmentOffsets),	ASSET_ENTRY_BOOL,0,0},
	{"viewModelOffsetBaseAttachment",		offsetof(WeaponAttachmentUnique, viewModelOffsetBaseAttachment),		ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"worldModelOffsetBaseAttachment",		offsetof(WeaponAttachmentUnique, worldModelOffsetBaseAttachment),		ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"overlayMaterial",						offsetof(WeaponAttachmentUnique, overlayMaterial),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"overlayMaterialLowRes",				offsetof(WeaponAttachmentUnique, overlayMaterialLowRes),				ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"overlayReticle",						offsetof(WeaponAttachmentUnique, overlayReticle),						ASSET_ENTRY_ENUM,				(AssetEntry*)szWeapOverlayReticleNames,		WEAPOVERLAYRETICLE_MAX},
	{"iFirstRaiseTime",						offsetof(WeaponAttachmentUnique, iFirstRaiseTime),						ASSET_ENTRY_INT,0,0},
	{"iAltRaiseTime",						offsetof(WeaponAttachmentUnique, iAltRaiseTime),						ASSET_ENTRY_INT,0,0},
	{"iAltDropTime",						offsetof(WeaponAttachmentUnique, iAltDropTime),							ASSET_ENTRY_INT,0,0},
	{"iReloadAmmoAdd",						offsetof(WeaponAttachmentUnique, iReloadAmmoAdd),						ASSET_ENTRY_INT,0,0},
	{"iReloadStartAdd",						offsetof(WeaponAttachmentUnique, iReloadStartAdd),						ASSET_ENTRY_INT,0,0},
	{"bSegmentedReload",					offsetof(WeaponAttachmentUnique, bSegmentedReload),						ASSET_ENTRY_BOOL,0,0},
	{"szXAnim_",							offsetof(WeaponVariantDef, szXAnims),									ASSET_ENTRY_CONTAINED,			WeaponXAnimsEntries,0},
	{"animationOverrides1",					offsetof(WeaponAttachmentUnique, animationOverrides[0]),				ASSET_ENTRY_INT,0,0},
	{"animationOverrides2",					offsetof(WeaponAttachmentUnique, animationOverrides[1]),				ASSET_ENTRY_INT,0,0},
	{"animationOverrides3",					offsetof(WeaponAttachmentUnique, animationOverrides[2]),				ASSET_ENTRY_INT,0,0},
	{"",									offsetof(WeaponAttachmentUnique, locationDamageMultipliers),			ASSET_ENTRY_CONTAINED,			LocationDamageEntries,0},
	{"soundOverrides",						offsetof(WeaponAttachmentUnique, soundOverrides),						ASSET_ENTRY_INT,0,0},
	{"fireSound",							offsetof(WeaponAttachmentUnique, fireSound),							ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"fireLoopSound",						offsetof(WeaponAttachmentUnique, fireLoopSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"fireLoopEndSound",					offsetof(WeaponAttachmentUnique, fireLoopEndSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"fireStartSound",						offsetof(WeaponAttachmentUnique, fireStartSound),						ASSET_ENTRY_STRING,0,0},
	{"fireStopSound",						offsetof(WeaponAttachmentUnique, fireStopSound),						ASSET_ENTRY_STRING,0,0},
	{"fireStartSoundPlayer",				offsetof(WeaponAttachmentUnique, fireStartSoundPlayer),					ASSET_ENTRY_STRING,0,0},
	{"fireStopSoundPlayer",					offsetof(WeaponAttachmentUnique, fireStopSoundPlayer),					ASSET_ENTRY_STRING,0,0},
	{"fireLastSound",						offsetof(WeaponAttachmentUnique, fireLastSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"fireKillcamSound",					offsetof(WeaponAttachmentUnique, fireKillcamSound),						ASSET_ENTRY_EMBEDDED,			ClientSideSoundEntry,0},
	{"effectOverrides",						offsetof(WeaponAttachmentUnique, effectOverrides),						ASSET_ENTRY_INT,0,0},
	{"viewFlashEffect",						offsetof(WeaponAttachmentUnique, viewFlashEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"worldFlashEffect",					offsetof(WeaponAttachmentUnique, worldFlashEffect),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"tracerType",							offsetof(WeaponAttachmentUnique, tracerType),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_TRACER,0},
	{"enemyTracerType",						offsetof(WeaponAttachmentUnique, enemyTracerType),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_TRACER,0},
	{"adsDofStart",							offsetof(WeaponAttachmentUnique, adsDofStart),							ASSET_ENTRY_FLOAT,0,0},
	{"adsDofEnd",							offsetof(WeaponAttachmentUnique, adsDofEnd),							ASSET_ENTRY_FLOAT,0,0},
	{"iAmmoIndex",							offsetof(WeaponAttachmentUnique, iAmmoIndex),							ASSET_ENTRY_INT,0,0},
	{"iClipIndex",							offsetof(WeaponAttachmentUnique, iClipIndex),							ASSET_ENTRY_INT,0,0},
	{"bOverrideLeftHandIK",					offsetof(WeaponAttachmentUnique, bOverrideLeftHandIK),					ASSET_ENTRY_BOOL,0,0},
	{"bOverrideLeftHandProneIK",			offsetof(WeaponAttachmentUnique, bOverrideLeftHandProneIK),				ASSET_ENTRY_BOOL,0,0},
	{"ikLeftHandOffset",					offsetof(WeaponAttachmentUnique, ikLeftHandOffset),						ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"ikLeftHandRotation",					offsetof(WeaponAttachmentUnique, ikLeftHandRotation),					ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"ikLeftHandProneOffset",				offsetof(WeaponAttachmentUnique, ikLeftHandProneOffset),				ASSET_ENTRY_EMBEDDED,			VectorEntry,0},
	{"ikLeftHandProneRotation",				offsetof(WeaponAttachmentUnique, ikLeftHandProneRotation),				ASSET_ENTRY_EMBEDDED,			AngleEntry,0},
	{"customFloat1",						offsetof(WeaponAttachmentUnique, customFloat[0]),						ASSET_ENTRY_FLOAT,0,0},
	{"customFloat2",						offsetof(WeaponAttachmentUnique, customFloat[1]),						ASSET_ENTRY_FLOAT,0,0},
	{"customFloat3",						offsetof(WeaponAttachmentUnique, customFloat[2]),						ASSET_ENTRY_FLOAT,0,0},
	{"customBool1",							offsetof(WeaponAttachmentUnique, customBool[0]),						ASSET_ENTRY_INT,0,0},
	{"customBool2",							offsetof(WeaponAttachmentUnique, customBool[1]),						ASSET_ENTRY_INT,0,0},
	{"customBool3",							offsetof(WeaponAttachmentUnique, customBool[2]),						ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_WeaponAttachmentUniqueAsset_t Load_WeaponAttachmentUniqueAsset = (Load_WeaponAttachmentUniqueAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x2D4)) + 0xA4));

int WeaponAttachmentUnique::dumpWeaponAttachmentUnique()
{
	CreateDirectoryB(va("game:\\dump\\attachments_unq\\mp\\%s", szInternalName));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "weapon", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog,"ATTACHMENTUNQFILE");

	for(int i = 0; WeaponAttachmentUniqueEntries[i].name; i++)
		DumpAssetEntry(writeLog, WeaponAttachmentUniqueEntries[i].type, WeaponAttachmentUniqueEntries[i].name, (void*)((int)(this) + WeaponAttachmentUniqueEntries[i].offset), WeaponAttachmentUniqueEntries[i].next, WeaponAttachmentUniqueEntries[i].enumCount);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

void Load_WeaponAttachmentUniqueAssetHook(WeaponAttachmentUnique ** input)
{
	WeaponAttachmentUnique * currentWeaponAttachmentUnique = *input;
	//currentWeaponAttachmentUnique->dumpWeaponAttachmentUnique();

	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
	sprintf(theAssetBuffer, "game:\\raw\\attachments_unq\\mp\\%s", currentWeaponAttachmentUnique->szInternalName);
	if(fileExists(theAssetBuffer))
	{
		HANDLE weaponAttachmentUniqueFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(weaponAttachmentUniqueFile, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (numberOfBytesRead + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[numberOfBytesRead + 1];

		ZeroMemory(myBuffer, numberOfBytesRead + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(weaponAttachmentUniqueFile != INVALID_HANDLE_VALUE && ReadFile(weaponAttachmentUniqueFile, myBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0))
		{
			char * currentName = 0, * currentValue = 0;

			CloseHandle(weaponAttachmentUniqueFile);
			char * currentToken = improved_strtok(myBuffer,"\\");

			if(!strcmp(currentToken, "ATTACHMENTUNQFILE"))
			for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
			{
				currentName = currentToken;
				currentValue = improved_strtok(NULL,"\\");

				if(!WriteAssetEntry((AssetEntry*)WeaponAttachmentUniqueEntries, currentName, currentValue, currentWeaponAttachmentUnique))
					printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "attachmentunique", currentWeaponAttachmentUnique->szInternalName);
			}
			else
				printf("%s is not a %s file\n", currentWeaponAttachmentUnique->szInternalName, "attachmentunique");
		}

		if(allocatedBuffer) delete[] myBuffer;
	}
	usingAssetBuffer = false;

	Load_WeaponAttachmentUniqueAssetSaveStub(input);
}
#pragma endregion

#pragma region rawfile (0x2A)
int RawFile::dumpRawfile()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
	//	printf("Overwriting previously dumped %s at %s\n", "rawfile", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fwrite(buffer,1,len,writeLog);
	fclose(writeLog);
	return ERROR_SUCCESS;
}

Load_RawFileAsset_t Load_RawFileAsset = (Load_RawFileAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x360)) + 0xA4));

char customLoadedRawfiles[0x40][0x20];
char * customLoadedRawfileData[0x40];
int customLoadedRawfileCount = 0;
void Load_RawFileAssetHook(RawFile ** input)
{
	//(*input)->dumpRawfile();
	RawFile * fileToUse = 0, *oldRawfileUsed = *input;

	//Have we loaded this rawfile custom before?
	for(int i = 0; i < customLoadedRawfileCount; i++)
	{
		if(!customLoadedRawfiles[i])
			break;

		if(!stricmp(oldRawfileUsed->name, customLoadedRawfiles[i]))
		{
			fileToUse = *input;
			fileToUse->buffer = customLoadedRawfileData[i];
		}
	}

	//Can we load this rawfile custom?
	while(usingAssetBuffer) Sleep(0);
		
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName(oldRawfileUsed->name));
	if(!fileToUse && fileExists(theAssetBuffer))
	{
		HANDLE rawfileFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(rawfileFile, NULL);

 		if(rawfileFile != INVALID_HANDLE_VALUE)
		{
			fileToUse = oldRawfileUsed;
			//I know its highly unlikely that the new decompressed size will be less than the old compressed size, but add a check for it cause that'd be nice...
			if(oldRawfileUsed->len < numberOfBytesRead)
			{
				fileToUse->buffer = new char[numberOfBytesRead+1];
				ZeroMemory((char*)fileToUse->buffer, numberOfBytesRead+1);
				customLoadedRawfileData[customLoadedRawfileCount] = (char*)fileToUse->buffer;
				strcpy(customLoadedRawfiles[customLoadedRawfileCount], fileToUse->name);
				customLoadedRawfileCount++;
			}
			else
				ZeroMemory((char*)fileToUse->buffer, fileToUse->len+1);

			ReadFile(rawfileFile, (LPVOID)fileToUse->buffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);

			fileToUse->len = numberOfBytesRead;
			CloseHandle(rawfileFile);
		}
	}
	usingAssetBuffer = false;

	Load_RawFileAssetSaveStub(input);
}
#pragma endregion

#pragma region stringtable (0x2B)
strtk::token_grid::options strtkGridOptions(strtk::split_options::default_mode, strtk::split_options::default_mode, "\r\n", ",");
Load_StringTableAsset_t Load_StringTableAsset = (Load_StringTableAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x37C)) + 0xA4));

int StringTable::dumpStringTable()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));
	
	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "stringtable", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	for(int j = 0; j < rowCount; j++)
	for(int k = 0; k < columnCount; k++)
		fprintf(writeLog, k == columnCount-1 ? "%s\n" : "%s,", values[columnCount * j + k].string);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

char customLoadedTables[0x40][0x20];
StringTableCell * allocatedTables[0x20];
int allocatedTablesSizes[0x20][2];
int customLoadedTableCount = 0;

char tempBuildBuffer[0x100];
void Load_StringTableAssetHook(StringTable ** input)
{
	StringTable * oldTable = *input;
	//oldTable->dumpStringTable();

	//Have we loaded this stringtable custom before?
	for(int i = 0; i < customLoadedTableCount; i++)
	{
		if(!customLoadedTables[i])
			break;

		if(!strcmpi(oldTable->name, customLoadedTables[i]))
		{
			oldTable->values = allocatedTables[i];
			oldTable->columnCount = allocatedTablesSizes[i][0];
			oldTable->rowCount = allocatedTablesSizes[i][1];
			return;
		}
	}

	//Can we load this stringtable custom?
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName(oldTable->name));
	if(fileExists(theAssetBuffer))
	{
		StringTable* newTable = 0;
		HANDLE rawStringtable = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		int rawStringtableLength = GetFileSize(rawStringtable, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (rawStringtableLength + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[rawStringtableLength + 1];

		ZeroMemory(myBuffer, rawStringtableLength + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(rawStringtable != INVALID_HANDLE_VALUE && ReadFile(rawStringtable, myBuffer, rawStringtableLength, (LPDWORD)&rawStringtableLength, 0))
		{
			CloseHandle(rawStringtable);
			strtk::token_grid grid(myBuffer, rawStringtableLength, strtkGridOptions);
			int columns = grid.min_column_count();
			int rows = grid.row_count();

			StringTableCell * oldTableValues = 0;
			newTable = oldTable;
			oldTableValues = newTable->values;

			if(oldTable->rowCount * oldTable->columnCount < rows * columns)
			{
				newTable->values = new StringTableCell[rows * columns];
				ZeroMemory(newTable->values, rows * columns * sizeof(StringTableCell));
				strcpy(customLoadedTables[customLoadedTableCount], newTable->name);
				allocatedTablesSizes[customLoadedTableCount][0] = columns;
				allocatedTablesSizes[customLoadedTableCount][1] = rows;
				customLoadedTableCount++;
			}

			for (std::size_t ri = 0; ri < (std::size_t)rows; ri++)
			{
				strtk::token_grid::row_type r = grid.row(ri);

				for (std::size_t ci = 0; ci < r.size(); ci++)
				{
					ZeroMemory(tempBuildBuffer, sizeof(tempBuildBuffer));
					std::string strSource = r.get<std::string>(ci);
					strcpy(tempBuildBuffer, strSource.c_str());
					if(ci == columns - 1) {
						while(ci < r.size() - 1)
						{
							ci++;
							strSource = r.get<std::string>(ci);
							strcat(tempBuildBuffer, ",");
							strcat(tempBuildBuffer, strSource.c_str());
						}
						ci = columns - 1;
					}
					else if(ci > columns - 1)
						break;

					if(!oldTable ||													//There is no oldTable OR
						oldTable->rowCount * oldTable->columnCount < rows * columns && (ri >= oldTable->rowCount || ci >= oldTable->columnCount) ||	//The oldTable itemlist was too small and we are out of the range of the old values OR
						strcmp(tempBuildBuffer, oldTableValues[(ri * oldTable->columnCount) + ci].string))	//The new value is not the old value
					{
						//char* str = new char[strSource.length() + 1];
						//strcpy(str, strSource.c_str());
						newTable->values[(ri * columns) + ci].string = AllocateString((char*)tempBuildBuffer);
					}
					else if(oldTable && //There is an oldTable AND
						oldTable->rowCount * oldTable->columnCount >= rows * columns || (ri < oldTable->rowCount && ci < oldTable->columnCount))	//We are inside the range of the old values
						newTable->values[(ri * columns) + ci].string = oldTableValues[(ri * oldTable->columnCount) + ci].string;
					
					newTable->values[(ri * columns) + ci].hash = StringTable_HashString(newTable->values[(ri * columns) + ci].string);
				}
			}
			grid.clear();

			newTable->columnCount = columns;
			newTable->rowCount = rows;
			if(allocatedBuffer) delete myBuffer;
		}
	}
	usingAssetBuffer = false;

	Load_StringTableAssetSaveStub(input);
}
#pragma endregion

#pragma region ddl (0x2E)
Load_ddlRoot_tAsset_t Load_ddlRoot_tAsset = (Load_ddlRoot_tAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x3D0)) + 0xA4));

int ddlRoot_t::Dump_ddlRoot_t()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;

	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	if(ddlDef) {
	for(ddlDef_t * currentEntry = ddlDef; currentEntry; currentEntry = currentEntry->next)
	//while(1)
	{
		fprintf(writeLog, "//////////////////\n// VERSION %i //\n//////////////////\n\n", currentEntry->version);
		for(int i = 0; i < currentEntry->enumCount; i++)
		{
			fprintf(writeLog, "enum %s\r\n{\r\n", currentEntry->enumList[i].name);
			for(int j = 0; j < currentEntry->enumList[i].memberCount; j++)
				fprintf(writeLog, "\t%s = %i,\r\n", currentEntry->enumList[i].members[j], j);
			fprintf(writeLog, "};\r\n\r\n");
		}

		for(int i = 0; i < currentEntry->structCount; i++)
		{
			fprintf(writeLog, "//Bit Size: 0x%X\r\n", currentEntry->structList[i].size);
			fprintf(writeLog, "struct %s\r\n{\r\n", currentEntry->structList[i].name);
			for(int j = 0; j < currentEntry->structList[i].memberCount; j++)
			{  
				fprintf(writeLog, "\t//Bit Offset: 0x%X\r\n", currentEntry->structList[i].members[j].offset);
				fprintf(writeLog, "\t//Bit Size: 0x%X\r\n", currentEntry->structList[i].members[j].size);
				fprintf(writeLog, "\t//Permissions: 0x%X\r\n", currentEntry->structList[i].members[j].permission);
				fprintf(writeLog, "\t//rangeLimit: %u\r\n", currentEntry->structList[i].members[j].rangeLimit);
				fprintf(writeLog, "\t//serverDelta: %u\r\n", currentEntry->structList[i].members[j].serverDelta);
				fprintf(writeLog, "\t//clientDelta: %u\r\n", currentEntry->structList[i].members[j].clientDelta);
				fprintf(writeLog, "\t");
				switch(currentEntry->structList[i].members[j].type)
				{
				case DDL_BYTE_TYPE:
					fprintf(writeLog, "byte ");
					break;
				case DDL_SHORT_TYPE:
					fprintf(writeLog, "short ");
					break;
				case DDL_UINT_TYPE:
					fprintf(writeLog, "unsigned ");
				case DDL_INT_TYPE:
					fprintf(writeLog, "int ");
					break;
				case DDL_INT64_TYPE:
					fprintf(writeLog, "__int64 ");
					break;
				case DDL_FLOAT_TYPE:
					fprintf(writeLog, "float ");
					break;
				case DDL_FIXEDPOINT_TYPE:
					fprintf(writeLog, "FixedPointTime ");
					break;
				case DDL_STRING_TYPE:
					fprintf(writeLog, "char ");
					break;
				case DDL_STRUCT_TYPE:
					fprintf(writeLog, "%s ", currentEntry->structList[currentEntry->structList[i].members[j].externalIndex].name);
					break;
				case DDL_ENUM_TYPE:
					fprintf(writeLog, "enum ");
					break;
				}
				fprintf(writeLog, currentEntry->structList[i].members[j].name);
				if(currentEntry->structList[i].members[j].arraySize > 1)
					if(currentEntry->structList[i].members[j].enumIndex != -1 &&
						currentEntry->enumList[currentEntry->structList[i].members[j].enumIndex].memberCount == currentEntry->structList[i].members[j].arraySize)
						fprintf(writeLog, "[%s]", currentEntry->enumList[currentEntry->structList[i].members[j].enumIndex].name);
					else
						fprintf(writeLog, "[%i]", currentEntry->structList[i].members[j].arraySize);
				fprintf(writeLog, ";\r\n\r\n");
			}
			fprintf(writeLog, "};\r\n\r\n");
		}
	}
	}

	fclose(writeLog);
	return ERROR_SUCCESS;
}

void Load_ddlRoot_tAssetHook(ddlRoot_t ** input) {
	//(*input)->Dump_ddlRoot_t();
	Load_ddlRoot_tAssetSaveStub(input);
}
#pragma endregion

#pragma region scriptparsetree (0x32)
int ScriptParseTree::dumpScriptParseTree()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;

	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	if(buffer) { 
		if(((GSC_OBJ*)buffer)->fixup_offset != len || ((GSC_OBJ*)buffer)->profile_offset != len)
			printf("\\\\\\\\\\\\\\ An unknown section has been found in %s \\\\\\\\\\\\\\\n\\\\\\\\\\\\\\ Report this to CraigChrist8239 right away!! \\\\\\\\\\\\\\\n");

		fwrite(buffer, 1, len, writeLog);
	}

	fclose(writeLog);
	return ERROR_SUCCESS;
}

Load_ScriptParseTreeAsset_t Load_ScriptParseTreeAsset = (Load_ScriptParseTreeAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x440)) + 0xA4));

int previouslyLoadedScriptsCounts = 0;
char previouslyLoadedScriptsName[0x40][0x40];
char * previouslyLoadedScripts[0x40];
int previouslyLoadedScriptsSizes[0x40];
void Load_ScriptParseTreeAssetHook(ScriptParseTree ** input)
{
	ScriptParseTree * myTree = *input;
	//myTree->dumpScriptParseTree();

	for(int i = 0; i < previouslyLoadedScriptsCounts; i++) {
		if(!strcmp(previouslyLoadedScriptsName[i], myTree->name)) {
			myTree->buffer = previouslyLoadedScripts[i];
			myTree->len = previouslyLoadedScriptsSizes[i];
			Load_ScriptParseTreeAssetSaveStub(input);
		}
	}
	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName((char*)myTree->name));
	if(fileExists(theAssetBuffer))
	{
		HANDLE scriptLoader = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(scriptLoader, NULL);
		if(numberOfBytesRead > myTree->len) {
			myTree->len = previouslyLoadedScriptsSizes[previouslyLoadedScriptsCounts] = numberOfBytesRead;
			myTree->buffer = previouslyLoadedScripts[previouslyLoadedScriptsCounts] = new char[myTree->len];
 			ReadFile(scriptLoader, myTree->buffer, myTree->len, (LPDWORD)&numberOfBytesRead, 0);
			strcpy(previouslyLoadedScriptsName[previouslyLoadedScriptsCounts], myTree->name);
			previouslyLoadedScriptsCounts++;
		}
		else if(scriptLoader != INVALID_HANDLE_VALUE && ReadFile(scriptLoader, myTree->buffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0)) {
			myTree->len = numberOfBytesRead;
		}
		CloseHandle(scriptLoader);
	}
	usingAssetBuffer = false;

	Load_ScriptParseTreeAssetSaveStub(input);
}

char newScriptName[0x50];
char newScriptBuffer[0x60];
void Scr_GetGSCObjHook(scriptInstance_t inst, const char *name, bool appendExtension, bool errorIfMissing)
{
	ScriptParseTree* currentAsset = g_scriptParseTreePool->freeHead;
	sprintf(newScriptName, "%s%s", name, inst && appendExtension ? ".csc" : ".gsc");
	ScriptParseTree* returnVal = DB_FindXAssetHeader(ASSET_TYPE_SCRIPTPARSETREE, newScriptName, true, -1).scriptParseTree;
	sprintf(newScriptBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName(newScriptName, newScriptName));
	
	if(fileExists(newScriptBuffer) && returnVal == 0) {
		HANDLE scriptLoader = CreateFile(newScriptBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(scriptLoader, NULL);
		currentAsset->name = new char[strlen(name) + 5];
		sprintf((char*)currentAsset->name, "%s%s", name, inst && appendExtension ? ".csc" : ".gsc");
		currentAsset->len = previouslyLoadedScriptsSizes[previouslyLoadedScriptsCounts] = numberOfBytesRead;
		currentAsset->buffer = previouslyLoadedScripts[previouslyLoadedScriptsCounts] = new char[currentAsset->len];
		ReadFile(scriptLoader, currentAsset->buffer, currentAsset->len, (LPDWORD)&numberOfBytesRead, 0);
		CloseHandle(scriptLoader);
		g_scriptParseTreePool->freeHead++;
		strcpy(previouslyLoadedScriptsName[previouslyLoadedScriptsCounts], currentAsset->name);
		previouslyLoadedScriptsCounts++;
	}
	Scr_GetGSCObjSaveStub(inst,name,appendExtension,errorIfMissing);
}

char newScriptName2[0x50];
char newScriptBuffer2[0x60];
void Scr_LoadScriptInternalHook(scriptInstance_t inst, const char *filename)
{
	ScriptParseTree* currentAsset = g_scriptParseTreePool->freeHead;
	sprintf(newScriptName2, "%s.%s", filename, inst ? "csc" : "gsc");
	ScriptParseTree* returnVal = DB_FindXAssetHeader(ASSET_TYPE_SCRIPTPARSETREE, newScriptName2, true, -1).scriptParseTree;
	
	sprintf(newScriptBuffer2, "game:\\raw\\%s", ConvertAssetNameToFileName(newScriptName2, newScriptName2));
	
	if(fileExists(newScriptBuffer2) && returnVal == 0) {
		HANDLE scriptLoader = CreateFile(newScriptBuffer2, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(scriptLoader, NULL);
		currentAsset->name = new char[strlen(filename) + 5];
		sprintf((char*)currentAsset->name, "%s.%s", filename, inst ? "csc" : "gsc");
		currentAsset->len = previouslyLoadedScriptsSizes[previouslyLoadedScriptsCounts] = numberOfBytesRead;
		currentAsset->buffer = previouslyLoadedScripts[previouslyLoadedScriptsCounts] = new char[currentAsset->len];
		ReadFile(scriptLoader, currentAsset->buffer, currentAsset->len, (LPDWORD)&numberOfBytesRead, 0);
		CloseHandle(scriptLoader);
		g_scriptParseTreePool->freeHead++;
		strcpy(previouslyLoadedScriptsName[previouslyLoadedScriptsCounts], currentAsset->name);
		previouslyLoadedScriptsCounts++;
	}
	Scr_LoadScriptInternalSaveStub(inst,filename);
}

Scr_ResolveScriptFunction_t Scr_ResolveScriptFunction;

int Scr_ResolveScriptFunctionHook(scriptInstance_t inst, GSC_OBJ *prime_obj, GSC_IMPORT_ITEM *import, char op, bool is_pushfunc)
{
	int stackLocation;
	__asm {
		mr stackLocation, r1
		mr inst, r25
		mr prime_obj, r31
		mr import, r30
	}
	int returnVal = Scr_ResolveScriptFunction(inst, prime_obj, import, op, is_pushfunc);

	if(!returnVal)
		sprintf((char*)(stackLocation + 0xF0), "**** Couldn't resolve function \"%s\" in %s\n", (int)prime_obj + import->name, (int)prime_obj + 0x40);

	return returnVal;
}

int* DB_PoolsOffset = (int*)ReadHILOOffset(AlignedMemorySearch(".text", DB_XAssetPools_Signature, 0xC), -2, 0xE);
XAssetPool<ScriptParseTree, 0x400> * g_scriptParseTreePool = (XAssetPool<ScriptParseTree, 0x400> *)DB_PoolsOffset[ASSET_TYPE_SCRIPTPARSETREE];
#pragma endregion

#pragma region vehicle (0x34)
AssetEntry BlurEntry[] = {
	{"",		0,	ASSET_ENTRY_FLOAT,0,0},
	{"Start",	4,	ASSET_ENTRY_FLOAT,0,0},
	{"End",		8,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry Vec2OffsetEntry[] = {
	{"X",	0,	ASSET_ENTRY_FLOAT,0,0},
	{"Y",	4,	ASSET_ENTRY_FLOAT,0,0},
	{0,0,(AssetEntryType)0,0,0}
};

AssetEntry VehScriptStringArray[] = {
	{"1",	0,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"2",	4,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"3",	8,	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"4",	0xC,ASSET_ENTRY_SCRIPT_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry SeatSwitchOrderEntry[] = {
	{"1",	0,		ASSET_ENTRY_INT,0,0},
	{"2",	4,		ASSET_ENTRY_INT,0,0},
	{"3",	8,		ASSET_ENTRY_INT,0,0},
	{"4",	0xC,	ASSET_ENTRY_INT,0,0},
	{"5",	0x10,	ASSET_ENTRY_INT,0,0},
	{"6",	0x14,	ASSET_ENTRY_INT,0,0},
	{"7",	0x18,	ASSET_ENTRY_INT,0,0},
	{"8",	0x1C,	ASSET_ENTRY_INT,0,0},
	{"9",	0x20,	ASSET_ENTRY_INT,0,0},
	{"10",	0x24,	ASSET_ENTRY_INT,0,0},
	{"11",	0x28,	ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry EnterRadiusGunnerEntry[] = {
	{"1",	0,	ASSET_ENTRY_FLOAT,0,0},
	{"2",	4,	ASSET_ENTRY_FLOAT,0,0},
	{"3",	8,	ASSET_ENTRY_FLOAT,0,0},
	{"4",	0xC,ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry GunnerWeaponEntry[] = {
	{"1",	0,		ASSET_ENTRY_STRING,0,0},
	{"2",	4,		ASSET_ENTRY_STRING,0,0},
	{"3",	8,		ASSET_ENTRY_STRING,0,0},
	{"4",	0xC,	ASSET_ENTRY_STRING,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehModelArrayEntry[] = {
	{"1",	0,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"2",	4,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"3",	8,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"4",	0xC,ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry SpanEntry[] = {
	{"HorizSpanLeft",	0,		ASSET_ENTRY_FLOAT,0,0},
	{"HorizSpanRight",	4,		ASSET_ENTRY_FLOAT,0,0},
	{"VertSpanUp",		8,		ASSET_ENTRY_FLOAT,0,0},
	{"VertSpanDown",	0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"HorizResistLeft",	0x10,	ASSET_ENTRY_FLOAT,0,0},
	{"HorizResistRight",0x14,	ASSET_ENTRY_FLOAT,0,0},
	{"VertResistUp",	0x18,	ASSET_ENTRY_FLOAT,0,0},
	{"VertResistDown",	0x1C,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry SurfaceFxEntries[] = {
	{"Default",		0,		ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Bark",		4,		ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Brick",		8,		ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Carpet",		0xC,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Cloth",		0x10,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Concrete",	0x14,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Dirt",		0x18,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Flesh",		0x1C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Foliage",		0x20,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Glass",		0x24,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Grass",		0x28,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Gravel",		0x2C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Ice",			0x30,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Metal",		0x34,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Mud",			0x38,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Paper",		0x3C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Plaster",		0x40,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Rock",		0x44,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Sand",		0x48,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Snow",		0x4C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Water",		0x50,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Wood",		0x54,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Asphalt",		0x58,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Ceramic",		0x5C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Plastic",		0x60,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Rubber",		0x64,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Cushion",		0x68,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Fruit",		0x6C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"PaintedMetal",0x70,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Player",		0x74,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Tallgrass",	0x78,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"Riotshield",	0x7C,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"OpaqueGlass",	0x80,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehFXArrayEntry[] = {
	{"1",	0,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"2",	4,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"3",	8,	ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{"4",	0xC,ASSET_ENTRY_ASSET_PTR,	(AssetEntry*)ASSET_TYPE_FX,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehButtonEntry[] = {
	{"Name",	0,	ASSET_ENTRY_STRING,0,0},
	{"Index",	4,	ASSET_ENTRY_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehHeliMaintainEntries[] = {
	{"Height",			0,		ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"MaxHeight",		4,		ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"HeightLimit",		8,		ASSET_ENTRY_FLOAT,0,0},
	{"HeightAccel",		0xC,	ASSET_ENTRY_FLOAT,0,0},
	{"HeightMinimum",	0x10,	ASSET_ENTRY_FLOAT,0,0},
	{"HeightMaximum",	0x14,	ASSET_ENTRY_FLOAT,0,0},
	{"CeilingMinimum",	0x18,	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehNosEntries[] = {
	{"maxSpeed",				offsetof(VehicleParameter, m_speed_max),					ASSET_ENTRY_FLOAT,0,0},
	{"accel",					offsetof(VehicleParameter, m_accel_max),					ASSET_ENTRY_FLOAT,0,0},
	{"reverse_scale",			offsetof(VehicleParameter, m_reverse_scale),				ASSET_ENTRY_FLOAT,0,0},
	{"steer_angle_max",			offsetof(VehicleParameter, m_steer_angle_max),				ASSET_ENTRY_FLOAT,0,0},
	{"steer_angle_speed_scale",	offsetof(VehicleParameter, m_steer_angle_speed_scale),		ASSET_ENTRY_FLOAT,0,0},
	{"steer_speed",				offsetof(VehicleParameter, m_steer_speed),					ASSET_ENTRY_FLOAT,0,0},
	{"wheel_radius",			offsetof(VehicleParameter, m_wheel_radius),					ASSET_ENTRY_FLOAT,0,0},
	{"susp_spring_k",			offsetof(VehicleParameter, m_susp_spring_k),				ASSET_ENTRY_FLOAT,0,0},
	{"susp_damp_k",				offsetof(VehicleParameter, m_susp_damp_k),					ASSET_ENTRY_FLOAT,0,0},
	{"susp_adj",				offsetof(VehicleParameter, m_susp_adj),						ASSET_ENTRY_FLOAT,0,0},
	{"susp_hard_limit",			offsetof(VehicleParameter, m_susp_hard_limit),				ASSET_ENTRY_FLOAT,0,0},
	{"susp_min_height",			offsetof(VehicleParameter, m_susp_min_height),				ASSET_ENTRY_FLOAT,0,0},
	{"tire_fric_fwd",			offsetof(VehicleParameter, m_tire_fric_fwd),				ASSET_ENTRY_FLOAT,0,0},
	{"tire_fric_side",			offsetof(VehicleParameter, m_tire_fric_side),				ASSET_ENTRY_FLOAT,0,0},
	{"tire_fric_brake",			offsetof(VehicleParameter, m_tire_fric_brake),				ASSET_ENTRY_FLOAT,0,0},
	{"tire_fric_hand_brake",	offsetof(VehicleParameter, m_tire_fric_hand_brake),			ASSET_ENTRY_FLOAT,0,0},
	{"body_mass",				offsetof(VehicleParameter, m_body_mass),					ASSET_ENTRY_FLOAT,0,0},
	{"roll_stability",			offsetof(VehicleParameter, m_roll_stability),				ASSET_ENTRY_FLOAT,0,0},
	{"pitch_stability",			offsetof(VehicleParameter, m_pitch_stability),				ASSET_ENTRY_FLOAT,0,0},
	{"pitch_roll_resistance",	offsetof(VehicleParameter, m_pitch_roll_resistance),		ASSET_ENTRY_FLOAT,0,0},
	{"yaw_resistance",			offsetof(VehicleParameter, m_yaw_resistance),				ASSET_ENTRY_FLOAT,0,0},
	{"upright_strength",		offsetof(VehicleParameter, m_upright_strength),				ASSET_ENTRY_FLOAT,0,0},
	{"tilt_fakey",				offsetof(VehicleParameter, m_tilt_fakey),					ASSET_ENTRY_FLOAT,0,0},
	{"peel_out_max_speed",		offsetof(VehicleParameter, m_peel_out_max_speed),			ASSET_ENTRY_FLOAT,0,0},
	{"tire_damp_coast",			offsetof(VehicleParameter, m_tire_damp_coast),				ASSET_ENTRY_FLOAT,0,0},
	{"tire_damp_brake",			offsetof(VehicleParameter, m_tire_damp_brake),				ASSET_ENTRY_FLOAT,0,0},
	{"tire_damp_hand",			offsetof(VehicleParameter, m_tire_damp_hand),				ASSET_ENTRY_FLOAT,0,0},
	{"auto_hand_brake_min_speed",offsetof(VehicleParameter, m_auto_hand_brake_min_speed),	ASSET_ENTRY_FLOAT,0,0},
	{"traction_type",			offsetof(VehicleParameter, m_traction_type),				ASSET_ENTRY_ENUM,		(AssetEntry*)s_tractionTypeNames,	NUM_TRACTION_TYPES},
	{"name",					offsetof(VehicleParameter, m_name),							ASSET_ENTRY_STRING,0,0},
	{"boundingbox_min_x",		offsetof(VehicleParameter, m_bbox_min),						ASSET_ENTRY_FLOAT,0,0},
	{"boundingbox_min_y",		offsetof(VehicleParameter, m_bbox_min) + 4,					ASSET_ENTRY_FLOAT,0,0},
	{"boundingbox_min_z",		offsetof(VehicleParameter, m_bbox_min) + 8,					ASSET_ENTRY_FLOAT,0,0},
	{"boundingbox_max_x",		offsetof(VehicleParameter, m_bbox_max),						ASSET_ENTRY_FLOAT,0,0},
	{"boundingbox_max_y",		offsetof(VehicleParameter, m_bbox_max) + 4,					ASSET_ENTRY_FLOAT,0,0},
	{"boundingbox_max_z",		offsetof(VehicleParameter, m_bbox_max) + 8,					ASSET_ENTRY_FLOAT,0,0},
	{"mass_center_x",			offsetof(VehicleParameter, m_mass_center_offset),			ASSET_ENTRY_FLOAT,0,0},
	{"mass_center_y",			offsetof(VehicleParameter, m_mass_center_offset) + 4,		ASSET_ENTRY_FLOAT,0,0},
	{"mass_center_z",			offsetof(VehicleParameter, m_mass_center_offset) + 8,		ASSET_ENTRY_FLOAT,0,0},
	{"buoyancybox_min_x",		offsetof(VehicleParameter, m_buoyancybox_min),				ASSET_ENTRY_FLOAT,0,0},
	{"buoyancybox_min_y",		offsetof(VehicleParameter, m_buoyancybox_min) + 4,			ASSET_ENTRY_FLOAT,0,0},
	{"buoyancybox_min_z",		offsetof(VehicleParameter, m_buoyancybox_min) + 8,			ASSET_ENTRY_FLOAT,0,0},
	{"buoyancybox_max_x",		offsetof(VehicleParameter, m_buoyancybox_max),				ASSET_ENTRY_FLOAT,0,0},
	{"buoyancybox_max_y",		offsetof(VehicleParameter, m_buoyancybox_max) + 4,			ASSET_ENTRY_FLOAT,0,0},
	{"buoyancybox_max_z",		offsetof(VehicleParameter, m_buoyancybox_max) + 8,			ASSET_ENTRY_FLOAT,0,0},
	{"water_speed_max",			offsetof(VehicleParameter, m_water_speed_max),				ASSET_ENTRY_FLOAT,0,0},
	{"water_accel_max",			offsetof(VehicleParameter, m_water_accel_max),				ASSET_ENTRY_FLOAT,0,0},
	{"water_turn_accel",		offsetof(VehicleParameter, m_water_turn_accel),				ASSET_ENTRY_FLOAT,0,0},
	{"water_turn_speed_max",	offsetof(VehicleParameter, m_water_turn_speed_max),			ASSET_ENTRY_FLOAT,0,0},
	{"water_ebrake_power",		offsetof(VehicleParameter, m_water_ebrake_power),			ASSET_ENTRY_FLOAT,0,0},
	{"boat_motor_x",			offsetof(VehicleParameter, m_boat_motor_offset),			ASSET_ENTRY_FLOAT,0,0},
	{"boat_motor_y",			offsetof(VehicleParameter, m_boat_motor_offset) + 4,		ASSET_ENTRY_FLOAT,0,0},
	{"boat_motor_z",			offsetof(VehicleParameter, m_boat_motor_offset) + 8,		ASSET_ENTRY_FLOAT,0,0},
	{"boat_speed_rise",			offsetof(VehicleParameter, m_boat_speed_rise),				ASSET_ENTRY_FLOAT,0,0},
	{"boat_speed_tilt",			offsetof(VehicleParameter, m_boat_speed_tilt),				ASSET_ENTRY_FLOAT,0,0},
	{"boat_side_fric_scale",	offsetof(VehicleParameter, m_boat_side_fric_scale),			ASSET_ENTRY_FLOAT,0,0},
	{"boat_forward_fric_scale",	offsetof(VehicleParameter, m_boat_forward_fric_scale),		ASSET_ENTRY_FLOAT,0,0},
	{"boat_vertical_fric_scale",offsetof(VehicleParameter, m_boat_forward_fric_scale),		ASSET_ENTRY_FLOAT,0,0},
	{"jump_force",				offsetof(VehicleParameter, m_jump_force),					ASSET_ENTRY_FLOAT,0,0},
	{"tire_fric_side_max",		offsetof(VehicleParameter, m_tire_fric_side_max),			ASSET_ENTRY_FLOAT,0,0},
	{"drive_on_walls",			offsetof(VehicleParameter, m_drive_on_walls),				ASSET_ENTRY_BOOL,0,0},
	{"linear_drag_scale",		offsetof(VehicleParameter, m_linear_drag_scale),			ASSET_ENTRY_FLOAT,0,0},
	{"angular_drag_scale",		offsetof(VehicleParameter, m_angular_drag_scale),			ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry PVehDrivebySound[] = {
	{"p_drive_by_sound_apex",	offsetof(VehicleDriveBySound, apex),	ASSET_ENTRY_INT,0,0},
	{"p_drive_by_sound_name",	offsetof(VehicleDriveBySound, name),	ASSET_ENTRY_STRING,0,0},
	{"p_drive_by_sound_alias",	offsetof(VehicleDriveBySound, alias),	ASSET_ENTRY_UNSIGNED_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry SVehDrivebySound[] = {
	{"s_drive_by_sound_apex",	offsetof(VehicleDriveBySound, apex),	ASSET_ENTRY_INT,0,0},
	{"s_drive_by_sound_name",	offsetof(VehicleDriveBySound, name),	ASSET_ENTRY_STRING,0,0},
	{"s_drive_by_sound_alias",	offsetof(VehicleDriveBySound, alias),	ASSET_ENTRY_UNSIGNED_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehEngineSoundOnload[] = {
	{"engine_onload_sound_name",	offsetof(VehicleEngineSound, name),			ASSET_ENTRY_STRING,0,0},
	{"engine_onload_sound_alias",	offsetof(VehicleEngineSound, alias),		ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"engine_onload_sound_param1_",	offsetof(VehicleEngineSound, params[0]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_onload_sound_param2_",	offsetof(VehicleEngineSound, params[1]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_onload_sound_param3_",	offsetof(VehicleEngineSound, params[2]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_onload_sound_param4_",	offsetof(VehicleEngineSound, params[3]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_onload_sound_param5_",	offsetof(VehicleEngineSound, params[4]),	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehEngineSoundOffload[] = {
	{"engine_offload_sound_name",		offsetof(VehicleEngineSound, name),			ASSET_ENTRY_STRING,0,0},
	{"engine_offload_sound_alias",		offsetof(VehicleEngineSound, alias),		ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"engine_offload_sound_param1_",	offsetof(VehicleEngineSound, params[0]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_offload_sound_param2_",	offsetof(VehicleEngineSound, params[1]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_offload_sound_param3_",	offsetof(VehicleEngineSound, params[2]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_offload_sound_param4_",	offsetof(VehicleEngineSound, params[3]),	ASSET_ENTRY_FLOAT,0,0},
	{"engine_offload_sound_param5_",	offsetof(VehicleEngineSound, params[4]),	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehEngineGearEntries[] = {
	{"min_rpm",		offsetof(VehicleGearData, minRPM),	ASSET_ENTRY_FLOAT,0,0},
	{"max_rpm",		offsetof(VehicleGearData, maxRPM),	ASSET_ENTRY_FLOAT,0,0},
	{"ratio",		offsetof(VehicleGearData, ratio),	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehEngineEntries[] = {
	{"idle_rpms",						offsetof(VehicleEngine, idleRpms),						ASSET_ENTRY_FLOAT,0,0},
	{"max_rpms",						offsetof(VehicleEngine, maxRpms),						ASSET_ENTRY_FLOAT,0,0},
	{"max_torque",						offsetof(VehicleEngine, maxTorque),						ASSET_ENTRY_FLOAT,0,0},
	{"braking_coeff",					offsetof(VehicleEngine, brakingCoeff),					ASSET_ENTRY_FLOAT,0,0},
	{"engine_onload_fadein_start",		offsetof(VehicleEngine, onLoadFadeInStart),				ASSET_ENTRY_FLOAT,0,0},
	{"engine_onload_fadein_end",		offsetof(VehicleEngine, onLoadFadeInEnd),				ASSET_ENTRY_FLOAT,0,0},
	{"engine_offload_fadeout_start",	offsetof(VehicleEngine, offLoadFadeOutStart),			ASSET_ENTRY_FLOAT,0,0},
	{"engine_offload_fadeout_end",		offsetof(VehicleEngine, offLoadFadeOutEnd),				ASSET_ENTRY_FLOAT,0,0},
	{"engine_load_scale",				offsetof(VehicleEngine, loadScale),						ASSET_ENTRY_FLOAT,0,0},
	{"engine_load_smoothing",			offsetof(VehicleEngine, loadSmoothing),					ASSET_ENTRY_FLOAT,0,0},
	{"engine_throttle_lag",				offsetof(VehicleEngine, throttleLag),					ASSET_ENTRY_FLOAT,0,0},
	{"engine_pitch_scale",				offsetof(VehicleEngine, pitchScale),					ASSET_ENTRY_FLOAT,0,0},
	{"1",								offsetof(VehicleEngine, onload[0]),						ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOnload,0},
	{"2",								offsetof(VehicleEngine, onload[1]),						ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOnload,0},
	{"3",								offsetof(VehicleEngine, onload[2]),						ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOnload,0},
	{"4",								offsetof(VehicleEngine, onload[3]),						ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOnload,0},
	{"5",								offsetof(VehicleEngine, onload[4]),						ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOnload,0},
	{"1",								offsetof(VehicleEngine, offload[0]),					ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOffload,0},
	{"2",								offsetof(VehicleEngine, offload[1]),					ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOffload,0},
	{"3",								offsetof(VehicleEngine, offload[2]),					ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOffload,0},
	{"4",								offsetof(VehicleEngine, offload[3]),					ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOffload,0},
	{"5",								offsetof(VehicleEngine, offload[4]),					ASSET_ENTRY_EMBEDDED_REVERSED,			VehEngineSoundOffload,0},
	{"num_gears",						offsetof(VehicleEngine, numGears),						ASSET_ENTRY_INT,0,0},
	{"loopLastGear",					offsetof(VehicleEngine, loopLastGear),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"gear1_",							offsetof(VehicleEngine, gears[0]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear2_",							offsetof(VehicleEngine, gears[1]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear3_",							offsetof(VehicleEngine, gears[2]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear4_",							offsetof(VehicleEngine, gears[3]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear5_",							offsetof(VehicleEngine, gears[4]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear6_",							offsetof(VehicleEngine, gears[5]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear7_",							offsetof(VehicleEngine, gears[6]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear8_",							offsetof(VehicleEngine, gears[7]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear9_",							offsetof(VehicleEngine, gears[8]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{"gear10_",							offsetof(VehicleEngine, gears[9]),						ASSET_ENTRY_EMBEDDED,					VehEngineGearEntries,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehAntennaEntries[] = {
	{"spring_k",	offsetof(VehicleAntenna, springK),	ASSET_ENTRY_FLOAT,0,0},
	{"damp",		offsetof(VehicleAntenna, damp),		ASSET_ENTRY_FLOAT,0,0},
	{"length",		offsetof(VehicleAntenna, length),	ASSET_ENTRY_FLOAT,0,0},
	{"gravity",		offsetof(VehicleAntenna, gravity),	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry VehicleDefEntries[] = {
	{"type",									offsetof(VehicleDef, type),									ASSET_ENTRY_ENUM_SHORT,			(AssetEntry*)s_vehicleClassNames,	NUM_VEHICLE_TYPES},
	{"remoteControl",							offsetof(VehicleDef, remoteControl),						ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"bulletDamage",							offsetof(VehicleDef, bulletDamage),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"armorPiercingDamage",						offsetof(VehicleDef, armorPiercingDamage),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"grenadeDamage",							offsetof(VehicleDef, grenadeDamage),						ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"projectileDamage",						offsetof(VehicleDef, projectileDamage),						ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"projectileSplashDamage",					offsetof(VehicleDef, projectileSplashDamage),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"heavyExplosiveDamage",					offsetof(VehicleDef, heavyExplosiveDamage),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"cameraMode",								offsetof(VehicleDef, cameraMode),							ASSET_ENTRY_ENUM_SHORT,			(AssetEntry*)s_vehicleCameraModes,	VEH_MODE_MAX},
	{"autoRecenterOnAccel",						offsetof(VehicleDef, autoRecenterOnAccel),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"thirdPersonDriver",						offsetof(VehicleDef, thirdPersonDriver),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"thirdPersonUseVehicleRoll",				offsetof(VehicleDef, thirdPersonUseVehicleRoll),			ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"thirdPersonCameraPitchVehicleRelative",	offsetof(VehicleDef, thirdPersonCameraPitchVehicleRelative),ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"thirdPersonCameraHeightWorldRelative",	offsetof(VehicleDef, thirdPersonCameraHeightWorldRelative),	ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"thirdPersonCameraRange",					offsetof(VehicleDef, thirdPersonCameraRange),				ASSET_ENTRY_FLOAT,0,0},
	{"thirdPersonCameraMinPitchClamp",			offsetof(VehicleDef, thirdPersonCameraMinPitchClamp),		ASSET_ENTRY_FLOAT,0,0},
	{"thirdPersonCameraMaxPitchClamp",			offsetof(VehicleDef, thirdPersonCameraMaxPitchClamp),		ASSET_ENTRY_FLOAT,0,0},
	{"thirdPersonCameraHeight",					offsetof(VehicleDef, thirdPersonCameraHeight),				ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"thirdPersonCameraPitch",					offsetof(VehicleDef, thirdPersonCameraPitch),				ASSET_ENTRY_EMBEDDED,			MinMax_FloatEntry,0},
	{"cameraAlwaysAutoCenter",					offsetof(VehicleDef, cameraAlwaysAutoCenter),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"cameraAutoCenterLerpRate",				offsetof(VehicleDef, cameraAutoCenterLerpRate),				ASSET_ENTRY_FLOAT,0,0},
	{"cameraAutoCenterMaxLerpRate",				offsetof(VehicleDef, cameraAutoCenterMaxLerpRate),			ASSET_ENTRY_FLOAT,0,0},
	{"thirdPersonCameraSpringDistance",			offsetof(VehicleDef, thirdPersonCameraSpringDistance),		ASSET_ENTRY_FLOAT,0,0},
	{"thirdPersonCameraSpringTime",				offsetof(VehicleDef, thirdPersonCameraSpringTime),			ASSET_ENTRY_FLOAT,0,0},
	{"thirdPersonCameraHandbrakeTurnRateInc",	offsetof(VehicleDef, thirdPersonCameraHandbrakeTurnRateInc),ASSET_ENTRY_FLOAT,0,0},
	{"cameraFOV",								offsetof(VehicleDef, cameraFOV),							ASSET_ENTRY_FLOAT,0,0},
	{"cameraRollFraction",						offsetof(VehicleDef, cameraRollFraction),					ASSET_ENTRY_FLOAT,0,0},
	{"tagPlayerOffset",							offsetof(VehicleDef, tagPlayerOffset),						ASSET_ENTRY_EMBEDDED,			OffsetEntry,0},
	{"killcamCollision",						offsetof(VehicleDef, killcamCollision),						ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"killcamDist",								offsetof(VehicleDef, killcamDist),							ASSET_ENTRY_FLOAT,0,0},
	{"killcamZDist",							offsetof(VehicleDef, killcamZDist),							ASSET_ENTRY_FLOAT,0,0},
	{"killcamMinDist",							offsetof(VehicleDef, killcamMinDist),						ASSET_ENTRY_FLOAT,0,0},
	{"killcamZTargetOffset",					offsetof(VehicleDef, killcamZTargetOffset),					ASSET_ENTRY_FLOAT,0,0},
	{"killcamFOV",								offsetof(VehicleDef, killcamFOV),							ASSET_ENTRY_FLOAT,0,0},
	{"killcamNearBlur",							offsetof(VehicleDef, killcamNearBlur),						ASSET_ENTRY_EMBEDDED,			BlurEntry,0},
	{"killcamFarBlur",							offsetof(VehicleDef, killcamFarBlur),						ASSET_ENTRY_EMBEDDED,			BlurEntry,0},
	{"isDrivable",								offsetof(VehicleDef, isDrivable),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"numberOfSeats",							offsetof(VehicleDef, numberOfSeats),						ASSET_ENTRY_INT,0,0},
	{"numberOfGunners",							offsetof(VehicleDef, numberOfGunners),						ASSET_ENTRY_INT,0,0},
	{"seatSwitchOrder",							offsetof(VehicleDef, seatSwitchOrder),						ASSET_ENTRY_EMBEDDED,			SeatSwitchOrderEntry,0},
	{"driverControlledGunPos",					offsetof(VehicleDef, driverControlledGunPos),				ASSET_ENTRY_INT,0,0},
	{"enterRadiusDriver",						offsetof(VehicleDef, enterRadiusDriver),					ASSET_ENTRY_FLOAT,0,0},
	{"enterRadiusGunner",						offsetof(VehicleDef, enterRadiusGunner),					ASSET_ENTRY_EMBEDDED,			EnterRadiusGunnerEntry,0},
	{"texureScrollScale",						offsetof(VehicleDef, texureScrollScale),					ASSET_ENTRY_FLOAT,0,0},
	{"wheelRotRate",							offsetof(VehicleDef, wheelRotRate),							ASSET_ENTRY_FLOAT,0,0},
	{"extraWheelRotScale",						offsetof(VehicleDef, extraWheelRotScale),					ASSET_ENTRY_FLOAT,0,0},
	{"wheelChildTakesSteerYaw",					offsetof(VehicleDef, wheelChildTakesSteerYaw),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"maxSpeed",								offsetof(VehicleDef, maxSpeed),								ASSET_ENTRY_FLOAT,0,0},
	{"maxSpeedVertical",						offsetof(VehicleDef, maxSpeedVertical),						ASSET_ENTRY_FLOAT,0,0},
	{"accel",									offsetof(VehicleDef, accel),								ASSET_ENTRY_FLOAT,0,0},
	{"accelVertical",							offsetof(VehicleDef, accelVertical),						ASSET_ENTRY_FLOAT,0,0},
	{"rotRate",									offsetof(VehicleDef, rotRate),								ASSET_ENTRY_FLOAT,0,0},
	{"rotAccel",								offsetof(VehicleDef, rotAccel),								ASSET_ENTRY_FLOAT,0,0},
	{"maxBodyPitch",							offsetof(VehicleDef, maxBodyPitch),							ASSET_ENTRY_FLOAT,0,0},
	{"maxBodyRoll",								offsetof(VehicleDef, maxBodyRoll),							ASSET_ENTRY_FLOAT,0,0},
	{"collisionDamage",							offsetof(VehicleDef, collisionDamage),						ASSET_ENTRY_FLOAT,0,0},
	{"collisionSpeed",							offsetof(VehicleDef, collisionSpeed),						ASSET_ENTRY_FLOAT,0,0},
	{"suspensionTravel",						offsetof(VehicleDef, suspensionTravel),						ASSET_ENTRY_FLOAT,0,0},
	{"heliCollisionScalar",						offsetof(VehicleDef, heliCollisionScalar),					ASSET_ENTRY_FLOAT,0,0},
	{"viewPitchOffset",							offsetof(VehicleDef, viewPitchOffset),						ASSET_ENTRY_FLOAT,0,0},
	{"viewInfluence",							offsetof(VehicleDef, viewInfluence),						ASSET_ENTRY_FLOAT,0,0},
	{"tiltFromAccelerationPitch",				offsetof(VehicleDef, tiltFromAccelerationPitch),			ASSET_ENTRY_FLOAT,0,0},
	{"tiltFromAccelerationRoll",				offsetof(VehicleDef, tiltFromAccelerationRoll),				ASSET_ENTRY_FLOAT,0,0},
	{"tiltFromDecelerationPitch",				offsetof(VehicleDef, tiltFromDecelerationPitch),			ASSET_ENTRY_FLOAT,0,0},
	{"tiltFromDecelerationRoll",				offsetof(VehicleDef, tiltFromDecelerationRoll),				ASSET_ENTRY_FLOAT,0,0},
	{"tiltFromVelocityPitch",					offsetof(VehicleDef, tiltFromVelocityPitch),				ASSET_ENTRY_FLOAT,0,0},
	{"tiltFromVelocityRoll",					offsetof(VehicleDef, tiltFromVelocityRoll),					ASSET_ENTRY_FLOAT,0,0},
	{"tiltSpeedPitch",							offsetof(VehicleDef, tiltSpeedPitch),						ASSET_ENTRY_FLOAT,0,0},
	{"tiltSpeedRoll",							offsetof(VehicleDef, tiltSpeedRoll),						ASSET_ENTRY_FLOAT,0,0},
	{"turretWeapon",							offsetof(VehicleDef, turretWeapon),							ASSET_ENTRY_STRING,0,0},
	{"turret",									offsetof(VehicleDef, turretViewLimits),						ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"turretRotRate",							offsetof(VehicleDef, turretRotRate),						ASSET_ENTRY_FLOAT,0,0},
	{"turretClampPlayerView",					offsetof(VehicleDef, turretClampPlayerView),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"turretLockTurretToPlayerView",			offsetof(VehicleDef, turretLockTurretToPlayerView),			ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"gunnerWeapon",							offsetof(VehicleDef, gunnerWeapon),							ASSET_ENTRY_EMBEDDED,			GunnerWeaponEntry,0},
	{"gunnerRotRate",							offsetof(VehicleDef, gunnerRotRate),						ASSET_ENTRY_FLOAT,0,0},
	{"gunnerRest0",								offsetof(VehicleDef, gunnerRestAngles[0]),					ASSET_ENTRY_EMBEDDED,			Vec2OffsetEntry,0},
	{"gunnerRest1",								offsetof(VehicleDef, gunnerRestAngles[1]),					ASSET_ENTRY_EMBEDDED,			Vec2OffsetEntry,0},
	{"gunnerRest2",								offsetof(VehicleDef, gunnerRestAngles[2]),					ASSET_ENTRY_EMBEDDED,			Vec2OffsetEntry,0},
	{"gunnerRest3",								offsetof(VehicleDef, gunnerRestAngles[3]),					ASSET_ENTRY_EMBEDDED,			Vec2OffsetEntry,0},
	{"passenger1",								offsetof(VehicleDef, passengerViewLimits[0]),				ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"passenger2",								offsetof(VehicleDef, passengerViewLimits[1]),				ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"passenger3",								offsetof(VehicleDef, passengerViewLimits[2]),				ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"passenger4",								offsetof(VehicleDef, passengerViewLimits[3]),				ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"passenger5",								offsetof(VehicleDef, passengerViewLimits[4]),				ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"passenger6",								offsetof(VehicleDef, passengerViewLimits[5]),				ASSET_ENTRY_EMBEDDED,			SpanEntry,0},
	{"turretSpinSndName",						offsetof(VehicleDef, turretSpinSndName),					ASSET_ENTRY_STRING,0,0},
	{"turretStopSndName",						offsetof(VehicleDef, turretStopSndName),					ASSET_ENTRY_STRING,0,0},
	{"turretSpinSndIndex",						offsetof(VehicleDef, turretSpinSndIndex),					ASSET_ENTRY_INT,0,0},
	{"turretStopSndIndex",						offsetof(VehicleDef, turretStopSndIndex),					ASSET_ENTRY_INT,0,0},
	{"wheelRoadNoiseSnd",						offsetof(VehicleDef, wheelRoadNoiseSnd),					ASSET_ENTRY_STRING,0,0},
	{"wheelSlidingSnd",							offsetof(VehicleDef, wheelSlidingSnd),						ASSET_ENTRY_STRING,0,0},
	{"wheelPeelingOutSnd",						offsetof(VehicleDef, wheelPeelingOutSnd),					ASSET_ENTRY_STRING,0,0},
	{"skidSpeedMin",							offsetof(VehicleDef, skidSpeedMin),							ASSET_ENTRY_FLOAT,0,0},
	{"skidSpeedMax",							offsetof(VehicleDef, skidSpeedMax),							ASSET_ENTRY_FLOAT,0,0},
	{"futzName",								offsetof(VehicleDef, futzName),								ASSET_ENTRY_STRING,0,0},
	{"futzBlend",								offsetof(VehicleDef, futzBlend),							ASSET_ENTRY_FLOAT,0,0},
	{"animType",								offsetof(VehicleDef, animType),								ASSET_ENTRY_INT,0,0},
	{"animSet",									offsetof(VehicleDef, animSet),								ASSET_ENTRY_STRING,0,0},
	{"scriptedAnimationEntry",					offsetof(VehicleDef, scriptedAnimationEntry),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"mantleAngleFront",						offsetof(VehicleDef, mantleAngleFront),						ASSET_ENTRY_FLOAT,0,0},
	{"mantleAngleBack",							offsetof(VehicleDef, mantleAngleBack),						ASSET_ENTRY_FLOAT,0,0},
	{"mantleAngleLeft",							offsetof(VehicleDef, mantleAngleLeft),						ASSET_ENTRY_FLOAT,0,0},
	{"mantleAngleRight",						offsetof(VehicleDef, mantleAngleRight),						ASSET_ENTRY_FLOAT,0,0},
	{"extraWheelLeft1",							offsetof(VehicleDef, extraWheelLeft1),						ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"extraWheelRight1",						offsetof(VehicleDef, extraWheelRight1),						ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"extraWheelLeft2",							offsetof(VehicleDef, extraWheelLeft2),						ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"extraWheelRight2",						offsetof(VehicleDef, extraWheelRight1),						ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"driverHideTag",							offsetof(VehicleDef, driverHideTag),						ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"attachmentModel",							offsetof(VehicleDef, attachmentModels),						ASSET_ENTRY_EMBEDDED,			VehModelArrayEntry,0},
	{"attachmentTag",							offsetof(VehicleDef, attachmentTags),						ASSET_ENTRY_EMBEDDED,			VehScriptStringArray,0},
	{"deathAttachmentModel",					offsetof(VehicleDef, deathAttachmentModels),				ASSET_ENTRY_EMBEDDED,			VehModelArrayEntry,0},
	{"deathAttachmentTag",						offsetof(VehicleDef, deathAttachmentTags),					ASSET_ENTRY_EMBEDDED,			VehScriptStringArray,0},
	{"tracerOffsetForward",						offsetof(VehicleDef, tracerOffsetForward),					ASSET_ENTRY_FLOAT,0,0},
	{"tracerOffsetUp",							offsetof(VehicleDef, tracerOffsetUp),						ASSET_ENTRY_FLOAT,0,0},
	{"model",									offsetof(VehicleDef, model),								ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"viewModel",								offsetof(VehicleDef, viewModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"deathModel",								offsetof(VehicleDef, deathModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"enemyModel",								offsetof(VehicleDef, enemyModel),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"modelSwapDelay",							offsetof(VehicleDef, modelSwapDelay),						ASSET_ENTRY_FLOAT,0,0},
	{"exhaustFx",								offsetof(VehicleDef, exhaustFx),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"oneExhaust",								offsetof(VehicleDef, oneExhaust),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"treadFx",									offsetof(VehicleDef, treadFx),								ASSET_ENTRY_EMBEDDED,			SurfaceFxEntries,0},
	{"deathFx",									offsetof(VehicleDef, deathFx),								ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"deathFxTag",								offsetof(VehicleDef, deathFxTag),							ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"deathFxSound",							offsetof(VehicleDef, deathFxSound),							ASSET_ENTRY_STRING,0,0},
	{"lightFx",									offsetof(VehicleDef, lightFxName),							ASSET_ENTRY_EMBEDDED,			VehFXArrayEntry,0},
	{"lightFxTag",								offsetof(VehicleDef, lightFxTag[0]),						ASSET_ENTRY_EMBEDDED,			VehScriptStringArray,0},
	{"friendlyLightFx",							offsetof(VehicleDef, friendlyLightFx),						ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"friendlyLightFxTag",						offsetof(VehicleDef, friendlyLightFxTag),					ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"enemyLightFx",							offsetof(VehicleDef, enemyLightFx),							ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"enemyLightFxTag",							offsetof(VehicleDef, enemyLightFxTag),						ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"radiusDamageMin",							offsetof(VehicleDef, radiusDamageMin),						ASSET_ENTRY_FLOAT,0,0},
	{"radiusDamageMax",							offsetof(VehicleDef, radiusDamageMax),						ASSET_ENTRY_FLOAT,0,0},
	{"radiusDamageRadius",						offsetof(VehicleDef, radiusDamageRadius),					ASSET_ENTRY_FLOAT,0,0},
	{"shootShock",								offsetof(VehicleDef, shootShock),							ASSET_ENTRY_STRING,0,0},
	{"shootRumble",								offsetof(VehicleDef, shootRumble),							ASSET_ENTRY_STRING,0,0},
	{"deathQuakeScale",							offsetof(VehicleDef, deathQuakeScale),						ASSET_ENTRY_FLOAT,0,0},
	{"deathQuakeDuration",						offsetof(VehicleDef, deathQuakeDuration),					ASSET_ENTRY_FLOAT,0,0},
	{"deathQuakeRadius",						offsetof(VehicleDef, deathQuakeRadius),						ASSET_ENTRY_FLOAT,0,0},
	{"rumbleType",								offsetof(VehicleDef, rumbleType),							ASSET_ENTRY_STRING,0,0},
	{"rumbleScale",								offsetof(VehicleDef, rumbleScale),							ASSET_ENTRY_FLOAT,0,0},
	{"rumbleDuration",							offsetof(VehicleDef, rumbleDuration),						ASSET_ENTRY_FLOAT,0,0},
	{"rumbleRadius",							offsetof(VehicleDef, rumbleRadius),							ASSET_ENTRY_FLOAT,0,0},
	{"rumbleBaseTime",							offsetof(VehicleDef, rumbleBaseTime),						ASSET_ENTRY_FLOAT,0,0},
	{"rumbleAdditionalTime",					offsetof(VehicleDef, rumbleAdditionalTime),					ASSET_ENTRY_FLOAT,0,0},
	{"healthDefault",							offsetof(VehicleDef, healthDefault),						ASSET_ENTRY_INT,0,0},
	{"healthMin",								offsetof(VehicleDef, healthMin),							ASSET_ENTRY_INT,0,0},
	{"healthMax",								offsetof(VehicleDef, healthMax),							ASSET_ENTRY_INT,0,0},
	{"team",									offsetof(VehicleDef, eTeam),								ASSET_ENTRY_INT,0,0},
	{"boostAccelMultiplier",					offsetof(VehicleDef, boostAccelMultiplier),					ASSET_ENTRY_INT,0,0},
	{"boostDuration",							offsetof(VehicleDef, boostDuration),						ASSET_ENTRY_FLOAT,0,0},
	{"boostSpeedIncrease",						offsetof(VehicleDef, boostSpeedIncrease),					ASSET_ENTRY_FLOAT,0,0},
	{"addToCompass",							offsetof(VehicleDef, addToCompass),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"addToCompassEnemy",						offsetof(VehicleDef, addToCompassEnemy),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"compassIcon",								offsetof(VehicleDef, compassIcon),							ASSET_ENTRY_STRING,0,0},
	{"compassIconMaterial",						offsetof(VehicleDef, compassIconMaterial),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"gasButton",								offsetof(VehicleDef, gasButtonName),						ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"reverseBrakeButton",						offsetof(VehicleDef, reverseBrakeButtonName),				ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"handBrakeButton",							offsetof(VehicleDef, handBrakeButtonName),					ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"attackButton",							offsetof(VehicleDef, attackButtonName),						ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"attackSecondaryButton",					offsetof(VehicleDef, attackSecondaryButtonName),			ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"boostButton",								offsetof(VehicleDef, boostButtonName),						ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"moveUpButton",							offsetof(VehicleDef, moveUpButtonName),						ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"moveDownButton",							offsetof(VehicleDef, moveDownButtonName),					ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"switchSeatsButton",						offsetof(VehicleDef, switchSeatButtonName),					ASSET_ENTRY_EMBEDDED,			VehButtonEntry,0},
	{"steerGraph",								offsetof(VehicleDef, steerGraph),							ASSET_ENTRY_STRING,0,0},
	{"accelGraph",								offsetof(VehicleDef, accelGraph),							ASSET_ENTRY_STRING,0,0},
	{"isNitrous",								offsetof(VehicleDef, isNitrous),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"isFourWheelSteering",						offsetof(VehicleDef, isFourWheelSteering),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"useCollmap",								offsetof(VehicleDef, useCollmap),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"radius",									offsetof(VehicleDef, radius),								ASSET_ENTRY_FLOAT,0,0},
	{"minHeight",								offsetof(VehicleDef, minHeight),							ASSET_ENTRY_FLOAT,0,0},
	{"maxHeight",								offsetof(VehicleDef, maxHeight),							ASSET_ENTRY_FLOAT,0,0},
	{"max_fric_tilt_angle",						offsetof(VehicleDef, max_fric_tilt_angle),					ASSET_ENTRY_FLOAT,0,0},
	{"max_fric_tilt",							offsetof(VehicleDef, max_fric_tilt),						ASSET_ENTRY_FLOAT,0,0},
	{"noDirectionalDamage",						offsetof(VehicleDef, noDirectionalDamage),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"fakeBodyStabilizer",						offsetof(VehicleDef, fakeBodyStabilizer),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"vehHelicopterBoundsRadius",				offsetof(VehicleDef, vehHelicopterBoundsRadius),			ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterDecelerationFwd",			offsetof(VehicleDef, vehHelicopterDecelerationFwd),			ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterDecelerationSide",			offsetof(VehicleDef, vehHelicopterDecelerationSide),		ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterDecelerationUp",				offsetof(VehicleDef, vehHelicopterDecelerationUp),			ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterTiltFromControllerAxes",		offsetof(VehicleDef, vehHelicopterTiltFromControllerAxes),	ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterTiltFromFwdAndYaw",			offsetof(VehicleDef, vehHelicopterTiltFromFwdAndYaw),		ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt",offsetof(VehicleDef, vehHelicopterTiltFromFwdAndYaw_VelAtMaxTilt),ASSET_ENTRY_FLOAT,0,0},//This entry name suxxx
	{"vehHelicopterTiltMomentum",				offsetof(VehicleDef, vehHelicopterTiltMomentum),			ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterQuadRotor",					offsetof(VehicleDef, vehHelicopterQuadRotor),				ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"vehHelicopterAccelTwardsView",			offsetof(VehicleDef, vehHelicopterAccelTwardsView),			ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"maxRotorArmMovementAngle",				offsetof(VehicleDef, maxRotorArmMovementAngle),				ASSET_ENTRY_FLOAT,0,0},
	{"maxRotorArmRotationAngle",				offsetof(VehicleDef, maxRotorArmRotationAngle),				ASSET_ENTRY_FLOAT,0,0},
	{"vehHelicopterMaintain",					offsetof(VehicleDef, vehHelicopterMaintainHeight),			ASSET_ENTRY_EMBEDDED,			VehHeliMaintainEntries,0},
	{"joltVehicle",								offsetof(VehicleDef, joltVehicle),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"joltVehicleDriver",						offsetof(VehicleDef, joltVehicleDriver),					ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"joltMaxTime",								offsetof(VehicleDef, joltMaxTime),							ASSET_ENTRY_FLOAT,0,0},
	{"joltTime",								offsetof(VehicleDef, joltTime),								ASSET_ENTRY_FLOAT,0,0},
	{"joltWaves",								offsetof(VehicleDef, joltWaves),							ASSET_ENTRY_FLOAT,0,0},
	{"joltIntensity",							offsetof(VehicleDef, joltIntensity),						ASSET_ENTRY_FLOAT,0,0},
	{"nitrous_",								offsetof(VehicleDef, nitrousVehParams),						ASSET_ENTRY_EMBEDDED,			VehNosEntries,0},
	{"p_driveby_sound_radius",					offsetof(VehicleDef, p_driveby_sound_radius),				ASSET_ENTRY_FLOAT,0,0},
	{"s_driveby_sound_radius",					offsetof(VehicleDef, s_driveby_sound_radius),				ASSET_ENTRY_FLOAT,0,0},
	{"1",										offsetof(VehicleDef, p[0]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"2",										offsetof(VehicleDef, p[1]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"3",										offsetof(VehicleDef, p[2]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"4",										offsetof(VehicleDef, p[3]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"5",										offsetof(VehicleDef, p[4]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"6",										offsetof(VehicleDef, p[5]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"7",										offsetof(VehicleDef, p[6]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"8",										offsetof(VehicleDef, p[7]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"9",										offsetof(VehicleDef, p[8]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"10",										offsetof(VehicleDef, p[9]),									ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"11",										offsetof(VehicleDef, p[10]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"12",										offsetof(VehicleDef, p[11]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"13",										offsetof(VehicleDef, p[12]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"14",										offsetof(VehicleDef, p[13]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"15",										offsetof(VehicleDef, p[14]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"16",										offsetof(VehicleDef, p[15]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"17",										offsetof(VehicleDef, p[16]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"18",										offsetof(VehicleDef, p[17]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"19",										offsetof(VehicleDef, p[18]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"20",										offsetof(VehicleDef, p[19]),								ASSET_ENTRY_EMBEDDED_REVERSED,	PVehDrivebySound,0},
	{"1",										offsetof(VehicleDef, s[0]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"2",										offsetof(VehicleDef, s[1]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"3",										offsetof(VehicleDef, s[2]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"4",										offsetof(VehicleDef, s[3]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"5",										offsetof(VehicleDef, s[4]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"6",										offsetof(VehicleDef, s[5]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"7",										offsetof(VehicleDef, s[6]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"8",										offsetof(VehicleDef, s[7]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"9",										offsetof(VehicleDef, s[8]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"10",										offsetof(VehicleDef, s[9]),									ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"11",										offsetof(VehicleDef, s[10]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"12",										offsetof(VehicleDef, s[11]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"13",										offsetof(VehicleDef, s[12]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"14",										offsetof(VehicleDef, s[13]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"15",										offsetof(VehicleDef, s[14]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"16",										offsetof(VehicleDef, s[15]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"17",										offsetof(VehicleDef, s[16]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"18",										offsetof(VehicleDef, s[17]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"19",										offsetof(VehicleDef, s[18]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"20",										offsetof(VehicleDef, s[19]),								ASSET_ENTRY_EMBEDDED_REVERSED,	SVehDrivebySound,0},
	{"doFootSteps",								offsetof(VehicleDef, doFootSteps),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"isSentient",								offsetof(VehicleDef, isSentient),							ASSET_ENTRY_BOOL_AS_INT,0,0},
	{"",										offsetof(VehicleDef, engine),								ASSET_ENTRY_EMBEDDED,			VehEngineEntries,0},
	{"antenna1_",								offsetof(VehicleDef, antenna[0]),							ASSET_ENTRY_EMBEDDED,			VehAntennaEntries,0},
	{"antenna2_",								offsetof(VehicleDef, antenna[1]),							ASSET_ENTRY_EMBEDDED,			VehAntennaEntries,0},
	{"csvInclude",								offsetof(VehicleDef, csvInclude),							ASSET_ENTRY_STRING,0,0},
	{"customFloat0",							offsetof(VehicleDef, customFloat[0]),						ASSET_ENTRY_FLOAT,0,0},
	{"customFloat1",							offsetof(VehicleDef, customFloat[1]),						ASSET_ENTRY_FLOAT,0,0},
	{"customFloat2",							offsetof(VehicleDef, customFloat[2]),						ASSET_ENTRY_FLOAT,0,0},
	{"customBool0",								offsetof(VehicleDef, customBool[0]),						ASSET_ENTRY_BOOL,0,0},
	{"customBool1",								offsetof(VehicleDef, customBool[1]),						ASSET_ENTRY_BOOL,0,0},
	{"customBool2",								offsetof(VehicleDef, customBool[2]),						ASSET_ENTRY_BOOL,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_VehicleDefAsset_t Load_VehicleDefAsset = (Load_VehicleDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x478)) + 0xA4));

int VehicleDef::dumpVehicleDef()
{
	CreateDirectoryB(va("game:\\dump\\vehicles\\%s", (char*)name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "vehicle", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog, "VEHICLEFILE");

	for(int i = 0; VehicleDefEntries[i].name; i++)
		DumpAssetEntry(writeLog, VehicleDefEntries[i].type, VehicleDefEntries[i].name, (void*)((int)(this) + VehicleDefEntries[i].offset), VehicleDefEntries[i].next, VehicleDefEntries[i].enumCount);

	fclose(writeLog);

	return ERROR_SUCCESS;
}

void Load_VehicleDefAssetHook(VehicleDef ** input)
{
	VehicleDef * currentVehicle = *input;
	//currentVehicle->dumpVehicleDef();

	//Can we load this tracer custom?
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\vehicles\\%s", currentVehicle->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE vehicleFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(vehicleFile, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (numberOfBytesRead + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[numberOfBytesRead + 1];

		ZeroMemory(myBuffer, numberOfBytesRead + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(vehicleFile != INVALID_HANDLE_VALUE && ReadFile(vehicleFile, myBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0))
		{
			char * currentName = 0, * currentValue = 0;

			CloseHandle(vehicleFile);
			char * currentToken = improved_strtok(myBuffer,"\\");

			if(!strcmp(currentToken, "VEHICLEFILE"))
			for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
			{
				currentName = currentToken;
				currentValue = improved_strtok(NULL,"\\");

				if(WriteAssetEntry(VehicleDefEntries, currentName, currentValue, currentVehicle))
					continue;
				else 
					printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "vehicle", currentVehicle->name);
			}
			else
				printf("%s is not a %s file\n", currentVehicle->name, "vehicle");
		}

		if(allocatedBuffer) delete[] myBuffer;
	}
	usingAssetBuffer = false;

	Load_VehicleDefAssetSaveStub(input);
}
#pragma endregion

#pragma region tracer (0x37)
AssetEntry TracerDefEntries[] = 
{
	{"type",			offsetof(TracerDef,type),			ASSET_ENTRY_ENUM,				(AssetEntry*)tracerTypeNames,			TRACERTYPE_NUM},
	{"material",		offsetof(TracerDef,material),		ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_MATERIAL,0},
	{"drawInterval",	offsetof(TracerDef,drawInterval),	ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"speed",			offsetof(TracerDef,speed),			ASSET_ENTRY_FLOAT,0,0},
	{"beamLength",		offsetof(TracerDef,beamLength),		ASSET_ENTRY_FLOAT,0,0},
	{"beamWidth",		offsetof(TracerDef,beamWidth),		ASSET_ENTRY_FLOAT,0,0},
	{"screwRadius",		offsetof(TracerDef,screwRadius),	ASSET_ENTRY_FLOAT,0,0},
	{"screwDist",		offsetof(TracerDef,screwDist),		ASSET_ENTRY_FLOAT,0,0},
	{"fadeTime",		offsetof(TracerDef,fadeTime),		ASSET_ENTRY_FLOAT,0,0},
	{"fadeScale",		offsetof(TracerDef,fadeScale),		ASSET_ENTRY_FLOAT,0,0},
	{"texRepeatRate",	offsetof(TracerDef,texRepeatRate),	ASSET_ENTRY_FLOAT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_TracerDefAsset_t Load_TracerDefAsset = (Load_TracerDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x4CC)) + 0xA4));

int TracerDef::dumpTracerDef()
{
	CreateDirectoryB(va("game:\\dump\\tracer\\%s", (char*)name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "tracer", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog, "TRACER");

	for(int i = 0; TracerDefEntries[i].name; i++)
		DumpAssetEntry(writeLog, TracerDefEntries[i].type, TracerDefEntries[i].name, (void*)((int)(this) + TracerDefEntries[i].offset), TracerDefEntries[i].next, TracerDefEntries[i].enumCount);

	for(int i = 0; i < 5; i++)
		fprintf(writeLog, "\\color%iR\\%g\\color%iG\\%g\\color%iB\\%g\\color%iA\\%g", i, colors[i][0], i, colors[i][1], i, colors[i][2], i, colors[i][3]);

	fclose(writeLog);

	return ERROR_SUCCESS;
}

void Load_TracerDefAssetHook(TracerDef ** input)
{
	TracerDef * currentTracer = *input;
	//currentTracer->dumpTracerDef();

	//Can we load this tracer custom?
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\tracer\\%s", currentTracer->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE tracerFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead;
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		if(tracerFile != INVALID_HANDLE_VALUE && ReadFile(tracerFile, theAssetBuffer, GetFileSize(tracerFile, NULL), (LPDWORD)&numberOfBytesRead, 0))
		{
			char * currentName = 0, * currentValue = 0;

			CloseHandle(tracerFile);
			char * currentToken = improved_strtok(theAssetBuffer,"\\");

			if(!strcmp(currentToken, "TRACER"))
			for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
			{
				currentName = currentToken;
				currentValue = improved_strtok(NULL,"\\");

				if(WriteAssetEntry(TracerDefEntries, currentName, currentValue, currentTracer))
					continue;
				else if(!strnicmp(currentName, "color", 5))
				{
					int currentIndex = currentName[5] - 0x30;
					switch(currentName[6])
					{
					case 'R':
					case 'r':
						currentTracer->colors[currentIndex][0] = atof(currentValue);
						break;
					case 'G':
					case 'g':
						currentTracer->colors[currentIndex][1] = atof(currentValue);
						break;
					case 'B':
					case 'b':
						currentTracer->colors[currentIndex][2] = atof(currentValue);
						break;
					case 'A':
					case 'a':
						currentTracer->colors[currentIndex][3] = atof(currentValue);
						break;
					}
				}
				else 
					printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "tracer", currentTracer->name);
			}
			else
				printf("%s is not a %s file\n", currentTracer->name, "tracer");
		}
	}
	usingAssetBuffer = false;

	Load_TracerDefAssetSaveStub(input);
}
#pragma endregion

#pragma region qdb (0x39)
Load_QdbAsset_t Load_QdbAsset = (Load_QdbAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x504)) + 0xA4));

int Qdb::dumpQdb()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;

	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fwrite(buffer,1,len,writeLog);
	fclose(writeLog);
	return ERROR_SUCCESS;
}

//I would never expect anyone to use this loader, or even dumper for that matter...
//This is here for my purposes only.
//CopyPasta from RawFile.
char customLoadedQdbs[0x40][0x20];
char * customLoadedQdbData[0x40];
int customLoadedQdbCount = 0;
void Load_QdbAssetHook(Qdb ** input)
{
	//(*input)->dumpQdb();
	Qdb * fileToUse = 0, *oldQdbUsed = *input;

	//Have we loaded this qdb custom before?
	for(int i = 0; i < customLoadedQdbCount; i++)
	{
		if(!customLoadedQdbs[i])
			break;

		if(!stricmp(oldQdbUsed->name, customLoadedQdbs[i]))
		{
			fileToUse = *input;
			fileToUse->buffer = customLoadedQdbData[i];
		}
	}

	//Can we load this qdb custom?
	while(usingAssetBuffer) Sleep(0);
		
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName(oldQdbUsed->name));
	if(!fileToUse && fileExists(theAssetBuffer))
	{
		HANDLE qdbFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(qdbFile, NULL);

		if(numberOfBytesRead == 0 && fileToUse->buffer == 0) {}
 		else if(qdbFile != INVALID_HANDLE_VALUE)
		{
			fileToUse = oldQdbUsed;
			if(oldQdbUsed->len < numberOfBytesRead)
			{
				fileToUse->buffer = new char[numberOfBytesRead+1];
				ZeroMemory((char*)fileToUse->buffer, numberOfBytesRead+1);
				customLoadedQdbData[customLoadedQdbCount] = (char*)fileToUse->buffer;
				strcpy(customLoadedQdbs[customLoadedQdbCount], fileToUse->name);
				customLoadedQdbCount++;
			}
			else
				ZeroMemory((char*)fileToUse->buffer, fileToUse->len+1);

			ReadFile(qdbFile, (LPVOID)fileToUse->buffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);

			fileToUse->len = numberOfBytesRead;
			CloseHandle(qdbFile);
		}
	}
	usingAssetBuffer = false;

	Load_QdbAssetSaveStub(input);
}
#pragma endregion

#pragma region slug (0x3A)
Load_SlugAsset_t Load_SlugAsset = (Load_SlugAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x520)) + 0xA4));

int Slug::dumpSlug()
{
	CreateDirectoryB(va("game:\\dump\\%s", ConvertAssetNameToFileName((char*)name,dumpFileName)));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;

	FILE * writeLog = fopen(MasterCharBuffer, "wb");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fwrite(buffer,1,len,writeLog);
	fclose(writeLog);
	return ERROR_SUCCESS;
}

//I would never expect anyone to use this loader, or even dumper for that matter...
//This is here for my purposes only.
//CopyPasta from Qdb.
char customLoadedSlugs[0x40][0x20];
char * customLoadedSlugData[0x40];
int customLoadedSlugCount = 0;
void Load_SlugAssetHook(Slug ** input)
{
	//(*input)->dumpSlug();
	Slug * fileToUse = 0, *oldSlugUsed = *input;

	//Have we loaded this slug custom before?
	for(int i = 0; i < customLoadedSlugCount; i++)
	{
		if(!customLoadedSlugs[i])
			break;

		if(!stricmp(oldSlugUsed->name, customLoadedSlugs[i]))
		{
			fileToUse = *input;
			fileToUse->buffer = customLoadedSlugData[i];
		}
	}

	//Can we load this slug custom?
	while(usingAssetBuffer) Sleep(0);
		
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\%s", ConvertAssetNameToFileName(oldSlugUsed->name));
	if(!fileToUse && fileExists(theAssetBuffer))
	{
		HANDLE slugFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(slugFile, NULL);

		if(numberOfBytesRead == 0 && fileToUse->buffer == 0) {}
 		else if(slugFile != INVALID_HANDLE_VALUE)
		{
			fileToUse = oldSlugUsed;
			if(oldSlugUsed->len < numberOfBytesRead)
			{
				fileToUse->buffer = new char[numberOfBytesRead+1];
				ZeroMemory((char*)fileToUse->buffer, numberOfBytesRead+1);
				customLoadedSlugData[customLoadedSlugCount] = (char*)fileToUse->buffer;
				strcpy(customLoadedSlugs[customLoadedSlugCount], fileToUse->name);
				customLoadedSlugCount++;
			}
			else
				ZeroMemory((char*)fileToUse->buffer, fileToUse->len+1);

			ReadFile(slugFile, (LPVOID)fileToUse->buffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0);

			fileToUse->len = numberOfBytesRead;
			CloseHandle(slugFile);
		}
	}
	usingAssetBuffer = false;

	Load_SlugAssetSaveStub(input);
}
#pragma endregion

#pragma region footsteptable (0x3B)
Load_FootstepTableDefAsset_t Load_FootstepTableDefAsset = (Load_FootstepTableDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x53C)) + 0xA4));

int FootstepTableDef::dumpFootstepTableDef()
{
	CreateDirectoryB(va("game:\\dump\\fx\\%s.csv", ConvertAssetNameToFileName((char*)name,dumpFileName)));
	
	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "stringtable", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	for(int i = 0; i < 0x20; i++) 
		for(int j = 0; j < 7; i++)
			fprintf(writeLog, "%u%s", sndAliasTable[i][j], j == 6 ? (i == 0x1F ? "" : "\n") : ",");

	fclose(writeLog);
	return ERROR_SUCCESS;
}

//Note that I've edited this to no results.
//I've debugged and the loader appears to be working, but unless I'm missing something the game does not appear to reference this and the next asset.
void Load_FootstepTableDefAssetHook(FootstepTableDef ** input)
{
	FootstepTableDef * oldTable = *input;
	//oldTable->dumpFootstepTableDef();

	//Can we load this stringtable custom?
	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\fx\\%s.csv", ConvertAssetNameToFileName(oldTable->name));
	if(fileExists(theAssetBuffer))
	{
		FootstepTableDef* newTable = 0;
		HANDLE footstepTableDefFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int footstepTableDefFileLength = GetFileSize(footstepTableDefFile, NULL);
		ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
		
		if(footstepTableDefFile != INVALID_HANDLE_VALUE && ReadFile(footstepTableDefFile, theAssetBuffer, footstepTableDefFileLength, (LPDWORD)&footstepTableDefFileLength, 0))
		{
			CloseHandle(footstepTableDefFile);
			strtk::token_grid grid(theAssetBuffer, footstepTableDefFileLength, strtkGridOptions);
			int rows = grid.row_count();
			int columns = grid.row_count();
			
			if(rows == 0x20 && columns == 7)
			for (std::size_t ri = 0; ri < 0x20; ri++)
			{
				strtk::token_grid::row_type r = grid.row(ri);
				for (std::size_t ci = 0; ci < 7; ci++)
				{
					std::string strSource = r.get<std::string>(ci);
					long long value = _atoi64(strSource.c_str());
					oldTable->sndAliasTable[ri][ci] = *(unsigned int*)(&value + 4);
				}
			}
			else
				printf("Loaded footstep table %s with unrecognized column/row counts\n", oldTable->name);
			grid.clear();
		}
	}
	usingAssetBuffer = false;

	Load_FootstepTableDefAssetSaveStub(input);
}
#pragma endregion

#pragma region footstepfxtable (0x3C)
Load_FootstepFXTableDefAsset_t Load_FootstepFXTableDefAsset = (Load_FootstepFXTableDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x558)) + 0xA4));

int FootstepFXTableDef::dumpFootstepFXTableDef()
{
	CreateDirectoryB(va("game:\\dump\\fx\\bio\\player\\%s.csv", ConvertAssetNameToFileName((char*)name,dumpFileName)));
	
	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;
		//printf("Overwriting previously dumped %s at %s\n", "stringtable", MasterCharBuffer);

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	for(int j = 0; j < 0x20; j++) {
		FxEffectDef * currentFx = footstepFX[j];
		fprintf(writeLog, "surfaceFx%s,%s%s", SurfaceFxEntries[j].name, currentFx ? currentFx->name : "", j == 0x1F ? "" : "\n");
	}

	fclose(writeLog);
	return ERROR_SUCCESS;
}

//Note that I've edited this to no results.
//I've debugged and the loader appears to be working, but unless I'm missing something the game does not appear to reference this and the previous asset.
void Load_FootstepFXTableDefAssetHook(FootstepFXTableDef ** input)
{
	FootstepFXTableDef * oldTable = *input;
//	oldTable->dumpFootstepFXTableDef();

	while(usingAssetBuffer) Sleep(0);
	
	usingAssetBuffer = true;
	sprintf(theAssetBuffer, "game:\\raw\\fx\\bio\\player\\%s.csv", ConvertAssetNameToFileName(oldTable->name));
	if(fileExists(theAssetBuffer))
	{
		FootstepFXTableDef* newTable = 0;
		HANDLE footstepFXTableDefFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int footstepFXTableDefFileLength = GetFileSize(footstepFXTableDefFile, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (footstepFXTableDefFileLength + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[footstepFXTableDefFileLength + 1];

		ZeroMemory(myBuffer, footstepFXTableDefFileLength + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(footstepFXTableDefFile != INVALID_HANDLE_VALUE && ReadFile(footstepFXTableDefFile, myBuffer, footstepFXTableDefFileLength, (LPDWORD)&footstepFXTableDefFileLength, 0))
		{
			CloseHandle(footstepFXTableDefFile);
			strtk::token_grid grid(myBuffer, footstepFXTableDefFileLength, strtkGridOptions);
			int rows = grid.row_count();

			for (std::size_t ri = 0; ri < (std::size_t)rows; ri++)
			{
				strtk::token_grid::row_type r = grid.row(ri);
				std::string strSourceSurfaceName = r.get<std::string>(0);
				std::string strSourceFxName = r.get<std::string>(1);

				//Find proper fx index
				int workingIndex = 0;
				char tempSurfNameBuff[0x18];
				ZeroMemory(tempSurfNameBuff,sizeof(tempSurfNameBuff));
				for(int workingIndex = 0; workingIndex < 0x20; workingIndex++) {
					sprintf(tempSurfNameBuff, "surfaceFx%s", SurfaceFxEntries[workingIndex].name);
					if(!stricmp(tempSurfNameBuff, strSourceSurfaceName.c_str()))
						break;
				}

				FxEffectDef * toReplaceWith =  *(strSourceFxName.c_str()) ? DB_FindXAssetHeader(ASSET_TYPE_FX, strSourceFxName.c_str(), true, -1).fx : 0;
				oldTable->footstepFX[workingIndex] = toReplaceWith;
			}
			grid.clear();

			if(allocatedBuffer) delete myBuffer;
		}
	}
	usingAssetBuffer = false;

	Load_FootstepFXTableDefAssetSaveStub(input);
}
#pragma endregion

#pragma region zbarrier (0x3D)
AssetEntry ZBarrierBoardEntries[] = 
{
	{"pBoardModel",					offsetof(ZBarrierBoard,pBoardModel),					ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"pAlternateBoardModel",		offsetof(ZBarrierBoard,pAlternateBoardModel),			ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"pUpgradedBoardModel",			offsetof(ZBarrierBoard,pUpgradedBoardModel),			ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_XMODEL,0},
	{"pTearAnim",					offsetof(ZBarrierBoard,pTearAnim),						ASSET_ENTRY_STRING,0,0},
	{"pBoardAnim",					offsetof(ZBarrierBoard,pBoardAnim),						ASSET_ENTRY_STRING,0,0},
	{"repairEffect1",				offsetof(ZBarrierBoard,repairEffect[0]),				ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"repairEffect2",				offsetof(ZBarrierBoard,repairEffect[1]),				ASSET_ENTRY_ASSET_PTR,			(AssetEntry*)ASSET_TYPE_FX,0},
	{"repairEffectOffset1X",		offsetof(ZBarrierBoard,repairEffectOffset[0]),			ASSET_ENTRY_FLOAT,0,0},
	{"repairEffectOffset1Y",		offsetof(ZBarrierBoard,repairEffectOffset[0]) + 4,		ASSET_ENTRY_FLOAT,0,0},
	{"repairEffectOffset1Z",		offsetof(ZBarrierBoard,repairEffectOffset[0]) + 8,		ASSET_ENTRY_FLOAT,0,0},
	{"repairEffectOffset2X",		offsetof(ZBarrierBoard,repairEffectOffset[1]),			ASSET_ENTRY_FLOAT,0,0},
	{"repairEffectOffset2Y",		offsetof(ZBarrierBoard,repairEffectOffset[1]) + 4,		ASSET_ENTRY_FLOAT,0,0},
	{"repairEffectOffset2Z",		offsetof(ZBarrierBoard,repairEffectOffset[1]) + 8,		ASSET_ENTRY_FLOAT,0,0},
	{"boardRepairSound",			offsetof(ZBarrierBoard,boardRepairSound),				ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"boardRepairHoverSound",		offsetof(ZBarrierBoard,boardRepairHoverSound),			ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"pauseAndRepeatRepairSound",	offsetof(ZBarrierBoard,pauseAndRepeatRepairSound),		ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"pauseBetweenRepSoundsMin",	offsetof(ZBarrierBoard,pauseBetweenRepSoundsMin),		ASSET_ENTRY_FLOAT,0,0},
	{"pauseBetweenRepSoundsMax",	offsetof(ZBarrierBoard,pauseBetweenRepSoundsMax),		ASSET_ENTRY_FLOAT,0,0},
	{"zombieBoardTearStateName",	offsetof(ZBarrierBoard,zombieBoardTearStateName),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"zombieBoardTearSubStateName",	offsetof(ZBarrierBoard,zombieBoardTearSubStateName),	ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"numRepsToPullProBoard",		offsetof(ZBarrierBoard,numRepsToPullProBoard),			ASSET_ENTRY_UNSIGNED_INT,0,0},
	{0, 0, (AssetEntryType)0,0,0}
};

AssetEntry ZBarrierDefEntries[] = 
{
	{"generalRepairSound1",				offsetof(ZBarrierDef,generalRepairSound[0]),			ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"generalRepairSound2",				offsetof(ZBarrierDef,generalRepairSound[1]),			ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"upgradedGeneralRepairSound1",		offsetof(ZBarrierDef,upgradedGeneralRepairSound[0]),	ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"upgradedGeneralRepairSound2",		offsetof(ZBarrierDef,upgradedGeneralRepairSound[1]),	ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"useDelayBetweenGeneralRepSounds",	offsetof(ZBarrierDef,useDelayBetweenGeneralRepSounds),	ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"delayBetweenGeneralRepSounds",	offsetof(ZBarrierDef,delayBetweenGeneralRepSounds),		ASSET_ENTRY_FLOAT,0,0},
	{"earthquakeOnRepair",				offsetof(ZBarrierDef,earthquakeOnRepair),				ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"earthquakeMinScale",				offsetof(ZBarrierDef,earthquakeMinScale),				ASSET_ENTRY_FLOAT,0,0},
	{"earthquakeMaxScale",				offsetof(ZBarrierDef,earthquakeMaxScale),				ASSET_ENTRY_FLOAT,0,0},
	{"earthquakeMinDuration",			offsetof(ZBarrierDef,earthquakeMinDuration),			ASSET_ENTRY_FLOAT,0,0},
	{"earthquakeMaxDuration",			offsetof(ZBarrierDef,earthquakeMaxDuration),			ASSET_ENTRY_FLOAT,0,0},
	{"earthquakeRadius",				offsetof(ZBarrierDef,earthquakeRadius),					ASSET_ENTRY_FLOAT,0,0},
	{"numBoardsInBarrier",				offsetof(ZBarrierDef,numBoardsInBarrier),				ASSET_ENTRY_INT,0,0},
	{"autoHideOpenPieces",				offsetof(ZBarrierDef,autoHideOpenPieces),				ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"taunts",							offsetof(ZBarrierDef,taunts),							ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"reachThroughAttacks",				offsetof(ZBarrierDef,reachThroughAttacks),				ASSET_ENTRY_UNSIGNED_INT,0,0},
	{"zombieTauntAnimState",			offsetof(ZBarrierDef,zombieTauntAnimState),				ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"zombieReachThroughAnimState",		offsetof(ZBarrierDef,zombieReachThroughAnimState),		ASSET_ENTRY_SCRIPT_STRING,0,0},
	{"numAttackSlots",					offsetof(ZBarrierDef,numAttackSlots),					ASSET_ENTRY_INT,0,0},
	{"attackSpotHorzOffset",			offsetof(ZBarrierDef,attackSpotHorzOffset),				ASSET_ENTRY_FLOAT,0,0},
	{"1",								offsetof(ZBarrierDef, boards[0]),						ASSET_ENTRY_EMBEDDED_REVERSED,	ZBarrierBoardEntries,0},
	{"2",								offsetof(ZBarrierDef, boards[1]),						ASSET_ENTRY_EMBEDDED_REVERSED,	ZBarrierBoardEntries,0},
	{"3",								offsetof(ZBarrierDef, boards[2]),						ASSET_ENTRY_EMBEDDED_REVERSED,	ZBarrierBoardEntries,0},
	{"4",								offsetof(ZBarrierDef, boards[3]),						ASSET_ENTRY_EMBEDDED_REVERSED,	ZBarrierBoardEntries,0},
	{"5",								offsetof(ZBarrierDef, boards[4]),						ASSET_ENTRY_EMBEDDED_REVERSED,	ZBarrierBoardEntries,0},
	{"6",								offsetof(ZBarrierDef, boards[5]),						ASSET_ENTRY_EMBEDDED_REVERSED,	ZBarrierBoardEntries,0},
	{0, 0, (AssetEntryType)0,0,0}
};

Load_ZBarrierDefAsset_t Load_ZBarrierDefAsset = (Load_ZBarrierDefAsset_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)Load_XAssetHeader + 0x574)) + 0xA4));

int ZBarrierDef::dumpZBarrierDef()
{
	CreateDirectoryB(va("game:\\dump\\zbarrier\\%s", name));

	if(fileExists(MasterCharBuffer))
		return ERROR_DUP_NAME;

	FILE * writeLog = fopen(MasterCharBuffer, "w");

	if(!writeLog)
		return ERROR_BAD_NETPATH;

	fprintf(writeLog,"ZBARRIER");

	for(int i = 0; ZBarrierDefEntries[i].name; i++)
		DumpAssetEntry(writeLog, ZBarrierDefEntries[i].type, ZBarrierDefEntries[i].name, (void*)((int)(this) + ZBarrierDefEntries[i].offset), ZBarrierDefEntries[i].next, ZBarrierDefEntries[i].enumCount);

	fclose(writeLog);
	return ERROR_SUCCESS;
}

void Load_ZBarrierDefAssetHook(ZBarrierDef ** input)
{
	ZBarrierDef * currentBarrier = *input;
	//currentBarrier->dumpZBarrierDef();

	while(usingAssetBuffer) Sleep(0);

	usingAssetBuffer = true;
	ZeroMemory(theAssetBuffer, sizeof(theAssetBuffer));
	sprintf(theAssetBuffer, "game:\\raw\\zbarrier\\%s", currentBarrier->name);
	if(fileExists(theAssetBuffer))
	{
		HANDLE zbarrierFile = CreateFile(theAssetBuffer, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
		int numberOfBytesRead = GetFileSize(zbarrierFile, NULL);
		
		char * myBuffer = theAssetBuffer;
		bool allocatedBuffer = (numberOfBytesRead + 1 > sizeof(theAssetBuffer));

		if(allocatedBuffer)
			myBuffer = new char[numberOfBytesRead + 1];

		ZeroMemory(myBuffer, numberOfBytesRead + 1);
		usingAssetBuffer = !allocatedBuffer;

		if(zbarrierFile != INVALID_HANDLE_VALUE && ReadFile(zbarrierFile, myBuffer, numberOfBytesRead, (LPDWORD)&numberOfBytesRead, 0))
		{
			char * currentName = 0, * currentValue = 0;

			CloseHandle(zbarrierFile);
			char * currentToken = improved_strtok(myBuffer,"\\");

			if(!strcmp(currentToken, "ZBARRIER"))
			for(currentToken = improved_strtok(NULL,"\\"); currentToken; currentToken = improved_strtok(NULL,"\\"))
			{
				currentName = currentToken;
				currentValue = improved_strtok(NULL,"\\");

				if(!WriteAssetEntry(ZBarrierDefEntries, currentName, currentValue, currentBarrier))
					printf("Couldn't recognize '%s' setting with '%s' value in %s %s.\n", currentName, currentValue, "zbarrier", currentBarrier->name);
			}
			else
				printf("%s is not a %s file\n", currentBarrier->name, "zbarrier");
		}

		if(allocatedBuffer) delete[] myBuffer;
	}
	usingAssetBuffer = false;

	Load_ZBarrierDefAssetSaveStub(input);
}
#pragma endregion
