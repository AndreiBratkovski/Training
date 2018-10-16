#include <ListOfSinglyLinkedNodes.h>

//
// Return the last node of the list 
//
Node * ListOfSinglyLinkedNodes :: getLast()
{
	Node *newNode = this->last;
	return (newNode);
}

//
// Set last to the given node
//
void   ListOfSinglyLinkedNodes :: setLast(Node *newNode)
{
	this->last = newNode;
}
