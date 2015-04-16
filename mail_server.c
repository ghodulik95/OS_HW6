#include "common.h"

struct user_list{
    char * username;
    char ** messages;
    struct user_list *next;
};

struct user_list *users = NULL;
int addUser(char * username);

int *start_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
	printf("%s\n", mp->username);
	static int response;
	response = addUser(mp->username);
	return(&response);	
}

int addUser(char * username){
    if(users == NULL){
        users = malloc(sizeof *users);
        users->username = NULL;
        users->messages = NULL;
        users->next = NULL;
    }
    printf("Looking for user %s\n", username);
    struct user_list *cur = users;
    
    while(cur->next != NULL){
        cur = cur->next;
        printf("%s?\n", cur->username);
        if(strcmp(cur->username, username) == 0){
            printf("Found user\n");
            return -2;
        }
    }
    struct user_list *currentUser = malloc(sizeof users);
    currentUser->username = username;
    currentUser->messages = NULL;
    currentUser->next = NULL;
    cur->next = currentUser;
    printf("Made new user\n");
    return 0;
}

int *quit_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
	printf("Woop1\n");
	fflush(NULL);
	exit(0);
}

int *insert_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    printf("Woop2\n");
	fflush(NULL);
	exit(0);
}
char **retrieve_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    printf("Woop3\n");
	fflush(NULL);
	exit(0);
}
char **list_all_messages_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    printf("Woop4\n");
	fflush(NULL);
	exit(0);
}
int *delete_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    printf("Woop5\n");
	fflush(NULL);
	exit(0);
}