#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/////////////////////////////////////////
//
// Andrei Bratkovski - nbm0 - base conversion 10/30/2017
// any base to any base
//
/////////////////////////////////////////

int main(int argc, char **argv)
{
	//
	// Check that there are 4 arguments given.  If there aren't return an error
	// statement
	//
	if (argc != 4)
	{
		fprintf(stderr, "ERROR: Needs to be 4 arguments\n");
		exit(1);
	}

	//
	// initialize input Base, output Base, and input number from command line
	// arguments
	//
	int inBase = atoi(argv[1]);
	int outBase = atoi(argv[3]);

	//char inputNum[20];
	//strcpy(inputNum, argv[2]);
	char *inputNum;

	inputNum = argv[2];

	// find length of inputNum
	int length;

	while (*(inputNum + length) != '\0')
		length++;

	//
	// Check that input base is between 2 and 36, if not, print error message
	//
	if (inBase < 2 || inBase > 36)
	{
		fprintf(stderr,
			"ERROR: input Base can only be between 2 and 36\n");
		exit(2);
	}
	//
	// Check that output base is between 2 and 36, if not, print error message
	//
	if (outBase < 2 || outBase > 36)
	{
		fprintf(stderr,
			"ERROR: output base can only be between 2 and 36\n");
		exit(2);
	}

	////////////////////////////////////////
	//
	//      Base conversion algorithm
	//
	////////////////////////////////////////

	//
	// Initialize counter variable, remainder variable, and currentDigit
	// variable, numberTotal variable, increment variable,  and basePosition variable
	//
	unsigned long long int increment;
	unsigned long long int counter = 0;
	unsigned long long int numberTotal = 0;
	unsigned long long int basePosition = 1;
	unsigned long long int remainder, currentDigit;

	//
	// Total up the numberTotal based upon the given input base
	//
	for (increment = length - 1; increment >= 0; increment--)
	{
		//
		// convert the number's char representation to it's decimal representation
		//
		if (inputNum[increment] >= 'A' && inputNum[increment] <= 'Z')
			currentDigit = inputNum[increment] - '0' - 7;
		else
			currentDigit = inputNum[increment] - '0';

		//
		// Add to number total the decimal representation of inputNum increment times
		// our current base position
		//
		numberTotal = currentDigit * basePosition + numberTotal;

		//
		// Increase base position by multiplying it by itself.  if it is base 2,
		// keep multiplying by two, if base 8, 8. Etc.
		//
		basePosition = basePosition * inBase;
		if ( increment == 0 )
			break;
	}

	//
	// Iterate FORWARD over input Number "string" and replace the digits with the new outBase
	// equivalents, thus leaving us with the converted number based on the bases given
	// Loop subtracts from the number total each time a chunk of it is converted and
	// changed in the input number string.
	//
	while (numberTotal != 0)
	{
		//
		// Divide total number by base we are converting to, as we are iterating
		// backwards now over the number base positions
		//
		remainder = numberTotal % outBase;
		currentDigit = '0' + remainder;

		if (currentDigit > '9')
			currentDigit += 7;

		//
		// Substitute base position in input number by char representation of
		// the current digit after forming it from adding the remainder to position '0'
		// on the ASCII table
		//
		inputNum[counter] = currentDigit;
		counter++;

		//
		// Number total keeps cutting by out base number because each position is base
		// divided by base number
		//
		numberTotal = numberTotal / outBase;
	}

	//
	// Loop for printing out the results based upon the number of iterations over
	// the input Number conversion iterations ( counter).  These iterations will print out the full
	// converted number
	//      
	for (increment = counter - 1; increment >= 0; increment--)
	{
		if ( increment == 0 )
		{
			fprintf(stdout, "%c", inputNum[increment]);
			break;
		}
		fprintf(stdout, "%c", inputNum[increment]);
	}
	//
	// Print out newline for pretty output :)
	//
	fprintf(stdout, "\n");
	return (0);
}
