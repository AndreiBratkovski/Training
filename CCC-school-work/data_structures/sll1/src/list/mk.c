#include "list.h"

//////////////////////////////////////////////////////////////////////
//
// mklist() - a list library function to allocate and initialize a 
//                      new list.
//
//  behavior: on error, return NULL.
//
//        note: you are to have only ONE return statement for this
//                      entire function. Change the existing one as needed.
//
List *mklist(void)
{
	//
	// initialize myList and allocate engine/caboose
	//
	List *myList;

	myList = (List *) malloc(sizeof(List));

	myList->engine = (Node *) malloc(sizeof(Node));
	myList->engine = NULL;
	myList->caboose = (Node *) malloc(sizeof(Node));
	myList->caboose = NULL;

	return (myList);
}
