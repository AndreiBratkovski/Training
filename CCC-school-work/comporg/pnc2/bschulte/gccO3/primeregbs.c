#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

int
main(int argc, char **argv)
{
struct timeval time_start; //starting time
struct timeval time_end;   //ending time

int divBy=2;
int i=3;  //counter index
int num=2;
int upBound;


///////////
//input argument checking
if(argc >= 2)
{
	sscanf(argv[1], "%d", &upBound);
	if(upBound<=0)
	{
		fprintf(stderr, "Bad Argument- must be greater than 0\n");
		exit(0);
	}
}
else
{
	fprintf(stderr, "No Upper Bound\n");
	exit(0);
}

gettimeofday(&time_start, 0);

fprintf(stderr, "2 3 ");

while(num!=upBound)
{//while the correct number of primes has not been found
	int sqt = sqrt(i);  //square root of i
	int mod = i%divBy;  

	if(mod!=0)
	{//if divBy is not a factor of i
		if(divBy!=sqt)
		{//if i cannot be determined to be prime yet by sqrt
			divBy++;
		}	
		else if(divBy==sqt)
		{//if i is prime
			fprintf(stderr, "%d ", i);
			i++;
			num++;
			divBy=2;
		}
		else
		{
			fprintf(stderr, "%d ", i);
			i++;
			num++;
			divBy=2;
		}
	}
	else
	{//i is not prime, breaks to next i
		i++;
		divBy=2;
	}
}


//prints time
gettimeofday(&time_end, 0);
fprintf (stdout, "%8.4lf\n",
time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec-time_start.tv_usec)/1000000.0));

return(0);
}
