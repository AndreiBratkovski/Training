/**
 **  compile: gcc --std=c99 -Wall -o gettimeofday gettimeofday.c
 **  execute: ./gettimeofday
 **  Displays time since 1970 in seconds
 Command line practice
 **  -h, -? help
 **  -V version
 **  -v verbose
 **  -q quiet, no output
 **  -p# precision
 **  -H human time
 **  -s just seconds
 **  -m just minutes
 **/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <getopt.h>

#define YES 	1
#define NO 		0
#define VERSION "2018.02.01"

void usage(char *);
void version(char *);

int main(int argc, char **argv)
{
	FILE *output 		   = stdout;
	FILE *verbose 		   = NULL;
	FILE *empty 		   = NULL;
	int arg 		       = 0;
	int digit_optind       = 0;
	int this_option_optind = 0;
	int option_index 	   = 0;
	int quiet_flag 		   = NO;
	int verbose_flag	   = NO;
	int seconds_flag 	   = NO;
	int milliseconds_flag  = NO;
	int precise 		   = 6;

	struct timeval time_val;

	static struct option long_options[] = {
		// name,               has_arg,      flag, letter rep.
		{ "help",         	   no_argument,       0, 'h' },
		{ "version",      	   no_argument,       0, 'V' },
		{ "verbose",      	   no_argument,       0, 'v' },
		{ "quiet",        	   no_argument,       0, 'q' },
		{ "precision",    	   required_argument, 0, 'p' },
		{ "human_time",   	   no_argument,       0, 'H' },
		{ "just-seconds",      no_argument,       0, 's' },
		{ "just-milliseconds", no_argument,       0, 'm' },
		{ 0,				   0,				  0,  0  }
	};

	empty = fopen("/dev/null", "w");
	if (empty == NULL)
	{
		fprintf(stderr, "Error opening /dev/null for writing!\n");
		exit(1);
	}
	verbose = empty;

	while ((arg = getopt_long (argc, argv, "hVvqp:Hsm", long_options, &option_index)) != -1)
	{
		switch (arg)
		{
			case 'h':
				usage(argv[0]);
				exit(0);

			case 'V':
				version(argv[0]);
				exit(1);

			case 'v':
				verbose_flag = YES;
				quiet_flag 	 = NO;
				break;

			case 'q':
				quiet_flag   = YES;
				verbose_flag = NO;
				break;

			case 'p':
				precise = atoi(optarg);
				break;

			case 'H':
				break;

			case 's':
				seconds_flag      = YES;
				milliseconds_flag = NO;
				break;

			case 'm':
				seconds_flag      = NO;
				milliseconds_flag = YES;
				break;

			default:
				fprintf(stderr, "Invalid argument '%c'\n", arg);
				fprintf(stderr, "Try %s --help for more information\n", argv[0]);
				exit(1);
		}
	}

	if ( quiet_flag == YES )
	{
		output 		= empty;
		verbose 	= empty;
	}
	else if ( verbose_flag == YES )
	{
		verbose 	= output;
	}
	gettimeofday(&time_val, 0);

	fprintf(verbose, "seconds:      %lu\n", time_val.tv_sec);
	fprintf(verbose, "milliseconds: %lu\n", time_val.tv_usec);

	if ((seconds_flag == NO) && (milliseconds_flag == NO))
		fprintf(output, "%.*lf\n", precise,  time_val.tv_sec + (time_val.tv_usec/1000000.0));
	
	else if (seconds_flag == YES)
		fprintf(output, "%lu\n", time_val.tv_sec);

	else
		fprintf(output, "%lu\n", time_val.tv_usec);

	return (0);
}

void usage(char *name)
{
	fprintf(stdout, "options displayed here for help\n");
	exit(0);
}
void version (char *name)
{
	fprintf (stdout, "%s %s\n", name, VERSION);
	exit(0);
}
