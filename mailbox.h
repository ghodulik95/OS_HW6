/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _MAILBOX_H_RPCGEN
#define _MAILBOX_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct message_params {
	char *username;
	int message_num;
	char *message;
};
typedef struct message_params message_params;

#define MAILBOXPROG 0x84467008
#define MAILBOXVERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define START 1
extern  int * start_1(struct message_params *, CLIENT *);
extern  int * start_1_svc(struct message_params *, struct svc_req *);
#define QUIT 2
extern  int * quit_1(struct message_params *, CLIENT *);
extern  int * quit_1_svc(struct message_params *, struct svc_req *);
#define INSERT_MESSAGE 3
extern  int * insert_message_1(struct message_params *, CLIENT *);
extern  int * insert_message_1_svc(struct message_params *, struct svc_req *);
#define RETRIEVE_MESSAGE 4
extern  char ** retrieve_message_1(struct message_params *, CLIENT *);
extern  char ** retrieve_message_1_svc(struct message_params *, struct svc_req *);
#define LIST_ALL_MESSAGES 5
extern  char ** list_all_messages_1(struct message_params *, CLIENT *);
extern  char ** list_all_messages_1_svc(struct message_params *, struct svc_req *);
#define DELETE_MESSAGE 6
extern  int * delete_message_1(struct message_params *, CLIENT *);
extern  int * delete_message_1_svc(struct message_params *, struct svc_req *);
extern int mailboxprog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define START 1
extern  int * start_1();
extern  int * start_1_svc();
#define QUIT 2
extern  int * quit_1();
extern  int * quit_1_svc();
#define INSERT_MESSAGE 3
extern  int * insert_message_1();
extern  int * insert_message_1_svc();
#define RETRIEVE_MESSAGE 4
extern  char ** retrieve_message_1();
extern  char ** retrieve_message_1_svc();
#define LIST_ALL_MESSAGES 5
extern  char ** list_all_messages_1();
extern  char ** list_all_messages_1_svc();
#define DELETE_MESSAGE 6
extern  int * delete_message_1();
extern  int * delete_message_1_svc();
extern int mailboxprog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_message_params (XDR *, message_params*);

#else /* K&R C */
extern bool_t xdr_message_params ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_MAILBOX_H_RPCGEN */