#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main()
{
	List *ltmp   = NULL;
	Node *ntmp   = NULL;
	int   i      = 0;
	int   data[] = { 0, 1, 2, 4, 8, 16, 32, 48, 64 };
	int   num    = 0;
	int   testno = 0;

	char *output[11];
	output[i++]  = "-> NULL";
	output[i++]  = "-> NULL";
	output[i++]  = "0 -> NULL";
	output[i++]  = "0 -> 1 -> NULL";
	output[i++]  = "0 -> 2 -> 1 -> NULL";
	output[i++]  = "0 -> 4 -> 2 -> 1 -> NULL";
	output[i++]  = "0 -> 4 -> 2 -> 1 -> 8 -> NULL";
	output[i++]  = "0 -> 4 -> 2 -> 1 -> 16 -> 8 -> NULL";
	output[i++]  = "0 -> 4 -> 2 -> 1 -> 32 -> 16 -> 8 -> NULL";
	output[i++]  = "0 -> 4 -> 2 -> 48 -> 1 -> 32 -> 16 -> 8 -> NULL";
	output[i++]  = "0 -> 4 -> 64 -> 2 -> 48 -> 1 -> 32 -> 16 -> 8 -> NULL";

	fprintf(stdout, "UNIT TEST: list library append() function\n");
	fprintf(stdout, "=========================================\n");

	// NULL list test
	fprintf(stdout, "Test %d: Appending on NULL list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp         = append(ltmp, NULL, NULL);
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);

	ltmp         = mklist();

	// EMPTY list test
	fprintf(stdout, "Test %d: Appending on empty list ...\n", testno++);
	fprintf(stdout, " you have: "); 
	ltmp         = append(ltmp, NULL, NULL);
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	
	// Building list
	for(i = 0; i < 4; i++)
	{
		fprintf(stdout, "Test %d: Appending %d after start of list ...\n", testno++, data[i]);
		ntmp     = mknode(data[i]);
		fprintf(stdout, " you have: "); 
		ltmp     = append(ltmp, ltmp -> engine, ntmp);
		displayf(ltmp, 0);
		fprintf(stdout, "should be: %s\n\n", output[num++]); 
		fflush(stdout);
	}

	i = 4;

	fprintf(stdout, "Test %d: Appending %d after end of list ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp         = append(ltmp, ltmp -> caboose, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Appending %d after second to caboose node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ntmp         = setpos(ltmp, getpos(ltmp, ltmp -> caboose) - 1);
	ltmp         = append(ltmp, ntmp, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Appending %d after third to caboose node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ntmp         = setpos(ltmp, getpos(ltmp, ltmp -> caboose) - 2);
	ltmp         = append(ltmp, ntmp, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Appending %d after fifth to caboose node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ntmp         = setpos(ltmp, getpos(ltmp, ltmp -> caboose) - 4);
	ltmp         = append(ltmp, ntmp, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	fprintf(stdout, "Test %d: Appending %d after second node ...\n", testno++, data[i]);
	fprintf(stdout, " you have: ");
	ltmp         = append(ltmp, ltmp -> engine -> to, mknode(data[i]));
	displayf(ltmp, 0);
	fprintf(stdout, "should be: %s\n\n", output[num++]); 
	fflush(stdout);
	i            = i + 1;

	return(0);
}
