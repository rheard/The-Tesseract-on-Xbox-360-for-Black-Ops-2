#include "bg_weapons_attachment.h"
#include "AddressReverser.h"
#include "xtl.h"

char * s_attachmentNamesSearchString = "acog";
int s_attachmentNamesSearchStringOffset = (int)AlignedMemorySearch(".rdata", s_attachmentNamesSearchString, strlen(s_attachmentNamesSearchString));
const char *(*s_attachmentNames)[30] = (const char *(*)[30])((int)AlignedMemorySearch(".data", &s_attachmentNamesSearchStringOffset, 4) - 4);
const char *(*s_attachmentPointNames)[6] = (const char *(*)[6])(s_attachmentNames+1);