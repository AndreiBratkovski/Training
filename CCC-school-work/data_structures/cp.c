#include "node.h"

//////////////////////////////////////////////////////////////////////
//
//    cpnode() - a node library function to duplicate a node and its 
//               contents -- it must call other functions as needed,
//               and take care to ensure all aspects of the source
//               node have been successfully replicated in the
//               copied/destination node.
//
//               be sure to utilize existing node library functions
//               to facilitate your implementation. Do NOT reinvent
//               the wheel.
//
// status codes:
//               DLN_SUCCESS:       no problems encountered
//               DLN_MALLOC_FAIL:   error on creation
//               DLN_ALREADY_ALLOC: destination node already exists
//               DLN_NULL:          node in NULL state
//               DLN_ERROR:         some error occurred
//               DLN_INVALID:       invalid use (NULL/UNDEFINED)
//
//   suggestion: don't use malloc() directly; use a function you have
//               written in dln0 that calls malloc() and takes care
//               of other details pertaining to a Node.
//
//         NOTE: you are to have only ONE return statement for this
//               entire function. Change the existing one as needed.
//
//               the contents of the "to" and "fro" pointers,
//               if non-NULL in the source node, should also be
//               copied. Do not just set them to NULL.
//
//               payload's duplication is to focus on the pointer,
//               NOT to whatever it may point at.
//
code_t cpnode(Node *oldNode, Node **copiedNode)
{
    // to be implemented (please remove this comment upon completion)
    return(DLN_DEFAULT_FAIL);

    //////////////////////////////////////////////////////////////////
    //
    // Declare variable(s) - our status code to return; note how it
    // is strategically set to ERROR, so if we don't get to mknode(),
    // it'll just fall through in an error state, where we merely 
    // add additional attributes to it.
    //
    code_t  status                          = DLN_ERROR;

    //////////////////////////////////////////////////////////////////
    //
    // Verify that copiedNode is NOT NULL nor UNDEFINED to continue
    //
    if ((copiedNode                        != NULL)       &&
        (copiedNode                        != UNDEFINED)  &&
        ((*copiedNode)                     != UNDEFINED))
    {
        //////////////////////////////////////////////////////////////
        //
        // Verify that (*copiedNode) is NULL to continue
        //
        if ((*copiedNode)                  == NULL)
        {
            //////////////////////////////////////////////////////////
            //
            // If oldNode exists (ie is not NULL nor UNDEFINED)
            // proceed onwards
            //
            if ((oldNode                   != NULL)       &&
                (oldNode                   != UNDEFINED))
            {
                //////////////////////////////////////////////////////
                //
                // Allocate new node (copiedNode), using mknode()- it
                // is important to utilize pre-existing functions, 
                // and not sloppily or unnecessarily reinvent the
                // wheel.
                //
                // Since we do not know which element of the union is
                // in use, we will simply pass a zero here.
                //
                status                      = mknode(copiedNode, 0);

                //////////////////////////////////////////////////////
                //
                // If mknode() was successful, proceed with the copy
                //
                if ((*copiedNode)          != NULL)
                {
                    //////////////////////////////////////////////////
                    //
                    // Copy DATA element, for it, like OTHER, is the
                    // largest variable in the union (not doing so
                    // will result in corruption, and fail at least
                    // one of the unit's tests)
                    //
                    // Copying the largest element will preserve
                    // whatever information is stored, whether it
                    // is a char or a pointer (Node * or void *)
                    //
                    (*copiedNode) -> DATA   = oldNode -> DATA;

                    //////////////////////////////////////////////////
                    //
                    // As per project specifications, point coiped 
                    // node "to" and "fro" pointers to whatever
                    // the original node "to" and "fro" pointers
                    // were pointing at (don't forget to compensate
                    // for this in other functions if it is NOT the
                    // desired behavior in that setting).
                    //
                    (*copiedNode) -> fro    = oldNode -> fro;
                    (*copiedNode) -> to     = oldNode -> to;
                }

                //////////////////////////////////////////////////////
                //
                // Else we had an allocation problem with mknode(),
                // set status code(s) as appropriate (ie malloc()
                // failed, which is an error, resulting in the node
                // being NULL).
                //
                else
                {
                    status                  = DLN_ERROR | DLN_MALLOC_FAIL;
                    status                  = status    | DLN_NULL;
                }
            }

            //////////////////////////////////////////////////////////
            //
            // If it turns out oldNode is NULL, set status code(s)
            //
            else if (oldNode               == NULL)
                status                      = DLN_ERROR | DLN_NULL;
        }

        //////////////////////////////////////////////////////////////
        //
        // copiedNode isn't NULL, so it is already allocated
        //
        else
            status                          = status    | DLN_ALREADY_ALLOC;
    }

    //////////////////////////////////////////////////////////////////
    //
    // The ultimate error: copiedNode doesn't exist
    //
    else
        status                              = status    | DLN_INVALID;

    return(status);
}
