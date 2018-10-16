#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Variable declarations
	//
    FILE *in                           = NULL;
    FILE *out                          = NULL;
    char *filename                     = NULL;
    char *basename                     = NULL;

	//////////////////////////////////////////////////////////////////
	//
	// Command-line argument checking; if no argument, error out
	//
    if (argc                          == 1)
	{
		fprintf(stderr, "Error\n");
	}

	//////////////////////////////////////////////////////////////////
	//
	// otherwise, argument is file name to encode
	//
    else
    {
        in                             = fopen(basename, "r");
        if (in                        == NULL)
        {
            fprintf(stderr, "Error opening '%s' for reading.\n", basename);
            exit (1);
        }
    }

	//////////////////////////////////////////////////////////////////
	//
	// Your dcfX RLE v1 encoding implementation here
	//

	//////////////////////////////////////////////////////////////////
	//
	// close open file pointers
	//
    fclose(in);
    fclose(out);

    return(0);
}
