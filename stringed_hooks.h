#ifndef _STRINGED_HOOKS
#define _STRINGED_HOOKS

typedef int (__cdecl * SEH_GetCurrentLanguage_t)();
extern SEH_GetCurrentLanguage_t SEH_GetCurrentLanguage;

typedef const char * (__cdecl * SEH_GetLanguageName_t)(const int iLanguage);
extern SEH_GetLanguageName_t SEH_GetLanguageName;

#endif//_STRINGED_HOOKS