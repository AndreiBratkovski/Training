#include <stdio.h>
#include <stdlib.h>
#include <utmp.h>
#include <fcntl.h>
#include <unistd.h>

#define SHOWHOST
void show_info( struct utmp *);

int main()
{
	struct utmp 	rec;            /* read info into here */
	int    			ufd;		   /* read from this descriptor */
	int 			len = sizeof(rec);

	if ( (ufd = open(UTMP_FILE, O_RDONLY)) == -1 )
	{
		perror(UTMP_FILE);
		exit(1);
	}

	while(read (ufd, &rec, len) == len)
	{
		show_info(&rec);
	}

	close(ufd);

	return(0);
}

void show_info ( struct utmp *buf)
{
	fprintf(stdout, "%-8.8s ", buf -> ut_name);
	fprintf(stdout, "%-8.8s ", buf -> ut_line);
	fprintf(stdout, "%10ds ", buf -> ut_time);
#ifdef SHOWHOST
	fprintf(stdout, "(%s)", buf 	-> ut_host);
#endif

	fprintf(stdout, "\n");
}
