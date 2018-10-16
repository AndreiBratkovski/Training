//////////////////////////////////////////////////////////////////////
//
// hex2ascii.c   - a quick helper program that may assist you on your
//                 puzzlebox journeys.
//
// This program will take data from STDIN, convert it, and display
// it to STDOUT.
//
// For those unfamiliar with C, the magic is in the format specifier
// string in the fscanf(). The 'x' of the "%hhx" will translate the
// given value to an octal value (base 8).
//
// There are additional means of translation. and I encourage you to
// seek them out; especially means that may directly aid you in the
// solving of this puzzlebox.
//
// This is C source code. In order to USE it, you will need to
// COMPILE it: gcc hex2ascii.c -o hex2ascii
//
// To use it, you need to run or execute it, as you would any other
// tool (even if it doesn't seem so at first).
// 
#include <stdio.h>

int main()
{
	char c;

	while ((fscanf(stdin, "%hhx", &c)) != EOF)
		putchar(c);

	return(0);
}
