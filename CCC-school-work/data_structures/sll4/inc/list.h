#ifndef _LIST_H
#define _LIST_H

#include "node.h"                       // list relies on node to work

//////////////////////////////////////////////////////////////////////
//
// list struct definition
//
struct list {
    Node              *engine;          // pointer to start of list
    Node              *caboose;         // pointer to end of list
    struct list       *next;            // pointer to the next list
    unsigned long int  qty;             // number of nodes in list
};
typedef struct list            List;    // cuz we deserve nice things
typedef unsigned long long int ulli;    // shorter name
typedef unsigned char          uc;      // shorter name

//////////////////////////////////////////////////////////////////////
//
// list utility functions
//
List *mklist(void  );                   // create/allocate new list 
List *cplist(List *);                   // duplicate list contents 
List *rmlist(List *);                   // deallocate empty list

//////////////////////////////////////////////////////////////////////
//
// list manipulation functions
//
List *insert(List *, Node *, Node *);   // add before given node
List *append(List *, Node *, Node *);   // add after given node
List *obtain(List *, Node **);          // disconnect node from list

//////////////////////////////////////////////////////////////////////
//
// list operation functions
//
uc    compare   (List *, List *, ulli *); // check lists for equality
Node *searchlist(List *, char);           // locate node with value
List *clearlist (List *);                 // empty an existing list
List *sortlist  (List *, int);            // sort list (to mode)
List *swapnode  (List *, Node *, Node *); // swap positions of nodes

//////////////////////////////////////////////////////////////////////
//
// list visualization functions
//
void  displayf(List *, int);            // display list forward
void  displayb(List *, int);            // display list backwards

//////////////////////////////////////////////////////////////////////
//
// list helper functions
//
int   getpos(List *, Node *);             // ID node's list position
Node *setpos(List *, int   );             // seek to node in list

//////////////////////////////////////////////////////////////////////
//
// return status codes
//
#define CMP_EQUALITY       0x00
#define CMP_L1_NULL        0x01
#define CMP_L1_EMPTY       0x02
#define CMP_L1_UNDEFINED   0x03
#define CMP_L1_GREATER     0x04
#define CMP_L1_LESS        0x08
#define CMP_L2_NULL        0x10
#define CMP_L2_EMPTY       0x20
#define CMP_L2_UNDEFINED   0x30
#define CMP_L2_GREATER     0x40
#define CMP_L2_LESS        0x80

#endif
