#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>

//
// Color scheme codes defined 
//
#define ANSI_RESET      "\x1b[0m"
#define ANSI_BOLD       "\x1b[1m"
#define ANSI_FG_BLACK   "\x1b[30m"
#define ANSI_FG_RED	    "\x1b[31m"
#define ANSI_FG_GREEN   "\x1b[32m"
#define ANSI_FG_YELLOW  "\x1b[33m"
#define ANSI_FG_BLUE    "\x1b[34m"
#define ANSI_FG_MAGENTA "\x1b[35m"
#define ANSI_FG_CYAN    "\x1b[36m"
#define ANSI_FG_WHITE   "\x1b[37m"
#define ANSI_BG_BLACK   "\x1b[40m"
#define ANSI_BG_RED     "\x1b[41m"
#define ANSI_BG_GREEN   "\x1b[42m"
#define ANSI_BG_YELLOW  "\x1b[43m"
#define ANSI_BG_BLUE    "\x1b[44m"
#define ANSI_BG_MAGENTA "\x1b[45m"
#define ANSI_BG_CYAN    "\x1b[46m"
#define ANSI_BG_WHITE   "\x1b[47m"

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////////////////////
	//
	// Declaration of variables:
	// input file, byteCounter, sizethrottle, file bytes, and byte array
	//
	// Other than the fileByte and byteArray, the rest are counters being initialized
	// one counter for array size (bytes per line), loop iteration (increment/lineCount) for printing
	// and a hex counter for the left indentation "0000010...etc" 
	//
	FILE *in = NULL;

	//
	// auto size throttle == 0, if any higher, program stops at that line.
	// if size throttle is specified in command line, it will be adjusted to that
	// value
	//
	int sizeThrottle = 0;
	int fileByte;
	int *byteArray;

	int remainder;

	int increment;
	int arrayCounter = 0;
	int hexCounter = 0;
	int lineCount = 0;

	//
	// Allocate the memory of the byte array to 16.  This will hold the current line's
	// byte contents so that they can be printed out as ASCII at the end of the line 
	//
	byteArray = malloc(sizeof(int) * 16);

	//
	// Check for enough arguments, too many arguments, or non-readable file
	// if any of these conditions are met, the program exits.  Else, the 
	// program opens the argument one file for reading and begins the hex dump
	// at the indicated size throttle line
	//
	if (argc == 1)
	{
		fprintf(stderr, "ERROR: not enough arguments\n");
		exit(1);
	}

	if (argc > 1)
	{
		in = fopen(argv[1], "r");
		if (in == NULL)
		{
			fprintf(stderr,
				"Error: could not open '%s' for reading.\n",
				argv[1]);
			exit(1);
		}
		if (argc == 3)
		{
			sizeThrottle = atoi(argv[2]);
		}
	}
	//////////////////////////////////////////////////////////////////////////
	//
	//      ANSI Sequence COLOR allocation
	//
	// If more than 2 arguments are supplied, allocate and build a color array, which will
	// be used to assign ANSI escape colors to locations specified in command line
	// arguments
	//
	//if (argc > 3)
	//{
	//      colorArray = malloc(sizeof(int) * (argc-2));
	//      for (increment = 2; increment < argc; increment++)
	//      {
	//              colorArray[increment-2] = (char*) malloc(strlen(argv[3]));
	//              colorArray[increment-2] = argv[increment+1];
	//              //*(colorArray + (increment - 2 )) = (char*) malloc(5);
	//              //**(colorArray + (increment - 2)) = *(argv + (increment+1));
	//      }
	//}
	if (sizeThrottle > 0)
	{
		lineCount = 1;
	}
	///////////////////////////////////////////////////////////////////////////
	//
	//              Terminal Size Check
	//
	// Check that terminal width/length
	// fits to specification. If not,
	// program prints out error message and exits
	//
	struct winsize terminal;

	ioctl(0, TIOCGWINSZ, &terminal);

	//fprintf(stdout, "lines: %d\n", terminal.ws_row);
	//fprintf(stdout, "columns: %d\n", terminal.ws_col);

	if (terminal.ws_col < 80)
	{
		fprintf(stderr,
			"Error: Terminal width is less than 80 columns!\n");
		exit(1);
	}
	if (terminal.ws_row < 20)
	{
		fprintf(stderr,
			"Error: Terminal height is less than 20 lines!\n");
		exit(1);
	}

	/////////////////////////////////////////////////////////////////////////////
	//
	// Hex Dump Tool (Binary Data Tool)
	//
	// Iterate over the entire file, saving and printing hex dump contents without any breaks
	// or seeking statements.  This is so that the program can run effortlessly from the beginning
	// to the end of the file, print out line by line
	//
	int argLength;
	int i;
	int argument;
	int trigger = 0;

	while (!feof(in) && lineCount <= sizeThrottle
	       && (fileByte = fgetc(in)) != EOF)
	{

		if (argc > 3)
		{
			for (i = 3; i < argc; i += 2)
			{
				if (hexCounter >= argument
				    && hexCounter <= argument + argLength - 1)
				{
					argument = strtol(argv[i], NULL, 16);
				}
				if (argument >= hexCounter
				    && (argument < hexCounter + 16)
				    )
				{
					fprintf(stdout, ANSI_BOLD);
					fprintf(stdout, "%07x: ", hexCounter);
					fprintf(stdout, ANSI_RESET);

					argLength =
					    strtol(argv[i + 1], NULL, 0);
					break;
				}
				//else
				//{
				//      fprintf(stdout, "%07x: ", hexCounter);
				//}
			}
		}

		if (hexCounter >= argument
		    && hexCounter <= argument + argLength - 1)
		{
			fprintf(stdout, "%07x: ", hexCounter);
		}

		arrayCounter = 0;
		//
		// Fetch and print binary values of input file data (middle field),
		// save those values into an array to print out in next loop
		// making sure that the EOF marker isn't saved or printed
		//

		fprintf(stdout, "%02hhx", fileByte);
		*(byteArray + arrayCounter) = fileByte;
		arrayCounter++;

		while (arrayCounter != 16 && !feof(in)
		       && (fileByte = fgetc(in)) != EOF)
		{
			if ((hexCounter + arrayCounter) >= argument
			    && (hexCounter + arrayCounter) <=
			    argument + (argLength - 1))
			{
				fprintf(stdout, ANSI_FG_GREEN);
			}

			// COLOR TIMEEEEE       
			if (arrayCounter % 2 == 0)
			{
				fprintf(stdout, "%02hhx", fileByte);
			}
			else
			{
				fprintf(stdout, "%02hhx ", fileByte);
			}

			if ((hexCounter + arrayCounter) >= argument
			    && (hexCounter + arrayCounter) <=
			    argument + (argLength - 1))
			{
				fprintf(stdout, ANSI_RESET);
			}

			*(byteArray + arrayCounter) = fileByte;
			arrayCounter++;

		}
		//
		// If program reaches the end of file, make up for all lost spaces(if any) so that 
		// the ASCII representation can be indented properly on the last line.
		//

		if (feof(in))
		{
			for (increment = 0;
			     increment <=
			     (40 - (arrayCounter * 2) - (arrayCounter / 2));
			     increment++)
			{
				fprintf(stdout, " ");
			}
		}
		else
		{
			fprintf(stdout, " ");
		}

		//
		// Print out all ASCII printable char representation (or "." if non printable")
		// to far right field. 
		//

		for (increment = 0; increment < arrayCounter; increment++)
		{
			if (*(byteArray + increment) < 0x20
			    || *(byteArray + increment) > 0x7E)
			{
				fprintf(stdout, ".");
			}
			else
			{
				fprintf(stdout, "%c", *(byteArray + increment));
			}
		}

		//
		// Start next line, increment Hex counter ( for upcoming left indentation line ) 
		// and lineCount (to see if we have reached size throttle)
		//
		fprintf(stdout, "\n");
		hexCounter += 16;

		if (sizeThrottle != 0)
		{
			lineCount++;
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	//
	// Close file pointer/ free memory
	//      
	free(byteArray);
	fclose(in);

	return (0);
}
