#include <stdio.h>
#include "list.h"
#include "support.h"

int main()
{
	List   *ltmp   = NULL;
	List   *ltmp2  = NULL;

	Node   *ntmp   = NULL;
	Node   *ntmp2  = NULL;

	int     i      = 0;
	int     count  = 0;
	int     tally  = 0;
	int     testno = 0;

	code_t  result = 0;

	fprintf(stdout, "UNIT TEST: list library cplist() function\n");
	fprintf(stdout, "=========================================\n");

	fprintf(stdout, "Test %d: Testing NULL case ...\n", testno++);
	result = cplist(NULL, NULL);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_INVALID | DLL_ERROR);
	fflush (stdout);

	result = cplist(ltmp, &ltmp2);

	fprintf(stdout, "\nTest %d: Copying a NULL list ...\n", testno++);
	if ((ltmp == NULL) && (ltmp2 == NULL))
		fprintf(stdout, " you have: NULL (success)\n");
	else
		fprintf(stdout, " you have: *NOT* NULL\n");

	fprintf(stdout, "should be: NULL (success)\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_ERROR | DLL_NULL);
	fflush (stdout);

	mklist(&ltmp);
	result = cplist(ltmp, &ltmp2);

	fprintf(stdout, "\nTest %d: Copying an empty list ...\n", testno++);
	if ((ltmp == NULL) && (ltmp2 == NULL))
		fprintf(stdout, " you have: NULL\n");
	else if (ltmp == ltmp2)
		fprintf(stdout, " you have: ltmp and ltmp2 point to same list\n");
	else if ((ltmp->engine == NULL) && (ltmp->caboose == NULL) &&
		 (ltmp2->engine == NULL) && (ltmp2->caboose == NULL))
		fprintf(stdout, " you have: *NOT* NULL (success)\n");
	else
		fprintf(stdout, " you have: not valid\n");

	fprintf(stdout, "should be: *NOT* NULL (success)\n\n");
	fflush (stdout);

	fprintf(stdout, "\nTest %d: Checking results ...\n", testno++);
	fprintf(stdout, " you have: ");
	lscodes(result);
	fprintf(stdout, "should be: ");
	lscodes(DLL_SUCCESS | DLL_EMPTY);
	fflush (stdout);

	for (i = 0; i < 8; i++)
	{
		ntmp = NULL;
		mknode(&ntmp, i);
		if (ltmp     -> engine == NULL)
		{
			ltmp     -> engine  = ltmp -> caboose = ntmp;
			if (ltmp -> engine == NULL)
			{
				fprintf(stderr, "mknode() encountered a problem. Bailing out...\n");
				exit(1);
			}
		}
		else
		{
			catnode(&ltmp, ltmp -> caboose, ntmp);
		}

		if ((i < 3) || ((i % 2) == 0))
		{
			//free(ltmp2);
	   	    ltmp2 = NULL;
		}
		else
		{
			free(ltmp);
			ltmp = NULL;
			ltmp = ltmp2;
		}

		result   = cplist(ltmp, &ltmp2);

		ntmp  = ltmp  -> caboose;
		ntmp2 = ltmp2 -> caboose;

		if ((result & (DLL_ERROR | DLL_ALREADY_ALLOC)) !=
		    (DLL_ERROR | DLL_ALREADY_ALLOC))
		{
			count = 0;
			tally = 0;
			while ((ntmp != NULL) && (ntmp2 != NULL))
			{
				if ((ltmp == NULL) && (ltmp2 == NULL))
				{
					tally += 100;
					break;
				}
				else if ((ltmp == ltmp2) || (ntmp == ntmp2))
				{
					tally = -1 * tally;
					break;
				}
				else if (ntmp->VALUE == ntmp2->VALUE)
					tally = tally + 1;

				ntmp  = ntmp  -> fro;
				ntmp2 = ntmp2 -> fro;
				count = count + 1;
			}

			fprintf(stdout, "\nTest %d: copying list of %d nodes ...\n", testno++, (i+1));
			if (tally == count)
				fprintf(stdout, " you have: list is a copy\n");
			else if ((tally < count) && (tally > -1))
				fprintf(stdout, " you have: list was not copied correctly\n");
			else if ((tally < count) && (tally < 1))
				fprintf(stdout, " you have: lists are not copies\n");
			else if (tally > count)
				fprintf(stdout, " you have: list has a problem\n");
			else
				fprintf(stdout, " you have: not valid (error)\n");

			fprintf(stdout, "should be: list is a copy\n");
			fflush (stdout);
		}

		if ((i % 2 == 0) || (i < 3))
		{
			fprintf(stdout, "\nTest %d: Checking results (i is %d) ...\n", testno++, i);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_SUCCESS);
			fflush (stdout);
		}
		else if (i > 2)
		{
			fprintf(stdout, "\nTest %d: Checking results (i is %d) ...\n", testno++, i);
			fprintf(stdout, " you have: ");
			lscodes(result);
			fprintf(stdout, "should be: ");
			lscodes(DLL_ERROR | DLL_ALREADY_ALLOC);
			fflush (stdout);
		}
	}

	return (0);
}
