#include "live_stats.h"
#include "AddressReverser.h"

#pragma optimize("", off)
__declspec(naked) void LiveStats_Probation_GiveProbation_Signature() {
	__asm {
		li        r8, 1
		li        r7, 0
		li        r6, 0xAA5
	}
}

__declspec(naked) void LiveStats_Probation_GiveProbationSaveStub(ControllerIndex_t controllerIndex, eGameModes gamemode, float time) {
	__asm {
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		li        r6, 0xAA5
	}
}
#pragma optimize("", on)

LiveStats_Probation_GiveProbation_t LiveStats_Probation_GiveProbation = (LiveStats_Probation_GiveProbation_t)((int)AlignedMemorySearch(".text", LiveStats_Probation_GiveProbation_Signature, 0xC) - 0x30);

void LiveStats_Probation_GiveProbationHook(ControllerIndex_t controllerIndex, eGameModes gamemode, float time) {
	time = 0;
	LiveStats_Probation_GiveProbationSaveStub(controllerIndex, gamemode, time);
}