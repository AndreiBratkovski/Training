// primeregba.c 
//
// your basic prime number calculation program, with square root
// approximation trick
//
// once you compile with gcc -Wall --std=c99 -o primeregba primeregba.c
//	(or just use make)
//
// run ./primeregba QTY where QTY is the number of primes you want to display,
// starting at 2
//
// stupid values for QTY will not be accepted 

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main (int ac, char **av)
{
	// file pointers for displaying primes and timing information
	FILE *primelist = stderr;
	FILE *timing = stdout;

	int qty; // number of primes we want
	int num_primes = 0; // number of primes we have
	int num = 2; // numbers to be tested for primality
	int factor; // check if this is a factor of num
	char prime; // is a number prime or not?

	// check that we have one argument and that it's not negative
	if(ac == 2)
	{
		qty = atoi(*(av+1));
		if(qty < 1)
		{
			fprintf(stderr, "Quantity must be positive\n");
			exit(1);
		}
	}
	else
	{
		fprintf(stderr, "Only provide one argument: quantity\n");
		exit(2);
	}

	struct timeval time_start; // time start
	struct timeval time_end; // time end

	gettimeofday(&time_start, 0); // start timing

	while(num_primes < qty)
	{
		// restore to defaults
		prime = 1;
		factor = 2;

		// test each factor, if a factor divides evenly into number
		// number is not prime
		while(factor*factor <= num)
		{
			if(!(num%factor))
			{
				prime = 0;
				break;
			}

			factor++;
		}

		// if prime, print number and increment number of primes found 
		if(prime)
		{
			fprintf(primelist, "%d ", num);
			num_primes += 1;
		}

		num++; // go to next number
	}
	// print a nice new line
	fprintf(primelist, "\n");

	gettimeofday(&time_end, 0); // end timing

	// print timing information
	fprintf(timing, "%8.4lf\n", 
		time_end.tv_sec-time_start.tv_sec + (time_end.tv_usec-time_start.tv_usec)/1000000.0);

	return(0);
}
