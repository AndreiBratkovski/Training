#include <ListOfSinglyLinkedNodes.h>

Node * ListOfSinglyLinkedNodes :: getFirst()
{
	//
	// Find first member of list, return it
	//
	Node *newNode = this->first;
	return (newNode);
}

//
// Set first to the new node, thus resetting newnode 
// 
void   ListOfSinglyLinkedNodes :: setFirst(Node *newNode)
{
	this->first = newNode;
}
