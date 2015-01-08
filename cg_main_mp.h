#ifndef _CG_MAIN_MP
#define _CG_MAIN_MP

enum LocalClientNum_t
{
  INVALID_LOCAL_CLIENT = 0xFFFFFFFF,
  LOCAL_CLIENT_FIRST = 0x0,
  LOCAL_CLIENT_0 = 0x0,
  ONLY_LOCAL_CLIENT = 0x0,
  LOCAL_CLIENT_COUNT = 0x1,
};

typedef int (__cdecl * CG_GetClientNum_t)(LocalClientNum_t localClientNum);
extern CG_GetClientNum_t CG_GetClientNum;

#endif//_CG_MAIN_MP