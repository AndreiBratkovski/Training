#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>

void usage(char **argv);

int main ( int argc, char **argv )
{
	int flags = 0;
	int opt	  = 0;
	int nsecs = 0;
	int tfnd  = 0;

	while (( opt = getopt (argc, argv, "ht:n")) != -1)
	{
		switch (opt)
		{
			case 'h':
				usage(argv);
				exit(0);
			case 'n':
				flags = 1;
				break;

			case 't':
				nsecs = atoi(optarg);
				tfnd  = 1;
				break;
	
			default:
				fprintf (stderr, "Usage: %s [-t nsecs] [-n] [-h] name\n", argv[0]);
				exit(1);
		}
	}

	fprintf (stdout, "flags=%d; tfnd=%d; nsecs=%d; optind=%d\n", 
				flags, tfnd, nsecs, optind);

	if ( optind >= argc )
	{
		fprintf (stderr, "Expected argument after options\n");
		exit(2);
	}

	fprintf(stdout, "name argument = %s\n", argv[optind]);

	return (0);
}

void usage(char **argv)
{
	fprintf(stdout, "Usage: %s [OPTION] name\n", argv[0]);
	fprintf(stdout, "Demo of getopt() argument parsing\n\n");
	fprintf(stdout, " -h        display help and exit\n");
	fprintf(stdout, " -n        doohickeymabob\n");
	fprintf(stdout, " -t #		activate interlocks\n");
}
