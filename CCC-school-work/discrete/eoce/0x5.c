///////////////////////////////////////////
//
// 0x5 - Weird Numbers - Andrei Bratkovski
//
//////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//
// Works properly up to integer 490, checking from greatest factor
// value to smallest factor value
//
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

//
// Declare all variables and arrays for factor checking
//
	int increment;
	int number;
	int index = 0;
	int factorTotal = 0;
	int factorTotal2 = 0;
	int *factors;
	int *semiPerfectAdds;
	int numFactors = 0;
	int weirdTotal = 0;

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
			numFactors = 0;

			for (increment = 1; increment < number; increment++)
			{
				//
				// add up all factors of each number
				//
				if (number % increment == 0)
				{
					factorTotal += increment;
					numFactors++;
				}
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
				if (factorTotal > number)
					fprintf(stdout, " = %d ", factorTotal);
				else
					fprintf(stdout, " = %d\n", factorTotal);
				factorTotal2 = 0;
			}
			// if abundant, check if semi perfect/perfect
			if (factorTotal > number)
			{	// create array of factors
				index = 0;
				weirdTotal = 0;
				factors =
				    (int *)malloc(numFactors * sizeof(int));
				semiPerfectAdds =
				    (int *)malloc(numFactors * sizeof(int));

				for (increment = 1; increment < number;
				     increment++)
				{
					if (number % increment == 0)
					{
						*(factors + index) = increment;
						index++;
					}
				}
				//
				// add up factorsand check for weird number/semiperfect
				//
				index = 0;
				for (increment = (numFactors - 1);
				     increment >= 0; increment--)
				{
					if (weirdTotal +
					    *(factors + increment) <= number)
					{
						weirdTotal +=
						    *(factors + increment);
						*(semiPerfectAdds + index) =
						    *(factors + increment);
						index++;
					}

				}
				//
				// if weird number total ever adds up to be equal to the number,
				// it is semiperfect
				//
				if (weirdTotal == number)
				{
					fprintf(stdout, "(semi-perfect: ");
					for (increment = (index - 1); increment >= 0; increment--)
					{
						if (increment != 0)
							fprintf(stdout, "%d+",
								*
								(semiPerfectAdds
								 + increment));
						else
							fprintf(stdout, "%d)\n",
								*
								(semiPerfectAdds
								 + increment));
					}
				}
				// if weird total never adds up to the number, it is
				// a weird number
				else
					fprintf(stdout, "(weird: none)\n");

				//
				// Free allocated arrays for semi perfect checks
				//
				free(semiPerfectAdds);
				free(factors);
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
			numFactors = 0;

			for (increment = 1; increment < number; increment++)
			{
				//
				// add up all factors of each number
				//
				if (number % increment == 0)
				{
					factorTotal += increment;
					numFactors++;
				}
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
				if (factorTotal > number)
					fprintf(stdout, " = %d ", factorTotal);
				else
					fprintf(stdout, " = %d\n", factorTotal);
				factorTotal2 = 0;
			}
			// if abundant, check if semi perfect/perfect
			if (factorTotal > number)
			{	// create array of factors
				index = 0;
				weirdTotal = 0;
				factors =
				    (int *)malloc(numFactors * sizeof(int));
				semiPerfectAdds =
				    (int *)malloc(numFactors * sizeof(int));

				for (increment = 1; increment < number;
				     increment++)
				{
					if (number % increment == 0)
					{
						*(factors + index) = increment;
						index++;
					}
				}
				// add and check for weird number/semiperfect
				index = 0;
				for (increment = (numFactors - 1);
				     increment >= 0; increment--)
				{
					if (weirdTotal +
					    *(factors + increment) <= number)
					{
						weirdTotal +=
						    *(factors + increment);
						*(semiPerfectAdds + index) =
						    *(factors + increment);
						index++;
					}

				}
				//
				// Same as above, if weird number ever equals number,
				// it is semi perfect, print added together numbers
				//
				if (weirdTotal == number)
				{
					fprintf(stdout, "(semi-perfect: ");
					for (increment = (index - 1);
					     increment >= 0; increment--)
					{
						if (increment != 0)
							fprintf(stdout, "%d+",
								*
								(semiPerfectAdds
								 + increment));
						else
							fprintf(stdout, "%d)\n",
								*
								(semiPerfectAdds
								 + increment));
					}
				}
				else
					fprintf(stdout, "(weird: none)\n");

				//
				// Free allocated arrays for checking semi perfect numbers
				//
				free(semiPerfectAdds);
				free(factors);
			}
		}
	}

	return 0;
}
