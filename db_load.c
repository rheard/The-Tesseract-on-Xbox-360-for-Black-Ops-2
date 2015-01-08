#include "db_load.h"
#include "AddressReverser.h"

#pragma optimize("", off)
__declspec(naked) void Load_XAssetHeaderHooks_Signature() {
	__asm {
		lis       r11, 2
		addi      r29, r29, 8
		ori       r10, r11, 0x318
		lbzx      r9, r31, r10
	}
}
#pragma optimize("", on)

Load_XAssetHeader_t Load_XAssetHeader = (Load_XAssetHeader_t)FindFunctionBranch((void*)((int)FindFunctionBranch((void*)((int)AlignedMemorySearch(".text", Load_XAssetHeaderHooks_Signature, 0x10) - 4)) + 0x40));