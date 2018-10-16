#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *ltmp   = NULL;
	List *ltmp2  = NULL;
	int   i      = 0;
	int   testno = 0;

	fprintf(stdout, "UNIT TEST: list library mklist() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Creating new list ...\n", testno++);
	ltmp = ltmp2 = mklist();
	if ((ltmp   == NULL) && (ltmp2 == NULL))
		fprintf(stdout, " you have: NULL\n");
	else if (ltmp == UNDEFINED)
		fprintf(stdout, " you have: UNDEFINED\n");
	else if ((ltmp -> engine == NULL) && (ltmp -> caboose == NULL))
		fprintf(stdout, " you have: *NOT* NULL\n");
	else
		fprintf(stdout, " you have: NULL\n");

	fprintf(stdout, "should be: *NOT* NULL\n\n"); 
	fflush(stdout);

	for (i = 0; i < 4; i++)
	{
		fprintf(stdout, "Test %d: Creating another new list ...\n", testno++);
		ltmp2          = mklist();
		if ((ltmp     == ltmp2) && (ltmp == NULL))
			fprintf(stdout, " you have: NULL\n");
		else if ((ltmp == UNDEFINED) || (ltmp2 == UNDEFINED))
			fprintf(stdout, " you have: UNDEFINED\n");
		else if (ltmp == ltmp2)
			fprintf(stdout, " you have: ltmp and ltmp2 still the same\n");
		else
			fprintf(stdout, " you have: ltmp and ltmp2 *NOT* the same\n");

		fprintf(stdout, "should be: ltmp and ltmp2 *NOT* the same\n\n"); 
		fflush(stdout);

		if ((i % 2)   == 0)
			ltmp       = ltmp2;
		else
			ltmp       = NULL;
	}

	return(0);
}
