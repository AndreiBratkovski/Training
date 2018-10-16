#include "ListOfSinglyLinkedNodes.h"
#include <stdio.h>

void ListOfSinglyLinkedNodes :: display(int mode)
{
	Node *tmp = this->first;
	int index = 0;

	//
	// Display without positional values
	//
	if ( mode == 0 )
	{
		while ( tmp != NULL )
		{
		fprintf(stdout, "%d -> ", tmp->getValue());
		tmp->setAfter(tmp);
		}
	}
	//
	// Display with positional values
	//
	else if ( mode == 1 )
	{
		while ( tmp != NULL )
		{
		fprintf(stdout, "[%d] %d -> ", index, tmp->getValue());
		index++;
		tmp->setAfter(tmp);
		}
	}
}
