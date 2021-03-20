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

#define ISTCP(t)        (((t)=='T')?1:0)

int main(int argc, char *argv[])
{
    if (argc != 3) // Test for correct number of arguments
    {
        printf("mysvr <Server Port> <T/U>\n");
        return 0;
    }

    in_port_t servPort = (in_port_t)atoi(argv[1]);  // First arg : local port
    char ctype = argv[2][0];                         // Second arg: TCP/UDP flag

    if (ctype == 'T' || ctype == 't')       ctype = 'T';
    else if (ctype == 'U' || ctype == 'u')  ctype = 'U';
    else
    {
        printf("required third argument 'T' or 'U'\n");
        return 0;
    }

    //=============================================================================================
    // 1.socket() - Create socket for incoming connections
    //=============================================================================================
    int servSock;
    if (ISTCP(ctype))   servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    else                servSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (servSock < 0)
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

    struct sockaddr_in clntAddr; // Client address
    socklen_t clntAddrLen = sizeof(clntAddr);   // Set length of client address structure (in-out parameter)
    char clientName[INET_ADDRSTRLEN];           // String to contain client address
    char recvBuffer[STRINGBUFSIZE];             // receive Buffer

    if (ISTCP(ctype))
    {
        //=============================================================================================
        // 3.listen() - Mark the socket so it will listen for incoming connections
        //=============================================================================================
        if (listen(servSock, MAXPENDING) < 0)
        {
            printf("listen() failed![%d:%s]\n", errno, strerror(errno));
            close(servSock);
            return 0;
        }

        for (;;)
        {
            clientName[0] = '\0'; // setempty
            recvBuffer[0] = '\0'; // setempty

            //=========================================================================================
            // 4.accept() - Wait for a client to connect --> block mode
            //=========================================================================================
            int clntSock = accept(servSock, (struct sockaddr*) & clntAddr, &clntAddrLen);
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
                if (STRINGBUFSIZE <= numBytesRcvd)  recvBuffer[STRINGBUFSIZE - 1] = '\0';
                else                                recvBuffer[numBytesRcvd] = '\0';
                printf("recv:[%s]\n", recvBuffer);
            }
            else
                printf("recv:[]\n");

            printf("[%s:%d]", clientName, ntohs(clntAddr.sin_port));

            //=========================================================================================
            // 6.send() - Echo message back to client
            //=========================================================================================
            if (send(clntSock, recvBuffer, numBytesRcvd, 0) < 0)
                printf("send() failed![%d:%s]\n", errno, strerror(errno));
            else
                printf("echo:[%s]\n", recvBuffer);

            close(clntSock); // Close client socket
        }
    }
    else
    {
        for (;;)
        {
            clientName[0] = '\0'; // setempty
            recvBuffer[0] = '\0'; // setempty 

            //========================================================================================= 
            // 3.recvfrom() - Receive message from client
            //========================================================================================= 
            int numBytesRcvd = recvfrom(servSock, recvBuffer, STRINGBUFSIZE, 0, (struct sockaddr*) & clntAddr, &clntAddrLen);
            if (0 < numBytesRcvd)
            {
                if (STRINGBUFSIZE <= numBytesRcvd)  recvBuffer[STRINGBUFSIZE - 1] = '\0';
                else                                recvBuffer[numBytesRcvd] = '\0';
            }
            else
                recvBuffer[0] = '\0';

            // clntSock is connected to a client!
            inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clientName, sizeof(clientName));
            printf("[%s:%d]rectfrom:[%s]\n", clientName, ntohs(clntAddr.sin_port), recvBuffer);
        }
    }

    return 1;
}
