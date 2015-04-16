struct message_params
{
	string username<20>;
    int message_num;
    string message<80>;
};

program MAILBOXPROG
{
	version MAILBOXVERS
	{
		int START(struct message_params) = 1;
		int QUIT(struct message_params) = 2;
        int INSERT_MESSAGE(struct message_params) = 3;
        string RETRIEVE_MESSAGE(struct message_params) = 4;
        string LIST_ALL_MESSAGES(struct message_params) = 5;
        int DELETE_MESSAGE(struct message_params) = 6;
	} = 1;
} = 0x84467008;