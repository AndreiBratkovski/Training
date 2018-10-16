#ifndef _SUPPORT_H
#define _SUPPORT_H

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////
//
// create a peer to NULL for our endeavors: UNDEFINED
//
#if !defined(UNDEFINED)
    #define UNDEFINED ((void*)1)
#endif

//////////////////////////////////////////////////////////////////////
//
// Project variable
//
char UNIT_CODE;

//////////////////////////////////////////////////////////////////////
//
// malloc() interposition
//
#define ALLOC_NORMAL          1
#define ALLOC_ERROR           2
#define ALLOC_RANDOM          4
#define ALLOC_VERBOSE         8
#define ALLOC_DEBUG           16

//define malloc(x) support_malloc(x, __FILE__, __LINE__)
void *support_malloc(size_t, char *, int);

//////////////////////////////////////////////////////////////////////
//
// Setting up for calloc() wrapper function
//
//void * __real_calloc(size_t nmemb, size_t size);
//void * __wrap_calloc(size_t nmemb, size_t size);

#endif
