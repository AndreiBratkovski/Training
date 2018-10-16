//////////////////////////////////////////////////////
//
// Andrei Bratkovski - 0x1 - Visualizing Long Division
//                       		LETTERIFIED
//////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

int *convertQuotientToArray(unsigned long long int, int *);
char *numToArray(unsigned long long int, int *);
char *convertToLetters(char *, char *, int);

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

	int iteration = 0;

	//
	// Generate alphabet range
	//      
	static int range = 'Z' - 'A' + 1;
	char wordKey[] = "..........";	// filled with 10 '.' to be replaced w upper letters
	char firstLetter;
	char randLetter;
	int populateCount = 0;
	int check = 0;

	//
	// Iterate over wordKey to see if our random letter is
	// in there already. If not, add it to the word key until
	// the word key is full of upper case unique letters
	//
	while (populateCount != 10)
	{
		iteration = 0;
		check = 0;
		randLetter = rand() % range + 'A';
		for (; iteration < 10; iteration++)
		{
			//
			// Check if the char is in the key already. Each
			// new letter is mapped to an array index
			//
			if (strchr(wordKey, randLetter) != NULL)
				check++;
		}
		if (check == 0)
		{
			if (populateCount == 0)
				firstLetter = randLetter;
			wordKey[populateCount] = randLetter;
			populateCount++;
		}
	}
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

	char *numArray;
	int numLength;		// for letterify
	unsigned long long int quotient = dividend / divisor;

	//
	// Letterify quotient
	//
	numArray = numToArray(quotient, &numLength);
	numArray = convertToLetters(numArray, wordKey, numLength);

	fprintf(stdout, "%16s\n", numArray);
	//
	// Print beautiful divisor lines
	//
	fprintf(stdout, "%7s", "+");
	fprintf(stdout, "---------\n");

	//
	// Letterify and print divisor
	//
	numArray = numToArray(divisor, &numLength);
	numArray = convertToLetters(numArray, wordKey, numLength);
	fprintf(stdout, "%6s|", numArray);

	//
	// Letterify and print dividend
	//
	numArray = numToArray(dividend, &numLength);
	numArray = convertToLetters(numArray, wordKey, numLength);
	fprintf(stdout, "%9s\n", numArray);

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
		// the format specifier over one - Letterified subtrahend
		//
		if (subtrahend != 0)
		{
			numArray = numToArray(subtrahend, &numLength);
			numArray =
			    convertToLetters(numArray, wordKey, numLength);
			if (increment == 0)
				fprintf(stdout, "%*s%-5s\n", subFormat, "-",
					numArray);
			else
				fprintf(stdout, "%*s%5s\n", subFormat, "-",
					numArray);
		}

		//
		// Damage control, if the subtrahend is equal to 0, the avoid segmentation faults,
		// print the first letter of the key
		//
		else
		{
			if (increment == 0)
				fprintf(stdout, "%*s%-5c\n", subFormat, "-",
					firstLetter);
			else
				fprintf(stdout, "%*s%5c\n", subFormat, "-",
					firstLetter);
		}
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
		// Print the adjusted answer - Letterified!
		//
		if (answer != 0)
		{
			numArray = numToArray(answer, &numLength);
			numArray =
			    convertToLetters(numArray, wordKey, numLength);

			if (answer >= 100000)
				fprintf(stdout, "%*s\n", (subFormat + 7),
					numArray);
			else
				fprintf(stdout, "%*s\n", (subFormat + 6),
					numArray);
		}
		else
		{
			if (answer >= 100000)
				fprintf(stdout, "%*c\n", (subFormat + 7),
					firstLetter);
			else
				fprintf(stdout, "%*c\n", (subFormat + 6),
					firstLetter);

		}
		subFormat++;

		//
		// Increment over the quotient and calculate the new subtrahend/answer
		//
		increment++;
		subtrahend = quotientArray[increment] * divisor;
		answer = answer - subtrahend;
	}
	//
	// Print out Letterified Answer Key
	//
	fprintf(stdout, "\nLETTERDIVISION: %s\n", &wordKey[0]);

	return 0;
}

//
// Function to convert our quotient into a quotient length array. This
// is used so that we can iterate over each member of the quotient and
// perform multiplicative calculations on each member separately
//
int *convertQuotientToArray(unsigned long long int quot, int *quotLength)
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

//
// Function which converts a ulli number into a character array ( string ),
// also adjusting the number length to match its length
//
char *numToArray(unsigned long long int number, int *numLength)
{
	//
	// Find the length of the local number
	//
	int length = log10(number) + 1;

	//
	// assign the numberLength in main to this value
	//
	*numLength = length;
	int iteration;
	char *numberArray = calloc(length, sizeof(char));

	//
	// Assign each element of the array each digit of the number
	//
	for (iteration = (length - 1); iteration >= 0;
	     --iteration, number /= 10)
	{
		numberArray[iteration] = number % 10;
	}
	return numberArray;
}

//
// Function which converts the number array into its letter representation
// as dictated by the wordKey that is generated previously
//
char *convertToLetters(char *numArray, char *wordKey, int numLength)
{
	int increment = 0;
	int number;

	//
	// Iterate over each element of the number string, and replace it with the
	// corresponding letter encryption
	//
	for (increment = 0; increment < numLength; increment++)
	{
		number = numArray[increment];
		numArray[increment] = wordKey[number];
	}
	return numArray;
}
