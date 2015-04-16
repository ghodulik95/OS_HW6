#include "common.h"

static int tCount = -1, pCount = -1, mCount = -1;

int *start_1_svc(struct message_params *mp, struct svc_req *rqstp)
{
	
	printf("%s\n", mp->username);
	static int response;
	response = 1;
	return(&response);	
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