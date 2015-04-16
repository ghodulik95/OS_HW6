#FOR eecslinab2 or eecslinab 7 -- eecslinab3 should run the server
USN="TIM"
USN2="BOB"
echo "Starting client $USN"
./mail_client eecslinab3.case.edu $USN START

echo "Starting client $USN2"
./mail_client eecslinab3.case.edu $USN2 START

echo "Adding 3 messages to $USN's mailbox"
./mail_client eecslinab3.case.edu $USN ADD 0 "0th message of $USN woot w00000t"
./mail_client eecslinab3.case.edu $USN ADD 1 "1st message of $USN yay"
./mail_client eecslinab3.case.edu $USN ADD 2 "2nd message of $USN woop"

echo "Adding 3 messages to $USN2's mailbox"
./mail_client eecslinab3.case.edu $USN2 ADD 0 "0th message of $USN2 woot w00000t"
./mail_client eecslinab3.case.edu $USN2 ADD 1 "1st message of $USN2 yay"
./mail_client eecslinab3.case.edu $USN2 ADD 2 "2nd message of $USN2 woop"

echo "Listing those messages:"
./mail_client eecslinab3.case.edu $USN LIST
./mail_client eecslinab3.case.edu $USN2 LIST

echo "Deleting message 1 and listing all messages"
./mail_client eecslinab3.case.edu $USN DELETE 1
./mail_client eecslinab3.case.edu $USN LIST
./mail_client eecslinab3.case.edu $USN2 DELETE 1
./mail_client eecslinab3.case.edu $USN2 LIST

echo "Retrieving message 2"
./mail_client eecslinab3.case.edu $USN RETRIEVE 2
./mail_client eecslinab3.case.edu $USN2 RETRIEVE 2

echo "Adding message 1 again and listing"
./mail_client eecslinab3.case.edu $USN ADD 1 "1st message of $USN AGAIN!"
./mail_client eecslinab3.case.edu $USN LIST
./mail_client eecslinab3.case.edu $USN2 ADD 1 "1st message of $USN2 AGAIN!"
./mail_client eecslinab3.case.edu $USN2 LIST

echo "Quiting user $USN and $USN2"
./mail_client eecslinab3.case.edu $USN QUIT
./mail_client eecslinab3.case.edu $USN2 QUIT
