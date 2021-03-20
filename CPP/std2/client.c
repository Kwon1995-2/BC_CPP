#include <stdio.h>          // printf
#include <stdlib.h>         // atoi
#include <string.h>         // strerror()
#include <unistd.h>         // close()
#include <arpa/inet.h>      // inet_pton
#include <sys/types.h>      // in_port_t
#include <sys/socket.h>     // socket
#include <netinet/in.h>     // IPPROTO_TCP
#include <errno.h>          // errno

#define STRINGBUFSIZE   512 

int main(int argc, char *argv[])
{
	if (argc != 4) // Test for correct number of arguments
	{
		printf("mycnt <Server Address> <Server Port> <EchoString>\n");
		return 0;
	}

	char *servIP = argv[1];							// First arg : server IP address (dotted quad)
	in_port_t servPort = (in_port_t)atoi(argv[2]);	// Second arg: server Port
	char *sendstring = argv[3];						// Third arg : string to send

	//================================================================================================
	// 1.socket() - Create a reliable, stream socket using TCP
	//================================================================================================
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0)
	{
		printf("socket() failed![%d:%s]\n", errno, strerror(errno));
		return 0;
	}

	// Construct the server address structure
	struct sockaddr_in servAddr;            // Server address
	memset(&servAddr, 0, sizeof(servAddr)); // Zero out structure
	servAddr.sin_family = AF_INET;										// IPv4 address family
	if (inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr) <= 0)		// address
	{
		printf("inet_pton() failed![%d:%s]\n", errno, strerror(errno));
		close(sock);
		return 0;
	}
	servAddr.sin_port = htons(servPort);								// Server port

	//================================================================================================
	// 2.connect() - Establish the connection to the server
	//================================================================================================
	if (connect(sock, (struct sockaddr*) & servAddr, sizeof(servAddr)) < 0)
	{
		printf("connect() failed![%d:%s]\n", errno, strerror(errno));
		close(sock);
		return 0;
	}

	int sendStringLen = strlen(sendstring);							// Determine input length

	//================================================================================================
	// 3.send() - Send the string to the server
	//================================================================================================
	int numBytes = send(sock, sendstring, sendStringLen, 0);
	if (numBytes < 0)
	{
		printf("send() failed![numBytes:%d][%d:%s]\n", numBytes, errno, strerror(errno));
		close(sock);
		return 0;
	}
	else if (numBytes != sendStringLen)
	{
		printf("sent unexpected number of bytes![numBytes:%d][%d:%s]\n", numBytes, errno, strerror(errno));
		close(sock);
		return 0;
	}
	else
		printf("send:[%s]\n", sendstring);		// Print the echo buffer

	char echoBuffer[STRINGBUFSIZE];	// echo Buffer
	//================================================================================================
	// 4.recv() - Receive up to the buffer size bytes from the server
	//================================================================================================
	numBytes = recv(sock, echoBuffer, STRINGBUFSIZE - 1, 0);
	if (0 < numBytes)	echoBuffer[numBytes] = '\0';    // Terminate the string!
	else				echoBuffer[0] = '\0';

	printf("echo:[%s]\n", echoBuffer);		// Print the echo buffer 

	close(sock);

	return 1;
}
