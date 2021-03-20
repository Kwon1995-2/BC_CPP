#include <stdio.h>          // printf
#include <stdlib.h>         // atoi
#include <string.h>         // strerror()
#include <unistd.h>         // close()
#include <arpa/inet.h>      // inet_pton
#include <sys/types.h>      // in_port_t
#include <sys/socket.h>     // socket
#include <netinet/in.h>     // IPPROTO_TCP
#include <errno.h>          // errno
#include <signal.h>
#include <fcntl.h>

#define MAXPENDING        5 // Maximum outstanding connection requests
#define STRINGBUFSIZE   512

#define STANDBYTYPE

void SIGhandler(int signo);

int g_servSock;


int main(int argc, char *argv[])
{
    if (argc != 2) // Test for correct number of arguments
    {
        printf("mysvr <Server Port>\n");
        return 0;
    }

    in_port_t servPort = atoi(argv[1]); // First arg:  local port 

    //=============================================================================================
    // 1.socket() - Create socket for incoming connections
    //============================================================================================= 
    if ((g_servSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
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
    if (bind(g_servSock, (struct sockaddr*) & servAddr, sizeof(servAddr)) < 0)
    {
        printf("bind() failed![%d:%s]\n", errno, strerror(errno));
        close(g_servSock);
        return 0;
    }

    //--------------------------------------------------------------------------------------
    struct sigaction handler;

    handler.sa_handler = SIGhandler;         // SIGIO핸들러 설정
    if (sigfillset(&handler.sa_mask) < 0)
    {
        printf("sigfillset() failed[%d:%s]\n", errno, strerror(errno));
        close(g_servSock);
        exit(1);
    }
    handler.sa_flags = 0;

    // I/O 시그널에 사용될 핸들러 등록
    if (sigaction(SIGIO, &handler, 0) < 0)
    {
        printf("sigaction() failed[%d:%s]\n", errno, strerror(errno));
        close(g_servSock);
        exit(1);
    }

    // F_SETOWN 명령어로 어떤 프로세스가 SIGIO 시그널을 받을지 지정
    if (fcntl(g_servSock, F_SETOWN, getpid()) < 0)
    {
        printf("fcntl(1) failed[%d:%s]\n", errno, strerror(errno));
        close(g_servSock);
        exit(1);
    }

    // SIGIO 전달 처리
    if (fcntl(g_servSock, F_SETFL, O_NONBLOCK | FASYNC) < 0)
    {
        printf("fcntl(2) failed[%d:%s]\n", errno, strerror(errno));
        close(g_servSock);
        exit(1);
    }
    for (;;)
    {
        // do something

        usleep(100); // msec
    }
}

void SIGhandler(int signo)
{
    char clientName[INET_ADDRSTRLEN];                     // String to contain client address 
    char recvBuffer[STRINGBUFSIZE];
    struct sockaddr_in clntAddr;                          // Client address
    socklen_t clntAddrLen = sizeof(struct sockaddr_in);   // Set length of client address structure (in-out parameter)

    // 클라이언트에서 데이터가 오면
    int numBytesRcvd = recvfrom(g_servSock, recvBuffer, STRINGBUFSIZE, 0, (struct sockaddr*)&clntAddr, &clntAddrLen);
    if (numBytesRcvd <= 0)
    {
        printf("recvfrom() failed!![%d:%s]\n", errno, strerror(errno));
        return;
    }
    recvBuffer[numBytesRcvd] = '\0';

    // clntSock is connected to a client!
    inet_ntop(AF_INET, &clntAddr.sin_addr.s_addr, clientName, sizeof(clientName));
    printf("[%s:%d]rectfrom:[%s]\n", clientName, ntohs(clntAddr.sin_port), recvBuffer);
}
