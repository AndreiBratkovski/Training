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
#define ANSI_FG_RED         "\x1b[31m"
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

// Declare variables

FILE *in = NULL;

int sizeThrottle = 0;	// default size throttle
int fileByte; 			// bytes of file
int byteCount = 0; 			// counting ALL bytes
int *byteArray;

int arrayCounter;
int lineCount = 0;
int increment;

byteArray = malloc(sizeof(int) * 16);

// Check arguments

if ( argc == 1)
{
	fprintf(stderr, "ERROR: not enough arguments\n");
	exit(1);
}

if ( argc > 1)
{
	in = fopen(argv[1], "r");
	if (in == NULL)
	{
		fprintf(stderr, "ERROR: could not open '%s' for reading.\n", argv[1]);
		exit(2);
	}
	//
	// If size throttle given, assign sizeThrottle/line Count
	//
	if ( argc > 2)
	{
		sizeThrottle = atoi(argv[2]);
		if (sizeThrottle > 0)
		{
			lineCount = 1;
		}
	}
}

// TERMINAL CHECKS

struct winsize terminal;

ioctl(0, TIOCGWINSZ, &terminal);

if ( terminal.ws_col < 80 )
{
	fprintf(stderr, "Error: Terminal width is less than 80 columns!\n");
	exit(3);
}
if ( terminal.ws_row < 20 )
{
	fprintf(stderr, "Error: Terminal height is less than 20 lines!\n");
	exit(4);
}

//////////////////////////////////////////////////////////////////////
//
// HEX DUMP TOOL WITH COLORS ( XXD COLORIZED )
//

// UNROLLED loop.. print first LEFT section 000000
if ( lineCount <= sizeThrottle)
{
fprintf( stdout, "%07x: ", byteCount);
}

while (!feof(in) && lineCount <= sizeThrottle && (fileByte = fgetc(in)) != EOF)
{
	// fgetc was called, so add to byteCounter
	if (!feof(in) && byteCount != 0)
	{
		if (sizeThrottle == 0)
			fprintf(stdout, "%07x: ", byteCount);

		else if ( lineCount <= sizeThrottle)
			fprintf(stdout, "%07x: ", byteCount);
	}

	byteCount++;

	// Print out Middle Section AND build up array for printing out the RIGHT section
	// UNROLLED loop again

	arrayCounter = 0;
	// first byte in sequence printed/recorded
	fprintf(stdout, "%02hhx", fileByte);
	*(byteArray + arrayCounter) = fileByte;
	arrayCounter++;

	while ( !feof(in) && arrayCounter != 16 && ( fileByte = fgetc(in) ) != EOF)
	{
		byteCount++; // fgetc called at beginning of loop

		if (arrayCounter % 2 == 0)
		{
			fprintf(stdout, "%02hhx", fileByte);
		}
		else
		{
			fprintf(stdout, "%02hhx ", fileByte); // byte with space after
		}

		*(byteArray + arrayCounter) = fileByte;
		arrayCounter++;
	}

	//
	// If program reaches end, make up for lost spaces here(if ANY)
	//
	if (feof(in))
	{
		for ( increment = 0; increment <= (40 - (arrayCounter * 2) - (arrayCounter / 2) ); increment++)
		{
			fprintf(stdout, " ");
		}
	}
	//
	// if Not at EOF, print space for RIGHT section buffer
	// 
	else
	{
		fprintf(stdout, " ");
	}
	
	//
	// Print out RIGHT section ASCII
	//
	for ( increment = 0; increment < arrayCounter; increment++)
	{
		// NON printable ASCII as "."
		if (*(byteArray + increment) < 0x20 || *(byteArray + increment) > 0x7E) 
			fprintf(stdout, ".");
		
		// printable ASCII
		else
			fprintf(stdout, "%c", *(byteArray + increment));
	}

	// Start NEXT line, print LEFT section header
	fprintf(stdout, "\n");
		// sizeThrottle check/ line count increment
	if (sizeThrottle != 0)
		lineCount++;
}
}
