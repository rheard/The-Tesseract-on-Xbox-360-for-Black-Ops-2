#ifndef _COM_SESSIONMODES
#define _COM_SESSIONMODES

enum eSessionModes
{
  SESSIONMODE_OFFLINE = 0x0,
  SESSIONMODE_SYSTEMLINK = 0x1,
  SESSIONMODE_ONLINE = 0x2,
  SESSIONMODE_PRIVATE = 0x3,
  SESSIONMODE_ZOMBIES = 0x4,
  SESSIONMODE_MAX = 0x5,
  INVALID_SESSIONMODE = 0x6
};

typedef bool (__cdecl * Com_SessionMode_IsMode_t)(eSessionModes mode);
extern Com_SessionMode_IsMode_t Com_SessionMode_IsMode;

typedef void (__cdecl * Com_SessionMode_SetMode_t)(eSessionModes mode, bool value);
extern Com_SessionMode_SetMode_t Com_SessionMode_SetMode;
extern char * Com_SessionMode_SetMode_SearchString;
void Com_SessionMode_SetMode_Signature();

#endif//_COM_SESSIONMODES