//
// Pds0 - Storing CSV Data into array and printing it out
// Andrei Bratkovski
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	// declare CSV file pointer
	FILE *csvFile;

	// open CSV file for reading
	csvFile = fopen(argv[1], "r");

	if (csvFile == NULL)
	{
		fprintf(stderr, "Error opening file\n");
		exit(0);
	}

	//
	// Declare struct for CSV element. Storing
	// Data into an array of structs
	//
	char date[5];
	char open[5];
	char high[5];
	char low[4];
	char close[6];
	char adjClose[10];
	char volume[7];

	//
	// Declare struct for one stock day
	//
	struct stockDay {
		char date[10];
		double open;
		double high;
		double low;
		double close;
		double adjClose;
		double volume;
	};

	//
	// Allocate an array that can hold up to 1 month of
	// stock data
	//
	struct stockDay month[30];
	int count = 0;

	// 
	// Iterate over each value separated by commas and store them in their designated
	// positions of each struct
	//
	while (!feof(csvFile))
	{
		if (count == 0)
			fscanf(csvFile,
			       "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
			       date, open, high, low, close, adjClose, volume);
		else
			fscanf(csvFile, "%[^,],%lf,%lf,%lf,%lf,%lf,%lf",
			       month[count].date, &month[count].open,
			       &month[count].high, &month[count].low,
			       &month[count].close, &month[count].adjClose,
			       &month[count].volume);
		count++;
	}
	//
	// Print stock headers
	//
	fprintf(stdout, "%10s %10s %10s %10s %10s %12s %12s\n", date, open,
		high, low, close, adjClose, volume);

	//
	// Iterate through the amount of lines that were previously read and print out
	// contents of stock structs as well as the stock header to have a pretty output
	//
	int index;

	for (index = 1; index <= (count - 2); index++)
	{
		fprintf(stdout,
			"%10s %10.2lf %10.2lf %10.2lf %10.2lf %12.2lf %12.2lf\n",
			month[index].date, month[index].open, month[index].high,
			month[index].low, month[index].close,
			month[index].adjClose, month[index].volume);
	}
	return (0);
}
