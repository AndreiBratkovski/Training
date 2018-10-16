#include <ListOfDoublyLinkedNodes.h>

ListOfDoublyLinkedNodes :: ~ListOfDoublyLinkedNodes()
{
while (this -> getFirst() != NULL)
	{
		delete (this -> obtain(this -> getFirst()));
	}

	// Set members to sane values...
	this -> setFirst(NULL);
	this -> setLast  (NULL);
	this -> setQuantity(0);
}
