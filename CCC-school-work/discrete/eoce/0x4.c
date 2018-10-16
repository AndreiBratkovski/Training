///////////////////////////////////////////
//
// 0x4 - Further Factoring Fun - Andrei Bratkovski
//
//////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
//
// Argument processing
//
	if (argc == 2)
	{
		fprintf(stdout, "missing upper bound\n");
		exit(1);
	}
//
// Not enough arguments provided
//
	if (argc < 2)
	{
		fprintf(stderr, "Insufficient data provided\n");
		exit(1);
	}
//
// If arguments are greater than 3, 
//
	if (argc != 3)
	{
		fprintf(stderr, "Needs to be two arguments\n");
		exit(1);
	}

//
// Initialize first and second integers from
// arguments
//
	int firstNum = atoi(argv[1]);
	int secondNum = atoi(argv[2]);

//
// Range has to be greater than 2
//
	if (firstNum < 2 || secondNum < 2)
	{
		fprintf(stderr, "Invalid range specification\n");
		exit(2);
	}

	int increment;
	int number;
	int factorTotal = 0;
	int factorTotal2 = 0;

//
// Ascending factor processing
//
//
// Factors wil be processed with a nested for loop, checking each number from 2 to
// the factor, to see if they are factors, then adding it all up in the total. Iterating
// over the numbers again for final printing
//
	if (firstNum <= secondNum)
	{
		for (number = firstNum; number <= secondNum; number++)
		{
			factorTotal = 0;
			for (increment = 1; increment < number; increment++)
			{
				//
				// add up all factors of each number
				//
				if (number % increment == 0)
					factorTotal += increment;
			}
			//
			// Factor printing, check if each number is perfect,
			// abundant, or deficient
			//
			fprintf(stdout, "[%d] ", number);
			if (factorTotal == number)
				fprintf(stdout, "%-10s ", "perfect:");
			else if (factorTotal > number)
				fprintf(stdout, "%-10s ", "abundant:");
			else
				fprintf(stdout, "%-10s ", "deficient:");

			//
			// Additive processing/printing
			//
			if (factorTotal == 1)
				// prime numbers
				fprintf(stdout, "1 = 1\n");
			else
			{
				//
				// Print addition of factors
				//
				for (increment = 1; increment < number;
				     increment++)
				{
					if (number % increment == 0)
					{
						factorTotal2 += increment;
						if (factorTotal2 == factorTotal)
							fprintf(stdout, "%d",
								increment);
						else
							fprintf(stdout, "%d+",
								increment);
					}
				}
				fprintf(stdout, " = %d\n", factorTotal);
				factorTotal2 = 0;
			}
		}
	}
//
// Descending factor processing
//
// Same exact as above, but check from the first number down
// to the second number
//
	else if (firstNum >= secondNum)
	{
		for (number = firstNum; number >= secondNum; number--)
		{
			factorTotal = 0;
			for (increment = 1; increment < number; increment++)
			{
				//
				// add up all factors of each number
				//
				if (number % increment == 0)
					factorTotal += increment;
			}
			//
			// Factor printing
			//
			fprintf(stdout, "[%d] ", number);
			if (factorTotal == number)
				fprintf(stdout, "%-10s ", "perfect:");
			else if (factorTotal > number)
				fprintf(stdout, "%-10s ", "abundant:");
			else
				fprintf(stdout, "%-10s ", "deficient:");

			//
			// Additive processing/printing
			//
			if (factorTotal == 1)
				// prime numbers
				fprintf(stdout, "1 = 1\n");
			else
			{
				//
				// Print addition of factors
				//
				for (increment = 1; increment < number;
				     increment++)
				{
					if (number % increment == 0)
					{
						factorTotal2 += increment;
						if (factorTotal2 == factorTotal)
							fprintf(stdout, "%d",
								increment);
						else
							fprintf(stdout, "%d+",
								increment);
					}
				}
				//
				// Print total of all number factors
				//
				fprintf(stdout, " = %d\n", factorTotal);
				factorTotal2 = 0;
			}
		}
	}

	return 0;
}
