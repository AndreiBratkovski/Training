#include "ListOfSinglyLinkedNodes.h"

// insert() - insert newNode before place in this
//
void ListOfSinglyLinkedNodes :: insert(Node *place, Node *newNode)
{
	int quantity = this->getQuantity();
	quantity++;
	Node *tmp = NULL;
	tmp = this->first;
	while ( tmp->getAfter() != place )
	{
		tmp->setAfter(tmp);
	}
	//
	// Inserting the node anywhere that exists
	//
	if ( place != NULL )
	{
		newNode->setAfter(place);
		tmp->setAfter(newNode);
		//
		// Up the list quantity on successful insertion
		//
		this->setQuantity(quantity);
	}
	
}
