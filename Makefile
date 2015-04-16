CC = clang
# -g : allows use of GNU Debugger
# -Wall : show all warnings
CFLAGS = -g -Wall
LIBS = # None yet...
CSOURCE = mail_client.c mailbox_clnt.c mailbox_xdr.c
SSOURCE = mail_server.c mailbox_svc.c mailbox_xdr.c
RPCSRC = mailbox.x
RPCGEN = mailbox.h mailbox_clnt.c mailbox_svc.c mailbox_xdr.c
CLIENT = mail_client
SERVER = mail_server

all: $(CLIENT) $(SERVER)

mail_client: $(CSOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(CLIENT) $(CSOURCE)

mail_server: $(SSOURCE) $(RPCGEN)
	$(CC) $(LIBS) $(CFLAGS) -o $(SERVER) $(SSOURCE)

$(RPCGEN): $(RPCSRC)
	rpcgen $(RPCSRC)

# 'clean' rule for remove non-source files
# To use, call 'make clean'
# Note: you don't have to call this in between every
# compilation, it's only in case you need to
# clean out your directory for some reason.
clean:
	@# Using the '@' sign suppresses echoing
	@# the line while the command is run
	rm -f $(CLIENT) $(SERVER) $(RPCGEN)