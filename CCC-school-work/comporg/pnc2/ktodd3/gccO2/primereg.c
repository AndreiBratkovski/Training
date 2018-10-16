
#include <stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>


int main(int argc, char *argv[])
{
//Below is error checking
if(argv[1]==0)
	{
	fprintf(stderr, "%s\n", "Error, no input.");
	return 0;
	}
int numberofprimes = atoi(argv[1]);

if(numberofprimes <= 0)
	{
	fprintf(stderr,"%s\n", "Error, put in a number, not zero or below.");
	return 0;
	}
//below is where we'll set up measuring the time.
struct timeval time_start;
struct timeval time_end;


//delcaring variables
int testnumber=2;
int test=0;
gettimeofday(&time_start, 0);
for(int n=0; n<numberofprimes;)
	{
	test=0;
		for(int m=2; m<=testnumber; m++)
			{
			if(testnumber % m == 0)
				{
				test++;
				}
			}

			if(test <= 1)
				{
				n++;
				fprintf ( stderr, "%d ", testnumber);
				}
	testnumber++;
	}
fprintf(stderr, "\n");
gettimeofday(&time_end, 0);


fprintf (stdout, "%8.4lf\n",
time_end.tv_sec-time_start.tv_sec+((time_end.tv_usec-time_start.tv_usec)/1000000.0));

return 0;
}
