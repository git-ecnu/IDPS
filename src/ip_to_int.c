#include "ip_to_int.h"
 
 
const int IP_STR_LEN= 15;
const int TOKEN_LEN = 4;
     
unsigned int ip2int(const char* ips){
	unsigned int ipInt = 0;
    int tokenInt = 0;
    char * token;
	char *ipStr = malloc(IP_STR_LEN);
	strcpy(ipStr, ips);
    token = strtok(ipStr, ".");
    int i = 3;
    while(token != NULL){
//      tokenInt = strtol(token, NULL, 10); //strtol comes from stdlib.h
        tokenInt = atoi(token);
        ipInt += tokenInt * pow(256, i);
        token = strtok(NULL, ".");
        i--;
    }
	free(ipStr);
    return ipInt;
}
const char* int2ip(unsigned int ipInt){
    int tokenInt = 0;
    unsigned int leftValue = ipInt;
    char * ipStr = malloc(IP_STR_LEN);
    char * ipToken = malloc(TOKEN_LEN);
    for(int i=0; i<4; i++){
        int temp = pow(256, 3-i);
        tokenInt = leftValue / temp;
        leftValue %= temp;
//      itoa(tokenInt, ipToken, 10); //non-standard function
        snprintf(ipToken, TOKEN_LEN, "%d", tokenInt);
        if(i != 3){
            strcat(ipToken, ".");
        }
        strncat(ipStr, ipToken, strlen(ipToken));
    }
    return ipStr;
}
