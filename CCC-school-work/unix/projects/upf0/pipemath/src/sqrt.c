//////////////////////////////////////////////////////////////////////
//
// sqrt.c     - program that accepts input from STDIN and displays 
//              the result of the operation to STDOUT. This is a 
//              unary operation.
//
//              this program performs a square root operation on
//              the STDIN input, and outputs the integer result to
//              STDOUT.
//
//              in the event of an error (improper/lack of input), an
//              error is displayed to STDERR and program exits with
//              a non-zero status.
//
// Compile:     run 'make' to automate the compile.
//
// Sample run (if installed into user's ~/bin directory):
//
//    $ nine | multby `eight` | plus `four` | plus `five` | sqrt
//    9
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    int   j, result;
    char  input[8];

    //////////////////////////////////////////////////////////////////
    //
    // Process the input expected on STDIN; if it is not a valid
    // integer value (whole number in base 10), then display an
    // error and exit
    //
    result          = fscanf(stdin, "%[0-9-]", input);
    if (result     != 0)
        j           = atoi(input);
    else
    {
        fprintf(stderr, "Error: must provide valid number as input!\n");
        exit(EXIT_FAILURE);
    }

    //////////////////////////////////////////////////////////////////
    //
    // Perform operation and display the result to STDOUT
    //
    result          = (int) sqrt ((double)j);
    fprintf(stdout, "%d\n", result);

    return(EXIT_SUCCESS);
}
