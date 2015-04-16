#include "mailbox.h"
#include <stdio.h>
#include <sys/unistd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_NUM_USERS 50
#define MAX_NUM_MESSAGES 100
#define MAX_MESSAGE_LEN 80
#define MAX_USERNAME_LEN 20

#define PRINT_MESSAGES 1

void printMessage(char * message){
    if(PRINT_MESSAGES == 1){
        printf("%s\n", message);
    }
}