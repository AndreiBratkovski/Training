#include <stdio.h>
#include "list.h"

int main()
{
	List *myList1             = NULL;
	List *myList2             = NULL;
	Node *tmp1                = NULL;
	Node *tmp2                = NULL;
	int   i                   = 0;
	int   data[]              = { 1, 2, 4, 8, 16, 32, 48, 64 };
	int   testno              = 0;

	fprintf(stdout, "UNIT TEST: list library cplist() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Copying on a NULL list ...\n", testno++);
	myList2                   = cplist(myList1);
	if ((myList1             == NULL) &&
		(myList2             == NULL))
	{
		fprintf(stdout, " you have: *NULL* List\n");
	}
	else
		fprintf(stdout, " you have: *NON-NULL* List\n");
	fprintf(stdout, "should be: *NULL* List\n");

	myList2                   = NULL;  // ensuring it is NULL
	myList1                   = mklist();

	fprintf(stdout, "\nTest %d: Copying an empty list ...\n", testno++);
	myList2                   = cplist(myList1);
	if (myList2              == NULL)
		fprintf(stdout, " you have: *NULL* List\n");
	else if (myList2         == myList1)
		fprintf(stdout, " you have: The *SAME* (Identical) List!\n");
	else
		fprintf(stdout, " you have: Copied List\n");
	fprintf(stdout, "should be: Copied List\n");

	for (i  = 0; i < 8; i++)
	{
		if ((i % 2)           == 0)
			myList1            = insert(myList1, myList1 -> engine, mknode(data[i]));
		else
			myList1            = insert(myList1, myList1 -> caboose,  mknode(data[i]));
	}

	myList2                    = NULL;

	fprintf(stdout, "\nDisplaying list:\n");
	displayf(myList1, 1);

	// Connecting this list to another list
	myList1 -> next           = mklist();
	myList1 -> next           = insert(myList1 -> next, myList1 -> next -> engine, mknode(3));

	fprintf(stdout, "\nTest %d: Copying a populated list ...\n", testno++);
	displayf(myList1, 1);
	myList2                    = cplist(myList1);
	displayf(myList2, 1);
	if (myList2               == NULL)
		fprintf(stdout, " you have: *NULL* List\n");
	else if (myList2          == myList1)
		fprintf(stdout, " you have: The *SAME* (Identical) List!\n");
	else
		fprintf(stdout, " you have: Copied List\n");
	fprintf(stdout, "should be: Copied List\n");

	fprintf(stdout, "\nTest %d: Checking list quantities ...\n", testno++);
	fprintf(stdout, " you have: %lu\n", myList2 -> qty); 
	fprintf(stdout, "should be: %lu\n", myList1 -> qty); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking list after pointers ...\n", testno++);
	if (myList2 -> next      == NULL)
		fprintf(stdout, " you have: NULL\n"); 
	else
		fprintf(stdout, " you have: %p\n", myList2 -> next); 
	fprintf(stdout,     "should be: %p\n", myList1 -> next); 
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking list after nodes ...\n", testno++);
	fprintf(stdout, " you have: %hhd\n", myList2 -> next -> engine -> contents); 
	fprintf(stdout, "should be: %hhd\n", 3); 
	fflush (stdout);

	for (i = 7; i >= 0; i--)
	{
		fprintf(stdout, "\nTest %d: Comparing copied lists (pos %d vs. pos %d) ...\n",testno++,i,i);
		tmp1                   = setpos(myList1, i);
		tmp2                   = setpos(myList2, i);

		if (tmp1              == tmp2)
			fprintf(stdout, " you have: Identical Node! (not a copy)\n");
		else if(tmp2          == NULL)
			fprintf(stdout, " you have: *NULL* Node!\n");
		else
		{
			if (tmp1 -> contents  == tmp2 -> contents)
				fprintf(stdout, " you have: Copied Node!\n");
			else
				fprintf(stdout, " you have: Different Node!\n");
		}
		fprintf(stdout, "should be: Copied Node!\n");
	}

	return(0);
}
