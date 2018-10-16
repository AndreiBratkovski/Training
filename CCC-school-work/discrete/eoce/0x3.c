////////////////////////////////////////////////////////////
//
// Andrei Bratkovski - 0x3 - Variable Factor Pair Processing
//
////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

//
// Argument processing
//
	if (argc < 3)
	{
		fprintf(stderr, "%s: insufficient number of arguments!\n",
			argv[0]);
		exit(1);
	}

//
// Default bound declarations
//
	int lowerBound = 2;
	int upperBound = 0;

	//
	// Default mode, printing factors
	// just displaying the factor with Nary pairs
	//
	int mode = 0;

//
// Initializing max quantity
//
	int maxQty = atoi(argv[1]);

	if (maxQty < 0)
	{
		fprintf(stderr, "%s: invalid quantity!\n", argv[1]);
		exit(1);
	}
//
// Initializing N-ary value
//
	int nAry = atoi(argv[2]);

	if (nAry < 1)
	{
		fprintf(stderr, "%s: invalid Nary value!\n", argv[2]);
		exit(2);
	}
//
// checking for invalid lower bound
//
	if (argc == 4)
	{
		fprintf(stderr, "%s: invalid lower bound!\n", argv[3]);
		exit(3);
	}
//
// setting upper and lower bound
//
	if (argc >= 5)
	{
		upperBound = atoi(argv[4]);
		lowerBound = atoi(argv[3]);
		if (argc == 6)
			mode = atoi(argv[5]);
	}

	if (lowerBound > upperBound && upperBound != 0)
	{
		fprintf(stderr, "%s: invalid upper bound!\n", argv[4]);
		exit(4);
	}

//
// factor calculations
//
	int factorCount;
	int number;
	int increment;
	int curQuantity = 0;

	if (maxQty == 0)
	{
		for (number = lowerBound; number <= upperBound; number++)
		{
			factorCount = 0;
			// count up factors per number
			for (increment = 1; increment <= number; increment++)
			{
				if (number % increment == 0)
					factorCount++;
				if (increment * increment == number)
					factorCount++;
			}
			// Nary check
			if (factorCount / 2.0 == nAry)
			{
				// print number if it matches Nary or number factors
				// depending on the mode
				if (mode == 0)
					fprintf(stdout, "%d ", number);

				else
				{
					fprintf(stdout, "%d = {", number);
					for (increment = 1; increment <= number;
					     increment++)
					{
						if (number == increment)
							fprintf(stdout,
								"%2d }\n",
								number);
						else if (increment *
							 increment == number)
							fprintf(stdout,
								"%2d, %2d, ",
								increment,
								increment);
						else if (number % increment ==
							 0)
							fprintf(stdout, "%2d, ",
								increment);
					}

				}
			}
		}
		if (mode == 0)
			//
			// Beautify with carriage return
			//
			fprintf(stdout, "\n");
	}
//
// any other max quantity Factors are checked until either upperBound or max
// quantity is reached
//
	else
	{
		number = lowerBound;
		while (curQuantity < maxQty)
		{
			factorCount = 0;
			// count up factors per number
			for (increment = 1; increment <= number; increment++)
			{
				if (number % increment == 0)
					factorCount++;
				if (increment * increment == number)
					factorCount++;
			}
			// Nary check
			if (factorCount / 2.0 == nAry)
			{
				// print number if it matches Nary or number factors
				// depending on the mode
				if (mode == 0)
					fprintf(stdout, "%d ", number);

				else
				{
					fprintf(stdout, "%d = {", number);
					for (increment = 1; increment <= number;
					     increment++)
					{
						if (number == increment)
							fprintf(stdout,
								"%2d }\n",
								number);
						else if (increment *
							 increment == number)
							fprintf(stdout,
								"%2d, %2d, ",
								increment,
								increment);
						else if (number % increment ==
							 0)
							fprintf(stdout, "%2d, ",
								increment);
					}

				}
				curQuantity++;
			}
			number++;
			if (number > upperBound)
				break;
		}
		//
		// Beautify with carriage return
		//
		if (mode == 0)
			fprintf(stdout, "\n");
	}
	return 0;
}
