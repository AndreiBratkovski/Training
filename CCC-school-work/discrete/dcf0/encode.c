#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Variable declarations
	//
	FILE *in = NULL;
	FILE *out = NULL;
	char *filename = NULL;
	char *basename = NULL;

	//////////////////////////////////////////////////////////////////
	//
	// Command-line argument checking; if no argument, error out
	//

	if (argc == 1)
	{
		fprintf(stderr, "Error\n");
	}

	//////////////////////////////////////////////////////////////////
	//
	// otherwise, argument is file name to encode
	//

	else
	{

		in = fopen(argv[1], "r");
		out = fopen(argv[2], "w");

		if (in == NULL)
		{
			fprintf(stderr, "Error opening '%s' for reading.\n",
				basename);
			exit(1);
		}
	}

	//////////////////////////////////////////////////////////////////
	//
	// Your dcfX RLE v1 encoding implementation here
	//      
	// Variable declaration
	//
	int inputNameBytes = strlen(argv[1]);
	int outputNameBytes = strlen(argv[2]);
	int stride = 1;
	int fileBytes;
	int outFileBytes;
	int i = 0;
	int count = 0;
	int tmp = 123456;	//any random int that isn't 0.. In order to void the first loop

	//
	// Necessary header hex stored in array
	//
	char header[] =
	    { 0x64, 0x63, 0x66, 0x58, 0x20, 0x52, 0x4c, 0x45, 0x00, 0x01, 0x01,
	strlen(argv[1]) };

	///////////////////////////////////////////////////////////////////
	//
	// printing out input and output filename/byte length
	//
	printf("input name length: %d bytes \n", inputNameBytes);
	printf("input file name: %s\n", argv[1]);
	printf("output name length: %d bytes\n", outputNameBytes);
	printf("output file name: %s\n", argv[2]);
	printf("stride value: %d byte\n", stride);

	///////////////////////////////////////////////////////////////////
	//
	// Print inFile bytes read in input file
	//
	fseek(in, 0, SEEK_END);
	fileBytes = ftell(in);
	printf("read in: %d bytes\n", fileBytes);
	int compressionDiv = ftell(in);

	///////////////////////////////////////////////////////////////////
	//
	// Write out header file and input filename in hex to new RLE file(output file)
	//
	for (i = 0; i < sizeof(header); i++)
	{
		fprintf(out, "%c", header[i]);
	}

	i = 0;
	for (i; i < strlen(argv[1]); i++)
	{
		fprintf(out, "%c", argv[1][i]);
	}

	///////////////////////////////////////////////////////////////////
	//
	// Encode and write contents of input file to output file (using fgetc(in) to access current character in file stream)
	//
	fseek(in, 0, SEEK_SET);	// set file pointer to beginning of input file
	while (1)
	{
		fileBytes = fgetc(in);

		if (fileBytes == tmp || tmp == 123456)
		{
			count++;
		}

		else
		{
			// only print out if count != 0 incase of ff reset
			if (count != 0)
			{
				fprintf(out, "%c%c", count, tmp);
			}
			count = 1;
		}

		if (count == 255)
		{
			fprintf(out, "%c%c", count, tmp);
			count = 0;
		}		// reset count incase of overflow (count > 255 for byte conversion correction)

		if (feof(in))
		{
			break;
		}		// break at end of file
		tmp = fileBytes;
	}

	//////////////////////////////////////////////////////////////////
	//
	// Print out RLE file byte size and compression rate
	//

	outFileBytes = ftell(out);
	float compressionRate;

	compressionRate = (float)outFileBytes / (float)compressionDiv;
	compressionRate = (1 - compressionRate) * 100;

	printf("wrote out: %d bytes\n", outFileBytes);
	printf("compression rate: %.2f%\n", compressionRate);

	//////////////////////////////////////////////////////////////////
	//
	// close open file pointers
	//
	fclose(in);
	fclose(out);

	return (0);
}
