//Samuel J Grenon
//3/27/2018
//mapalloc.h
//CS321 Assignment 4 A



#ifndef MAPALLOC_H_INCLUDED
#define MAPALLOC_H

#include <stdio.h>
#include <cstddef> 
#include <sys/mman.h> 



void * mapAlloc(size_t);
void mapFree(void *);
size_t size;




#endif