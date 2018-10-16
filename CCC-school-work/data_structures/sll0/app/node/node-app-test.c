#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2, *tmp3, *tmp4;

	tmp		   = (Node *) malloc (sizeof(Node)*1);
	tmp  -> contents = 8;
	tmp  -> to  = NULL;

	tmp2		  = (Node *) malloc (sizeof(Node)*1);
	tmp2 -> contents = 12;
	tmp2 -> to  = NULL;

	tmp3		  = (Node *) malloc (sizeof(Node)*1);
	tmp3 -> contents = 17;
	tmp3 -> to  = NULL;
	tmp2 -> contents = tmp3 -> contents;

	tmp2 -> contents = tmp2 -> contents + 16;

	tmp4		  = (Node *) malloc (sizeof(Node)*1);
	tmp4 -> contents = tmp2 -> contents;
	tmp4 -> to  = NULL;

	fprintf(stdout, "tmp  points to %p, contains: %d\n", tmp,  tmp  -> contents);
	fprintf(stdout, "tmp2 points to %p, contains: %d\n", tmp2, tmp2 -> contents);
	fprintf(stdout, "tmp3 points to %p, contains: %d\n", tmp3, tmp3 -> contents);
	fprintf(stdout, "tmp4 points to %p, contains: %d\n", tmp4, tmp4 -> contents);

	return(0);
}
