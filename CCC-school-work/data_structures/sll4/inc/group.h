#ifndef _GROUP_H
#define _GROUP_H

#include "list.h"                         // group relies on list

struct groupoflists {
    List *initial;                        // pointer to first list
    List *closing;                        // pointer to last list
};
typedef struct groupoflists Group;        // cuz we deserve nice things
typedef long   int          sli;          // short name for big thing

Group *mkgroup (void);                    // create/allocate new Group
Group *rmgroup (Group *);                 // clear/deallocate Group

Group *linsert (Group *, List *, List *); // add list before given list
Group *lappend (Group *, List *, List *); // add list after given list
Group *lobtain (Group *, List **);        // obtain list from group

sli    ldisplay(Group *, sli);            // display list group

sli    lgetpos (Group *, List *);         // retrieve position of list
List  *lsetpos (Group *, sli);            // seek to list in group

#endif
