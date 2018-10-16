#include <DoublyLinkedNode.h>

DoublyLinkedNode :: ~DoublyLinkedNode()
{
	//
	// Single out the node, setting its value
	// to 0 and pointing to nothing both ways
	//
	this -> setValue(0);
	this -> prior = NULL;
}
