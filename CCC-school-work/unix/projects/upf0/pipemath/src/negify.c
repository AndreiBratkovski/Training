//////////////////////////////////////////////////////////////////////
//
// negify.c   - program that accepts input from STDIN and displays 
//              the result of the operation to STDOUT. This is a 
//              unary operation.
//
//              this program performs an absolute negation on the
//              STDIN input, and outputs the integer result to
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
//    $ one | minus `three` | negify
//    -2
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
	if (j          >  0)
		result      = j * -1;
	else
		result      = j;

    fprintf(stdout, "%d\n", result);

    return(EXIT_SUCCESS);
}
