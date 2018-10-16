#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	/////////////////////////////////////////////////////
	//
	// Test to see if the program has been run with
	// enough arguments.
	//
	if(argc < 2)
	{
		fprintf(stderr,"Not enough arguments!");
		exit (0);
	}
	/////////////////////////////////////////////////////
	//
	// Declaring variables, and starting the time of day
	//

	int divisor, max, maxFound,flag, lowerbound, square;	
	max = atoi(argv[1]);

	struct timeval time_start;
	struct timeval time_end;
	gettimeofday(&time_start, 0);

	/////////////////////////////////////////////////////
	//
	// This is where the calculation starts. Set the 
	// lowerbound or the starting number to 2 because
	// 1 can't be prime. The main driving loop is while
	// the maxFound is less than the max specified.
	// After every iteration the lowerbound increases 
	// by 1 (to test a new number). The loop starts
	// by resetting the flag and divisor back to the OG
	// vlaues. Then square is calculated.
	//
	lowerbound = 2;
	while(maxFound < max)
	{
		flag = 0;
		divisor = 2;
		square = sqrt(lowerbound);
		/////////////////////////////////////////////////////
		//
		// This second loop goes for as long as the divisor
		// is less than or equal to the squareroot of the 
		// number being tested. In the loop the number is
		// being tested for a remainder if there is not
		// a remainder then it isn't a prime number so
		// set off a flag and break out of the loop.
		// After every iteration increase the divisor by 1.
		//
		while(divisor <= square)
		{
			if(lowerbound % divisor == 0)
			{
				flag = 1;
				break;
			}
			divisor++;
		}
		/////////////////////////////////////////////////////
		//
		// If the flag is 0 then that means that number is
		// a prime number. Print that number out and 
		// increment the maxFound by 1.
		//
		if(flag == 0)
		{
			fprintf(stderr,"%d ",lowerbound);
			maxFound++;
		}
		lowerbound++;
	}
	/////////////////////////////////////////////////////
	//
	// Next is to print off a new line
	// End the timer, then print it to the screen.
	//
	fprintf(stderr,"\n");
	gettimeofday(&time_end, 0);
	fprintf (stdout, "%8.4lf\n",
	time_end.tv_sec-time_start.tv_sec+(
	(time_end.tv_usec-time_start.tv_usec)/1000000.0));
	return 0;
}
