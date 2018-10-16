#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// variables
	//
	FILE *in = NULL;
	FILE *out = NULL;
	char *filename = NULL;
	unsigned char header[12];

	//////////////////////////////////////////////////////////////////
	//
	// process command-line, no arguments get an error
	//
	if (argc < 2)
	{
		fprintf(stderr, "Error\n");
	}

	//////////////////////////////////////////////////////////////////
	//
	// if given, open specified file for reading
	//
	else
	{
		in = fopen(argv[1], "r");
		out = fopen(argv[2], "w");
		if (in == NULL)
		{
			fprintf(stderr, "Error opening '%s' for reading\n",
				argv[1]);
			exit(1);
		}
	}

	//////////////////////////////////////////////////////////////////
	//
	// your dcfX RLE v1 decoding implementation
	//

	//
	// Variable declaration, and printing to stdout:
	// input file name/byte size, output file name/byte size, header text, and stride value
	//
	int inputNameLength = strlen(argv[1]);
	int outputNameLength = strlen(argv[2]);
	int stride = 1;

	printf("input name length: %d bytes\n", inputNameLength);
	printf("input filename: %s\n", argv[1]);
	printf("output name length: %d bytes\n", outputNameLength);
	printf("output filename: %s\n", argv[2]);
	printf("header text: dcfX RLE v1\n");
	printf("stride value: %d byte\n", stride);

	//////////////////////////////////////////////////////////////////
	//
	// Display stdout  size of input file being read in
	// 
	int inFileBytes;

	fseek(in, 0, SEEK_END);
	inFileBytes = ftell(in);
	printf("read in: %d bytes\n", inFileBytes);

	int inflationDiv = ftell(in);

	///////////////////////////////////////////////////////////////////
	//
	// Setting file pointer to beginning of input file
	//
	fseek(in, 0, SEEK_SET);
	int count = 0;

	///////////////////////////////////////////////////////////////////
	//
	// write out header bytes and inFile title bytes to outFile
	// This while loop is NOT necessary unless we want the header/title in output file contents
	while (1)
	{

		inFileBytes = fgetc(in);

		if (count <= outputNameLength + 11)
		{
			//fprintf(out, "%c", inFileBytes); Can be uncommented
			// to put header/title into output file contents
		}
		count++;
		if (feof(in))
		{
			break;
		}
	}

	///////////////////////////////////////////////////////////////////
	//
	// Initialize beginning position of input file contents
	//
	int fileContentsPosition = outputNameLength + 12;

	//
	// Set file pointer to position where input file contents begin
	//
	fseek(in, fileContentsPosition, SEEK_SET);

	//
	// Write out decoded contents into file output file 
	//
	int tmp = fgetc(in);
	int i = 0;

	while (1)
	{
		i = 0;
		if (feof(in))
		{
			break;
		}

		inFileBytes = fgetc(in);
		for (i; i < tmp; i++)
		{
			fprintf(out, "%c", inFileBytes);
		}
		tmp = fgetc(in);
	}

	/////////////////////////////////////////////////////////////////////
	//
	// Print to stdout the size of file written out and the inflation rate
	//
	int outFileBytes = ftell(out);

	printf("wrote out: %d bytes\n", outFileBytes);

	float inflationRate;

	inflationRate = (float)inflationDiv / (float)outFileBytes;
	inflationRate = (1 - inflationRate) * 100;
	printf("inflation rate: %.2f%\n", inflationRate);

	//////////////////////////////////////////////////////////////////
	//
	// close our open files
	//
	fclose(in);
	fclose(out);

	return (0);
}
