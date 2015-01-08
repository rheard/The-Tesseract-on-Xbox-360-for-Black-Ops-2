#ifndef _COM_STRINGTABLE_OBJ
#define _COM_STRINGTABLE_OBJ

typedef int (__cdecl * StringTable_HashString_t)(const char *string);
extern StringTable_HashString_t StringTable_HashString;

#endif//_COM_STRINGTABLE_OBJ