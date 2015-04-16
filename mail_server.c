#include "common.h"

//Array to store usernames
char users[MAX_NUM_USERS][MAX_USERNAME_LEN];
//Array to store messages
char messages[MAX_NUM_USERS][MAX_NUM_MESSAGES][MAX_MESSAGE_LEN];
//Change after data is initialized
int init = -1;

int getUserNum(char * usn);
int addMessage(char * usn, int msgNum, char * message);
char * retMessage(char * usn, int msgNum);
int delMessage(char * usn, int msgNum);

//Sets all messages to "" for user at index userNum
void clearMessages(int userNum)
{
    int j;
    //Go to each message and copy "" to it
    for(j = 0; j < MAX_NUM_MESSAGES; j++){
        strcpy(messages[userNum][j], "");
    }
}

//Initialized the data
void initialize(){
    int i;
    //Set all usernames to ""
    for(i = 0; i < MAX_NUM_USERS; i++){
        strcpy(users[i], "");
        //Set all messages to ""
        clearMessages(i);
    }
    init = 0;
}

//Adds a user (if does not exist)
int *start_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
	static int response;
	response = addUser(usn);
	return(&response);	
}

//Adds a user with name usn if not already exists
int addUser(char * usn){
    //If first call, initialize the data
    if(init == -1){
        printf("Initializing data to empty\n");
        initialize();
    }
    //If the username is too long, print error
    if(strlen(usn) + 1 > MAX_USERNAME_LEN){
        printf("Username %s is too long\n", usn);
        return -1;
    }
    int i = 0;
    printf("Looking for an empty space to put %s\n", usn);
    //Find a username space that is "" to put the user
    while(strcmp(users[i], "") != 0 && i < MAX_NUM_USERS){
        printf("Checking user number %d\n", i);
        if(strcmp(users[i], usn) == 0){
            printf("User %s found already - will not create new user\n", usn);
            return -1;
        }
        i++;
    }
    printf("Putting %s at %d\n", usn, i);
    strcpy(users[i], usn);
    return i;
}

//Calls removeUser to remove the user
int *quit_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
	char * usn = mp->username;
	static int response;
	response = removeUser(usn);
	return(&response);	
}

//Remove user wiht username usn
int removeUser(char * usn){
    if(init == -1){
        printf("Data not initialized yet\n");
        return -1;
    }
    //int i = 0;
    //while(strcmp(users[i], usn) != 0 && i < MAX_NUM_USERS){
     //   i++;
    //}
    //Get the user's number
    int i = getUserNum(usn);
    //if found
    if(i > -1 ){
        //copy "" to the user space
        printf("Found user %s at %d -- removing\n", usn, i);
        strcpy(users[i], "");
        //Set all messages to ""
        clearMessages(i);
        return i;
    }else{
        return -1;
    }
}

//Insert a message
int *insert_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    //Get message params
    char * usn = mp->username;
    int msgNum = mp->message_num;
    char * msg = mp->message;
    static int result;
    //call the message
    result = addMessage(usn, msgNum, msg);
    return(&result);
}

//Gets the index of a user
int getUserNum(char * usn)
{
    int i = 0;
    //Check each user until this user is found
    while(strcmp(users[i], usn) != 0 && i < MAX_NUM_USERS){
        i++;
    }
    //If the resulting index contains this user
    if(strcmp(users[i], usn) == 0 ){
        //return that index
        return i;
    }
    //Otherwise, return -1
    else{
        return -1;
    }
}

int addMessage(char * usn, int msgNum, char * message)
{
    //Check if data is initialized
    if(init == -1){
        printf("Not initialized\n");
        return -1;
    }
    //Check if message index number is valid
    if(msgNum < 0 || msgNum >= MAX_NUM_MESSAGES){
        printf("Invalid message number %d\n", msgNum);
        return -2;
    }
    //Checks if message is not too long
    if(strlen(message) + 1 > MAX_MESSAGE_LEN){
        printf("Message is too long\n");
        return -4;
    }
    //Get the user index
    int userNum = getUserNum(usn);
    if(userNum == -1){
        return -1;
    }
    printf("User %s found at $d\n", usn, userNum);
    //Get the pointer to the message location
    char * origMessage = messages[userNum][msgNum];
    //Check if there is already a message
    if(strcmp(origMessage, "") == 0){
        //If its empty, add the message
        strcpy(origMessage, message);
        printf("Put message %s at %d\n", message, msgNum);
        return 0;
    }else{
        //If theres already a message here, print error
        printf("There is already a message at %d\n",msgNum);
        return -3;
    }
    
}

//Retrieve a message
char **retrieve_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
    int msgNum = mp->message_num;
    static char * result;
    result = retMessage(usn, msgNum);
    return(&result);
}

//Retrieve a message from data
char * retMessage(char * usn, int msgNum)
{
    //Check if data is initialized
    if(init == -1){
        printf("Not initialized\n");
        return -1;
    }
    //Check if message index is vald
    if(msgNum < 0 || msgNum >= MAX_NUM_MESSAGES){
        printf("Invalid message number %d\n", msgNum);
        return -2;
    }
    //Get the user index
    int userNum = getUserNum(usn);
    if(userNum == -1){
        return -1;
    }
    printf("User %s found at %d\n", usn, userNum);
    //get the message pointerm and write "" to it
    char * origMessage = messages[userNum][msgNum];
    printf("%s\n", origMessage);
    return origMessage;
}

//List all messages of a user -- FUN STRING STUFF
char **list_all_messages_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    //I will return a pointer to a string that is all the messages, separated by newlines
    //So, I need to allocate enough memory for the case that the user has every message filled to the max
    //I will be replacing each '\0' with '\n' except the last one, so I do not need more space than that
    char * all_messages = malloc(sizeof(char)*(MAX_NUM_MESSAGES*MAX_MESSAGE_LEN));
    
    //Get necessary parameters
    char * usn = mp->username;
    int userNum = getUserNum(usn);
    
    //temporary pointer for pointer manipulations
    char * temp;
    //the current message index
    int currentMsgNum;
    //The length of all_messages
    int end = 0;
    //Go through each message
    for(currentMsgNum = 0; currentMsgNum < MAX_NUM_MESSAGES; currentMsgNum++){
        char * msg = messages[userNum][currentMsgNum];
        //If that message is not emppty
        if(strcmp(msg, "") != 0){
            //Copy it to the end of all_messages
            temp = all_messages + end;
            strcpy(temp, msg);
            //Overwrite the ending '\0' with '\n'
            end = end + strlen(msg);
            temp = all_messages + end;
            *temp = '\n';
            end += 1;
        }
    }
    //End the string with '\0'
    temp = all_messages + end;
    *temp = '\0';
    
    return &all_messages;
}

//Delete a message
int *delete_message_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
    char * usn = mp->username;
    int msgNum = mp->message_num;
    static int * result;
    result = delMessage(usn, msgNum);
    return(&result);
}

//Delete a message
int delMessage(char * usn, int msgNum)
{
    //Check if data is initialized
    if(init == -1){
        printf("Not initialized\n");
        return -1;
    }
    //Check if message index is valid
    if(msgNum < 0 || msgNum >= MAX_NUM_MESSAGES){
        printf("Invalid message number %d\n", msgNum);
        return -2;
    }
    //Get the user index
    int userNum = getUserNum(usn);
    if(userNum == -1){
        return -1;
    }
    printf("User %s found at %d\n", usn, userNum);
    //Get the original message pointer
    char * origMessage = messages[userNum][msgNum];
    printf("Deleting %s\n", origMessage);
    //Write "" to it
    strcpy(origMessage, "");
    return 0;
}