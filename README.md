Revised Smokers Problem
=======================

Recommended Usage:
------------------
* Run ./run.sh
  - runs rpcgen to generate the C code for the client and server
  - builds the agent and smoker executables using clang
  - uses ssh to launch an agent and three smokers, capturing their output to the file system
* once everything is done, you should send a termination request to the agent
  - (./assignment7/smoker localhost -1)

Server Usage:
-------------
* <code>./agent</code>
* Start the agent (server) before starting a smoker

Client Usage:
-------------
* <code>./smoker HOSTNAME SmokerId</code>
* HOSTNAME is the address of the machine where server is running
* SmokerId is the number of the smoker (1, 2, 3)
* If SmokerId == -1, this tells the server to terminate: <code>./smoker HOSTNAME -1</code>

Normal compilation:
----------------------
* <code>make</code>

To manually generate the C code for the RPC protocol:
----------------------
* <code>rpcgen test.x</code>

To manually compile the client:
----------------------
* <code>gcc -c test_clnt.c</code>
* <code>gcc -c client.c</code>
* <code>gcc -o client client.o test_clnt.o</code>

To manually compile the server:
----------------------
* <code>gcc -c test_svc.c</code>
* <code>gcc -c server.c</code>
* <code>gcc -o server server.o test_svc.o</code>

