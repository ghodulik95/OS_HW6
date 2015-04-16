#include "smoking.h"

int main(int argc, char**argv)
{
	CLIENT *cl;
	
	// validate input
	if(argc != 3)
	{
		printf("Usage: ./client HOSTNAME i\n");
		return 1;
	}
	
	// create client
	char *server_hostname = argv[1];
	cl = clnt_create(server_hostname, RDK5_SMOKERS, ASSIGNMENT_7, "udp");
	if(cl == NULL) 
	{
		clnt_pcreateerror("Error creating client");
		exit(EXIT_FAILURE);
	}

	int smokerId;
	smokerId = atoi(argv[2]);

	// handle termination requests
	if(smokerId == -1)
	{
		quit_smoking_1(&smokerId, cl);
		printf("Successfully quit smoking\n");
		return 0;
	}
	
	

	// create request object
	struct SupplyRequest t = {TOBACCO, 9999, smokerId};
	
	int* result = request_supplies_1(&t, cl);
	printf("Received result %d\n", *result);

	clnt_destroy(cl);
	return 0;
}