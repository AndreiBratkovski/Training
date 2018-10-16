#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	int index = 0;		// iteration variable

	//////////////////////////////////////////////////////////////////
	//
	// Display table header
	//
	fprintf(stdout, " binary |oct|dec|hex\n");
	fprintf(stdout, "--------+---+---+----\n");

	unsigned char start;
	int temp = 256; // max check is 255
	int end;
	int trigger = 0;
	//
	// Handle arguments, allow the start and finish to be set by the user
	//
	if (argc == 1)
	{
		start = 0;
		end = 15;
	}

	if (argc == 2)
	{
		start = atoi(argv[1]);
		end = 15;
	}

	else if (argc == 3)
	{
		start = atoi(argv[1]);
		end = atoi(argv[2]);
	}

	//
	// If not more than 3 arguments, there are too many arguments. Should only
	// take program, start, and finish points
	//
	else if (argc > 3)
	{
		fprintf(stderr, "Too many arguments BRO\n");
		exit(1);
	}

	//
	// Main programming logic, print out table in various string formats, then
	// increment starting value and repeat the process until end value
	//
	do
	{
	//
	// Bitwise binary logic, setting the size of the mask to 8 ie 128 as the
	// largest value check
	//
	while (temp > 0)
	{
		if((start & temp) == 0 )
		{	
			 printf("0");
		}
		else
		{
			printf("1");
		}
		temp = temp >> 1 ;
		
	}
		fprintf(stdout, "|");
		fprintf(stdout, "%03o|", start);
		fprintf(stdout, "%3u|", start);
		fprintf(stdout, "0x%02X\n", start);
		start++;
		temp = 256;
	}
	
	while (start <= end);

	return (0);
}
