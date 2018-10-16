#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2, *tmp3, *tmp4;

	tmp		   = (Node *) malloc (sizeof(Node)*1);
	tmp  -> contents = 8;
	tmp  -> to  = tmp2 = (Node *) malloc (sizeof(Node)*1);
	tmp2 -> contents = 12;
	tmp2 -> to  = NULL;

	tmp3		  = (Node *) malloc (sizeof(Node)*1);
	tmp3 -> contents = 17;
	tmp3 -> to  = tmp2;

	tmp2 -> contents = tmp2 -> contents + 16;

	tmp2 -> to  = tmp4 = (Node *) malloc (sizeof(Node)*1);
	tmp4 -> contents = tmp2 -> contents - 2;
	tmp4 -> to  = NULL;

	fprintf(stdout, "tmp  points to %p, contains: %d, ", tmp,  tmp  -> contents);
	fprintf(stdout, "tmp's to is: %p\n", tmp -> to);
	fprintf(stdout, "tmp2 points to %p, contains: %d, ", tmp2, tmp2 -> contents);
	fprintf(stdout, "tmp2's to is: %p\n", tmp2 -> to);
	fprintf(stdout, "tmp3 points to %p, contains: %d, ", tmp3, tmp3 -> contents);
	fprintf(stdout, "tmp3's to is: %p\n", tmp3 -> to);
	fprintf(stdout, "tmp4 points to %p, contains: %d, ", tmp4, tmp4 -> contents);
	fprintf(stdout, "tmp4's to is: %p\n", tmp4 -> to);

	return(0);
}
