#ifndef __EVENT_H__
#define __EVENT_H__
#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char EventID;
	char EventCate;
	unsigned int SequenceNum;
	unsigned int TimeStamp;
	int Source;
	char Priority;
	char Reason[13];
	char CMAC[4];
} Event;

void event_display(Event *p);
void free_event(Event *q);



#endif
