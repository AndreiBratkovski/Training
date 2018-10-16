#include <stdio.h>
#include "list.h"

int main()
{
	List *myList = NULL;
	Node *tmp    = NULL;
	int   i      = 0;
	int   data[] = { 2, 4, 8, 16, 32, 64 };
	int   testno = 0;

	fprintf(stdout, "UNIT TEST: list library getpos() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "\nTest %d: Running on NULL list ...\n", testno++);
	tmp = NULL;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position -1\n");

	myList       = mklist();

	for (i = 0; i < 6; i++)
	{
		if ((myList != NULL) && (myList != UNDEFINED))
		{
			if (myList -> caboose == NULL)
			{
				myList -> engine          = mknode(data[i]);
				myList -> caboose           = myList -> engine;
			}
			else
			{
				myList -> caboose -> to  = mknode(data[i]);
				myList -> caboose           = myList -> caboose -> to;
			}
		}
	}

	fprintf(stdout, "\nDisplaying list, with position values:\n");
	displayf(myList, 1);

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> engine -> to ...\n", testno++);
	if ((myList != NULL) && (myList != UNDEFINED))
		tmp = myList -> engine -> to;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 1\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> caboose ...\n", testno++);
	if ((myList != NULL) && (myList != UNDEFINED))
		tmp = myList -> caboose;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 5\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> engine -> to -> to -> to ...\n", testno++);
	if ((myList != NULL) && (myList != UNDEFINED))
		tmp = myList -> engine -> to -> to -> to;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 3\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> engine -> to -> to ...\n", testno++);
	if ((myList != NULL) && (myList != UNDEFINED))
		tmp = myList -> engine -> to -> to;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 2\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> engine ...\n", testno++);
	if ((myList != NULL) && (myList != UNDEFINED))
		tmp = myList -> engine;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 0\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to invalid node (not in list) ...\n", testno++);
	tmp = mknode(37);
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position -2\n");

	fprintf(stdout, "\nTest %d: Pointing tmp to myList -> engine -> to -> to -> to -> to ...\n", testno++);
	if ((myList != NULL) && (myList != UNDEFINED))
		tmp = myList -> engine -> to -> to -> to -> to;
	i = getpos(myList, tmp);
	fprintf(stdout, " you have: list position %d\n", i);
	fprintf(stdout, "should be: list position 4\n");

	return(0);
}
