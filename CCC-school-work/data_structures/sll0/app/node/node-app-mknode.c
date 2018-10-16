#include <stdio.h>
#include <stdlib.h>
#include "node.h"

int main()
{
	Node *tmp1, *tmp2;
	
	fprintf(stdout, "Before calling mknode() ... \n");
	fprintf(stdout, "---------------------------------------------\n");
	fprintf(stdout, "tmp1 has an address of:		%p\n", &tmp1);
	fprintf(stdout, "tmp1 points to:				%p\n",  tmp1);
	fprintf(stdout, "tmp2 has an address of:		%p\n", &tmp2);
	fprintf(stdout, "tmp2 points to:				%p\n",  tmp2);

	tmp1 = mknode(8);

	if (tmp1 == NULL)
	{
		fprintf(stderr, "Error creating new node (tmp1).\n");
		exit(1);
	}

	tmp1 -> to = mknode(13);

	if (tmp1 -> to == NULL)
	{
		fprintf(stderr, "Error creating new node (tmp1 -> to).\n");
		exit(1);
	}

	tmp2 = mknode(7);

	if (tmp2 == NULL)
	{
		fprintf(stderr, "Error creating new node (tmp2).\n");
		exit(1);
	}

	tmp2 -> to = tmp1;
 
	fprintf(stdout, "\nAfter calling mknode() ... \n");
	fprintf(stdout, "---------------------------------------------\n");
	fprintf(stdout, "tmp1 has an address of:		%p\n",   &tmp1);
	fprintf(stdout, "tmp1 points to:				%p\n",	tmp1);
	fprintf(stdout, "tmp1 contains a contents of:	  %d\n",	tmp1 -> contents);
	fprintf(stdout, "tmp1's to pointer points to: %p\n\n",  tmp1 -> to);

	fprintf(stdout, "tmp1's to contains contents:	%d\n",	tmp1 -> to -> contents);
	fprintf(stdout, "tmp1 to's to points to:	%p\n\n",  tmp1 -> to -> to);
 
	fprintf(stdout, "tmp2 has an address of:		%p\n",   &tmp2);
	fprintf(stdout, "tmp2 points to:				%p\n",	tmp2);
	fprintf(stdout, "tmp2 contains a contents of:	  %d\n",	tmp2 -> contents);
	fprintf(stdout, "tmp2's to pointer points to: %p\n\n",  tmp2 -> to);

	fprintf(stdout, "draw this collection of nodes\n\n");

	return(0);
}
