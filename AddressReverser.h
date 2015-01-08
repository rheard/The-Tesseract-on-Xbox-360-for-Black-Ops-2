#ifndef _ADDRESS_REVERSER
#define _ADDRESS_REVERSER

////////////////////////////////////////////////////////////////////
////////////////////  Made by CraigChrist8239  /////////////////////
////////////////////////////////////////////////////////////////////
//////  The purpose of this set of functions is to parse an  ///////
////  exeutable and partially decompile it if need be, in order  ///
////  to produce the offset of a particular element in memory.  ////
////  This will hopefully make updating to a new TU as easy as  ////
///  possible.   Keep in mind that there will be no substitute  ////
///  to opening IDA and reversing these yourself, so be careful.  //
////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////
//////////////////////////  Basic Search  //////////////////////////
////////////////////////////////////////////////////////////////////
///  This first function is just a simple scan through the XEX  ////
/////  for binary data. This should be AVOIDED AT ALL COSTS!  //////
///  It is incredibly slow, and the next functions down will be  ///
/////  more effiecient and suffice for most Xbox 360 offsets.  /////
//////  sectionName will be something like ".rdata"/".text"  ///////
void * BasicMemorySearch(char * sectionName, void * scanData, int dataLength);
///  The next is the same as the above, however it doesn't stop  ///
/////  at the first occurance. occurances should be a buffer  //////
///  ready to accept the found offsets. maxOccurances should be  ///
///////  the size of the occurances buffer. Returned is the  ///////
///////////////  number of elements that were found.  //////////////
int BasicMemorySearch(char * sectionName, void * scanData, int dataLength, void * * occurances, int maxOccurances);


////////////////////////////////////////////////////////////////////
/////////////////////  4-byte Algined Search  //////////////////////
////////////////////////////////////////////////////////////////////
//  These are the same as above, however they search for a match  //
///  only on 4-byte aligned offsets. Everything on the Xbox is  ////
/////  4-byte aligned, so this should be used over the above.  /////
void* AlignedMemorySearch(char * sectionName, void * scanData, int dataLength);
int AlignedMemorySearch(char * sectionName, void * scanData, int dataLength, void * * occurances, int maxOccurances);

///  This function will split newOffset into HIWORD and LOWORD  ////
//////  and write it to the buffer at hiOffset and loOffset.  //////
void WriteHILOToBuffer(void* buffer, int hiOffset, int loOffset, int newOffset);

/////  Opposite of the above function. Reads an offset from a  /////
//////////////////  HIWORD and LOWORD in buffer  ///////////////////
void * ReadHILOOffset(void* buffer, int hiOffset, int loOffset);

///  This will look backwards from an offset and attemp to find  ///
////  the start of the function it is in. Some functions start  ////
///  with a mflr, and some are preceeded by a null int. This is  ///
///  the target for this function. Keep in mind, I don't expect  ///
///////////  it to work for everything, so be careful.  ////////////
void * FindFunctionStart(void * buffer);

///// This will take an offset that contains a "bl" instruction ////
////////////////// and return the branch offset. ///////////////////
void * FindFunctionBranch(void * buffer);

#endif//_ADDRESS_REVERSER