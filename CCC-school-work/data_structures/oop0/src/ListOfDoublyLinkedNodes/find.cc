#include "ListOfDoublyLinkedNodes.h"

Node * ListOfDoublyLinkedNodes :: find(int value)
{
	Node *newNode = this->first;
	while (newNode->getValue() != value && newNode != NULL)
	{
		newNode = newNode->getAfter();
	}

	return(newNode);
}
