#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// Color schemes defined, because we deserve nice things
//
#define ANSI_RESET 		"\x1b[0m"
#define ANSI_FG_GREEN 	"\x1b[32m"

///////////////////////////////////////////////////////////////////////////
//
// Function for printing lines side by side, saving a lot of extra leg work
//
// trigger:
// (0 == previous, 1 == current, 2 == next); trigger indicates which line needs byte coloring (current)
//
//
// I wrote this function so that I wouldn't have to retype my printing logic
// throughout the program.  Essentially, this function prints out both lines given
// side by side, adding coloring on the first byte of difference.
//
void printLines(char *line1, char *line2, int byteCount, int trigger,
		int byteCulprit)
{
	int increment = 0;

	//
	// Print header address, which is kept track of with byte Count
	//
	fprintf(stdout, "%07x: ", byteCount);

	// Print out file1 line
	//
	// If the byte is a byteCulprit discovered, then the byte is colored
	//
	// lines print side by side regularly, but if an EOF is in the array,
	// spaces are printed for formatting
	//
	for (increment = 0; increment < 16; increment++)
	{
		if (increment == byteCulprit && trigger == 1)
		{
			fprintf(stdout, ANSI_FG_GREEN);
		}

		if (increment % 2 == 0 && *(line1 + increment) != EOF)
		{
			fprintf(stdout, "%02hhx", *(line1 + increment));
		}

		else if (increment % 2 != 0 && *(line1 + increment) != EOF)
		{
			fprintf(stdout, "%02hhx ", *(line1 + increment));
		}
		else if (increment % 2 == 0)
		{
			fprintf(stdout, "  ");
		}
		else
		{
			fprintf(stdout, "   ");
		}

		fprintf(stdout, ANSI_RESET);
	}

	//
	// Line separator between line comparisons
	//
	fprintf(stdout, "| ");

	//
	// Print out file2 line
	//
	for (increment = 0; increment < 16; increment++)
	{
		if (increment == byteCulprit && trigger == 1)
		{
			fprintf(stdout, ANSI_FG_GREEN);
		}
		if (increment % 2 == 0 && *(line2 + increment) != EOF)
		{
			fprintf(stdout, "%02hhx", *(line2 + increment));
		}
		else if (increment % 2 != 0 && *(line2 + increment) != EOF)
		{
			fprintf(stdout, "%02hhx ", *(line2 + increment));
		}
		else if (increment % 2 == 0)
		{
			fprintf(stdout, "  ");
		}
		else
		{
			fprintf(stdout, "   ");
		}

		fprintf(stdout, ANSI_RESET);
	}

	//
	// Print new Line after side by side comparisons are printed
	//
	fprintf(stdout, "\n");
}

////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////  MAIN PROGRAM //////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char **argv)
{
	//
	// initialize two file streams
	//
	FILE *file1 = NULL;
	FILE *file2 = NULL;

	//
	// variable for tracking both bytes, and byteCount, counting byte position
	// in both files.  
	//
	int byteCount = 0;	// Counts number of bytes in the file, mainly used for addresses
	char byteCulprit = -1;	//-1 for UNDEFINED in this case

	int increment;

	char *prevLine1;
	char *currLine1;
	char *nextLine1;
	char *prevLine2;
	char *currLine2;
	char *nextLine2;

	int fileByte1;
	int fileByte2;

	//
	// malloc arrays for comparison, previous, current, and next line
	// using integer sized elements in order to check for EOF while printing, so
	// that spaces format properly
	//
	prevLine1 = malloc(sizeof(int) * 16);
	currLine1 = malloc(sizeof(int) * 16);
	nextLine1 = malloc(sizeof(int) * 16);
	prevLine2 = malloc(sizeof(int) * 16);
	currLine2 = malloc(sizeof(int) * 16);
	nextLine2 = malloc(sizeof(int) * 16);

	//
	// Handle arguments. Since comparing two files, arguments should Always be 3, 1 for program and 2 for files
	//
	if (argc <= 2)
	{
		fprintf(stderr, "ERROR: Not enough arguments! Should have 3\n");
		exit(1);
	}

	else if (argc > 3)
	{
		fprintf(stderr, "ERROR: Too many arguments! Should have 3\n");
		exit(2);
	}

	//
	// If enough arguments, open file pointers for reading
	// If files don't exist, print out error message
	//
	else
	{
		file1 = fopen(*(argv + 1), "r");
		if (file1 == NULL)
		{
			fprintf(stderr, "Could not open file '%s'\n",
				*(argv + 1));
			exit(3);
		}

		file2 = fopen(*(argv + 2), "r");
		if (file2 == NULL)
		{
			fprintf(stderr, "Could not open file '%s'\n",
				*(argv + 2));
			exit(4);
		}
	}
//////////////////////////////////////////////////////////////////////
//
// FIRST EDGE CASE
// Build first and second line of each file, then compare/print if there is a byte of difference
//
/////////////////////////////////////////////////////////////////////

	//
	// Build first line of each file
	//
	for (increment = 0; increment < 16; increment++)
	{
		fileByte1 = fgetc(file1);
		fileByte2 = fgetc(file2);

		*(currLine1 + increment) = fileByte1;
		*(currLine2 + increment) = fileByte2;;
		byteCount++;
	}
	//
	// Build second line of each file
	//
	for (increment = 0; increment < 16; increment++)
	{
		fileByte1 = fgetc(file1);
		fileByte2 = fgetc(file2);

		*(nextLine1 + increment) = fileByte1;
		*(nextLine2 + increment) = fileByte2;;
		byteCount++;
	}
//
// Compare first two lines of each file
//
	for (increment = 0; increment < 16; increment++)
	{
		if (*(currLine1 + increment) != *(currLine2 + increment))
		{
			byteCulprit = increment;
			printLines(currLine1, currLine2, 0, 1, byteCulprit);
			printLines(nextLine1, nextLine2, (byteCount - 16), 0,
				   byteCulprit);
			break;
		}
	}

////////////////////////////////////////////////////////////////////////
//
// reassign previous/current lines, build next lines, and compare current lines.  Here is where the bulk
// of the logic lies for the middle of the files. The lines are constantly traversed through
// and the current lines are compared.  The program stores previous,  current, and next lines
// so that they can be printed in the comparison.
//
///////////////////////////////////////////////////////////////////////

	while ((!feof(file1) || !feof(file2)) && byteCulprit == -1)
	{
//
// make previous == current contents AND current == next contents on each traversal (moving through the file)
//              
		for (increment = 0; increment < 16; increment++)
		{
			*(prevLine1 + increment) = *(currLine1 + increment);
			*(prevLine2 + increment) = *(currLine2 + increment);

			*(currLine1 + increment) = *(nextLine1 + increment);
			*(currLine2 + increment) = *(nextLine2 + increment);
		}

//
// Build Next Line in both files
//
		for (increment = 0; increment < 16; increment++)
		{
			fileByte1 = fgetc(file1);
			fileByte2 = fgetc(file2);

			*(nextLine1 + increment) = fileByte1;
			*(nextLine2 + increment) = fileByte2;

			byteCount++;
		}

//
// Check Current line( where we find culprit byte ). If culprit byte is found,
// print out the colored comparisons
//

		for (increment = 0; increment < 16; increment++)
		{

			if (*(currLine1 + increment) !=
			    *(currLine2 + increment))
			{
				byteCulprit = increment;
				printLines(prevLine1, prevLine2,
					   (byteCount - 48), 0, byteCulprit);
				printLines(currLine1, currLine2,
					   (byteCount - 32), 1, byteCulprit);
				printLines(nextLine1, nextLine2,
					   (byteCount - 16), 2, byteCulprit);

				break;
			}
		}

	}

////////////////////////////////////////////////////////////////////////
//
// TOP EDGE CASE
//
// After checking the bulk of the files, the program will check the edge cases (last 2 lines) and print
// out comparisons if byte differs
//
///////////////////////////////////////////////////////////////////////

	if (byteCulprit == -1)
	{
		for (increment = 0; increment < 16; increment++)
		{
			if (*(nextLine1 + increment) !=
			    *(nextLine2 + increment))
			{
				byteCulprit = increment;
				printLines(currLine1, currLine2,
					   (byteCount - 32), 0, byteCulprit);
				printLines(nextLine1, nextLine2,
					   (byteCount - 16), 1, byteCulprit);
				break;
			}
		}
		//
		// If lines aren't printed, then the files are the same, Let the user know
		//
		if (increment == 16)
		{
			fprintf(stdout, "Files are the same\n");
		}
	}

///////////////////////////////////////////////////////////////////     
//
// Close files and free arrays
//
///////////////////////////////////////////////////////////////////
	fclose(file1);
	fclose(file2);
	free(prevLine2);
	free(currLine2);
	free(nextLine2);
	free(prevLine1);
	free(currLine1);
	free(nextLine1);
	return (0);
}
