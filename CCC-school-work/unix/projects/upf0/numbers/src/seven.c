//////////////////////////////////////////////////////////////////////
//
// seven.c     - program that displays a value to STDOUT.
//
//              this program displays 7 to STDOUT.
//
// Compile:     run 'make' to automate the compile.
//
// Sample run (if installed into user's ~/bin directory):
//
//    $ seven
//    7
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    //////////////////////////////////////////////////////////////////
    //
    // Display the result to STDOUT
    //
    fprintf(stdout, "%d\n", 7);

    return(EXIT_SUCCESS);
}
