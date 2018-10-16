#include <DoublyLinkedNode.h>

DoublyLinkedNode :: DoublyLinkedNode()
{
	//
	// Create a default new Node pointing at
	// Nothing, but default valued at 0
	//
	this->prior = NULL;
	this->setValue(0);
}

DoublyLinkedNode :: DoublyLinkedNode(int value)
{
	//
	// Do the same as above, except set the value to
	// the user's listed value in the parameter
	//
	this->setValue(value);
	this->prior = NULL;
}
