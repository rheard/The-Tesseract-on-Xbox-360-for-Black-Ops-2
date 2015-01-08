#include "com_sessionmodes.h"
#include "AddressReverser.h"
#include <xtl.h>

#pragma optimize("", off)
__declspec(naked) void Com_SessionMode_IsMode_Signature() {
	__asm {
		and       r8, r9, r11
		addic     r7, r8, -1
		subfe     r3, r7, r8
		blr
	}
}

__declspec(naked) void Com_SessionMode_SetMode_Signature() {
	__asm {
		lis       r11, 0
		li        r3, 0
		addi      r4, r11, 0
	}
}
#pragma optimize("", on)

void* xrefs[2];
int xrefsFound = AlignedMemorySearch(".text", Com_SessionMode_IsMode_Signature, 0x10, xrefs, 2);
Com_SessionMode_IsMode_t Com_SessionMode_IsMode = (Com_SessionMode_IsMode_t)((int)xrefs[1] - 0x10);

char * Com_SessionMode_SetMode_SearchString = "\x15""Com_GameMode_SetMode: Can not set the mode when in backup block!";
Com_SessionMode_SetMode_t Com_SessionMode_SetMode;