//////////////////////////////////////////////////////
//
// Andrei Bratkovski - 0x0 - Visualizing Long Division
//
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int *convertQuotientToArray(unsigned int, int *);

int main()
{
	//
	// Generate a random number between 3-5 digits for divisor
	// and 7-9 digits for dividend
	//
	srand(time(NULL));
	unsigned long long int divisorMin = 100;
	unsigned long long int divisorMax = 99999;

	unsigned long long int dividendMin = 1000000;
	unsigned long long int dividendMax = 999999999;

	//
	// Assign random number for divisor/dividend for rest of
	// program
	//
	unsigned long long int divisor =
	    divisorMin + rand() % (divisorMax + 1 - divisorMin);

	unsigned long long int dividend =
	    dividendMin + rand() % (dividendMax + 1 - dividendMin);
	//
	// Display current simple state of division
	// solve the quotient and print
	//
	unsigned long long int quotient = dividend / divisor;

	fprintf(stdout, "%16lld\n", quotient);

	//
	// Print beautiful divisor lines
	//
	fprintf(stdout, "%7s", "+");
	fprintf(stdout, "---------\n");
	fprintf(stdout, "%6lld|", divisor);
	fprintf(stdout, "%9lld\n", dividend);

	//
	// Assign random digits to subtrahend/answer
	//
	unsigned long long int subtrahend;
	unsigned long long int answer;
	int *quotientArray;
	int quotLength;

	//
	// Before beginning subtrahend subractive programing logic,
	// allocate an array of integers for the quotient
	//
	quotientArray = convertQuotientToArray(quotient, &quotLength);

	//
	// Test that the quotient is printing out correctly
	//
	int increment = 0;

	//
	// Subtrahend printing logic, main bulk of program.  The loop will
	// continue until each subtraction is done and recorded
	//      

	//
	// Declare dividendDigits array and digit integer for 
	// storing the "bring down digits"
	//
	int dividendDigits[10];
	int digit;

	//
	// Find length of first subtrahend and first subrahend value
	//
	subtrahend = quotientArray[increment] * divisor;
	int subLength = floor(log10(abs(subtrahend))) + 1;

	//
	// Strip "bring down" digits and put into array for later appending to
	// the subtrahend
	//
	increment = 0;
	// calculate dividend "left over digits" length
	int dividendLength = (int)floor(log10(abs(dividend))) + 1;
	int dividendRemLength = dividendLength - subLength;
	int origDividendLength = dividendLength;

	//
	// Store remaining dividend digits into array, making sure to check
	// that dividend does not end up being less than the subtrahend
	//      
	while (dividendLength > subLength && (dividend / 10 > subtrahend))
	{
		digit = dividend % 10;
		dividend = dividend / 10;
		dividendDigits[increment] = digit;	// add digit to array
		increment++;
		dividendLength--;
	}
	//
	// Shift the length of the remaining dividend over by one incase
	// the dividend subtracted is of larger length. ( that way we don't
	// subtract by a number larger than itself
	//
	if (dividendLength > subLength)
		dividendRemLength--;

	int subFormat = 7 + (9 - origDividendLength);

	//
	// Unrolled loop, finds the first answer, subtracting 
	// the dividend from first subtrahend
	//
	increment = 0;
	answer = dividend - subtrahend;
	while (increment < quotLength)
	{
		//
		// Find stripped dividend- subtrahend, then append
		// the dividend missing digit ( the "bring down")
		// program won't bring down on the last iteration because
		// there is nothing left to bring down. The final answer should
		// be the remainder
		//
		if (increment != quotLength - 1)
			answer =
			    (answer * 10) + dividendDigits[dividendRemLength -
							   1];
		dividendRemLength--;
		//
		// Print out the subtrahend, answer and subtraction line, then increment
		// the format specifier over one
		//
		if (increment == 0)
			fprintf(stdout, "%*s%-5lld\n", subFormat, "-",
				subtrahend);
		else
			fprintf(stdout, "%*s%5lld\n", subFormat, "-",
				subtrahend);

		//
		// Print correct number of '=' based on subtrahend
		//
		if (subtrahend >= 100000)
			fprintf(stdout, "%*s\n", (subFormat + 6), "======");
		else if (subtrahend >= 10000)
			fprintf(stdout, "%*s\n", (subFormat + 5), "=====");
		else
			fprintf(stdout, "%*s\n", (subFormat + 5), "====");

		//
		// Print the adjusted answer
		//
		if (answer >= 100000)
			fprintf(stdout, "%*lld\n", (subFormat + 7), answer);
		else
			fprintf(stdout, "%*lld\n", (subFormat + 6), answer);
		subFormat++;

		//
		// Increment over the quotient and calculate the new subtrahend/answer
		//
		increment++;
		subtrahend = quotientArray[increment] * divisor;
		answer = answer - subtrahend;
	}
	return 0;
}

//
// Function to convert our quotient into a quotient length array. This
// is used so that we can iterate over each member of the quotient and
// perform multiplicative calculations on each member separately
//
int *convertQuotientToArray(unsigned int quot, int *quotLength)
{
	//
	// Digit pos is the position of each digit represented in our
	// array
	//
	int digitPos = 0;
	int number = quot;

	//
	// Divide our number by 10 each time to determine the max index
	// our array will ned
	//
	while (number != 0)
	{
		number /= 10;
		digitPos++;
	}

	//
	// We statically allocate an array with a buffer of 20 because
	// returning a dynamically allocated array is a bit tricker than we
	// want
	//
	static int numberArray[20];

	*quotLength = digitPos;
	digitPos--;
	number = quot;

	//
	// Allocate each digit to the corresponding digitPos in the array
	//
	while (number != 0)
	{
		numberArray[digitPos] = number % 10;
		number /= 10;
		digitPos--;
	}

	return numberArray;
}
