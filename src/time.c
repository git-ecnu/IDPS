#include "time.h"

void get_time(char *currentTime)
{
	time_t timep;
	struct tm *p;
	time(&timep);
	p = gmtime(&timep);

	sprintf(currentTime, "%d_%d_%d",1900+p->tm_year, 1+p->tm_mon, p->tm_mday);
}
