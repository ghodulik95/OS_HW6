#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include "common.h"

int start(char * username, CLIENT *);
int quit(char * username, CLIENT *);
int add( char * username, int message_num, char * message, CLIENT *);
char * retrieve( char * username, int message_num, CLIENT *);
int delete( char * username, int message_num, CLIENT *);

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
    }else if(strcmp(argv[3], "QUIT") == 0){
        int result = quit(username, cl);
        printf("%d\n", result);
    }else if(strcmp(argv[3], "ADD") == 0){
        int msgNum;
        sscanf (argv[4],"%d",&msgNum);
        int result = add(username, msgNum, argv[5], cl);
        printf("%d\n", result);
    }else if(strcmp(argv[3], "RETRIEVE") == 0){
        int msgNum;
        sscanf (argv[4],"%d",&msgNum);
        char * result = retrieve(username, msgNum,  cl);
        printf("%s\n", result);
    }else if(strcmp(argv[3], "DELETE") == 0){
        int msgNum;
        sscanf (argv[4],"%d",&msgNum);
        int result = delete(username, msgNum,  cl);
        printf("%d\n", result);
    }
	clnt_destroy(cl);
	return 0;
}

int quit(char * username, CLIENT *cl)
{
	struct message_params t;
    t.username = username;
    t.message_num = -1;
    t.message = "NOTHING";
	
	int* result = quit_1(&t, cl);
	if(*result < 0)
	{
		return -1;
	}
	return 0;
}

int start(char * username, CLIENT *cl)
{
	struct message_params t;
    t.username = username;
    t.message_num = -1;
    t.message = "NOTHING";
	
	int* result = start_1(&t, cl);
	if(*result < 0)
	{
		return -1;
	}
	return 0;
}

int add( char * username, int message_num, char * message, CLIENT * cl){
    struct message_params t;
    t.username = username;
    t.message_num = message_num;
    t.message = message;
    int* result = insert_message_1(&t, cl);
	if(*result < 0)
	{
		return -1;
	}
	return 0;
}

char * retrieve( char * username, int message_num, CLIENT * cl)
{
    struct message_params t;
    t.username = username;
    t.message_num = message_num;
    t.message = "NOTHING";
    char ** result = retrieve_message_1(&t, cl);
	return result[0];
}

int delete( char * username, int message_num, CLIENT * cl)
{
    struct message_params t;
    t.username = username;
    t.message_num = message_num;
    t.message = "NOTHING";
    int* result = delete_message_1(&t, cl);
	if(*result < 0)
	{
		return -1;
	}
	return 0;
}