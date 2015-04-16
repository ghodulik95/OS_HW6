#include "common.h"

char users[50][20];
char messages[50][100][80];
int init = -1;

int getUserNum(char * usn);
int addMessage(char * usn, int msgNum, char * message);
char * retMessage(char * usn, int msgNum);
int delMessage(char * usn, int msgNum);

void initialize(){
    int i;
    for(i = 0; i < 50; i++){
        strcpy(users[i], "");
        int j;
        for(j = 0; j < 100; j++){
            strcpy(messages[i][j], "");
        }
    }
    init = 0;
}

int *start_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
	//printf("%s\n", usn);
	static int response;
	response = addUser(usn);
	return(&response);	
}

int addUser(char * usn){
    if(init == -1){
        printf("Initializing\n");
        initialize();
    }
    int i = 0;
    printf("Looking\n");
    while(strcmp(users[i], "") != 0 && i < 50){
        printf("Checking %d\n", i);
        if(strcmp(users[i], usn) == 0){
            printf("User found - will not create new user\n");
            return -1;
        }
        i++;
    }
    printf("Putting at %d\n", i);
    strncpy(users[i], usn, 20);
    return i;
}

int *quit_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
	char * usn = mp->username;
	//printf("%s\n", usn);
	static int response;
	response = removeUser(usn);
	return(&response);	
}

int removeUser(char * usn){
    if(init == -1){
        return -1;
    }
    int i = 0;
    while(strcmp(users[i], usn) != 0 && i < 50){
        i++;
    }
    if(strcmp(users[i], usn) == 0 ){
        printf("Found\n");
        strcpy(users[i], "");
        return i;
    }else{
        return -1;
    }
}

int *insert_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
    int msgNum = mp->message_num;
    char * msg = mp->message;
    static int result;
    result = addMessage(usn, msgNum, msg);
    return(&result);
}

int getUserNum(char * usn)
{
    int i = 0;
    while(strcmp(users[i], usn) != 0 && i < 50){
        i++;
    }
    if(strcmp(users[i], usn) == 0 ){
        printf("Found\n");
        return i;
    }else{
        return -1;
    }
}

int addMessage(char * usn, int msgNum, char * message)
{
    if(init == -1){
        printf("Not initialized\n");
        return -1;
    }
    if(msgNum < 0 || msgNum >= 100){
        printf("Invalid message number %d\n", msgNum);
        return -2;
    }
    printf("Adding message %s\n", message);
    int userNum = getUserNum(usn);
    printf("User Num is %d", userNum);
    if(userNum == -1){
        return -1;
    }
    char * origMessage = messages[userNum][msgNum];
    if(strcmp(origMessage, "") == 0){
        strcpy(origMessage, message);
        return 0;
    }else{
        return -3;
    }
    
}

char **retrieve_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
    int msgNum = mp->message_num;
    static char * result;
    result = retMessage(usn, msgNum);
    return(&result);
}

char * retMessage(char * usn, int msgNum)
{
    if(init == -1){
        printf("Not initialized\n");
        return -1;
    }
    if(msgNum < 0 || msgNum >= 100){
        printf("Invalid message number %d\n", msgNum);
        return -2;
    }
    int userNum = getUserNum(usn);
    printf("User Num is %d\n", userNum);
    if(userNum == -1){
        return -1;
    }
    char * origMessage = messages[userNum][msgNum];
    printf("%s\n", origMessage);
    return origMessage;
}

char **list_all_messages_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * all_messages = malloc(sizeof(char)*(100*80 + 100));
    char * usn = mp->username;
    int userNum = getUserNum(usn);
    char * temp;
    int currentMsgNum;
    int end = 0;
    for(currentMsgNum = 0; currentMsgNum < 100; currentMsgNum++){
        char * msg = messages[userNum][currentMsgNum];
        if(strcmp(msg, "") != 0){
            temp = all_messages + end;
            strcpy(temp, msg);
            end = end + strlen(msg);
            temp = all_messages + end;
            *temp = '\n';
            end += 1;
        }
    }
    temp = all_messages + end;
    *temp = '\0';
    
    return &all_messages;
}
int *delete_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
    int msgNum = mp->message_num;
    static int * result;
    result = delMessage(usn, msgNum);
    return(&result);
}

int delMessage(char * usn, int msgNum)
{
    if(init == -1){
        printf("Not initialized\n");
        return -1;
    }
    if(msgNum < 0 || msgNum >= 100){
        printf("Invalid message number %d\n", msgNum);
        return -2;
    }
    int userNum = getUserNum(usn);
    printf("User Num is %d\n", userNum);
    if(userNum == -1){
        return -1;
    }
    char * origMessage = messages[userNum][msgNum];
    if(strcmp(origMessage, "") == 0){
        printf("No message at %d\n", msgNum);
        return -3;
    }
    printf("Deleting %s\n", origMessage);
    strcpy(origMessage, "");
    return origMessage;
}