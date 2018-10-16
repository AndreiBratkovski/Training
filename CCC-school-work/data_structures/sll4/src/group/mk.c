#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// mkgroup() - a group library function to allocate and initialize a 
//             new group.
//
//   behavior: on error, return NULL.
//
//       note: as with the other functions, you may use no more
//             than one return() statement per function.
//
Group *mkgroup(void)
{
	//
	// Allocate and initialize a Group of lists.  Each group
	// contains an initial and closing list pointer.
	// They will be allocated to List size and point to NULL.  
	//
	Group *myGroup;

	myGroup = (Group *) malloc(sizeof(Group));

	myGroup->initial = (List *) malloc(sizeof(List));
	myGroup->initial = NULL;

	myGroup->closing = (List *) malloc(sizeof(List));
	myGroup->closing = NULL;

	return (myGroup);
}
