#include <stdio.h>
#include "node.h"

int main()
{
	Node *tmp, *tmp2;
	char input;

	tmp = tmp2 = (Node *) malloc(sizeof(Node) * 1);
	tmp->contents = 0;
	tmp->to = NULL;

	fprintf(stdout, "Enter a contents (-1 to quit): ");
	fscanf(stdin, "%hhd", &input);

	int count = 0;		// counter to keep track of inputs

	while (input != -1)
	{
		tmp2->contents = input;

		tmp2->to = (Node *) malloc(sizeof(Node) * 1);
		tmp2->to->contents = 0;
		tmp2->to->to = NULL;

		fprintf(stdout, "Enter a contents (-1 to quit): ");
		fscanf(stdin, "%hhd", &input);

		if (input == -1)
		{
			free(tmp2->to);
			tmp2->to = NULL;
		}
		else
			tmp2 = tmp2->to;

		count++;
	}

	//
	// Iterate through contents of linked List and print out values
	//
	int increment = 0;

	for (increment; increment < count; increment++)
	{
		printf("%hhd -> ", tmp->contents);
		tmp = tmp->to;
	}
	printf("NULL\n");	// print NULL at end to represent final pointer (in linked list)

	return (0);
}
