#include "physconstraints_load_obj.h"
#include "AddressReverser.h"
#include <xtl.h>

char * s_attachPointTypeNames[] = { "world", "dynent", "ent", "bone" };
char * s_constraintTypeNamesSearchString = "actuator";
int s_constraintTypeNamesSearchStringOffset = (int)AlignedMemorySearch(".rdata", s_constraintTypeNamesSearchString, strlen(s_constraintTypeNamesSearchString));
char * (*s_constraintTypeNames)[10] = (char*(*)[10])((int)AlignedMemorySearch(".data", &s_constraintTypeNamesSearchStringOffset, 4) - 0x14);