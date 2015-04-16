Recommended usage:

1. Compile everything by calling "make"
2. If the files client1_commands.sh and client2_commands.sh do not have execute permissions, grant those permissions with the command
    chmod 0777 client*.sh
3. Call ./mail_server on eecslinab3.case.edu.  I did this by ssh-ing in and calling it, but there are multiple ways to do this.
4. On eecslinab[2,7].case.edu call either of the .sh files.  Preferably, do not call either file at the same time, or the output
    may not be desired.
5 (optional).  If you want to try and run your own commands, the usage is:
    ./mail_client HOSTNAME USERNAME COMMAND MESSAGENUM MESSAGE
    If you are following the recommended usage, HOSTNAME is eecslinab3.case.edu.
    The username is the user's name - different users must have unique names.
    COMMAND is one of the following:
        START : Add this user to the server
        QUIT : Remove this user from the server
        LIST : List all messages of this user
        DELETE : Delete the message with index MESSAGENUM
        ADD : Insert MESSAGE into index MESSAGENUM
        RETRIEVE : Retrieve the message with index MESSAGENUM
    MESSAGENUM is the index of a message for this user; note: message 1 is a different message for each user.
        MESSAGENUM param is not required for START, QUIT, or LIST commands.
    MESSAGE is the actual message text.  Note that this should be surrounded by "".  MESSAGE is only required for ADD.
    
Note that client1_commands are some simple commands for one client, whereas client2_commands runs commands for two
clients at the same time.

I have output for the .sh files in client1_commands.txt and client2_commands.txt.  These are copied and pasted from the terminal because
I include both the output of the server and the output of the client.
