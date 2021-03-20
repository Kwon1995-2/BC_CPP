#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (argc != 4) // Test for correct number of arguments
	{
		printf("mycnt <Server Address> <Server Port> <SendString>\n");
		return 0;
	}

	char *servIP = argv[1];							// First arg : server IP address (dotted quad)
	in_port_t servPort = (in_port_t)atoi(argv[2]);	// Second arg: server port
	char *sendString = argv[3];						// Third arg : string to send

	//================================================================================================
	// 1.socket() - Create a reliable, stream socket using UDP
	//================================================================================================
	int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sock < 0)
	{
		printf("socket() failed![%d:%s]\n", errno, strerror(errno));
		return 0;
	}

	// Construct the server address structure
	struct sockaddr_in servAddr;            // Server address
	memset(&servAddr, 0, sizeof(servAddr)); // Zero out structure
	servAddr.sin_family = AF_INET;          // IPv4 address family
	if (inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr) <= 0)
	{
		printf("inet_pton() failed![%d:%s]\n", errno, strerror(errno));
		close(sock);
		return 0;
	}
	servAddr.sin_port = htons(servPort);    // Server port

	int sendStringLen = strlen(sendString); // Determine input length

	//================================================================================================
	// 2.sendto() - Send the string to the server 
	//================================================================================================ 
	if (sendto(sock, sendString, sendStringLen, 0, (struct sockaddr*) & servAddr, sizeof(servAddr)) < 0)
		printf("sendto() failed![%d:%s]\n", errno, strerror(errno));
	else
		printf("sendto:[%s]\n", sendString);

	close(sock);

	return 1;
}
