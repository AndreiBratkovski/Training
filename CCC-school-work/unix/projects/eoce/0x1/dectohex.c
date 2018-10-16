//////////////////////////////////////////////////////////////////////
//
// dectohex.c - a quick helper program that may assist you on your
//              forensic investigative journeys.
//
// This program will take data from STDIN, convert it, and display
// it to STDOUT.
//
// For those unfamiliar with C, the magic is in the format specifier
// string in the fscanf(3) and fprintf(3) calls. Their manual pages
// can be an excellent source of information.
//
// Figure out what it does, and then feel free to edit/make various
// alterations to suit your needs.
//
// This is C source code. In order to USE it, you will need to
// COMPILE it: gcc dectohex.c -o dectohex
//
// To use it, you need to run or execute it, as you would any other
// tool (although it may not be in your PATH, so adapt accordingly).
// 
#include <stdio.h>

int main()
{
    int value  = 0;

    fscanf (stdin,  "%u",   &value);
    fprintf(stdout, "%x\n",  value);

    return(0);
}
