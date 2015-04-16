#include "common.h"

struct user_list{
    char * usn;
    char ** messages;
    struct user_list *next;
};

struct user_list *users = NULL;
int addUser(char * usn);
int removeUser(char * usn);

int *start_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
	printf("%s\n", usn);
	static int response;
	response = addUser(usn);
	return(&response);	
}

int addUser(char * usn){
    if(users == NULL){
        struct user_list currentUser;
        currentUser.usn = NULL;
        currentUser.messages = NULL;
        currentUser.next = NULL;
        users = &currentUser;
    }
    printf("Looking for user %s\n", usn);
    struct user_list *cur = users;
    
    while(cur->next != NULL){
        cur = cur->next;
        printf("%s?\n", cur->usn);
        if(strncmp(cur->usn, usn, 20) == 0){
            printf("Found user\n");
            return -2;
        }
    }
    struct user_list currentUser;// = {usn, NULL, NULL};
    currentUser.usn = malloc(sizeof(char)*20);
    strncpy(currentUser.usn, usn, 20);
    currentUser.messages = NULL;
    currentUser.next = NULL;
    cur->next = &currentUser;
    printf("Made new user named %s\n", usn);
    return 0;
}

int *quit_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
	char * usn = mp->username;
	printf("%s\n", usn);
	static int response;
	response = removeUser(usn);
	return(&response);	
}

int removeUser(char * usn){
    if(users == NULL){
        return -1;
    }
    printf("Looking for user %s\n", usn);
    struct user_list *cur = users;
    
    while(cur->next != NULL && cur->next->usn != NULL){
        
        struct user_list *next = cur->next;
        
        printf("Look.. %s\n", next);
        printf("%s?\n", next->usn);
        if(strncmp(next->usn, usn, 20) == 0){
            printf("Found user\n");
            cur->next = next->next;
            return -2;
        }
        printf("Not this guy\n");
        cur = cur->next;
    }
    return -1;
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