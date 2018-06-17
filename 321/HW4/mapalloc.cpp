//Samuel J Grenon
//3/28/2018
//mapalloc.cpp allocates memory using mmap. Frees memory using munmap.
//CS321 Assignment 4 A



#include "mapalloc.h"
#include <iostream>
#include <map>
#include <string>
using std::map;
using std::size_t;







//Pre: None
//Post: Allocates n amount of memory using mmap
//      returns nullptr if failed.
void * mapAlloc(size_t bytes) {

    size = bytes;
    void * addr = mmap(
        nullptr,
        bytes,
        PROT_READ | PROT_WRITE,
        MAP_SHARED | MAP_ANONYMOUS,
        -1,
        0);

    if (addr == MAP_FAILED){
        return nullptr;
    }
    
  
    return addr;

}

    
//Pre:none
//Post: Frees the memory allocated with mmap.
void mapFree(void * memPtr) {
    munmap(memPtr,size);
}



