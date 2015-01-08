#include <xtl.h>
#include <xboxmath.h>
#include <xbox.h>
#include <xam.h>
#include <stdio.h>
#include "Hooking.h"
#include "utility.h"

typedef UINT32 (__cdecl * XamGetCurrentTitleId_t)(void);
XamGetCurrentTitleId_t XamGetCurrentTitleId = (XamGetCurrentTitleId_t)resolveFunct("xam.xex", 0x1CF);
int runningID;

HANDLE thisApplication;
XOVERLAPPED bo2Overlap;
WCHAR keyboardTitle[0x20],keyboardDesc[0x40];

BOOL APIENTRY DllMain(HANDLE hInstDLL, DWORD dreason, LPVOID lpReserved)
{
	//RETAIL DISC LOADING:
	//0x800C4B28
	//0x800C4B50

	bool recognized = false;
	thisApplication = hInstDLL;
	switch(dreason)
	{
	case DLL_PROCESS_ATTACH:
	runningID = XamGetCurrentTitleId();
	if(runningID == 0x415608C3)			//Black Ops 2
	{
		patchBO2BootXEXOnDev();
	}
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}