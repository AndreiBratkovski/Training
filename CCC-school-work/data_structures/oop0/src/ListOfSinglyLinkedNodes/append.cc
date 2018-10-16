#include "ListOfSinglyLinkedNodes.h"

void ListOfSinglyLinkedNodes :: append(Node *place, Node *newNode)
{
	//
	// Add a new node and increase the quantity of the list by 1
	//
	int quantity = this->getQuantity();
	quantity++;
	if ( place->getAfter() != NULL )
		newNode->setAfter(place->getAfter());
	
	//
	// If at the end, add caboose
	//
	else
		this->setLast(newNode);

	place -> setAfter(newNode);
	this->setQuantity(quantity);
}
