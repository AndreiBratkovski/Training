#include "ListOfSinglyLinkedNodes.h"

//
// Disconnect a node from the list
//
Node * ListOfSinglyLinkedNodes :: obtain (Node *place)
{
	//
	// Set the quantity as one lower just incase obtain is
	// successful
	//
	int quantity = this->getQuantity();
	quantity--;
	Node *tmp = this->first;

	//
	// Get to the position before the place parameter node
	// so that logic can be set
	//
	while ( tmp->getAfter() != place )
		tmp->setAfter(tmp);

	//
	// direct the temporary node pointer to the node
	// after place, therefore disconnecting place
	//
	if ( place != NULL )
	{
		tmp->setAfter(place->getAfter());
		this->setQuantity(quantity);
	}
	return(place);
}
