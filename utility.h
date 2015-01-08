#ifndef _UTILITY_H
#define _UTILITY_H

float UnpackShortFloat(unsigned short value);

// change whether TLB memory protections are in effect
#define SET_PROT_OFF	2
#define SET_PROT_ON		3
DWORD HvxSetState(DWORD mode);

// resolve an ordinal to an address
DWORD resolveFunct(PCHAR modname, DWORD ord);

// mount a path to a drive name
HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both);

// find the Export Address Table in a given module
// only works in threads with the ability to peek crypted memory
// only tested on "xam.xex" and "xboxkrnl.exe"
//PIMAGE_EXPORT_ADDRESS_TABLE getModuleEat(char* modName);

// returns true if the file exists
BOOL fileExists(PCHAR path);

// patches in a 4 instruction jump which uses R11/scratch reg and ctr to assemble
// addr = pointer to address being patched
// dest = address of the new destination
// linked = (true = ctr branch with link used) (false = ctr branch, link register unaffected)
VOID patchInJump(PDWORD addr, DWORD dest, BOOL linked);

// hook export table ordinals of a module, anything linked after this hook is redirected to dstFun
// modName = pointer to string of the module name to alter the export table, like "xam.xex" or "xboxkrnl.exe"
// ord = ordinal number
// dstFun = address to change ordinal link address to
// returns the address of the start of the hook patched into modName@ord
// ** note that this type of hook ONLY works on things that haven't been linked by the time the patch is made
DWORD hookExportOrd(char* modName, DWORD ord, DWORD dstFun);

// hook imported jumper stubs to a different function
// modname = module with the import to patch
// impmodname = module name with the function that was imported
// ord = function ordinal to patch
// patchAddr = destination where it is patched to
// returns TRUE if hooked
// ** NOTE THIS FUNCTION MAY STILL BE BROKEN FOR MODULES WITH MULTIPLE IMPORT TABLES OF THE SAME impmodname
BOOL hookImpStub(char* modname, char* impmodname, DWORD ord, DWORD patchAddr);

// hook a function start based on address, using 8 instruction saveStub to do the deed
// addr = address of the hook
// saveStub = address of the area to create jump stub for replaced instructions
// dest = where the hook at addr is pointing to
VOID hookFunctionStart(PDWORD addr, PDWORD saveStub, DWORD dest);

// hook a function start based on ordinal, using 8 instruction saveStub to do the deed
// modName = pointer to string of the module name to alter the export table, like "xam.xex" or "xboxkrnl.exe"
// ord = ordinal number of the function to hook in module modName
// saveStub = address of the area to create jump stub for replaced instructions
// dest = where the hook at addr is pointing to
// returns the address of the start of the hook patched into modName@ord
PDWORD hookFunctionStartOrd(char* modName, DWORD ord, PDWORD saveStub, DWORD dest);

// tries to get the data segment size and start address of named module
// modName = pointer to string of the module name to alter the export table, like "xam.xex" or "xboxkrnl.exe"
// size = pointer to a DWORD to take the size from base
BYTE* getModBaseSize(char* modName, PDWORD size);

#endif // _UTILITY_H
