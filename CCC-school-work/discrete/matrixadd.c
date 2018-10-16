#include <stdio.h>
#include <stdlib.h>

typedef signed char sc;

int main(int argc, char **argv)
{
	FILE *in;
	FILE *out;

	sc **matrixA;
	sc **matrixB;
	sc **matrixC;		// result matrix

	sc x;
	sc y;
	sc r1;
	sc r2;
	sc c1;
	sc c2;

	if (argc < 3)
	{
		fprintf(stderr, "ERROR: Must provide at least 2 arguments!\n");
		fprintf(stderr, "usage:\n");
		fprintf(stderr, "\t%s MATRIX1FILE MATRIX2FILE [OUTPUTFILE]\n",
			*(argv + 0));
		exit(1);
	}

	in = fopen(*(argv + 1), "r");
	if (in == NULL)
	{
		fprintf(stderr, "ERROR: Could not open '%s' for reading!\n",
			*(argv + 1));
		exit(2);
	}

	fscanf(in, "%hhd", &r1);
	fscanf(in, "%hhd", &c1);

	matrixA = (sc **) calloc(r1, sizeof(sc *));
	for (x = 0; x < r1; x++)
	{
		*(matrixA + x) = (sc *) calloc(c1, sizeof(sc));
		for (y = 0; y < c1; y++)
		{
			fscanf(in, "%hhd", (*(matrixA + x) + y));
		}
	}
	fclose(in);

	in = fopen(*(argv + 2), "r");
	if (in == NULL)
	{
		fprintf(stderr, "ERROR: Could not open '%s' for reading!\n",
			*(argv + 2));
		exit(3);
	}

	fscanf(in, "%hhd", &r2);
	fscanf(in, "%hhd", &c2);

	matrixB = (sc **) calloc(r2, sizeof(sc *));
	for (x = 0; x < r2; x++)
	{
		*(matrixB + x) = (sc *) calloc(c2, sizeof(sc));
		for (y = 0; y < c2; y++)
		{
			fscanf(in, "%hhd", (*(matrixB + x) + y));
		}
	}
	fclose(in);
	// Perform matrix conherence analysis
	if ((r1 != r2) || (c1 != c2))
	{
		fprintf(stderr, "MATTER STREAMS MISALIGNED!\n");
		exit(4);
	}

	matrixC = (sc **) calloc(r2, sizeof(sc *));
	if (matrixC == NULL)
	{
		fprintf(stderr, "Bad malloc! No memory\n");
		exit(5);
	}

	out = fopen("result.data", "w");
	if (out == NULL)
	{
		fprintf(stderr, "No bueno on filenessity\n");
		exit(6);
	}

	fprintf(out, "%hhd\n", r1);
	fprintf(out, "%hhd\n", c1);
	for (x = 0; x < r2; x++)
	{
		*(matrixC + x) = (sc *) calloc(c2, sizeof(sc));
		// check against NULL, for great justice        

		for (y = 0; y < c2; y++)
		{
			// addificate
			*(*(matrixC + x) + y) =
			    *(*(matrixA + x) + y) + *(*(matrixB + x) + y);

			// displayify
			fprintf(out, "%hhd ", *(*(matrixC + x) + y));
		}
		fprintf(out, "\n");

	}
	fclose(out);
	return (0);
}
