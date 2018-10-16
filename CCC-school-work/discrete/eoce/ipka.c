// Andrei Bratkovski discrete ipka

#include <stdlib.h>
#include <stdio.h>

int main()
{
// 0x0
//
// Initialize count, length of array, and initial array.  increment used
// for odds processing
//
int numArray[] = { 56, 73, 36, 112, 177, 80, 23, 17, 6, 14, 29, 79 };
int count = 0;
int length = sizeof(numArray)/sizeof(numArray[0]);
int increment;

//
// Check array for odd numbers using modulus operator. If odd, add to
// count
//
for ( increment = 0; increment <= length; increment++)
{
	if ( *(numArray + increment) % 2 == 1 )
		count++;
}

// let user know how many odds there are
fprintf( stdout, "There are %d odd numbers in this array\n", count);

//
// 0x1
//
count = 0;
for ( increment = 0; increment <= length; increment++ )
{
	if ( numArray[increment] & 1 )
		fprintf( stdout, "%d is an odd number\n", numArray[increment]);
}

//
// 0x4 to bin
//
int mask = 0x80;
char latan = ')';
while ( mask > 0 )
{
	printf("%d", ( latan & mask ) > 0 );
	mask >>= 1;
}

return 0;
}
