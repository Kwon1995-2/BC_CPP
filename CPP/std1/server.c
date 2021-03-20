#include <stdio.h>          // printf
#include <stdlib.h>         // atoi
#include <string.h>         // strerror()
#include <unistd.h>         // close()
#include <arpa/inet.h>      // inet_ntop
#include <sys/types.h>      // in_port_t
#include <sys/socket.h>     // socket
#include <netinet/in.h>     // IPPROTO_TCP
#include <errno.h>          // errno

#define MAXPENDING        5  // Maximum outstanding connection requests
#define STRINGBUFSIZE   512 

int main(int argc, char *argv[])
{
    if (argc != 2) // Test for correct number of arguments
    {
        printf("mysvr <Server Port>\n");
        return 0;
    }

    in_port_t servPort = (in_port_t)atoi(argv[1]); // First arg:  local port

    //=============================================================================================
    // 1.socket() - Create socket for incoming connections
    //=============================================================================================
    int servSock;
    if ((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
    {
        printf("socket() failed![%d:%s]\n", errno, strerror(errno));
        return 0;
    }

    // Construct local address structure
    struct sockaddr_in servAddr;                  // Local address
    memset(&servAddr, 0, sizeof(servAddr));       // Zero out structure
    servAddr.sin_family = AF_INET;                // IPv4 address family
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
    servAddr.sin_port = htons(servPort);          // Local port

    //=============================================================================================
    // 2.bind() - Bind to the local address
    //=============================================================================================
    if (bind(servSock, (struct sockaddr*) & servAddr, sizeof(servAddr)) < 0)
    {
        printf("bind() failed![%d:%s]\n", errno, strerror(errno));
        close(servSock);
        return 0;
    }

    //=============================================================================================
    // 3.listen() - Mark the socket so it will listen for incoming connections
    //=============================================================================================
    if (listen(servSock, MAXPENDING) < 0)
    {
        printf("listen() failed![%d:%s]\n", errno, strerror(errno));
        close(servSock);
        return 0;
    }

    struct sockaddr_in clntAddr; // Client address
    socklen_t clntAddrLen = sizeof(clntAddr);   // Set length of client address structure (in-out parameter)
    char clientName[INET_ADDRSTRLEN];           // String to contain client address
    char recvBuffer[STRINGBUFSIZE];                 // receive Buffer

    for (;;)
    {
        clientName[0] = '\0'; // setempty
        recvBuffer[0] = '\0'; // setempty

        //=========================================================================================
        // 4.accept() - Wait for a client to connect --> block mode
        //=========================================================================================
        int clntSock = accept(servSock, (struct sockaddr *) &clntAddr, &clntAddrLen);
        if (clntSock < 0)
        {
            printf("accept() failed![%d:%s]\n", errno, strerror(errno));
            continue;
        }

        // clntSock is connected to a client!
        if (inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clientName, sizeof(clientName)) == NULL)
        {
            printf("Unable to get client address![%d:%s]\n", errno, strerror(errno));
            close(clntSock);
            continue;
        }

        printf("[%s:%d]", clientName, ntohs(clntAddr.sin_port));

        //=========================================================================================
        // 5.recv() - Receive message from client
        //=========================================================================================
        int numBytesRcvd = recv(clntSock, recvBuffer, STRINGBUFSIZE, 0);
        if (0 < numBytesRcvd)
        {
            if (STRINGBUFSIZE <= numBytesRcvd)  recvBuffer[STRINGBUFSIZE-1] = '\0';
            else                                recvBuffer[numBytesRcvd] = '\0';
            printf("recv:[%s]\n", recvBuffer);
        }
        else
            printf("recv:[]\n");

        close(clntSock); // Close client socket
    }

    return 1;
}
