#include "common.h"

//The client functions
int start(char * username, CLIENT *);
int quit(char * username, CLIENT *);
int add( char * username, int message_num, char * message, CLIENT *);
char * retrieve( char * username, int message_num, CLIENT *);
int delete( char * username, int message_num, CLIENT *);
char * listall(char * username, CLIENT *);

//Cleint main takes args HOSTNAME COMMAND [MESSAGENUM, MESSAGE]
int main(int argc, char**argv)
{
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
    
    //Call a function based on the input command
    if(strcmp(argv[3], "START") == 0){
        //Call the start function
        int result = start(username, cl);
        printf("%d\n", result);
    }else if(strcmp(argv[3], "QUIT") == 0){
        //Call the quit function
        int result = quit(username, cl);
        printf("%d\n", result);
    }else if(strcmp(argv[3], "ADD") == 0){
        //Get the message number from argument string
        int msgNum;
        sscanf (argv[4],"%d",&msgNum);
        //Call Add message
        int result = add(username, msgNum, argv[5], cl);
        printf("%d\n", result);
    }else if(strcmp(argv[3], "RETRIEVE") == 0){
        //Get the message number from argument string
        int msgNum;
        sscanf (argv[4],"%d",&msgNum);
        //all Retrieve message
        char * result = retrieve(username, msgNum,  cl);
        printf("%s\n", result);
    }else if(strcmp(argv[3], "DELETE") == 0){
        //Get the message number from argument string
        int msgNum;
        sscanf (argv[4],"%d",&msgNum);
        //Call Delete
        int result = delete(username, msgNum,  cl);
        printf("%d\n", result);
    }else if(strcmp(argv[3], "LIST") == 0){
        //Call list all
        char * result = listall(username, cl);
        printf("%s\n", result);
    }else{
        printf("Unrecognized command %s\n", argv[3]);
        clnt_destroy(cl);
        return -1;
    }
	clnt_destroy(cl);
	return 0;
}

//Call Quit 
int quit(char * username, CLIENT *cl)
{
    //Build the message params - message_num and message are dummy values
	struct message_params t;
    t.username = username;
    t.message_num = -1;
    t.message = "NOTHING";
	
	int* result = quit_1(&t, cl);
    return *result;
	
}

//Call start
int start(char * username, CLIENT *cl)
{
    //Build the message params - message_num and message are dummy values
	struct message_params t;
    t.username = username;
    t.message_num = -1;
    t.message = "NOTHING";
	
	int* result = start_1(&t, cl);
    return * result;
	
}

//Call insert_message (add message - hence add)
int add( char * username, int message_num, char * message, CLIENT * cl){
    //Build the message params
    struct message_params t;
    t.username = username;
    t.message_num = message_num;
    t.message = message;
    int* result = insert_message_1(&t, cl);
	return *result;
}

//Call retrieve message
char * retrieve( char * username, int message_num, CLIENT * cl)
{
    //Build the message params - message is dummy value
    struct message_params t;
    t.username = username;
    t.message_num = message_num;
    t.message = "NOTHING";
    char ** result = retrieve_message_1(&t, cl);
	return result[0];
}

//Call delete message
int delete( char * username, int message_num, CLIENT * cl)
{
    //Build the message params - message is dummy value
    struct message_params t;
    t.username = username;
    t.message_num = message_num;
    t.message = "NOTHING";
    int* result = delete_message_1(&t, cl);
	return *result;
}

//Call list all messages
char * listall(char * username, CLIENT * cl)
{
    //Build message params
    struct message_params t;
    t.username = username;
    t.message_num = -1;
    t.message = "NOTHING";
    //Call list all
    char ** result = list_all_messages_1(&t, cl);
	return result[0];
}