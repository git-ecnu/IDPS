#include "event.h"


void event_display(Event *p)
{
	printf("EventID %c  ", p->EventID);
	printf("EventCate %c  ", p->EventCate);
	printf("SequenceNum %s  ", p->SequenceNum);
	printf("TimeStamp %c%c%c%c  ", p->TimeStamp[0],  p->TimeStamp[1],p->TimeStamp[3],  p->TimeStamp[3]);
	printf("Source %s  ", p->Source);
	printf("Priority %c  ", p->Priority);
	printf("Reason %s  ", p->Reason);
	printf("CMAC %s  \n", p->CMAC);
}

void free_event(Event *q) {
	if(q != NULL)
	{
		free(q);
	}
}
