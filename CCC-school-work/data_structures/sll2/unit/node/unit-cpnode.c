#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
	Node *tmp	= NULL;
	Node *tmp2   = NULL;

	int   testno = 0;

	UNIT_CODE	= 0;

	fprintf(stdout, "UNIT TEST: node library cpnode() function\n");
	fprintf(stdout, "=========================================\n");

	tmp2		 = cpnode(tmp);

	fprintf(stdout, "Test %d: Copying a NULL node ...\n", testno++);
	if (tmp2 == NULL)
		fprintf(stdout, " you have: NULL (success)\n");
	else
		fprintf(stdout, " you have: *NOT* NULL\n");

	fprintf(stdout, "should be: NULL (success)\n\n"); 
	fflush(stdout);
	
	tmp		  = mknode(37);
	tmp2		 = cpnode(tmp); 

	fprintf(stdout, "Test %d: Copying a node ...\n", testno++);
	if (tmp2	== UNDEFINED)
		fprintf(stdout, " you have: UNDEFINED\n");
	else if ((tmp != NULL) && (tmp2 != NULL) && (tmp != tmp2))
		fprintf(stdout, " you have: different (success)\n");
	else if ((tmp == NULL) && (tmp2 == NULL))
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: the same\n");

	fprintf(stdout, "should be: different (success)\n\n"); 
	fflush(stdout);

	if (tmp != NULL)
		tmp -> contents  = 57;

	fprintf(stdout, "Test %d: Changing tmp ...\n", testno++);
	if ((tmp != NULL) && (tmp2 != NULL) && (tmp -> contents != tmp2 -> contents))
		fprintf(stdout, " you have: different (success)\n");
	else if ((tmp == NULL) && (tmp2 == NULL))
		fprintf(stdout, " you have: NULL\n");
	else
		fprintf(stdout, " you have: the same\n");

	fprintf(stdout, "should be: different (success)\n\n"); 
	fflush(stdout);

	if (tmp != NULL)
	{
		tmp -> to				 = mknode(73);

		if (tmp -> to != NULL)
		{
			tmp -> to -> to	= mknode(81);
			tmp2					 = cpnode (tmp -> to);
		}
	}

	fprintf(stdout, "Test %d: Checking value on copied node in list ...\n", testno++);
	if ((tmp == NULL) || (tmp -> to == NULL) || (tmp2 == NULL))
		fprintf(stdout, " you have: NULL node\n");
	else if (tmp -> to -> contents == tmp2 -> contents)
		fprintf(stdout, " you have: the same value (success)\n");
	else
		fprintf(stdout, " you have: different\n");
	fprintf(stdout, "should be: the same value (success)\n\n");

	fprintf(stdout, "Test %d: Checking to on copied node in list ...\n", testno++);
	if ((tmp == NULL) || (tmp -> to == NULL) || (tmp2 == NULL))
		fprintf(stdout, " you have: NULL node\n");
	else if (tmp -> to -> to == tmp2 -> to)
		fprintf(stdout, " you have: the same to (success)\n");
	else
		fprintf(stdout, " you have: different\n");
	fprintf(stdout, "should be: the same to (success)\n\n");

	return(0);
}
