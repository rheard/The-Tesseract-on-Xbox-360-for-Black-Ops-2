#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Hooking.h"

#ifndef LOWORD
#define LOWORD(a) ((short)(a))
#endif//LOWORD
#ifndef HIWORD
#define HIWORD(a) ((short)(((int)(a) >> 16) & 0xFFFF))
#endif//HIWORD

bool FindSectionInfo(char * sectionName, int * virtualAddress, int * virtualLength)
{
	int sectionInfoOffset = 0x82000000;
	while(strcmp(".rdata", (char*)sectionInfoOffset)) sectionInfoOffset+=4;
	IMAGE_SECTION_HEADER *defaultSections = (IMAGE_SECTION_HEADER*)sectionInfoOffset;

	bool succeded = false;
	*virtualAddress = *virtualLength = 0;
	for(int i = 0; strlen((char*)defaultSections[i].Name); i++)
		if(!strcmp(sectionName, (char*)defaultSections[i].Name))
		{
			*virtualAddress = _byteswap_ulong(defaultSections[i].VirtualAddress);
			*virtualLength = _byteswap_ulong(defaultSections[i].Misc.VirtualSize);
			succeded = true;
			break;
		}

	if(!succeded)
		printf("ERROR!\n");

	return succeded;
}

void * BasicMemorySearch(char * sectionName, void * scanData, int dataLength)
{
	int sectionOffset, sectionLength;
	if(FindSectionInfo(sectionName, &sectionOffset, &sectionLength))
	{
		void * currentAddress = (void*)(0x82000000 + sectionOffset);
		while(currentAddress <= (void*)(0x82000000 + sectionOffset + sectionLength - dataLength))
			if(!memcmp(currentAddress, scanData, dataLength))
				return currentAddress;
			else
				currentAddress = (void*)((int)currentAddress + 1);
	}
	
	printf("ERROR!\n");

	return 0;
}

int BasicMemorySearch(char * sectionName, void * scanData, int dataLength, void ** occurances, int maxOccurances)
{
	int numFound = 0;
	int sectionOffset, sectionLength;
	if(FindSectionInfo(sectionName, &sectionOffset, &sectionLength))
	{
		void * currentAddress = (void*)(0x82000000 + sectionOffset);
		while(currentAddress <= (void*)(0x82000000 + sectionOffset + sectionLength - dataLength) && numFound < maxOccurances)
		{
			if(!memcmp(currentAddress, scanData, dataLength))
				occurances[numFound++] = currentAddress;
			
				currentAddress = (void*)((int)currentAddress + 1);
		}
	}

	if(numFound == 0)
		printf("ERROR!\n");

	return numFound;
}

void * AlignedMemorySearch(char * sectionName, void * scanData, int dataLength)
{
	int sectionOffset, sectionLength;
	if(FindSectionInfo(sectionName, &sectionOffset, &sectionLength))
	{
		void * currentAddress = (void*)(0x82000000 + sectionOffset);
		while((unsigned int)currentAddress <= (0x82000000 + sectionOffset + sectionLength - dataLength)) {
			if(!memcmp(currentAddress, scanData, dataLength))
				return currentAddress;
			else
				currentAddress = (void*)((int)currentAddress + 4);
		}
	}

	printf("ERROR!\n");

	return 0;
}

int AlignedMemorySearch(char * sectionName, void * scanData, int dataLength, void ** occurances, int maxOccurances)
{
	int numFound = 0;
	int sectionOffset, sectionLength;
	if(FindSectionInfo(sectionName, &sectionOffset, &sectionLength))
	{
		void * currentAddress = (void*)(0x82000000 + sectionOffset);
		while(currentAddress <= (void*)(0x82000000 + sectionOffset + sectionLength - dataLength) && numFound < maxOccurances)
		{
			if(!memcmp(currentAddress, scanData, dataLength))
				occurances[numFound++] = currentAddress;
			
				currentAddress = (void*)((int)currentAddress + 4);
		}
	}

	if(numFound == 0)
		printf("ERROR!\n");

	return numFound;
}

void WriteHILOToBuffer(void* buffer, int hiOffset, int loOffset, int newOffset)
{
	short firstVal = HIWORD(newOffset);
	if(newOffset & 0x8000)
		firstVal++;
	WriteMemory((LPVOID)((int)buffer + hiOffset), 2, (LPCVOID)&firstVal);
	firstVal = LOWORD(newOffset);
	WriteMemory((LPVOID)((int)buffer + loOffset), 2, (LPCVOID)&firstVal);
}

void* ReadHILOOffset(void* buffer, int hiOffset, int loOffset)
{
	unsigned int returnVal = *(unsigned short*)((int)buffer + hiOffset) << 16;
	returnVal |= *(unsigned short*)((int)buffer + loOffset);
	if(!returnVal)
		printf("ERROR!\n");
	if(returnVal & 0x8000) returnVal -= 0x10000;
	return (void*)returnVal;
}

void * FindFunctionStart(void * buffer)
{
	while(1)
	{
		if(!*(int*)buffer)
		{
			buffer = (void*)((int)buffer + 4);
			break;
		}
		else if(*(int*)buffer == 0x7D8802A6)
			break;
		else
			buffer = (void*)((int)buffer - 4);
	}

	return buffer;
}

void * FindFunctionBranch(void * buffer)
{
	int DifferenceInOffset = *(unsigned int*)buffer & 0x3FFFFFC;
	if(DifferenceInOffset & 0x2000000)
	{
		DifferenceInOffset = (~DifferenceInOffset + 1) & 0x3FFFFFC;
		buffer = (void*)((int)buffer - DifferenceInOffset);
	}
	else buffer = (void*)((int)buffer + DifferenceInOffset);
	return buffer;
}