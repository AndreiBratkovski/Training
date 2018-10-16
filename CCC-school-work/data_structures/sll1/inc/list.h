#ifndef _LIST_H
#define _LIST_H

#include "node.h"                       // list relies on node to work

//////////////////////////////////////////////////////////////////////
//
// list struct definition
//
struct list {
    Node *engine;                       // pointer to start of list
    Node *caboose;                      // pointer to end of list
};
typedef struct list            List;    // 'cuz we deserve nice things
typedef unsigned long long int ulli;    // short name for biggest type
typedef unsigned char          uc;      // short name for tiniest type

//////////////////////////////////////////////////////////////////////
//
// list utility functions
//
List *mklist(void  );                   // create/allocate new list
List *cplist(List *);                   // duplicate list contents
uc    compare(List *, List *, ulli *);  // check lists for equality
Node *searchlist(List *, char);         // locate node with value

//////////////////////////////////////////////////////////////////////
//
// list manipulation functions
//
List *insert(List *, Node *, Node *);   // add node before given node
List *append(List *, Node *, Node *);   // add node after given node

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
int   getpos(List *, Node *);           // ID list position from node
Node *setpos(List *, int   );           // seek to node in list

//////////////////////////////////////////////////////////////////////
//
// return status codes (for compare)
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

endif
