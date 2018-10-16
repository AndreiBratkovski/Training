#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
//
// Andrei Bratkovski pnc3
// primerolos.c
//
int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	//FILE *primelist = stdout;     // file pointer for prime number display
	FILE *timing = stderr;	// file pointer for timing data display
	struct timeval ts;	// time start
	struct timeval te;	// time elapsed

	//////////////////////////////////////////////////////////////////
	//
	// Argument processing
	//

	if (argc < 3)
	{
		fprintf(stderr, "%s: insufficient number of arguments!\n",
			argv[0]);
		exit(1);
	}

	//
	// Default declarations
	//

	int lowerBound = 2;
	int upperBound = 0;

	// initializing max prime quantity
	int maxPrimes = atoi(argv[1]);

	if (maxPrimes < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		exit(1);
	}

	// initializing reserved Number
	int reservedNumber = atoi(argv[2]);

	if (reservedNumber != 1)
	{
		fprintf(stderr, "%s: invalid value!\n", argv[0]);
		exit(1);
	}

	// checking for invalid lower bound
	if (argc == 4)
	{
		fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
		exit(1);
	}

	// setting upper and lower bound
	if (argc == 5)
	{
		upperBound = atoi(argv[4]);
		lowerBound = atoi(argv[3]);
	}

	if (lowerBound > upperBound && upperBound != 0)
	{
		fprintf(stderr, "%s: invalid upper bound!\n", argv[0]);
		exit(1);
	}

	// argc == argument counts, argc will always be 1.
	//////////////////////////////////////////////////////////////////
	//
	// Start our timing
	//
	gettimeofday(&ts, 0);

	//////////////////////////////////////////////////////////////////
	//
	//  prime calculation algorithm ONE LOOP
	//

	//
	// Declare variables, Create test variable to check if prime via modulus operator
	// if a number mod test is not 0, then it is not prime
	//
	int test = 2;
	int lowerBoundMark;
	int primeCount = 0;
	int compositeCount = 0;

	lowerBoundMark = lowerBound;

	do
	{
		//
		// Since we have one loop, we will check in the loop for the number of arguments
		// as well as to see if the upperBound/max prime value has been met. If it has, then the program
		// can terminate.  In this case we use a break statement
		//
		if (argc > 4)
		{
			if (upperBound >= lowerBoundMark)
			{
				if (lowerBound >= upperBound)
					break;
			}
			if (primeCount >= maxPrimes && maxPrimes > 0)
				break;
		}
		else if (primeCount >= maxPrimes && maxPrimes > 0)
			break;

		//
		// if Test is greater than sqrt lowerBound then it cannot divide lowerbound. This by 
		// definition makes the current number a prime number
		//
		if (lowerBound % 2 == 0)
		{

			if (test > sqrt(lowerBound))	// sqrt trick, check up to sqrt
			{
				if (compositeCount > 0)
				{
					compositeCount = 0;
					lowerBound++;
					test = 2;
				}
				else
				{
					test = 2;
					fprintf(stdout, "%d ", lowerBound);
					lowerBound++;
					primeCount++;
				}
			}
			//
			// If lowerBound can divide evenly by test, then it is composite
			// My break on composite is omitted here.  Checking all numbers
			//
			else if (lowerBound % test == 0)
			{
				compositeCount++;
				test++;
				//test = 2;
				//lowerBound++;
			}
			//
			// If neither condition above works out, we test the next number by incrementing by 1
			//
			else
				test++;
		}
		//
		// odd  traversal + sqrt trick, Only check odds up to sqrt of number 
		// using inefficient method without break here
		//
		else if (lowerBound % 2 == 1)
		{
			if (test > sqrt(lowerBound))	// sqrt trick, check up to sqrt
			{
				if (compositeCount > 0)
				{
					compositeCount = 0;
					lowerBound += 2;
					test = 2;
				}

				else
				{
					test = 2;
					fprintf(stdout, "%d ", lowerBound);
					lowerBound += 2;
					primeCount++;
				}
			}

			//
			// If lowerBound can divide evently by test, then it is composite
			// but this is the slow version that checks all numbers
			//
			else if (lowerBound % test == 0)
			{
				compositeCount++;
				test++;
				//test = 2;
				//lowerBound += 2;
			}
			//
			// If neither condition above works out, we test the next number by incrementing by 1
			//
			else
				test++;
		}

		else
			lowerBound++;

	}
	//
	// While loop condition checking if lowerBound is still less than upperBound OR primeCount is
	// still less than max prime count
	//
	while (lowerBound <= upperBound || primeCount < maxPrimes);

	fprintf(stdout, "\n");
	// Initializing counter variables

	//////////////////////////////////////////////////////////////////
	//
	// Stop our timing
	//
	gettimeofday(&te, 0);

	//////////////////////////////////////////////////////////////////
	//
	// Display timing information
	//
	fprintf(timing, "%8.4lf\n",
		te.tv_sec - ts.tv_sec +
		((te.tv_usec - ts.tv_usec) / 1000000.0));

	return (0);
}
