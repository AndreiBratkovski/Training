#include "ListOfSinglyLinkedNodes.h"

//
// Iterate over list to find a node with the same value
//
Node * ListOfSinglyLinkedNodes :: find(int value)
{
	Node *newNode = this->first;
	while (newNode->getValue() != value && newNode != NULL)
	{
		newNode = newNode->getAfter();
	}

	return(newNode);
}
