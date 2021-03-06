#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

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
	// Declaring max primes
	//
	int maxPrimes = atoi(argv[1]);

	if (maxPrimes < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[0]);
		exit(1);
	}

	//
	// Initializing reservedNumber
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
	// Declaring upper and lower bound if necessary
	//      
	if (argc == 5)
	{
		upperBound = atoi(argv[4]);
		lowerBound = atoi(argv[3]);
	}

	// Checking for valid upper bound
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

	//int checkComposite = 0;

	// 
	// If max primes quantity set, algorithm using 6n +-1 prime check
	// AND check that 6n +-1 is odd
	//
	if (maxPrimes == 0)
	{
		if (argc > 4 && lowerBound > 3)
		{
			increment = lowerBound + 6;
		}
		else
		{
			printf("%d %d ", 2, 3);
			increment = 4;
		}

		while (increment <= upperBound)
		{

			if (increment % 6 == 0)
			{
				int counter = 0;
				int possiblePrime1 = increment - 1;
				int possiblePrime2 = increment + 1;

				//
				// Check if possiblePrime1 is  odd (primeregmo.c)
				//
				if (possiblePrime1 % 2 != 0)
				{
					for (int i = 2; i <= possiblePrime1;
					     i++)
					{
						if (possiblePrime1 % i == 0)
						{
							counter++;
						}
						//
						// Break if composite (primeregbmo.c)
						//
						if (counter >= 2)
						{
							break;
						}
					}
					if (counter < 2)
					{
						printf("%d ", possiblePrime1);
						primeCounter++;
					}
					counter = 0;
				}
				//
				// Check if possiblePrime2 is odd (primeregomo.c)
				//
				if (possiblePrime2 % 2 != 0)
				{
					for (int i = 2; i <= possiblePrime2;
					     i++)
					{
						if (possiblePrime2 % i == 0)
						{
							counter++;
						}
						//
						// Break if composite (primeregbmo.c)
						//
						if (counter >= 2)
						{
							break;
						}
					}
					if (counter < 2)
					{
						printf("%d ", possiblePrime2);
						primeCounter++;
					}
				}
				counter = 0;
			}
			increment++;
		}
		printf("\n");
	}

	//
	// Same algorithm above, only if maxprimes quantity is set to 0
	//
	else
	{
		if (argc > 4 && lowerBound > 3)
		{
			increment = lowerBound + 6;
		}

		if (increment < 4)
		{
			printf("%d %d ", 2, 3);
			increment = 4;
			maxPrimes -= 2;
		}

		while (primeCounter <= maxPrimes)
		{

			if (increment % 6 == 0)
			{

				int counter = 0;
				int possiblePrime1 = increment - 1;
				int possiblePrime2 = increment + 1;

				if (possiblePrime1 % 2 != 0)
					//
					// Check if possible prime is Odd (primeregmo.c)
					//
				{
					for (int i = 2; i <= possiblePrime1;
					     i++)
					{
						if (possiblePrime1 % i == 0)
						{
							counter++;
						}
						//
						// Break on composite (primeregbmo.c)
						//
						if (counter >= 2)
						{
							break;
						}
					}
					if (counter < 2)
					{
						printf("%d ", possiblePrime1);
						primeCounter++;
					}
					counter = 0;

					if (primeCounter == maxPrimes)
					{
						break;
					}
				}
				if (possiblePrime2 % 2 != 0)
					//
					// Check if possible prime is Odd (primeregmo.c)
					//
				{
					for (int i = 2; i <= possiblePrime2;
					     i++)
					{
						if (possiblePrime2 % i == 0)
						{
							counter++;
						}
						//
						// Break on composite (primeregbmo.c)
						//
						if (counter >= 2)
						{
							break;
						}
					}
					if (counter < 2)
					{
						printf("%d ", possiblePrime2);
						primeCounter++;
					}
					counter = 0;
				}
				if (argc > 3 && upperBound != 0)
				{
					if (increment >= upperBound)
					{
						break;
					}
				}
			}
			increment++;
		}
		printf("\n");
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
