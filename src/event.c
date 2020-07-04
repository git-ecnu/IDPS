#include "event.h"


void event_display(Event *p)
{
	printf("EventID %c  ", p->EventID);
	printf("EventCate %c  ", p->EventCate);
	printf("SequenceNum %s  ", p->SequenceNum);
	printf("TimeStamp %s  ", p->TimeStamp);
	printf("Source %s  ", p->Source);
	printf("Priority %c  ", p->Priority);
	printf("Reason %s  ", p->Reason);
	printf("CMAC %s  \n", p->CMAC);
}

