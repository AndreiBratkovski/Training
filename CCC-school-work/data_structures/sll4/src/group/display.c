#include <stdio.h>
#include "group.h"

//////////////////////////////////////////////////////////////////////
//
// ldisplay() - display the list group in an organized fashion (list
//              by list) or to display an isolated list from the group
//              of lists (as indicated by the pos parameter).
//
//    behavior: on a NULL group, output "<NULL>", return -1
//              on an EMPTY group, output "<EMPTY>", return 0
//              on an error state, output "<ERROR>", return -2
//
//              pos serves a dual purpose:
//                  -1: displays all lists in the list group
//                   0-n: displays that particular list in the group
//
//      output: (if pos is a -1):
//              <0>: 2 -> 4 -> 8 -> NULL
//              <1>: 3 -> 6 -> NULL
//              <2>: -> NULL
//              <3>: 12 -> 36 -> 96 -> 112 -> 119 -> NULL
//
//              (if pos is a 1):
//              <1>: 3 -> 6 -> NULL
//
//return value: the number of lists displayed
//
//        note: ALL output ends with a newline character
//
sli ldisplay(Group * myListGroup, sli pos)
{
	//
	// Function to display groups of lists
	//

	//
	// Initialize List tmp variable for traversing groups and 
	// a numLists variable to keep track of the number of lists
	//
	List *tmp;
	sli numLists = 0;

	//
	// If List group is NULL, return <NULL> messagee
	//
	if (myListGroup == NULL)
	{
		numLists = -1;
		fprintf(stdout, "<NULL>\n");
	}

	//
	// If List group is not Null and List group is not undefined,
	// we begin programming logic, due to the list group existing
	//
	else if (myListGroup != NULL && myListGroup != UNDEFINED)
	{
		//
		// If the list group is empty,
		// print out <EMPTY> message
		//
		if (myListGroup->initial == NULL)
		{
			numLists = 0;
			fprintf(stdout, "<EMPTY>\n");
		}
		//
		// If list is NOT empty, begin programming logic
		//
		else if (myListGroup->initial != NULL)
		{
			//
			// If pos is given as -1, ldisplay prints out all lists in
			// a list group, traversing through groups in a while loop
			//
			if (pos == -1)
			{
				tmp = myListGroup->initial;
				while (tmp != NULL)
				{
					fprintf(stdout, "<%ld>: ",
						lgetpos(myListGroup, tmp));
					displayf(tmp, 0);
					tmp = tmp->next;
					numLists++;
				}
			}
			//
			// If the pos in list group is not -1, then ldisplay prints out
			// the list group corresponding to that number. numLists is 1 because
			// ldisplay prints 1 list
			//
			else if (lsetpos(myListGroup, pos) != NULL)
			{
				tmp = lsetpos(myListGroup, pos);
				fprintf(stdout, "<%ld>: ", pos);
				displayf(tmp, 0);
				numLists = 1;
			}
			//
			// if pos/ the list Group does not fit into any of the previous categories,
			// there is an error message printed out, setting numLists to -2. meaning error.
			//
			else
			{
				numLists = -2;
				fprintf(stdout, "<ERROR>\n");
			}
		}
	}
	//
	// if listGroup is undefined, print out error message, and set numLists to error
	// code -2
	//
	else if (myListGroup == UNDEFINED)
	{
		numLists = -2;
		fprintf(stdout, "<ERROR>\n");
	}

	return (numLists);
}
