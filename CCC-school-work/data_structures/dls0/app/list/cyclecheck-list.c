#include <stdio.h>
#include <stdlib.h>
#include "list.h"

/*****************************************************************************
 ** dll2 extra credit program - the purpose of this program is to explore
 ** list cycle detection        the concepts and logic involved in linked
 ** -------------------------   list cycle detection.
 **
 ** 0. write function: write a function (cyclecheck()) that takes the list
 **                    as a parameter and returns a 0 if no cycle is found,
 **                    or a 1 if a cycle is found (-1 if NULL or EMPTY).
 **
 ** 1.      tag nodes: using double pointers as parameters, tag the node
 **                    that is the source of the cycle, and the node that
 **                    is the destination.
 **
 ** 2.   create lists: in main(), build various lists (some with cycles, and
 **                    some without) to test your cyclecheck() function.
 **              NOTE: You probably want to avoid displaying the list (at 
 **                    least unless you're sure there isn't a cycle in it)
 **
 ** 3.        comment! make sure you document your process, as well as the
 **                    tests you perform, so I can follow your logic and
 **                    make sure you're properly testing things.
 **
 ** 4.  all-in-1 case: be able to detect cycles where a node cycles back
 **                    on itself.
 **
 ** 5.  two node case: be able to detect cycles where a node cycles back
 **                    to its preceding node.
 **
 ** 6. many-node case: be able to detect cycles that span more than a
 **                    few nodes (likely harder to directly check)
 **
 ** 7.    directional: cycle checks should exist for the list in both
 **                    forward (to) and reverse (fro) directions
 **
 ** extra credit will be awarded based on your appropriate use of linked
 ** list function usage, correctness, and non-reinventing of wheels. It also
 ** wouldn't hurt to comment your code and ensure it is indented and readable.
 **/

int cyclecheck(List *, Node **, Node **);

int main()
{
    int i;
    List *ltmp1    = NULL;
    List *ltmp2    = NULL;
    List *ltmp3    = NULL;

    //////////////////////////////////////////////////////////////////
    //
    // list with cycle to the same node (in to direction)
    //
    mknode(&ltmp1);
    for (i = 0; i < 17; i+=2)
    {
        ntmp       = NULL;
        mknode(&ntmp, i);
        append(&ltmp1, ltmp1 -> caboose, ntmp);
    }
    ntmp           = ltmp1 -> engine -> to -> to -> to -> to;
    ntmp -> to  = ntmp;

    //////////////////////////////////////////////////////////////////
    //
    // list with cycle to the previous node (in to direction)
    //
    mknode(&ltmp2);
    for (i = 0; i < 17; i+=2)
    {
        ntmp       = NULL;
        mknode(&ntmp, i);
        append(&ltmp2, ltmp2 -> caboose, ntmp);
    }
    ntmp           = ltmp2   -> engine -> to -> to;
    ntmp -> to  = ntmp    -> fro;

    //////////////////////////////////////////////////////////////////
    //
    // list with 2-back cycle (in to direction)
    //
    mknode(&ltmp3);
    for (i = 0; i < 17; i+=2)
    {
        ntmp       = NULL;
        mknode(&ntmp, i);
        append(&ltmp3, ltmp3 -> caboose, ntmp);
    }
    ntmp           = ltmp2   -> engine -> to -> to -> to;
    ntmp -> to  = ntmp    -> fro    -> fro;

    // Try displaying these lists-- they should display fine in reverse,
    // but will "infinitely loop" when displayed in the forward direction

    // your implementation here
    return(0);
}

int cyclecheck(List *myList, Node **source, Node **dest)
{
    // your implementation here
    return(-1);
}
