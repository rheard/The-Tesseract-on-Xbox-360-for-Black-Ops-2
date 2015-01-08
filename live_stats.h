#ifndef _LIVE_STATS
#define _LIVE_STATS

#include "live_anticheat.h"

enum eGameModes
{
  GAMEMODE_PUBLIC_MATCH = 0x0,
  GAMEMODE_PRIVATE_MATCH = 0x1,
  GAMEMODE_LOCAL_SPLITSCREEN = 0x2,
  GAMEMODE_WAGER_MATCH = 0x3,
  GAMEMODE_BASIC_TRAINING = 0x4,
  GAMEMODE_THEATER = 0x5,
  GAMEMODE_LEAGUE_MATCH = 0x6,
  GAMEMODE_RTS = 0x7,
  GAMEMODE_MAX = 0x8,
  INVALID_GAMEMODE = 0x9
};

typedef bool (__cdecl * LiveStats_Probation_GiveProbation_t)(ControllerIndex_t controllerIndex, eGameModes gamemode, float time);
extern LiveStats_Probation_GiveProbation_t LiveStats_Probation_GiveProbation;

void LiveStats_Probation_GiveProbationSaveStub(ControllerIndex_t controllerIndex, eGameModes gamemode, float time);
void LiveStats_Probation_GiveProbationHook(ControllerIndex_t controllerIndex, eGameModes gamemode, float time);

#endif//_LIVE_STATS