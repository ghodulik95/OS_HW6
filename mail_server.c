#include "common.h"

struct user_list{
    char * usn;
    char ** messages;
    struct user_list *next;
};

struct user_list *users = NULL;
int addUser(char * usn);

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
        users = malloc(sizeof users);
        users->usn = NULL;
        users->messages = NULL;
        users->next = NULL;
    }
    printf("Looking for user %s\n", usn);
    struct user_list *cur = users;
    
    while(cur->next != NULL){
        cur = cur->next;
        printf("%s?\n", cur->usn);
        if(strcmp(cur->usn, usn) == 0){
            printf("Found user\n");
            return -2;
        }
    }
    struct user_list currentUser = {usn, NULL, NULL};
    //currentUser->usn = usn;
   // currentUser->messages = NULL;
    //currentUser->next = NULL;
    cur->next = &currentUser;
    printf("Made new user named %s\n", usn);
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