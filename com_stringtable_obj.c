#include "com_stringtable_obj.h"
#include "AddressReverser.h"

__declspec(naked) void StringTable_HashString_Signature() {
	__asm {
		mr        r26, r3
		lwz       r11, 8(r30)
		mr        r3, r30
		lwz       r10, 4(r30)
	}
}

StringTable_HashString_t StringTable_HashString = (StringTable_HashString_t)FindFunctionBranch((void*)((int)AlignedMemorySearch(".text", StringTable_HashString_Signature, 0x10) - 4));