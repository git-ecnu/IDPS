#ifndef __EVENT_H__
#define __EVENT_H__
#include <stdio.h>

typedef struct {
	char EventID;
	char EventCate;
	char SequenceNum[4];
	char TimeStamp[4];
	char Source[4];
	char Priority;
	char Reason[13];
	char CMAC[4];
} Event;

void event_display(Event *p);



#endif
