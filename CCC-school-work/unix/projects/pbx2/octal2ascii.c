//////////////////////////////////////////////////////////////////////
//
// octal2ascii.c - a quick helper program that may assist you on your
//                 puzzlebox journeys.
//
// This program will take data from STDIN, convert it, and display
// it to STDOUT.
//
// For those unfamiliar with C, the magic is in the format specifier
// string in the fscanf(). The 'o' of the "%hho" will translate the
// given value to an octal value (base 8).
//
// In place of the 'o', you can also format to signed decimal 'd',
// unsigned decimal 'u', hexadecimal 'x', floating point 'f', and
// a few other variations. The section 3 manual pages on fprintf(3)
// and fscanf(3) contain additional information.
//
// The leading 'hh' indicates a half of a half (of the o,d,u,x,f, 
// which happens to be 4 bytes), so half of half of 4 bytes is 
// 1 byte, which is the size of an ASCII character (what we want).
//
// This is C source code. In order to USE it, you will need to
// COMPILE it: gcc oct2ascii.c -o oct2ascii
//
// To use it, you need to run or execute it, as you would any other
// tool (even if it doesn't seem so at first- hint, it may act a
// bit like cat(1) in some usage scenarios).
// 
// Data is gathered via STDIN, and upon processing, information is
// output via STDOUT.
//
#include <stdio.h>

int main()
{
	char c;

	while ((fscanf(stdin, "%hho", &c)) != EOF)
		putchar(c);

	return(0);
}
