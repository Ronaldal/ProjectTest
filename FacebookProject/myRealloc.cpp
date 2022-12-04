#include "myRealloc.h"
//generic function for realloc
void* reallocation(void* ptr, int numElem, int elemSize)
{
	void* newptr;
	newptr = new unsigned char* [numElem];
	memcpy(newptr, (unsigned char*)ptr, numElem * elemSize);
	delete[]ptr;
	return newptr;
}