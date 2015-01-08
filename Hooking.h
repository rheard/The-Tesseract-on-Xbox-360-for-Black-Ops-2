#ifndef _HOOKING_H
#define _HOOKING_H

#include <xtl.h>
#include <xboxmath.h>
#include <xbox.h>
#include <stdio.h>

void CreateDirectoryB(char * name);

extern char MasterCharBuffer[0x8000];
extern char theAssetBuffer[0x8000];
extern bool usingAssetBuffer;
extern int runningID;

char * va( char *format,...);

//Contains any global definitions and hooking functions

//The following externs are used in patching PPC
extern int returnFalse,
		returnTrue,
		liR40,
		liR50,
		liR60,
		liR70,
		liR90,
		BLR,
		NOP;
extern bool thisIsTrue, thisIsFalse;
extern short alwaysBranchPatch;

void patchBO2BootXEXOnDev();
DWORD WINAPI BlackOps2Loop(LPVOID);

char *improved_strtok(char *buf, const char *delim);
char *improved_strtok2(char *buf, const char *delim);
extern HANDLE thisApplication;

VOID DoPatches( PDWORD pBuffer, DWORD dwLength );
void patchMemory(DWORD addr, DWORD sourceAddr, int size);
DWORD WriteMemory(LPVOID address, DWORD size, LPCVOID data, HRESULT * optionalOutput = 0);

char * ConvertAssetNameToFileName(const char * assetName);
char * ConvertAssetNameToFileName(char * assetName);
char * ConvertAssetNameToFileName(char * assetName, char * outputBuff);
#define offsetof(s,m)   (size_t)&reinterpret_cast<const volatile char&>((((s *)0)->m))

#endif