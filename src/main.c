#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "time.h"
#include "queue.h"
#include "event.h"
#include "log_audit.h"
#include "log.h"


DEFINE_Q_GET(queue_get_event, Event)
DEFINE_Q_DESTROY(queue_destroy_complete_event, Event)


queue_t *q;



	
void get_number()
{
    Event *s1;
	while(1)
	{	
		while(!queue_get_event(q, &s1))
		{
			sleep(1);
			event_display(s1);
			free(s1);
		}
		sleep(1);
		if( queue_empty(q) == 0)
			continue;
		else
			return;
	}
}

int main(int argc, char *argv[]) {

/* Initialize the log file */

	char currentTime[20];
	get_time(currentTime);
	char logFile[40];
	sprintf(logFile, "/tmp/idps_log_%s.txt", currentTime);
	FILE *logHandle = fopen(logFile, "ab");
	log_add_fp(logHandle, 1);
/* End Initialize the log file */


	log_info("IDPS have lunch");
	
	q = queue_create_limited(30);

	pthread_t thread;
	char * message;
	
	pthread_create(&thread, NULL, (void *)&log_audit, (void *)message);
	get_number();
	queue_destroy_complete_event(q, free_event);
	return 0;
}
