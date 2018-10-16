#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
//////////////////////////////////////////////////////////////////////
//
// Andrei Bratkovski - Discrete - DCF1 - decode.c   9/14/17
//

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// File and header variables
	//
	FILE *in = NULL;
	FILE *out = NULL;
	unsigned char header[12];
	char bname[255] = "";
	char outName[255] = "";
	char checkHeader[] =
	    { 0x64, 0x63, 0x66, 0x58, 0x20, 0x52, 0x4c, 0x45, 0x00 };

	//////////////////////////////////////////////////////////////////
	//
	// process command-line, no arguments get an error
	//
	if (argc < 3)
	{
		fprintf(stderr, "ERROR: Not enough arguments\n");
		exit(1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// if given, open specified file for reading
	//
	else
	{
		in = fopen(argv[1], "r");
		if (in == NULL)
		{
			fprintf(stderr, "Error opening '%s' for reading\n",
				argv[1]);
			exit(1);
		}
	}

	//////////////////////////////////////////////////////////////////
	//
	// dcfX RLE v2 decoding implementation
	//

	// Find output file name from header.
	int headerCount = 0;
	int inFileByte;
	int readInBytes = 0;
	int stride;
	int versionNumber;
	int sourceFileNameLength;

	//
	// Determine version number, stride, and sourceFileNameLength from header of input file
	//
	while (headerCount < 12)
	{
		inFileByte = fgetc(in);
		readInBytes++;

		header[headerCount] = inFileByte;

		if (headerCount == 9)
		{
			versionNumber = inFileByte;
		}
		if (headerCount == 10)
		{
			stride = inFileByte;
		}
		if (headerCount == 11)
		{
			sourceFileNameLength = inFileByte;
		}
		//
		// Check that first 8 bytes of header match
		//
		if (headerCount < 9)
		{
			if (header[headerCount] != checkHeader[headerCount])
			{
				fprintf(stderr, "first 8 bytes mismatch!\n");
				exit(1);
			}
		}
		headerCount++;
	}

	//
	// Verify version number
	//
	if (versionNumber == 1)
	{
		stride = 1;
	}
	else if (versionNumber > 2)
	{
		fprintf(stderr, "version mismatch!\n");
		exit(1);
	}

	//
	// Build up original filename
	//
	int increment = 0;

	for (increment; increment < sourceFileNameLength; increment++)
	{
		inFileByte = fgetc(in);
		readInBytes++;
		bname[increment] = inFileByte;
	}

	//
	// Open file to decode to
	//
	snprintf(outName, sizeof(outName), "%s/%s", argv[2], bname);
	out = fopen(outName, "w");
	/////////////////////////////////////////////////////////////////////
	//
	// Decode STDOUT statements
	//      
	fprintf(stdout, "input filename: %s\n", argv[1]);
	fprintf(stdout, "output name length: %d bytes\n", strlen(bname));
	fprintf(stdout, "output filename: %s\n", bname);
	fprintf(stdout, "header text: dcfX RLE v%d\n", versionNumber);
	fprintf(stdout, "stride value: %d bytes\n", stride);
	//////////////////////////////////////////////////////////////////
	//
	// Begin writing out to file
	//

	//
	// Declare array to allocate stride sequences to
	// Initialize value for value amount written out, counter for nested for loop increments
	// remainder used for remaining bytes once we reach EOF
	//
	char strideArray[255] = "";
	int value;
	int counter = 0;
	int remainder;
	int wroteOutBytes = 0;	//to keep track of bytes written out

	//
	// Check if empty data segment
	//
	if (feof(in))
	{
		fprintf(stderr, "empty data segment\n");
		exit(1);
	}

	//
	// set value and sequence 
	//
	while (!feof(in))
	{
		value = fgetc(in);
		readInBytes++;

		for (increment = 0; increment < stride; increment++)
		{
			strideArray[increment] = fgetc(in);

			if (feof(in))
			{
				remainder = increment;
				break;
			}
			readInBytes++;
		}
		//
		// write out sequence, value # of times
		//
		if (!feof(in))
		{
			for (increment = 0; increment < value; increment++)
			{
				for (counter = 0; counter < stride; counter++)
				{
					fprintf(out, "%c",
						strideArray[counter]);
					wroteOutBytes++;
				}
			}
		}

		//
		// write out unfinished sequence of bytes from EOF
		//
		else
		{
			for (increment = 0; increment < value; increment++)
			{
				for (counter = 0; counter < remainder;
				     counter++)
				{
					fprintf(out, "%c",
						strideArray[counter]);
					wroteOutBytes++;
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////
	//
	// Final STDOUT statements of data written out
	//
	fprintf(stdout, "read in: %d bytes\n", readInBytes);
	fprintf(stdout, "wrote out: %d bytes\n", wroteOutBytes);

	//
	// Inflation Rate
	//
	float inflationRate;

	inflationRate = (1 - ((float)readInBytes / (float)wroteOutBytes)) * 100;
	fprintf(stdout, "inflation rate: %.2f%\n", inflationRate);
	//////////////////////////////////////////////////////////////////
	//
	// close our open files
	//
	fclose(in);
	fclose(out);

	return (0);
}
