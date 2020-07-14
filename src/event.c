#include "event.h"


void event_display(Event *p)
{
	printf("EventID %c  ", p->EventID);
	printf("EventCate %c  ", p->EventCate);
	printf("SequenceNum %d  ", p->SequenceNum);
	printf("TimeStamp %d  ", p->TimeStamp);
	printf("Source %d  ", p->Source);
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
