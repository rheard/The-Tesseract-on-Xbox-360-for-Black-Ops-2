#include "bg_misctables.h"
#include "AddressReverser.h"
#include <xtl.h>

char * s_vehicleClassNamesSearchString = "4 wheel";
int s_vehicleClassNamesSearchStringOffset = (int)AlignedMemorySearch(".rdata", s_vehicleClassNamesSearchString, strlen(s_vehicleClassNamesSearchString));
char * * s_vehicleClassNames = (char**)((int)AlignedMemorySearch(".data", &s_vehicleClassNamesSearchStringOffset, 4));
char * * s_tractionTypeNames = (char**)((int)s_vehicleClassNames + 0x1C);
char * * s_vehicleCameraModes = (char**)((int)s_tractionTypeNames + 0xC);