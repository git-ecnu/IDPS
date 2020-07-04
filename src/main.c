#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include "time.h"
#include "queue.h"
#include "event.h"
#include "log.h"
typedef struct {
	int *number1;

} test;





DEFINE_Q_GET(queue_get_event, Event)
DEFINE_Q_DESTROY(queue_destroy_complete_event, Event)


queue_t *q;

void free_event(Event *q) {
	if(q != NULL)
	{
		free(q);
	}
}


void unsorted_mode() {

	int i = 0;
	while(1)
	{

		Event *s1 = (Event *)malloc(sizeof(Event));
		s1->EventID = '0' + i % 10;
		s1->EventCate = '0' + i % 10;
		strcpy(s1->SequenceNum, "d");
		strcpy(s1->TimeStamp, "d");
		strcpy(s1->Source, "d");
		strcpy(s1->Reason, "d");
		strcpy(s1->CMAC, "d");
		queue_put_wait(q, s1);
		
		sleep(1);
		log_info("add %d in the queue, size of Evnet %ld,the queue size is %d", i,sizeof(*s1),queue_elements(q));
		i++;
	}

	
	
	queue_destroy_complete_event(q, free_event);
}

void get_number()
{
    Event *s1;
	while(1)
	{
		while(!queue_get_event(q, &s1))
		{
			event_display(s1);
			free(s1);
			sleep(2);
		}
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
	pthread_create(&thread, NULL, (void *)&get_number, (void *)message);
	unsorted_mode();
	
	return 0;
}
