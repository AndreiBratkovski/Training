#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *ltmp   = NULL;
	Node *ntmp   = NULL;
	Node *ntmp2  = NULL;
	int   i      = 0;
	int   data[] = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int   num    = 0;
	int   testno = 0;

	char *output[14];
	output[i++]  = "NULL";
	output[i++]  = "-> NULL";
	output[i++]  = "-> NULL";
	output[i++]  = "1 -> NULL";
	output[i++]  = "0 -> NULL";
	output[i++]  = "1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 4 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 8 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> 16 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> 8 -> 32 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 48 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 64 -> NULL";
	output[i++]  = "0 -> 1 -> 2 -> 4 -> 8 -> 16 -> 32 -> 48 -> NULL";

	fprintf(stdout, "UNIT TEST: list library obtain() function\n");
	fprintf(stdout, "=========================================\n");

	// NULL list test
	fprintf(stdout, "Test %d: Obtaining on NULL list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp         = obtain(ltmp, &ntmp);
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush (stdout);

	ltmp         = mklist();

	// EMPTY list test
	fprintf(stdout, "Test %d: Obtaining on empty list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp         = obtain(ltmp, &ntmp);
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush (stdout);
	
	// Building list
	for (i = 0; i <= 8; i++)
	{
		if ((ltmp != UNDEFINED) && (ltmp != NULL))
			ltmp     = append(ltmp, ltmp -> caboose,  mknode(data[i]));

		if (i   == 0)
		{
			fprintf(stdout, "Test %d: Obtaining on one-node list (1/2) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				ntmp         = ltmp -> engine;
			ltmp         = obtain(ltmp, &ntmp);
			displayf(ltmp, 0);
			fprintf(stdout, "should be: %s\n\n", output[num++]); 
			fflush (stdout);

			fprintf(stdout, "Test %d: Obtaining on one-node list (2/2) ...\n", testno++);
			if (ntmp != NULL)
				fprintf(stdout, " you have: %d\n", ntmp -> contents); 
			else
				fprintf(stdout, " you have: NULL node\n"); 
			fprintf(stdout, "should be: %d\n\n", data[i]); 
			fflush (stdout);
			
			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				ltmp         = insert(ltmp, ltmp -> engine, ntmp);
		}
		else if (i == 1)
		{
			fprintf(stdout, "Test %d: Obtaining on two-node list (1/4) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				ntmp         = ltmp -> engine;
			ltmp         = obtain(ltmp, &ntmp);
			displayf(ltmp, 0);
			fprintf(stdout, "should be: %s\n\n", output[num++]); 
			fflush (stdout);

			fprintf(stdout, "Test %d: Obtaining on two-node list (2/4) ...\n", testno++);
			if (ntmp != NULL)
				fprintf(stdout, " you have: %d\n", ntmp -> contents); 
			else
				fprintf(stdout, " you have: NULL node\n"); 
			fprintf(stdout, "should be: %d\n\n", data[0]); 
			fflush (stdout);
			
			fprintf(stdout, "Test %d: Is engine now caboose? ...\n", testno++);
			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				fprintf(stdout, " you have: %d\n", ltmp -> engine -> contents); 
			else
				fprintf(stdout, " you have: UNDEFINED or NULL list\n");
			fprintf(stdout, "should be: %d\n\n", data[1]); 
			fflush (stdout);

			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				ltmp         = insert(ltmp, ltmp -> engine, ntmp);

			fprintf(stdout, "Test %d: Obtaining on two-node list (3/4) ...\n", testno++);
			fprintf(stdout, " you have: "); 
			ntmp         = ltmp -> caboose;
			ltmp         = obtain(ltmp, &ntmp);
			displayf(ltmp, 0);
			fprintf(stdout, "should be: %s\n\n", output[num++]); 
			fflush (stdout);

			fprintf(stdout, "Test %d: Obtaining on two-node list (4/4) ...\n", testno++);
			if (ntmp != NULL)
				fprintf(stdout, " you have: %d\n", ntmp -> contents); 
			else
				fprintf(stdout, " you have: NULL node\n"); 
			fprintf(stdout, "should be: %d\n\n", data[1]); 
			fflush (stdout);
			
			fprintf(stdout, "Test %d: Is caboose now engine? ...\n", testno++);
			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				fprintf(stdout, " you have: %d\n", ltmp -> caboose -> contents); 
			else
				fprintf(stdout, " you have: UNDEFINED or NULL list\n");
			fprintf(stdout, "should be: %d\n\n", data[0]); 
			fflush (stdout);
			
			if ((ltmp != UNDEFINED) && (ltmp != NULL))
				ltmp         = append(ltmp, ltmp -> caboose, ntmp);
		}
	}

	for (i = 0; i <= 8; i++)
	{
		ntmp       = setpos(ltmp, i);
		ntmp2      = setpos(ltmp, (i+1));
		if (ntmp2 == NULL)
			ntmp2  = ltmp -> engine;

		ltmp       = obtain(ltmp, &ntmp);

		fprintf(stdout, "Test %d: Checking list integrity (pos %d/8) ...\n", testno++, i);
		fprintf(stdout, " you have: "); 
		displayf(ltmp, 0);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush (stdout);

		fprintf(stdout, "Test %d: Checking obtained value ...\n", testno++);
		if (ntmp != NULL)
			fprintf(stdout, " you have: %d\n", ntmp -> contents); 
		else
			fprintf(stdout, " you have: NULL node\n"); 
		fprintf(stdout, "should be: %d\n\n", data[i]); 
		fflush (stdout);

		if (i     != 8)
			ltmp   = insert(ltmp, ntmp2, ntmp);
		else
			ltmp   = append(ltmp, ntmp2, ntmp);
	}

	// Clean up
	//
	ntmp           = rmnode(ntmp);
	ntmp2          = rmnode(ntmp2);
	
	return(0);
}
