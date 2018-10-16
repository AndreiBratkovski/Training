#include "ListOfSinglyLinkedNodes.h"

// needs to properly handle invalid list positions ( < 0)
Node * ListOfSinglyLinkedNodes :: setListPosition(int pos)
{
	int currentPos = 0;
	Node *tmp = this->first;
	//
	// Make sure position exists
	//
	if ( pos >= 0 && pos <= this->getQuantity() )
	{
		//
		// Iterate over the list until tmp is set to the
		// position listed in the parameter
		//
		while ( currentPos != pos )
		{
			tmp->setAfter(tmp);
			currentPos++;
		}
	}
	return(tmp);
}

// Needs to handle improper place pointers (ie NULL)
int ListOfSinglyLinkedNodes :: getListPosition(Node *place)
{
	int position = 0;
	Node *tmp = this->first;

	//
	// Iterate over the list until tmp is the same as place
	// increase the position pointer each time
	//	
	while ( tmp != place && tmp != NULL )
	{
		tmp->setAfter(tmp);
		position++;
	}
	return(position);
}
