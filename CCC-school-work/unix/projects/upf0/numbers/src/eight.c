//////////////////////////////////////////////////////////////////////
//
// eight.c     - program that displays a value to STDOUT.
//
//              this program displays 8 to STDOUT.
//
// Compile:     run 'make' to automate the compile.
//
// Sample run (if installed into user's ~/bin directory):
//
//    $ eight
//    8
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
    fprintf(stdout, "%d\n", 8);

    return(EXIT_SUCCESS);
}
