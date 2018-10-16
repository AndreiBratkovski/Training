#include <stdio.h>
#include "node.h"

void display(Node *);

int main()
{
	// rewrite node-app-display to use the node library functions
	// (mknode(), specifically). The resulting output
	// should be IDENTICAL to the original node-app-display program.

	char input;

	fprintf(stdout, "Enter a contents (-1 to quit): ");
	fscanf(stdin, "%hhd", &input);

	Node *newNode;

	newNode = mknode(input);

	Node *start;

	start = newNode;

	while (input != -1)
	{
		fprintf(stdout, "Enter a contents (-1 to quit): ");
		fscanf(stdin, "%hhd", &input);

		if (input == -1)
		{
			break;
		}

		newNode->to = mknode(input);
		newNode = newNode->to;
	}

	// Display list from start to end by calling the display() 
	// function, passing in a pointer to the start of the list.
	display(start);

	return (0);
}

void display(Node * start)
{
	// implement your display list function here, and call it from
	// main() -- you may use the same code implemented previously 
	// for displaying the list.

	while (start != NULL)
	{
		printf("%hhd -> ", start->contents);
		start = start->to;
	}
	printf("NULL\n");
	// This is a test to see if you can modularize your code.
}
