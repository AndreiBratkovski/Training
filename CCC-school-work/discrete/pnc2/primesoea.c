#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	//FILE *primelist = stdout;	// file pointer for prime number display
	FILE *timing = stderr;	// file pointer for timing data display
	struct timeval ts;	// time start
	struct timeval te;	// time elapsed
	int lowerBound = 2;
	int upperBound = 0;	// default values before being assigned

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
	// Initializing max prime quantity
	//
	int maxPrimes = atoi(argv[1]);

	if (maxPrimes < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		exit(1);
	}

	//
	// Initializing reserved number
	//
	int reservedNumber = atoi(argv[2]);

	if (reservedNumber != 1)
	{
		fprintf(stderr, "%s: invalid value!\n", argv[0]);
		exit(1);
	}

	//
	// Checking for invalid lower bound
	//
	if (argc == 4)
	{
		fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
		exit(1);
	}

	//
	// Setting upper and lower bound
	//
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

	//////////////////////////////////////////////////////////////////
	//
	// Start our timing
	//
	gettimeofday(&ts, 0);

	//////////////////////////////////////////////////////////////////
	//
	// Initialize important variables
	//
	unsigned long long int increment1, increment2;
	unsigned long long int maximumListSize = 4194304;
	int *primeNumbers;
	int primeCounter = 0;

	if (upperBound != 0)
	{
		maximumListSize = upperBound;
	}

	//
	// Allocate primeNumbers List memory
	//
	primeNumbers = malloc(sizeof(int) * maximumListSize);

	//////////////////////////////////////////////////////////////////
	//
	// My Sieve of Eratosthenes algorithm
	//
	for (increment1 = 2; increment1 < maximumListSize; increment1++)
	{
		primeNumbers[increment1] = 1;
	}
	//
	// Filtering squares up to maximumListSize in order to build up
	// Primes list. Checking the square of each increment is less than the upper bound (approximated sqrt trick)
	// primes are all set set to 1
	//
	for (increment1 = 2; increment1 * increment1 < maximumListSize;
	     increment1++)
	{
		if (primeNumbers[increment1])
		{
			for (increment2 = increment1;
			     increment1 * increment2 < maximumListSize;
			     increment2++)
			{
				primeNumbers[increment1 * increment2] = 0;
			}
		}

	}

	//
	// Set lower Bound if necessary
	//      
	if (lowerBound > 2)
	{
		increment1 = lowerBound;
	}
	else
	{
		increment1 = 2;
	}

	//
	// Now that all the prime numbers are situated,
	// Program loop prints out as many prime numbers as asked for
	//
	for (; increment1 < maximumListSize; increment1++)
	{
		if (primeNumbers[increment1])
		{
			fprintf(stdout, "%llu ", increment1);
			primeCounter++;
			if (maxPrimes > 0)
			{
				if (primeCounter == maxPrimes)
				{
					break;
				}
			}
		}
	}
	fprintf(stdout, "\n");
	free(primeNumbers);
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
