#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Declare variables
	//
	FILE *primelist = stdout;	// file pointer for prime number display
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

	//
	// Declaring max Primes
	//
	int maxPrimes = atoi(argv[1]);

	if (maxPrimes < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		exit(1);
	}

	//
	// Declaring reserved Number
	//
	int reservedNumber = atoi(argv[2]);

	if (reservedNumber != 1)
	{
		fprintf(stderr, "%s: invalid value!\n", argv[0]);
		exit(1);
	}

	//
	// Checking for valid lower bound
	//
	if (argc == 4)
	{
		fprintf(stderr, "%s: invalid lower bound!\n", argv[0]);
		exit(1);
	}

	//
	// Declaring upper and lower bound
	//
	if (argc == 5)
	{
		upperBound = atoi(argv[4]);
		lowerBound = atoi(argv[3]);
	}
	//
	// Checking for valid upper bound
	//
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
	// Initialize important variables
	//

	//////////////////////////////////////////////////////////////////
	//
	// Your prime calculation algorithm
	//
	int increment = 2;
	int primeCounter = 0;
	int checkComposite = 0;

	//
	// Checking odd numbers only algorithm
	//
	if (maxPrimes == 0)
	{
		if (argc > 4)
		{
			increment = lowerBound;
		}

		while (increment <= upperBound)
		{
			checkComposite = 0;
			for (int i = 2; i <= sqrt(increment); i++)
				// sqrt trick added (primeregos.c)
			{
				if (increment % i == 0)
				{
					checkComposite++;
				}
				if (checkComposite >= 1)
				{
					break;
				}	// break for primeregbos.c
			}

			if (checkComposite < 1)	// check value lowered for sqrt trick (primeregos.c)
			{
				printf("%d ", increment);
			}

			if (increment % 2 == 0)
			{
				increment++;
			}
			else
			{
				increment += 2;
			}
		}
		printf("\n");
	}
	//
	// Same algorithm as above if maxPrime isn't set
	//
	else
	{
		if (argc > 4)
		{
			increment = lowerBound;
		}

		while (primeCounter < maxPrimes)
		{
			checkComposite = 0;
			for (int i = 2; i <= sqrt(increment); i++)
				// sqrt trick added (primeregos.c)
			{
				if (increment % i == 0)
				{
					checkComposite++;
				}
				if (checkComposite >= 1)
				{
					break;
				}	// break for primeregbos.c
			}

			if (checkComposite < 1)	// check value lowered for sqrt trick (primeregos.c)
			{
				printf("%d ", increment);
				primeCounter++;
			}
			if (argc > 3 && upperBound != 0)
			{
				if (increment >= upperBound)
				{
					break;
				}
			}

			if (increment % 2 == 0)
			{
				increment++;
			}
			else
			{
				increment += 2;
			}
		}
		printf("\n");
		//printf("\n\nPrime Counter: %d", primeCounter);        
	}

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
