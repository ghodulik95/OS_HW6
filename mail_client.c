#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

int start(char * username, CLIENT *);

int main(int argc, char**argv)
{
	srand(time(NULL));
	CLIENT *cl;
	
	// validate input
	if(argc < 4 || argc >6)
	{
		printf("Usage: ./client HOSTNAME username cmd [messageno] [message]\n");
		return 1;
	}
	
	// create client
	char *server_hostname = argv[1];
	cl = clnt_create(server_hostname, MAILBOXPROG, MAILBOXVERS, "udp");
	if(cl == NULL) 
	{
		clnt_pcreateerror("Error creating client");
		exit(EXIT_FAILURE);
	}
    char *username = argv[2];
    
    if(strcmp(argv[3], "START") == 0){
        int result = start(username, cl);
        printf("%d\n", result);
    }else{
        printf("NOOOOOOOP\n");
    }
	clnt_destroy(cl);
	return 0;
}

int start(char * username, CLIENT *cl)
{
	struct message_params t = {username, -1, "NOTHING"};
	
	int* result = start_1(&t, cl);
	if(*result < 0)
	{
		return -1;
	}
	return 0;
}