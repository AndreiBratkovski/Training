#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define SHOWHOST
void show_time( time_t );
void show_info( struct utmp *, int);

int main()
{
	struct utmp 	rec;            /* read info into here */
	struct stat 	dat;
	char 			*file = NULL;
	int    			ufd;		   /* read from this descriptor */
	int 			flg = 0;

	if ( (ufd = open(UTMP_FILE, O_RDONLY)) == -1 )
	{
		perror(UTMP_FILE);
		exit(1);
	}

	while(read (ufd, &rec, sizeof(rec)) == sizeof(rec))
	{
		if ( rec.ut_type == USER_PROCESS )
		{
			file = (char *) malloc(sizeof(char) * (strlen ( rec.ut_line) + 6));
			sprintf ( file, "/dev/%s", rec.ut_line );
			stat ( file, &dat );
			if ((( dat.st_mode & 020) >> 4) == 1)
				flg = 1;
			else
				flg = 0;

			//fprintf(stdout, "%s, %o\n", rec.ut_name, dat.st_mode);
			//exit(0);
			show_info(&rec, flg);
		}
	}

	close(ufd);

	return(0);
}

void show_info ( struct utmp *buf, int flag)
{

	fprintf(stdout, "%-8.8s ", buf -> ut_name);
	if ( flag == 1 )
		fprintf(stdout, "+ ");
	else
		fprintf(stdout, "- ");
	fprintf(stdout, "%-8.8s ", buf -> ut_line);
	show_time (buf -> ut_time);
#ifdef SHOWHOST
	fprintf(stdout, "(%s)", buf 	-> ut_host);
#endif

	fprintf(stdout, "\n");
}

void show_time ( time_t timeval )
{

	char *cp = NULL;
	cp 		 = ctime(&timeval);

	fprintf(stdout, "%12.12s", (cp+4));
}
