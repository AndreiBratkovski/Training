#include "prime.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

prime :: prime()
{
	primeCount = 1;
	max        = 0;
}

char prime :: primeCheck(int testNum)
{	
	int divisor = 2;
	int root = sqrt(testNum);
	int remainder = 0;

	for (divisor = 2; divisor <= root; divisor++)
	{		
		remainder = testNum % divisor;
		if (remainder == 0)
			return(0);
	}
	
	return(1);
}

char prime :: primePrint(int testNum)
{
	fprintf(stderr, "%d ", testNum);
	primeCount++;
	
	if (primeCount == max)
		return(1);

	else
		return(0);
	

}

void prime :: setMax(int input)
{
	max = input;
}




