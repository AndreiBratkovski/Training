//
// tool.c - Implementation of head Unix tool - Andrei
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	// Declare input File pointer
	FILE *inputFile;

	// Each line is read 4000 chars max
	// per line  at a time
	char line[4000]; 

	// open inputFile for reading
	inputFile = fopen(argv[1], "r");

	//
	// If input file does not exist, or fails to open,
	// return error message
	//
	if ( inputFile == NULL )
	{
		fprintf(stderr, "Error opening file: %s\n", argv[1]);
		exit(1);
	}

	//
	// Read line by line, printing it out until we reach 10 lines.
	//
	int lineCount = 0;
	while ( fgets ( line, 100, inputFile ) != NULL && lineCount != 10)
	{
		printf("%s", line);
		lineCount++;
	}

return (0);
}
