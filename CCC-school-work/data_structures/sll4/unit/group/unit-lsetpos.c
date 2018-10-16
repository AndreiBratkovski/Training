#include <stdio.h>
#include "group.h"

int main()
{
	Group    *myListGroup             = NULL;
	List     *tmp                     = NULL;
	List     *tmp2                    = NULL;
	long int i                        = 0;
	long int j                        = 0;
	long int data[]                   = { 2, 3, 0, 1, 4, 0, 6, 1 };
	long int order[]                  = { 2, 3, 0, 1, 4, 7, 6, 5, -3, 9 };
	long int result                   = 0;
	int      testno                   = 0;

	char *output[10];
	output[i++]  = "<2>: -> NULL";
	output[i++]  = "<3>: 7 -> NULL";
	output[i++]  = "<0>: 4 -> 6 -> NULL";
	output[i++]  = "<1>: 5 -> 7 -> 1 -> NULL";
	output[i++]  = "<4>: 8 -> 10 -> 4 -> 6 -> NULL";
	output[i++]  = "<7>: 11 -> NULL";
	output[i++]  = "<6>: 10 -> 12 -> 6 -> 8 -> 14 -> 6 -> NULL";
	output[i++]  = "<5>: -> NULL";
	output[i++]  = "<ERROR>";
	output[i++]  = "<ERROR>";

	fprintf (stdout, "UNIT TEST: group library lsetpos() function\n");
	fprintf (stdout, "===========================================\n");

	fprintf (stdout, "Test %d: Processing on NULL group, NULL list ...\n", testno++);
	result                            = lgetpos(myListGroup, tmp);
	tmp2                              = lsetpos(myListGroup, result);
	fprintf (stdout, " you have: ");
	displayf(tmp2, 0);
	fprintf (stdout, "should be: NULL\n\n");
	fflush  (stdout);

	tmp = mklist();

	fprintf (stdout, "Test %d: Processing on NULL group, EMPTY list ...\n", testno++);
	result                            = lgetpos(myListGroup, tmp);
	tmp2                              = lsetpos(myListGroup, result);
	fprintf (stdout, " you have: ");
	displayf(tmp2, 0);
	fprintf (stdout, "should be: NULL\n\n");
	fflush  (stdout);

	myListGroup                       = mkgroup();

	fprintf (stdout, "Test %d: Processing on EMPTY group, NULL list ...\n", testno++);
	result                            = lgetpos(myListGroup, NULL);
	tmp2                              = lsetpos(myListGroup, result);
	fprintf (stdout, " you have: ");
	displayf(tmp2, 0);
	fprintf (stdout, "should be: NULL\n\n");
	fflush  (stdout);

	fprintf (stdout, "Test %d: Processing on EMPTY group, EMPTY list ...\n", testno++);
	result                            = lgetpos(myListGroup, tmp);
	tmp2                              = lsetpos(myListGroup, result);
	fprintf (stdout, " you have: ");
	displayf(tmp2, 0);
	fprintf (stdout, "should be: NULL\n\n");
	fflush  (stdout);

	if (myListGroup -> initial         == NULL)
	{
		myListGroup -> initial          = mklist();
		myListGroup -> closing           = myListGroup -> initial;
	}

	tmp                               = myListGroup -> initial;
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < data[i]; j++)
			tmp                       = append(tmp, tmp -> caboose, mknode(data[j]*2+i));

		if (i                        != 7)
		{
			myListGroup -> closing -> next  = mklist();
			myListGroup -> closing           = myListGroup -> closing -> next;
		}
		tmp                               = myListGroup -> closing;
		myListGroup -> closing -> next      = NULL;
	}

	result = ldisplay(myListGroup, -1);

	tmp                                   = myListGroup -> initial;
	for (i = 0; i < 10; i++)
	{
		fprintf (stdout, "Test %d: Testing lsetpos() [%ld/7] ...\n", testno++, i);
		tmp2                              = lsetpos(myListGroup, order[i]);
		fprintf (stdout, " you have: ");
		result = ldisplay(myListGroup, order[i]);
		j = order[i];
		fprintf (stdout, "should be: %s\n\n", output[i]);
		fflush  (stdout);

		if (tmp != NULL)
			tmp                           = tmp -> next;
	}

	return(0);
}
