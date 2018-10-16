//////////////////////////////////////////////////////////////////////
//
// multby.c   - program that accepts input from both STDIN and the 
//              first command-line argument, and displays the result
//              of the operation to STDOUT.
//
//              this program performs a multiplication operation on
//              the two inputs, displaying the result of STDIN * ARG1
//              to STDOUT.
//
//              and note: any of the inputs or result can be negative
//
//              in the event of an error (improper/lack of input), an
//              error is displayed to STDERR and program exits with
//              a non-zero status.
//
// Compile:     run 'make' to automate the compile.
//
// Sample run (if installed into user's ~/bin directory):
//
//    $ six | multby `seven`
//    42
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int   i, j, result;
    char  input[8];
    char *str       = NULL;
    char *endptr    = NULL;

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
    // Process the input expected from the command-line (ARG1). If it
    // is not a valid integer value (whole number in base 10), then
    // display an error and exit
    //
    if (argc       != 1)
    {
        str         = *(argv+1);
        i           = strtol(str, &endptr, 10);
        if (endptr == str)
        {
            fprintf(stderr, "Error: must provide valid number as argument!\n");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "Error: must provide argument!\n");
        exit(EXIT_FAILURE);
    }

    //////////////////////////////////////////////////////////////////
    //
    // Perform operation and display the result to STDOUT
    //
    result          = j * i;
    fprintf(stdout, "%d\n", result);

    return(EXIT_SUCCESS);
}
