#include "log_audit.h"
#include "queue.h"
#include <string.h>

int main()
{
	FILE *iptablesLogHandle;
	if((iptablesLogHandle = fopen("../log/iptables.log", "r")) == NULL)
		return 1;
	char oneLine[2048];
	printf("debug 1\n");
	fgets(oneLine, 2047, iptablesLogHandle);
	printf("debug 2\n");
	printf("%s\n", oneLine);
	sleep(1);
	printf("debug 3\n");

	char *test;
	test = strstr(oneLine, "IDPS");
	printf("%s\n", test);
	
	
};


