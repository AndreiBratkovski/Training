#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv)
{
	int bit = 0;
	int count = 7;
	int index = 0;
	int min = 0;
	int max = 15;

	if (argc > 1)
		min = atoi(*(argv+1));

	if (argc > 2)
		max = atoi(*(argv+2));

	fprintf (stdout, "binary |oct|dec|hex\n");
	fprintf (stdout, "--------+---+---+----\n");

	for ( index = min; index <= max; index++)
	{
		count = 7;
		for (bit = 0x00000080; bit > 0x00000000; bit = bit >> 1)
		{
			fprintf (stdout, "%hhu", ((index & bit) >> count--));
			//count = count - 1;
		}
		fprintf(stdout, "|%3.3o|%3u|0x%.2hhX\n", index, index, index);
	}

	return (0);
}
