///////////////////////////////////////////////////
//
// Bdt0- Colorized Binary Data Tool - Andrei Bratkovski
// 9/29/2017
//
//
///////////////////////////////////////////////////

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
#define ANSI_FG_RED     "\x1b[31m"
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

///////////////////////////////////////////////////////
// Declare variables:
// Size throttle is defaulted at 0, fileByte represents
// the exact byte being accessed from the file, byteCount
// is a counter that keeps track of the number of bytes being
// pulled into the program.  Byte Array stores the bytes so that
// they can be printed as ASCII on the leftmost  section 
// Line count keeps track of the lines being counted and
// arrayCounter/increment are used to traverse arrays in loops
// they are mainly used in printing and comparing arguments

	FILE *in = NULL;

	int sizeThrottle = 0x00;	// default size throttle
	int fileByte;		// bytes of file
	int byteCount = 0x00;	// counting ALL bytes
	char *byteArray;

	char arrayCounter;
	int lineCount = 0x00;
	char increment;

	byteArray = malloc(sizeof(char) * 0x10);

////////////////////////////////////////////////////////////
// Check arguments:
// 
// Check the the amount of arguments, program opens a file,
// and sets the size throttle if listed in command line, 
// If there are no files or not enough arguments, program
// prints error message

	if (argc == 0x01)
	{
		fprintf(stderr, "ERROR: not enough arguments\n");
		exit(0x01);
	}

	if (argc > 0x01)
	{
		in = fopen(*(argv + 0x01), "r");
		if (in == NULL)
		{
			fprintf(stderr,
				"ERROR: could not open '%s' for reading.\n",
				*(argv + 0x01));
			exit(0x02);
		}

		//
		// If size throttle given, assign sizeThrottle/line Count
		//

		if (argc > 0x02)
		{
			sizeThrottle = atoi(*(argv + 0x02));
			if (sizeThrottle > 0x00)
			{
				lineCount = 0x01;
			}
		}
	}

///////////////////////////////////////////////////////
// TERMINAL CHECKS
//
// This part of the program checks if the terminal size is within
// the range of the specifications.  If it is not within range, program
// prints an error and exits

	struct winsize terminal;

	ioctl(0x00, TIOCGWINSZ, &terminal);

	if (terminal.ws_col < 0x50)
	{
		fprintf(stderr,
			"Error: Terminal width is less than 80 columns!\n");
		exit(0x03);
	}
	if (terminal.ws_row < 0x14)
	{
		fprintf(stderr,
			"Error: Terminal height is less than 20 lines!\n");
		exit(0x04);
	}

//////////////////////////////////////////////////////////////////////
//
// HEX DUMP TOOL WITH COLORS ( same as UNIX XXD command but COLORIZED )
//
// Initialize argument and previous argument variables.  These represent the
// current and previous hex argument (ie 0x0b) in integer form. The program keeps track of
// the previous argument because it is used to check for collisions (when the program needs to
// make a header bold because the ANSI COLOR spills over to the next line)

	int argument;
	int prevArgument;

// This segment checks if we have more than three arguments.
// if we do, then it knows it is provided a hex argument which
// needs to be bolded.  If the argument is within range of the first line,
// it must be bolded.

	if (argc > 0x03)
	{
		for (increment = 0x03; increment < argc; increment += 0x02)
		{
			argument = strtol(*(argv + increment), NULL, 0x00);
			if ((argument - byteCount) >= 0x00
			    && (argument - byteCount) <= 0x10)
			{
				fprintf(stdout, ANSI_BOLD);
				prevArgument = argument;
			}
		}
	}

// UNROLLED loop.. print first LEFT section 000000
// Loop is unrolled for the purposes of making sure that
// size throttle works.  Therefore the first header is printed
// outside of the rest of program logic. (Can be bolded or not
// depending on the previous section.

	if (lineCount <= sizeThrottle)
	{
		fprintf(stdout, "%07x: ", byteCount);
	}
	// Resets are placed periodically throughout the code after
	// each escape sequence so that colors do not spill over to the
	// next byte unless directly specified in command line argument range

	if (argc > 0x03)
		fprintf(stdout, ANSI_RESET);

////********** BULK OF PROGRAMMING LOGIC IN FOLLOWING WHILE LOOP ***********///////
//
// While loop which covers the bulk of the program (minus the first line, which is
// taken care of in above logic. This loop stores the fileByte values while printing them,
// along with the header, and finally prints out the third section.  This reiterates for each
// line being printed until EOF OR size throttle is reached

	while (!feof(in) && lineCount <= sizeThrottle
	       && (fileByte = fgetc(in)) != EOF)
	{
		// HEADER BOLD CHECK (arguments greater than three and within range)

		if (argc > 0x03)
		{
			for (increment = 0x03; increment < argc;
			     increment += 0x02)
			{
				argument =
				    strtol(*(argv + increment), NULL, 0x00);
				if ((argument - byteCount) >= 0x00
				    && (argument - byteCount) <= 0x10)
				{
					fprintf(stdout, ANSI_BOLD);
					prevArgument = argument;
				}

				//
				// If previous argument is assigned because
				// of a color spill over (collision)  and byte Count
				// spills over to next line, program bolds that line
				//

				else if ((argument +
					  atoi(*(argv + (increment + 0x01))) >
					  byteCount
					  && argument == prevArgument))
				{
					fprintf(stdout, ANSI_BOLD);
				}
			}
		}

		// Following logic prints out the header, whether or not
		// it is bolded.  This logic runs for all headers except the 
		// first one, which is taken care of before the loop.

		if (!feof(in) && byteCount != 0x00)
		{

			if (sizeThrottle == 0x00)
				fprintf(stdout, "%07x: ", byteCount);
			else if (lineCount <= sizeThrottle)
				fprintf(stdout, "%07x: ", byteCount);
		}

		//
		// if bolding occured, reset ANSI colors to prevent extra coloring
		//

		if (argc > 0x03)
		{
			fprintf(stdout, ANSI_RESET);
		}

		byteCount++;

		// Print out Middle Section AND build up array for printing out the RIGHT section
		// UNROLLED loop again. The first byte of each 16 byte sequence is taken care of before
		// the loop.  This is all done to make sure the size throttle works incase we print out a full
		// line of bytes right before the EOF (audio.mp3 example)

		//
		// BYTE COLORING CHECK
		//

		arrayCounter = 0x00;
		if (argc > 0x03)
		{
			for (increment = 0x03; increment < argc;
			     increment += 0x02)
			{
				argument =
				    strtol(*(argv + increment), NULL, 0x00);
				if (byteCount >= (argument + 0x01)
				    && byteCount <=
				    (argument +
				     atoi(*(argv + (increment + 0x01)))))
				{
					fprintf(stdout, ANSI_FG_GREEN);
				}
			}
		}

		//
		// First byte in sequence printed/recorded
		//
		fprintf(stdout, "%02hhx", fileByte);
		if (argc > 0x03)
		{
			fprintf(stdout, ANSI_RESET);
		}
		*(byteArray + arrayCounter) = fileByte;
		arrayCounter++;

		//
		// Rest of the bytes in MIDDLE section printed/recorded in byteArray
		// to be printed as ASCII in RIGHT section
		//

		while (!feof(in) && arrayCounter != 0x10
		       && (fileByte = fgetc(in)) != EOF)
		{
			byteCount++;

			//
			// BYTE COLORING CHECK
			//

			if (argc > 0x03)
			{
				for (increment = 0x03; increment < argc;
				     increment += 0x02)
				{
					argument =
					    strtol(*(argv + increment), NULL,
						   0x00);
					if (byteCount >= (argument + 0x01)
					    && byteCount <=
					    (argument +
					     atoi(*
						  (argv + (increment + 0x01)))))
					{
						fprintf(stdout, ANSI_FG_GREEN);
					}
				}
			}

			//
			// Byte being printed (MIDDLE section)
			//

			if (arrayCounter % 0x02 == 0x00)
			{
				fprintf(stdout, "%02hhx", fileByte);
			}
			else
			{
				fprintf(stdout, "%02hhx ", fileByte);	// byte with space after
			}

			//
			// Byte for current line being stored in array to be printed in
			// third section
			//

			*(byteArray + arrayCounter) = fileByte;
			arrayCounter++;
			if (argc > 0x03)
			{
				fprintf(stdout, ANSI_RESET);
			}
		}

		///////////////////////////////////////////////////////////////////
		// MAKING UP FOR LOST SPACES (if any)
		// If program reaches end, make up for lost spaces here(if ANY)
		// ONLY occurs at EOF since all other lines will be filled

		if (feof(in))
		{
			for (increment = 0x00;
			     increment <=
			     (0x28 - (arrayCounter * 0x02) -
			      (arrayCounter / 0x02)); increment++)
			{
				fprintf(stdout, " ");
			}
		}

		//////////////////////////////////////////////////////////
		// IN ALL CASES BUT EOF PRINT ONE SPACE before RIGHT section
		//
		// if Not at EOF, print ONE space for RIGHT section buffer space

		else
		{
			fprintf(stdout, " ");
		}

		//////////////////////////////////////////////////////////////
		// 
		// Print out RIGHT section ASCII

		for (increment = 0x00; increment < arrayCounter; increment++)
		{
			// NON printable ASCII as "."
			if (*(byteArray + increment) < 0x20
			    || *(byteArray + increment) > 0x7E)
				fprintf(stdout, ".");

			// printable ASCII
			else
				fprintf(stdout, "%c", *(byteArray + increment));
		}

		// Start NEXT line, print LEFT section header

		fprintf(stdout, "\n");

		// sizeThrottle check / line count increment
		// if sizeThrottle is greater than zero and matches the
		// line count, program stops printing

		if (sizeThrottle != 0x00)
			lineCount++;
	}
	//
	// Free array after program runs, and close file being read
	//
	free(byteArray);
	fclose(in);

	return (0x00);
}
