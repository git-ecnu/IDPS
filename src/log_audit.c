#include "log_audit.h"
#include "queue.h"
#include "event.h"
#include <string.h>
#include "time.h"

extern queue_t *q;

void setEvent(Event *p, char cate)
{
	p->EventID = '7';
	p->EventCate = cate;
	strcpy(p->SequenceNum, "d");
	sprintf(p->TimeStamp, "%d%d", get_min(), get_sec());
	strcpy(p->Source, "d");
	p->Priority='d';
	strcpy(p->Reason, "d");
	strcpy(p->CMAC, "d");
}

void log_audit()
{
	log_info("log audit, handle the log file");
	FILE *iptablesLogHandle;
	if((iptablesLogHandle = fopen("../log/iptables.log", "r")) == NULL)
	{
		log_info("open the log file fail");
		return;
	}

	char oneLine[512];
	while(fgets(oneLine, 510, iptablesLogHandle) != NULL)
	{
		char *matchContent;
		if((matchContent = strstr(oneLine, "IDPS")) == NULL)
			continue;
		else
		{
			Event *logEvent = (Event *)malloc(sizeof(Event));
			logEvent->EventID = '7';
			setEvent(logEvent, matchContent[8]);
			queue_put_wait(q, logEvent);
		}
	}
	log_info("log audit, handle the log file  end");
	return;
}
