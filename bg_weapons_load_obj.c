#include "bg_weapons_load_obj.h"
#include "AddressReverser.h"
#include <xtl.h>

char * weapTypeSearchString = "binoculars";
int weapTypeSearchStringOffset = (int)AlignedMemorySearch(".rdata", weapTypeSearchString, strlen(weapTypeSearchString));
char * * szWeapTypeNames = (char**)((int)AlignedMemorySearch(".data", &weapTypeSearchStringOffset, 4) - 0xC);
char * * szWeapClassNames = (char**)(szWeapTypeNames + 9);
const char * (*szWeapInventoryTypeNames)[6] = (const char*(*)[6])(szWeapClassNames + 14);
char * * szWeapFireTypeNames = (char**)(szWeapInventoryTypeNames + 1);
const char * (*szWeapClipTypeNames)[6] = (const char*(*)[6])(szWeapFireTypeNames + 10);
const char * * penetrateTypeNames = (const char**)(szWeapClipTypeNames + 1);
const char * (*impactTypeNames_0)[16] = (const char*(*)[16])(penetrateTypeNames + 4);
const char * (*szProjectileExplosionNames)[11] = (const char*(*)[11])(impactTypeNames_0 + 1);
char * * szWeapOverlayReticleNames = (char**)(szProjectileExplosionNames + 1);
const char * (*szWeapStanceNames)[3] = (const char*(*)[3])(szWeapOverlayReticleNames + 2);
const char * (*offhandClassNames)[6] = (const char*(*)[6])(szWeapStanceNames + 1);
const char * (*offhandSlotNames)[5] = (const char*(*)[5])(offhandClassNames + 1);
const char * (*activeReticleNames)[4] = (const char*(*)[4])(offhandSlotNames + 1);
const char * (*guidedMissileNames)[9] = (const char*(*)[9])(activeReticleNames + 1);
const char * (*stickinessNames)[6] = (const char*(*)[6])(guidedMissileNames + 1);
const char * (*rotateTypeNames)[3] = (const char*(*)[3])(stickinessNames + 1);
char * * overlayInterfaceNames = (char**)(rotateTypeNames + 1);
const char * (*ammoCounterClipNames)[7] = (const char*(*)[7])(overlayInterfaceNames + 3);
const char * (*weapIconRatioNames)[3] = (const char*(*)[3])(ammoCounterClipNames + 1);
const char * (*barrelTypeNames)[6] = (const char*(*)[6])(weapIconRatioNames + 1);