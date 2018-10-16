/////////////////////////////
//
// primereg pnc0- Andrei - comporg
//
/////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(int argc, char **argv)
{

	/////////////////////////
	//
	// Declare variables
	//
	FILE *primelist = stderr;	// file pointer for prime number display
	FILE *timing = stdout;	// file pointer for timing data display
	struct timeval ts;	// time start
	struct timeval te;	// time elapsed

	////////////////////////
	//
	// Argument Processing
	//

	if (argc != 2)
	{
		fprintf(stderr, "%s: insufficient number of arguments!\n",
			argv[0]);
		exit(1);
	}

	int maxNumPrimes = atoi(argv[1]);

	if (maxNumPrimes < 1)
	{
		fprintf(stderr,
			"Number of primes  must be greater than 0 (lower bound)\n");
		exit(2);
	}

	/////////////////////////
	//
	// Start our timing
	//
	gettimeofday(&ts, 0);

	/////////////////////////
	//
	// Prime calculations algorithm
	//
	int increment;
	int lowerBound = 2;
	int numPrimes = 0;
	int compositeCounter = 0;

	//
	// Check the primality of each number starting from
	// 2, until max amount of primes is reached.
	// Iterate through each digit to add up a "composite counter".
	// if the counter exceeds 2, it is a composite number
	//
	while (numPrimes < maxNumPrimes)
	{
		for (increment = 2; increment <= lowerBound; increment++)
		{
			if (lowerBound % increment == 0)
				compositeCounter++;
		}
		if (compositeCounter < 2)
		{
			fprintf(primelist, "%d ", lowerBound);
			numPrimes++;
		}
		lowerBound++;
		compositeCounter = 0;
	}
	fprintf(stdout, "\n");

	/////////////////////////
	//
	// Stop our timing
	//
	gettimeofday(&te, 0);

	////////////////////////
	//
	// Display timing information
	//
	fprintf(timing, "%8.4lf\n",
		te.tv_sec - ts.tv_sec +
		((te.tv_usec - ts.tv_usec) / 1000000.0));
	return (0);
}
