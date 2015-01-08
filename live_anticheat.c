#include "live_anticheat.h"
#include "AddressReverser.h"
#include "Hooking.h"

#pragma optimize("", off)
__declspec(naked) void LiveAntiCheat_GetChallengeResponseSignature() {
	__asm {
lwz       r11, 0(r5)
mr        r31, r3
mr        r30, r5
mr        r29, r6
	}
}
#pragma optimize("", on)

LiveAntiCheat_GetChallengeResponse_t LiveAntiCheat_GetChallengeResponse = (LiveAntiCheat_GetChallengeResponse_t)FindFunctionStart(AlignedMemorySearch(".text", LiveAntiCheat_GetChallengeResponseSignature, 0x10));

bool LiveAntiCheat_GetChallengeResponseHook(ControllerIndex_t controllerIndex, unsigned __int16 functionID, bdArray<bdAntiCheatChallengeParam> *params, __int64 *response)
{
	if(params->m_data->m_size && functionID != FUNC_ID_NOP) {
		switch(functionID) {
		case FUNC_ID_CHECKSUM_CRC32_SPLIT:
			//bdAntiCheatChallengeParam:
			//0x18 - char moduleNameSize
			//0x19 - char moduleName[moduleNameSize] //On only challenge, this is null.
			//0x19 + moduleNameSize - char sectionNameSize
			//0x1A + moduleNameSize - char sectionName[sectionNameSize]

			*response = 0x4f19632acb2bf784;
			//Only 1 checksum request, crc32_split on the .text section
			//This should be the right hash... either this or 0x5f11fa86997c35db
			break;
		case FUNC_ID_DVAR:
			//bdAntiCheatChallengeParam: Just long enough to contain the dvar's name.

			*response = 0;
			//Only 1 dvar request, cg_drawFPS. Return 0 so they see what they want.
			//Just wondering, has anyone else ever tried setting this dvar on another bypass?
			break;
		case FUNC_ID_NOP: break; //For NOP, return something... anything...
		case FUNC_ID_MIPSTER:
			//bdAntiCheatChallengeParam:
			//This is a zlib compressed data block. Once decompressed it appears to be MIPS assembly language data....

			*response = 0xb;
			//Theres not much info on this in the PDBs.
			//Theres only 1 request and it appears the correct response is 0xB
			break;
		default: //Unknown challenge recieved. Lets get out of here so I can update my dll...
			XLaunchNewImage(XLAUNCH_KEYWORD_DEFAULT_APP, 0);
			break;
		}
	}

	return true; //Unlike other bypasses, we're actually going to respond.
}