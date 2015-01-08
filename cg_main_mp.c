#include "cg_main_mp.h"
#include "AddressReverser.h"

int CG_GetClientNum_Signature[] = { 0x80600000, 0x4E800020 };
CG_GetClientNum_t CG_GetClientNum = (CG_GetClientNum_t)((int)AlignedMemorySearch(".text", CG_GetClientNum_Signature, 0x8) - 0x10);