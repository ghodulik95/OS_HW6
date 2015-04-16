#FOR eecslinab2 or eecslinab 7 -- eecslinab3 should run the server
USN="JIM"
echo "Starting client $USN"
./mail_client eecslinab3.case.edu $USN START

echo "Adding 3 messages to $USN's mailbox"
./mail_client eecslinab3.case.edu $USN ADD 0 "0th message woot w00000t"
./mail_client eecslinab3.case.edu $USN ADD 1 "1st message yay"
./mail_client eecslinab3.case.edu $USN ADD 2 "2nd message woop"

echo "Listing those messages:"
./mail_client eecslinab3.case.edu $USN LIST

echo "Deleting message 1 and listing all messages"
./mail_client eecslinab3.case.edu $USN DELETE 1
./mail_client eecslinab3.case.edu $USN LIST

echo "Retrieving message 2"
./mail_client eecslinab3.case.edu $USN RETRIEVE 2

echo "Adding message 1 again and listing"
./mail_client eecslinab3.case.edu $USN ADD 1 "1st message AGAIN!"
./mail_client eecslinab3.case.edu $USN LIST

echo "Quiting user $USN"
./mail_client eecslinab3.case.edu $USN QUIT
