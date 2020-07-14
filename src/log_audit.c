#include <string.h>
#include <time.h>
#include "log_audit.h"
#include "queue.h"
#include "event.h"
#include "time.h"
#include "ip_to_int.h"

extern queue_t *q;
unsigned 
int seqNum = 1;
void setEvent(Event *p, char cate, const char* ipaddress)
{
	p->EventID = '7';
	p->EventCate = cate;
	p->SequenceNum = seqNum++;
	p->TimeStamp = (unsigned int)time(NULL);
	p->Source = ip2int(ipaddress);
	if(cate == '1' || cate == '2' || cate == '3' || cate == '7' || cate == '9' || cate == 'b')
		p->Priority='1';
	else if(cate == '4')
		p->Priority='4';
	else if(cate == '5')
		p->Priority='2';
	else if(cate == '6')
		p->Priority='4';
	else if(cate == '8')
		p->Priority='4';
	else if(cate == 'a')
		p->Priority='3';
	else
		p->Priority='0';
	strncpy(p->Reason, "empty", 13);
	strncpy(p->CMAC, "9c", 4);
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
		char *matchSRC;
		char ipaddress[16];
		if((matchContent = strstr(oneLine, "IDPS")) == NULL)
			continue;
		else
		{
			Event *logEvent = (Event *)malloc(sizeof(Event));
			logEvent->EventID = '7';

			if((matchSRC = strstr(oneLine, "SRC")) != NULL)
			{
				int i = 4;
				while( *(matchSRC+i) != ' ')
				{
					ipaddress[i-4] = *(matchSRC+i);
					i++;
				}
				ipaddress[i-4] = '\0';
			}
			else
			{
				strcpy(ipaddress, "0.0.0.0");
			}
			//printf("%s\n", ipaddress);
			setEvent(logEvent, matchContent[8], ipaddress);
			queue_put_wait(q, logEvent);
		}
	}
	log_info("log audit, handle the log file  end");
	return;
}
