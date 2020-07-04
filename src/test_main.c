#include "time.h"
#include <stdio.h>

int main()
{
	char currentTime[20];
	get_time(currentTime);
	printf("%s\n", currentTime);
}
