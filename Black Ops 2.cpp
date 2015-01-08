#include <xtl.h>
#include <xboxmath.h>
#include <xbox.h>
#include <xam.h>
#include <stdio.h>
#include "Hooking.h"
#include "utility.h"
#include "AddressReverser.h"
#include "physconstraints_load_obj.h"
#include "com_sessionmodes.h"
#include "db_load.h"
#include "db_registry.h"
#include "CScr_StringList.h"
#include "stringed_hooks.h"
#include "live_anticheat.h"
#include "live_stats.h"
char MasterCharBuffer[0x8000];
char theAssetBuffer[0x8000];
bool usingAssetBuffer = false;

#pragma optimize("", off)
__declspec(naked) void BG_UnlockablesGetUsedAllocation_Signature() {
	__asm {
		add       r26, r3, r26
		addi      r27, r27, 1
		addi      r11, r27, 4
		cmpwi     cr6, r11, 0x28
	}
}

__declspec(naked) void Dvar_SetVariant_Signature() {
	__asm {
		lwz       r3, 0x10(r3)
		ld        r6, 0x38(r31)
		ld        r7, 0x40(r31)      
	}
}

__declspec(naked) void externalDLCMaps_Signature() {
	__asm {
		lis       r11, 0
		li        r3, 1
		addi      r4, r11, 0
	}
}

__declspec(naked) void allDLCMaps_Signature() {
	__asm {
addi      r31, r31, 0x4C
addi      r11, r29, 0x2A5
cmpw      cr6, r31, r11
	}
}

__declspec(naked) void disableGTCheck_Signature() {
	__asm {
		lis       r11, 0
		li        r3, 0
		addi      r4, r11, 0
	}
}

__declspec(naked) void Scr_GetGSCObjSignature() {
	__asm {
mr        r31, r4
mr        r29, r6
cmplwi    cr6, r4, 0
	}
}

__declspec(naked) void Scr_LoadScriptInternalSignature() {
	__asm {
lis       r11, 0
cmpwi     cr6, r31, 1
addi      r7, r11, 0
	}
}

__declspec(naked) void Content_DetermineContentDriveName_Signature() {
	__asm {
lis       r11, 0
mr        r6, r3
addi      r5, r11, 0
	}
}

__declspec(naked) void SL_FindString_Signature() {
	__asm {
mr        r6, r28
li        r5, 0
lwz       r4, 0x1D0(r27)
li        r3, 1
	}
}

__declspec(naked) void SEH_GetCurrentLanguage_Signature() {
	__asm {
lis       r8, 0
stw       r3, 0x7C(r1)
mr        r9, r22
addi      r5, r8, 0
	}
}

__declspec(naked) void UI_Keyboard_ClanTagEntered_Signature() {
	__asm {
addi      r7, r1, 0xB0
li        r6, -1
li        r4, 0
ori       r3, r3, 0xFDE9
	}
}

__declspec(naked) void UI_KeyboardComplete_Signature() {
	__asm {
addi      r7, r1, 0x50
li        r6, -1
li        r4, 0
ori       r3, r3, 0xFDE9
	}
}
#pragma optimize("", on)

unsigned int gentityOffset;
void patchBO2BootXEXOnDev()
{
	int outInt = 0;
	
	//DLC Files are overwriting new patch FFs that were extracted. I'd rater just disable them, and load the FFs directly.
	//Extract DLC Files using a program like Le Fluffie or Horizon. Put any SABS files in the stream folder
	//and any SABL files in the load folder. The rest go in the Black Ops 2 folder itself.
	//Be sure not to overwrite any TU files. If you do, you will have to re-extract the TU. I recommend extracting
	//all DLC first, then doing the TU file again just to be safe.
	char * externalDLCMapsSearchString = "PLATFORM_MISSINGMAP";
	WriteHILOToBuffer(externalDLCMaps_Signature, 2, 10, (int)AlignedMemorySearch(".rdata", externalDLCMapsSearchString, strlen(externalDLCMapsSearchString)));
	int externalDLCMapsSignatureOffset = (int)AlignedMemorySearch(".text", externalDLCMaps_Signature, 0xC);
	WriteMemory((LPVOID)((int)FindFunctionBranch((void*)(externalDLCMapsSignatureOffset - 0x1C)) + 0x14), 4, (LPCVOID)&NOP);//Patch Live_GetMapSource to always return 2 (disc)
	WriteMemory((LPVOID)((int)FindFunctionBranch((void*)(externalDLCMapsSignatureOffset - 0x20)) + 4), 4, (LPCVOID)&NOP);//Patch Content_DoWeHaveContentPack to always return true

	//Say we have all maps, to get the server off our back about not having map packs. 
	int returnAllBitflags = 0x3860FFFF;
	WriteMemory((LPVOID)((int)AlignedMemorySearch(".text", allDLCMaps_Signature, 0xC) + 0x14), 4, (LPCVOID)&returnAllBitflags);

	//Remove dvar system checks, for obvious reasons
	//I honestly don't even think this is neccesary, but whatever...
	WriteMemory((LPVOID)((int)AlignedMemorySearch(".text", Dvar_SetVariant_Signature, 0xC) + 0x14), 4, (LPCVOID)&NOP);

	//Remove Gamertag Check
	//I had problems with editing my gamertag online, and this is just for my own personal use.
	char * disableGTCheckSearchString = "EXE_INVALID_GAMERTAG";
	WriteHILOToBuffer(disableGTCheck_Signature, 2, 10, (int)AlignedMemorySearch(".rdata", disableGTCheckSearchString, strlen(disableGTCheckSearchString)));
	WriteMemory((LPVOID)((int)AlignedMemorySearch(".text", disableGTCheck_Signature, 0xC) - 4), 2, (LPCVOID)&alwaysBranchPatch);

	//Remove Clan Tag Checks....... for gabe....... lol
	int offsetInUI_Keyboard_ClanTagEntered = (int)AlignedMemorySearch(".text", UI_Keyboard_ClanTagEntered_Signature, 0x10);
	WriteMemory((LPVOID)(offsetInUI_Keyboard_ClanTagEntered + 0x38), 2, &alwaysBranchPatch);
	WriteMemory((LPVOID)(offsetInUI_Keyboard_ClanTagEntered + 0x78), 2, &alwaysBranchPatch);
	WriteMemory((LPVOID)(offsetInUI_Keyboard_ClanTagEntered + 0x168), 2, &alwaysBranchPatch);
	WriteMemory((LPVOID)(offsetInUI_Keyboard_ClanTagEntered + 0x1AC), 2, &alwaysBranchPatch);
	WriteMemory((LPVOID)(offsetInUI_Keyboard_ClanTagEntered + 0x2CC), 4, &NOP);
	WriteMemory((LPVOID)(offsetInUI_Keyboard_ClanTagEntered + 0x2D8), 4, &NOP);

	//Remove Custom Class Name Checks
	void *xrefs[3];
	AlignedMemorySearch(".text", UI_KeyboardComplete_Signature, 0x10, xrefs, 2);
	WriteMemory((LPVOID)((int)xrefs[1] + 0x80), 2, &alwaysBranchPatch);

	//Find Com_SessionMode_SetMode, for force load zombies.
	WriteHILOToBuffer(Com_SessionMode_SetMode_Signature, 2, 10, (int)AlignedMemorySearch(".rdata", Com_SessionMode_SetMode_SearchString, strlen(Com_SessionMode_SetMode_SearchString)));
	AlignedMemorySearch(".text", Com_SessionMode_SetMode_Signature, 0xC, xrefs, 2);
	Com_SessionMode_SetMode = (Com_SessionMode_SetMode_t)FindFunctionStart(xrefs[1]);

	//Find SL_ConvertToString, for getting ScriptStrings
	AlignedMemorySearch(".rdata", "giveweapon", strlen("giveweapon"), xrefs, 2);
	SL_ConvertToString = (SL_ConvertToString_t)FindFunctionBranch((void*)(((int)FindFunctionBranch((void*)(*(int*)((int)AlignedMemorySearch(".rdata", &xrefs[1], 4) + 0x10) + 0x84)) + 0x10)));
	
	//Find SL_FindString, for getting ScriptStrings
	SL_FindString = (SL_FindString_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)AlignedMemorySearch(".text", SL_FindString_Signature, 0x10) - 4)) + 0x3C));
	
	//Find BG_UnlockablesGetUsedAllocation, for no custom class spent patch....
	//Was thinking about going so detailed with this, but oped for a simple patch, no function definition or anything...
	WriteMemory((LPVOID)AlignedMemorySearch(".text", BG_UnlockablesGetUsedAllocation_Signature, 0x10), 0x4, &NOP);

	//Find SEH_GetCurrentLanguage and SEH_GetLanguageNameAbbr for localized strings
	const char * SEH_GetCurrentLanguageSearchString = "%d,%d,%d,%lld,%llu,%s,%s,%s,%s,%d,%s";
	WriteHILOToBuffer(SEH_GetCurrentLanguage_Signature, 2, 14, (int)AlignedMemorySearch(".rdata", (void*)SEH_GetCurrentLanguageSearchString, strlen(SEH_GetCurrentLanguageSearchString)));
	int referenceAddress = (int)AlignedMemorySearch(".text", SEH_GetCurrentLanguage_Signature, 0x10) - 8;
	SEH_GetCurrentLanguage = (SEH_GetCurrentLanguage_t)FindFunctionBranch((void*)referenceAddress);
	SEH_GetLanguageName = (SEH_GetLanguageName_t)FindFunctionBranch((void*)(referenceAddress + 4));

	//This is declared before the enum is located in mem... fix that...
	PhysConstraintEntries[1].next = (AssetEntry*)s_constraintTypeNames;
	
	hookFunctionStart((PDWORD)Load_PhysPresetAsset, (PDWORD)Load_PhysPresetAssetSaveStub, (DWORD)Load_PhysPresetAssetHook);
	hookFunctionStart((PDWORD)Load_PhysConstraintsAsset, (PDWORD)Load_PhysConstraintsAssetSaveStub, (DWORD)Load_PhysConstraintsAssetHook);
	hookFunctionStart((PDWORD)Load_DestructibleDefAsset, (PDWORD)Load_DestructibleDefAssetSaveStub, (DWORD)Load_DestructibleDefAssetHook);
	hookFunctionStart((PDWORD)Load_MapEntsAsset, (PDWORD)Load_MapEntsAssetSaveStub, (DWORD)Load_MapEntsAssetHook);
	hookFunctionStart((PDWORD)Load_GfxLightDefAsset, (PDWORD)Load_GfxLightDefAssetSaveStub, (DWORD)Load_GfxLightDefAssetHook);
	hookFunctionStart((PDWORD)Load_LocalizeEntryAsset, (PDWORD)Load_LocalizeEntryAssetSaveStub, (DWORD)Load_LocalizeEntryAssetHook);
	hookFunctionStart((PDWORD)Load_WeaponVariantDefAsset, (PDWORD)Load_WeaponVariantDefAssetSaveStub, (DWORD)Load_WeaponVariantDefAssetHook);
	hookFunctionStart((PDWORD)Load_WeaponAttachmentAsset, (PDWORD)Load_WeaponAttachmentAssetSaveStub, (DWORD)Load_WeaponAttachmentAssetHook);
	hookFunctionStart((PDWORD)Load_WeaponAttachmentUniqueAsset, (PDWORD)Load_WeaponAttachmentUniqueAssetSaveStub, (DWORD)Load_WeaponAttachmentUniqueAssetHook);
	hookFunctionStart((PDWORD)Load_RawFileAsset, (PDWORD)Load_RawFileAssetSaveStub, (DWORD)Load_RawFileAssetHook);
	hookFunctionStart((PDWORD)Load_StringTableAsset, (PDWORD)Load_StringTableAssetSaveStub, (DWORD)Load_StringTableAssetHook);
	hookFunctionStart((PDWORD)Load_ddlRoot_tAsset, (PDWORD)Load_ddlRoot_tAssetSaveStub, (DWORD)Load_ddlRoot_tAssetHook);
	hookFunctionStart((PDWORD)Load_ScriptParseTreeAsset, (PDWORD)Load_ScriptParseTreeAssetSaveStub, (DWORD)Load_ScriptParseTreeAssetHook);
	hookFunctionStart((PDWORD)Load_VehicleDefAsset, (PDWORD)Load_VehicleDefAssetSaveStub, (DWORD)Load_VehicleDefAssetHook);
	hookFunctionStart((PDWORD)Load_TracerDefAsset, (PDWORD)Load_TracerDefAssetSaveStub, (DWORD)Load_TracerDefAssetHook);
	hookFunctionStart((PDWORD)Load_QdbAsset, (PDWORD)Load_QdbAssetSaveStub, (DWORD)Load_QdbAssetHook);
	hookFunctionStart((PDWORD)Load_SlugAsset, (PDWORD)Load_SlugAssetSaveStub, (DWORD)Load_SlugAssetHook);
	hookFunctionStart((PDWORD)Load_FootstepTableDefAsset, (PDWORD)Load_FootstepTableDefAssetSaveStub, (DWORD)Load_FootstepTableDefAssetHook);
	hookFunctionStart((PDWORD)Load_FootstepFXTableDefAsset, (PDWORD)Load_FootstepFXTableDefAssetSaveStub, (DWORD)Load_FootstepFXTableDefAssetHook);
	hookFunctionStart((PDWORD)Load_ZBarrierDefAsset, (PDWORD)Load_ZBarrierDefAssetSaveStub, (DWORD)Load_ZBarrierDefAssetHook);

	//Previous asset dumpers (and 1 ghetto compiler) that all need tons of work and a good source format to bring them into this update.
	/*hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x78)) + 0xA4)), (PDWORD)Load_XAnimPartsAssetSaveStub, (DWORD)Load_XAnimPartsAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x94)) + 0xA4)), (PDWORD)Load_XModelAssetSaveStub, (DWORD)Load_XModelAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0xB0)) + 0xA4)), (PDWORD)Load_MaterialAssetSaveStub, (DWORD)Load_MaterialAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x104)) + 0xA4)), (PDWORD)Load_GfxImageAssetSaveStub, (DWORD)Load_GfxImageAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x120)) + 0xA4)), (PDWORD)Load_snd_alias_list_tAssetSaveStub, (DWORD)Load_snd_alias_list_tAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x588)) + 0xA4)), (PDWORD)Load_clipMap_tAssetSaveStub, (DWORD)Load_clipMap_tAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x1D8)) + 0xA4)), (PDWORD)Load_GfxWorldAssetSaveStub, (DWORD)Load_GfxWorldAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x22C)) + 0xA4)), (PDWORD)Load_FontAssetSaveStub, (DWORD)Load_FontAssetHook);
	hookFunctionStart((PDWORD)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)(Load_XAssetHeaderOffset + 0x248)) + 0xA4)), (PDWORD)Load_FontIconAssetSaveStub, (DWORD)Load_FontIconAssetHook);*/
	
	//GSC++
	int Scr_ResolveScriptFunctionXrefSignature[] = {0x7FC5F378, 0x7FE4FB78, 0x7F23CB78};
	void* Scr_ResolveScriptFunctionXref = AlignedMemorySearch(".text", Scr_ResolveScriptFunctionXrefSignature, 0xC);
	Scr_ResolveScriptFunction = (Scr_ResolveScriptFunction_t)FindFunctionBranch((void*)((int)Scr_ResolveScriptFunctionXref + 0xC));
	patchInJump((PDWORD)Scr_ResolveScriptFunctionXref, (DWORD)Scr_ResolveScriptFunctionHook, true);
	
	hookFunctionStart((PDWORD)(int)FindFunctionStart(AlignedMemorySearch(".text", Scr_GetGSCObjSignature, 0xC)), (PDWORD)Scr_GetGSCObjSaveStub, (DWORD)Scr_GetGSCObjHook);
	
	int Scr_LoadScriptInternalSearchString = 0x67736300;
	WriteHILOToBuffer(Scr_LoadScriptInternalSignature, 2, 10, (int)AlignedMemorySearch(".rdata", &Scr_LoadScriptInternalSearchString, 0x4));
	hookFunctionStart((PDWORD)(int)FindFunctionStart(AlignedMemorySearch(".text", Scr_LoadScriptInternalSignature, 0xC)), (PDWORD)Scr_LoadScriptInternalSaveStub, (DWORD)Scr_LoadScriptInternalHook);

	////////// Challenges Tiem \\\\\\\\\\\
	//nobody gets hurt. easy
	hookFunctionStart((PDWORD)LiveStats_Probation_GiveProbation, (PDWORD)LiveStats_Probation_GiveProbationSaveStub, (DWORD)LiveStats_Probation_GiveProbationHook);
	//look at me! i am the captain now
	patchInJump((PDWORD)LiveAntiCheat_GetChallengeResponse, (DWORD)LiveAntiCheat_GetChallengeResponseHook, false);

	//Force Load Zombies
	//Com_SessionMode_SetMode(SESSIONMODE_ZOMBIES, true);
}
