#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libgen.h>

//////////////////////////////////////////////////////////////////////
//
//      Andrei Bratkovski - Discrete - 2017 - DCF1 encode.c 9/14/17
//
int main(int argc, char **argv)
{
	//////////////////////////////////////////////////////////////////
	//
	// Variable declarations
	//
	FILE *in = NULL;
	FILE *out = NULL;
	char *filename = NULL;
	char *bname = basename(argv[1]);
	char outName[255] = "";

	//////////////////////////////////////////////////////////////////
	//
	// Command-line argument checking; if no argument, error out
	//
	if (argc < 3)
	{
		fprintf(stderr, "ERROR: Not enough arguments\n");
		fprintf(stderr, "usage:\n");
		fprintf(stderr, "\t%s FILENAME STRIDE\n\n", argv[0]);
		exit(1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// otherwise, argument is file name to encode
	//
	else
	{
		snprintf(outName, sizeof(outName), "%s/%s%s", argv[2], bname,
			 ".rle");

		in = fopen(argv[1], "r");
		if (in == NULL)
		{
			fprintf(stderr, "Error opening '%s' for reading.\n",
				argv[1]);
			exit(1);
		}
		out = fopen(outName, "w");
	}
	//
	// Initialize and check stride value
	//
	int stride = 1;		// default stride

	if (argc == 4)
	{
		stride = atoi(argv[3]);
	}

	if (stride < 1 || stride > 255)
	{
		fprintf(stderr, "Error, stride value out of bounds\n");
		exit(1);
	}

	//////////////////////////////////////////////////////////////////
	//
	// STDOUT (printed statistics) declarations
	//

	/// HEADER ///
	char header[] =
	    { 0x64, 0x63, 0x66, 0x58, 0x20, 0x52, 0x4c, 0x45, 0x00, 0x02,
		stride, strlen(bname)
	};

	fprintf(stdout, "input name length: %d bytes\n", strlen(argv[1]));
	fprintf(stdout, "input file name: %s\n", argv[1]);
	fprintf(stdout, "embedded name length: %d bytes\n", strlen(bname));
	fprintf(stdout, "embedded file name: %s\n", bname);
	fprintf(stdout, "output name length: %d bytes\n", strlen(outName));
	fprintf(stdout, "output filename: %s\n", outName);
	fprintf(stdout, "stride value: %d bytes\n", stride);

	//////////////////////////////////////////////////////////////////
	//
	// Your dcfX RLE v2 encoding implementation here
	//

	//
	// Write out header and title to RLE output file
	//
	int iteration = 0;
	int outByteCounter = 0;	// counts bytes being output
	int headerByteCounter = 0;

	for (iteration = 0; iteration < sizeof(header); iteration++)
	{
		fprintf(out, "%c", header[iteration]);
		outByteCounter++;
		headerByteCounter++;
	}

	iteration = 0;
	for (iteration; iteration < strlen(bname); iteration++)
	{
		fprintf(out, "%c", bname[iteration]);
		outByteCounter++;
		headerByteCounter++;
	}
	//////////////////////////////////////////////////////////////////
	//
	// Encoding to output file with RLE v2 specification
	//
	int trigger = 1;	// set trigger for first check
	int fileByte;
	int inByteCounter = 0;
	int checkCount = 0;	// count keeps track of repetition
	int writeOutCount = 1;
	int eofCount = 0;

	int increment = 0;
	char strideArray[255];
	char checkArray[255];

	//
	// Begin iterating through input file bytes
	// File sequences are read and compared based on stride
	//
	while (!feof(in))
	{
		//
		// Build stride array
		//
		eofCount = 0;
		for (increment = 0; increment < stride; increment++)
		{
			fileByte = fgetc(in);
			if (!feof(in))
			{
				inByteCounter++;
			}
			strideArray[increment] = fileByte;
			if (!feof(in))
			{
				eofCount++;
			}
		}

		if (trigger != 0)
		{
			trigger = 0;	// hit the trigger on first loop
			//
			// Build first check array
			//
			for (increment = 0; increment < stride; increment++)
			{
				fileByte = fgetc(in);
				if (!feof(in))
				{
					inByteCounter++;
				}
				checkArray[increment] = fileByte;
			}
			//
			// first comparison to see if both sequences are the same
			//
			for (increment = 0; increment < stride; increment++)
			{
				if (strideArray[increment] ==
				    checkArray[increment])
				{
					checkCount++;
				}
			}
			//
			// Check that write out count doesn't exceed 255
			// write out and reset
			//
			if (writeOutCount == 256)
			{
				fprintf(out, "%c", writeOutCount - 1);
				writeOutCount = 1;
				outByteCounter++;

				for (increment = 0; increment < stride;
				     increment++)
				{
					fprintf(out, "%c",
						checkArray[increment]);
					outByteCounter++;
				}
			}
			if (checkCount == stride)
			{
				writeOutCount++;	// if both sequences match, tally writeOutCount
			}
			//
			// In first check, write out the count,
			// then write out the stride length sequence
			//
			else
			{
				fprintf(out, "%c", writeOutCount);
				writeOutCount = 1;
				outByteCounter++;

				for (increment = 0; increment < stride;
				     increment++)
				{
					fprintf(out, "%c",
						strideArray[increment]);
					outByteCounter++;
				}
			}
			checkCount = 0;
		}
		//
		// If trigger is hit already, compare new stride array with check array,
		// then add up writeOutCount, and set check array equal to stride array
		//       
		else
		{
			for (increment = 0; increment < stride; increment++)
			{
				if (strideArray[increment] ==
				    checkArray[increment])
				{
					checkCount++;
				}
			}
			//
			// Check that write out count doesn't exceed 255
			// write out and reset
			//
			if (writeOutCount == 256)
			{
				fprintf(out, "%c", writeOutCount - 1);
				writeOutCount = 1;
				outByteCounter++;

				for (increment = 0; increment < stride;
				     increment++)
				{
					fprintf(out, "%c",
						checkArray[increment]);
					outByteCounter++;
				}
			}

			if (checkCount == stride)
			{
				writeOutCount++;
			}
			else
			{
				fprintf(out, "%c", writeOutCount);
				writeOutCount = 1;
				outByteCounter++;

				for (increment = 0; increment < stride;
				     increment++)
				{
					fprintf(out, "%c",
						checkArray[increment]);
					outByteCounter++;
				}

			}
			checkCount = 0;
			//
			// Set check array equal to stride array contents
			//
			for (increment = 0; increment < stride; increment++)
			{
				checkArray[increment] = strideArray[increment];
			}

		}
		if (feof(in) && eofCount > 0)
		{
			fprintf(out, "%c", 0x01);
			outByteCounter++;

			for (increment = 0; increment < eofCount; increment++)
			{
				fprintf(out, "%c", strideArray[increment]);
				outByteCounter++;
			}
		}		//cut off stride array at end of file

	}

	//////////////////////////////////////////////////////////////////
	//
	// STDOUT the read in, data written out, total written out and compression rate
	fprintf(stdout, "read in: %d bytes\n", inByteCounter);
	fprintf(stdout, "data written out: %d bytes\n",
		(outByteCounter - headerByteCounter));
	fprintf(stdout, "total written out: %d bytes\n", outByteCounter);

	//////////////////////////////////////////////////////////////////
	//
	// Compression Rate
	//

	float compressionRate;

	compressionRate =
	    (float)(outByteCounter - headerByteCounter) / (float)inByteCounter;
	compressionRate = (1 - compressionRate) * 100;
	fprintf(stdout, "compression rate: %.2f%\n", compressionRate);
	//////////////////////////////////////////////////////////////////
	//
	// close open file pointers
	//
	fclose(in);
	fclose(out);

	return (0);
}
