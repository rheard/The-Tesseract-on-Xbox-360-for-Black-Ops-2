#ifndef _CSCR_STRINGLIST
#define _CSCR_STRINGLIST

typedef const char *(__cdecl * SL_ConvertToString_t)(unsigned int stringValue);
extern SL_ConvertToString_t SL_ConvertToString;

typedef unsigned int(__cdecl * SL_FindString_t)(const char *str);
extern SL_FindString_t SL_FindString;

#endif