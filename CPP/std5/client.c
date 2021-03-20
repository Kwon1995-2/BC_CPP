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

int main(int argc, char* argv[])
{
	if (argc != 4) // Test for correct number of arguments
	{
		printf("mycnt <Server Address> <Server Port> <FileName>\n");
		return 0;
	}

	char* servIP = argv[1];							// First arg : server IP address (dotted quad)
	in_port_t servPort = (in_port_t)atoi(argv[2]);	// Second arg: server Port
	char* filename = argv[3];						// Third arg : FileName

	//================================================================================================
	// 0.fopen() - file open
	//================================================================================================
	FILE* fp = fopen(filename, "rt");
	if (!fp)
	{
		printf("fopen() failed![%d:%s]\n", errno, strerror(errno));
		return 0;
	}

	char rstring[STRINGBUFSIZE];
	while (fgets(rstring, STRINGBUFSIZE, fp))
	{
		//================================================================================================
		// 1.socket() - Create a reliable, stream socket using TCP
		//================================================================================================
		int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sock < 0)
		{
			printf("socket() failed![%d:%s]\n", errno, strerror(errno));
			fclose(fp);
			return 0;
		}

		// Construct the server address structure
		struct sockaddr_in servAddr;            // Server address
		memset(&servAddr, 0, sizeof(servAddr)); // Zero out structure
		servAddr.sin_family = AF_INET;										// IPv4 address family
		if (inet_pton(AF_INET, servIP, &servAddr.sin_addr.s_addr) <= 0)		// address
		{
			printf("inet_pton() failed![%d:%s]\n", errno, strerror(errno));
			fclose(fp);
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
			fclose(fp);
			close(sock);
			return 0;
		}

		int rstringLen = strlen(rstring);
		rstring[rstringLen-1] = '\0';

		//================================================================================================
		// 4.send() - Send the string to the server
		//================================================================================================
		int numBytes = send(sock, rstring, rstringLen, 0);
		if (numBytes < 0)
		{
			printf("send() failed![numBytes:%d][%d:%s]\n", numBytes, errno, strerror(errno));
			break;
		}
		else if (numBytes != rstringLen)
		{
			printf("sent unexpected number of bytes![numBytes:%d][%d:%s]\n", numBytes, errno, strerror(errno));
			break;
		}
		else
			printf("send:[%s]\n", rstring);		// Print the sendString

		close(sock);
	}

	fclose(fp);

	return 1;
}
