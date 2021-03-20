#include <stdio.h>          // printf
#include <stdlib.h>         // atoi
#include <string.h>         // strerror()
#include <unistd.h>         // close()
#include <arpa/inet.h>      // inet_ntop
#include <sys/types.h>      // in_port_t
#include <sys/socket.h>     // socket
#include <netinet/in.h>     // IPPROTO_TCP
#include <errno.h>          // errno
#include <pthread.h>        // pthread_

#define MAXPENDING        5  // Maximum outstanding connection requests
#define STRINGBUFSIZE   512 

typedef struct _THREADARG_
{
    int socket;
    struct sockaddr_in* pclntAddr;
}THREADARG, * LPTHREADARG;

void* threadFunc(void* arg);

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

    struct sockaddr_in* pclntAddr;                      // Client address 
    socklen_t clntAddrLen = sizeof(struct sockaddr_in); // Set length of client address structure (in-out parameter)
    char clientName[INET_ADDRSTRLEN];                   // String to contain client address
    char recvBuffer[STRINGBUFSIZE];                     // receive Buffer

    for (;;)
    {
        clientName[0] = '\0'; // setempty
        recvBuffer[0] = '\0'; // setempty

        pclntAddr = (struct sockaddr_in*)malloc(sizeof(struct sockaddr_in));

        //=========================================================================================
        // 4.accept() - Wait for a client to connect --> block mode
        //=========================================================================================
        int clntSock = accept(servSock, (struct sockaddr *) pclntAddr, &clntAddrLen);
        if (clntSock < 0)
        {
            printf("accept() failed![%d:%s]\n", errno, strerror(errno));
            continue;
        }

        //=========================================================================================
        // pthread_create
        //=========================================================================================
        LPTHREADARG pArg = (LPTHREADARG)malloc(sizeof(THREADARG));        // malloc for Thread Argument
        pArg->socket = clntSock;
        pArg->pclntAddr = pclntAddr;

        pthread_t pid;
        int ret = pthread_create(&pid, NULL, &threadFunc, pArg);
        if (ret != 0)
        {
            printf("error to pthread_create():[%d:%s]\n", errno, strerror(errno));
            close(clntSock); // Close client socket
        }
    }

    return 1;
}

void* threadFunc(void* arg)
{
    char recvBuffer[STRINGBUFSIZE]; // Buffer for receive string

    pthread_detach(pthread_self());

    LPTHREADARG pArg = (LPTHREADARG)arg;

    // clntSock is connected to a client!
    char clientName[INET_ADDRSTRLEN] = ""; // String to contain client address
    if (inet_ntop(AF_INET, &(pArg->pclntAddr->sin_addr.s_addr), clientName, sizeof(clientName)) == NULL)
    {
        printf("Unable to get client address![%d:%s]\n", errno, strerror(errno));
        close(pArg->socket);
        return NULL;
    }

    printf("[%s:%d]", clientName, ntohs(pArg->pclntAddr->sin_port));

    //=========================================================================================
    // 5.recv() - Receive message from client
    //=========================================================================================
    int numBytesRcvd = recv(pArg->socket, recvBuffer, STRINGBUFSIZE, 0);
    if (0 < numBytesRcvd)
    {
        if (STRINGBUFSIZE <= numBytesRcvd)  recvBuffer[STRINGBUFSIZE - 1] = '\0';
        else                                recvBuffer[numBytesRcvd] = '\0';
        printf("recv:[%s]\n", recvBuffer);
    }
    else
        printf("recv:[]\n");

    printf("[%s:%d]", clientName, ntohs(pArg->pclntAddr->sin_port));

    close(pArg->socket);

    free(pArg->pclntAddr);
    free(pArg);

    return NULL;
}
