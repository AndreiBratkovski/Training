//////////////////////////////////////////////////////////////////////
//
// four.c     - program that displays a value to STDOUT.
//
//              this program displays 4 to STDOUT.
//
// Compile:     run 'make' to automate the compile.
//
// Sample run (if installed into user's ~/bin directory):
//
//    $ four
//    4
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
    fprintf(stdout, "%d\n", 4);

    return(EXIT_SUCCESS);
}
