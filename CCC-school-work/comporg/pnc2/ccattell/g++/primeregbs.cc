#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "prime.h"


int main (int argc, char** argv)
{
	struct timeval time_start; // start time
	struct timeval time_end;   // end time
	
	 gettimeofday(&time_start, 0); // start timer

	// get input
	int input    = atoi(argv[1]);
	int testNum  = 3;
	char isPrime = 0;
	char isDone  = 0;
	// construct thing
	prime prime;

	// get number of primes to print
	prime.setMax(input);
	
	fprintf(stderr, "2 "); // compensate

	while(1)
	{
		// primeCheck returns 0 on composite
		isPrime = prime.primeCheck(testNum);
		if (isPrime == 1)
		{
			// primePrint returns 1 when primeCount = max num of primes
			isDone = prime.primePrint(testNum);
			if (isDone == 1)
				break;
		}
		testNum++;
	}

	fprintf(stderr, "\n");
	

    // print time 
	gettimeofday(&time_end, 0);
	fprintf(stdout, "%8.4f\n", time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec)/1000000.0));

	return(0);
}



