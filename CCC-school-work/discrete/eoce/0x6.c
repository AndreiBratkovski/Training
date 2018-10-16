/////////////////////////////////////////////
//
// 0x6- Anagrams - Andrei Bratkovski
//
////////////////////////////////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
//
// Prototype functions
//
void swapLetters( char *, char *);
void permutation(char *, int, int, int * );
//
// Main programming logic, checks argument and then processes all
// possible combinations
//
int main(int argc, char **argv)
{

if ( argc != 2 )
{
	fprintf(stderr, "Need one string argument, try again. If using spaces, use '_' char to view all permutations\n");
	exit(1);
}

//
// Calculates length of the string being input before
// being used in permutation parameters
//
int length = strlen(argv[1]);
int possible = 0;
//
// Cycles through and prints every combination of string provided
//
permutation(argv[1], 0, length-1, &possible);

fprintf(stdout, "Possible Combinations: %d\n", possible);
return 0;

}

//
// Helper function for permutation which swaps two
// characters in a string using pointers
//
void swapLetters(char *char1, char *char2)
{
    char temp;
    temp = *char1;
    *char1 = *char2;
    *char2 = temp;
}

//   
// Permutation takes string, start index, and ending index of
// word for each permuation
// 
void permutation(char *str, int startIndex, int endIndex, int *possible)
{
   int index;
   if (startIndex == endIndex)
	{
     fprintf(stdout, "%s\n", str);
	(*possible)++;
	}
   else
   {
       for (index = startIndex; index <= endIndex; index++)
       {
          swapLetters((str+startIndex), (str+index));
          permutation(str, startIndex+1, endIndex, possible);
          swapLetters((str+startIndex), (str+index));
       }
   }
}
