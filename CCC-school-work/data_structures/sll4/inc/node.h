#ifndef _NODE_H
#define _NODE_H

#include "support.h"

struct node {
	char		 contents;
	struct node *to;
};
typedef struct node Node;

Node *mknode(char  );	 // allocate new node containing value
Node *rmnode(Node *);	 // deallocate node
Node *cpnode(Node *);	 // duplicate node

#endif
