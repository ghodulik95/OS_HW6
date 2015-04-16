

#include "mailbox.h"
#include <stdio.h>
#include <sys/unistd.h>
#include <time.h>

int rand0to2()
{
    short randval = 3;

    while (randval > 2)
        randval = (rand() & 0x0300) >> 8;
    return (int)randval;
}

void printinfo()
{
	char hostname[128];

	gethostname(hostname, sizeof hostname);

	char            fmt[64], buf[64];
    struct timeval  tv;
    struct tm       *tm;

    gettimeofday(&tv, NULL);
    if((tm = localtime(&tv.tv_sec)) != NULL)
    {
            strftime(fmt, sizeof fmt, "%H:%M:%S.%%03u", tm);
            snprintf(buf, sizeof buf, fmt, tv.tv_usec);
    }

	printf("%s-%s-%d: ", buf, hostname, getpid());
}
