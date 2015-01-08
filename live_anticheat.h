#ifndef _LIVE_ANTICHEAT
#define _LIVE_ANTICHEAT

struct bdAntiCheatChallengeParam;
struct bdReferencable;

enum ControllerIndex_t
{
  INVALID_CONTROLLER_PORT = 0xFFFFFFFF,
  CONTROLLER_INDEX_FIRST = 0x0,
  CONTROLLER_INDEX_0 = 0x0,
  CONTROLLER_INDEX_1 = 0x1,
  CONTROLLER_INDEX_2 = 0x2,
  CONTROLLER_INDEX_3 = 0x3,
  CONTROLLER_INDEX_COUNT = 0x4
};

enum challengeResponseFunctionIDs_t : short
{
  FUNC_ID_CHECKSUM_CRC32 = 0x1,
  FUNC_ID_CHECKSUM_SHA = 0x2,
  FUNC_ID_CHECKSUM_CRC32_SPLIT = 0x3,
  FUNC_ID_DVAR = 0x4,
  FUNC_ID_DVAR_FLOAT = 0x5,
  FUNC_ID_EXPRESSION = 0x6,
  FUNC_ID_NOP = 0x7,
  FUNC_ID_MIPSTER = 0x8
};

template<typename T> struct bdArray
{
  T *m_data;
  unsigned int m_capacity;
  unsigned int m_size;
};

template<typename T> struct bdReference
{
  T *m_ptr;
};

struct bdReferencableVtbl
{
  void *(__thiscall *__vecDelDtor)(bdReferencable *test, unsigned int);
};

struct bdReferencable
{
  bdReferencableVtbl *vfptr;
  volatile int m_refCount;
};

struct __declspec(align(2)) bdByteBuffer : bdReferencable
{
  unsigned int m_size;
  char *m_data;
  char *m_readPtr;
  char *m_writePtr;
  bool m_typeChecked;
  bool m_typeCheckedCopy;
  bool m_allocatedData;
};

struct bdAntiCheatChallengeParamVtbl
{
  void *(__thiscall *__vecDelDtor)(bdAntiCheatChallengeParam *test, unsigned int);
  bool (__thiscall *deserialize)(bdAntiCheatChallengeParam *test, bdReference<bdByteBuffer>);
  unsigned int (__thiscall *sizeOf)(bdAntiCheatChallengeParam *test);
};

struct bdAntiCheatChallengeParam
{
  bdAntiCheatChallengeParamVtbl *vfptr;
  char *m_data;
  unsigned int m_size;
};

typedef bool (__cdecl * LiveAntiCheat_GetChallengeResponse_t)(ControllerIndex_t controllerIndex, unsigned __int16 functionID, bdArray<bdAntiCheatChallengeParam> *params, __int64 *response);
extern LiveAntiCheat_GetChallengeResponse_t LiveAntiCheat_GetChallengeResponse;

bool LiveAntiCheat_GetChallengeResponseHook(ControllerIndex_t controllerIndex, unsigned __int16 functionID, bdArray<bdAntiCheatChallengeParam> *params, __int64 *response);

#endif//_LIVE_ANTICHEAT