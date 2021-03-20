#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>          // printf
#include <stdlib.h>         // atoi
#include <string.h>         // strerror()
#include <errno.h>          // errno
#include <winsock2.h>       // socket
#include <WS2tcpip.h>       // inet_ntop
#include <process.h>        // _beginthreadex/_endthreadex
//#include <my_global.h>
#include <mysql.h>

#pragma comment(lib, "libmySQL.lib")

#pragma comment(lib, "ws2_32.lib")

#define MAXPENDING         5  // Maximum outstanding connection requests
#define STRINGBUFSIZE   1024 

typedef struct _THREADPARAM
{
    char ip[16];
    int port;
    SOCKET sock;
}THREADPARAM, * LPTHREADPARAM;

void writeToSQL(char* sql, int id, int day, int tm, int t, int h, int p) //sql이 로컬 변수
{
    //char sql[STRINGBUFSIZE];
    char daytime[20];
    int d1 = day / 10000;
    int d2 = (day - d1 * 10000) / 100;
    int d3 = day - (d1 * 10000) - d2 * 100;
    int t1 = tm / 10000;
    int t2 = (tm - t1 * 10000) / 100;
    int t3 = tm - t1 * 10000 - t2 * 100;
    sprintf(daytime, "%d-%02d-%02d %02d:%02d:%02d", d1, d2, d3, t1, t2, t3);
    sprintf(sql, "insert into sensingdata(id, daytime, temperature, humidity, pressure) values (%d, '%s', %d, %d, %d);", id, daytime, t, h, p);

    //return sql;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// Thread Function
unsigned __stdcall ThreadDB(void* data)
{
    //    char recvBuffer[STRINGBUFSIZE] = "";    // receive Buffer
    LPTHREADPARAM param = (LPTHREADPARAM)data;

    printf("[%s:%d]connected!\n", param->ip, param->port);

    //    while (1)
    //    {
    //        //=========================================================================================
    //        // 5.recv() - Receive message from client
    //        //=========================================================================================
    //        int numBytesRcvd = recv(param->sock, recvBuffer, STRINGBUFSIZE, 0);
    //        if (0 < numBytesRcvd)
    //        {
    //            int offset = 0;
    //            short count;
    //            memcpy(&count, recvBuffer, sizeof(short));  offset += sizeof(short);
    //
    ////            printf("recv[%d]\n", count);
    //            for (int i = i; i < count; i++)
    //            {
    //                short id, t, h, p;
    //                int day, tm;
    //                memcpy(&id,  recvBuffer + offset, sizeof(short));    offset += sizeof(short);
    //                memcpy(&day, recvBuffer + offset, sizeof(int));      offset += sizeof(int);
    //                memcpy(&tm,  recvBuffer + offset, sizeof(int));      offset += sizeof(int);
    //                memcpy(&t,   recvBuffer + offset, sizeof(short));    offset += sizeof(short);
    //                memcpy(&h,   recvBuffer + offset, sizeof(short));    offset += sizeof(short);
    //                memcpy(&p,   recvBuffer + offset, sizeof(short));    offset += sizeof(short);
    //
    //                printf("recv[%d]%d,%d,%d,%d,%d,%d\n", count, id, day, tm, t, h, p);
    //            }
    //        }
    //        else
    //            break;
    //    }


    short count; //초기화 or 바이트 수 맞춰주기
    int numBytesRcvd = recv(param->sock, (char*)&count, sizeof(short), 0);
    int len = count * 16;

    char buf[16];
    //DB연결
    MYSQL mysql;
    mysql_init(&mysql);
    if (!mysql_real_connect(&mysql, "localhost", "scott", "tiger", "sensingdb", 0, NULL, 0))
    {
        printf("connect failed!\n");
        return 0;
    };
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    //=========================================================================================
    // 5.recv() - Receive message from client
    //=========================================================================================
    
    short id, t, h, p;
    int day, tm;
    for (int i = 0; i < count; i++)
    {
        char sql[STRINGBUFSIZE] = {NULL,};
        int offset = 0;
        recv(param->sock, buf, 16, 0); //buf는 계속 덮어쓴다.

        memcpy(&id, buf + offset, sizeof(short));   offset += sizeof(short);
        memcpy(&day, buf + offset, sizeof(int));    offset += sizeof(int);
        memcpy(&tm, buf + offset, sizeof(int));     offset += sizeof(int);
        memcpy(&t, buf + offset, sizeof(short));    offset += sizeof(short);
        memcpy(&h, buf + offset, sizeof(short));    offset += sizeof(short);
        memcpy(&p, buf + offset, sizeof(short));    offset += sizeof(short);

        //printf("recv[%d]%d,%d,%d,%d,%d,%d\n", count, id, day, tm, t, h, p);

        //DB 저장
        //"insert into sensingdata(id, daytime, temperature, humidity, pressure) values(%d, ,%d,%d,%d);", id, ~
        //mysql_query(&mysql, "insert into sensingdata(id, daytime, temperature, humidity, pressure values(%d, %d, %d, %d, %d);\n"));
        writeToSQL(sql, id, day, tm, t, h, p);
        printf("[%s] \n", sql);
        mysql_query(&mysql, sql);
        ///////////////////////////////////////////////////////////////////////////////////////////////////
    }
    closesocket(param->sock); // Close client socket
    //DB 닫기
    mysql_close(&mysql);
    ///////////////////////////////////////////////////////////////////////////////////////////////////

    printf("[%s:%d]disconnected!\n", param->ip, param->port);
    free(param);
    _endthreadex(0);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
    WSADATA wsaData;
    SOCKET serverSocket, clientSocket;
    SOCKADDR_IN serverAddress, clientAddress;

    if (argc != 2) // Test for correct number of arguments
    {
        printf("std1Svr <Server Port>\n");
        return 0;
    }

    //소켓 라이브러리 초기화
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup() Error!\n");
        return 0;
    }

    int servPort = atoi(argv[1]); // First arg:  local port

    //=============================================================================================
    // 1.socket() - Create socket for incoming connections
    //=============================================================================================
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET)
    {
        printf("socket() failed![%d:%s]\n", errno, strerror(errno));
        return 0;
    }

    // Construct local address structure
    memset(&serverAddress, 0, sizeof(serverAddress));   // Zero out structure
    serverAddress.sin_family = AF_INET;                 // IPv4 address family
    serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);  // Any incoming interface
    serverAddress.sin_port = htons(servPort);           // Local port

    //=============================================================================================
    // 2.bind() - Bind to the local address
    //=============================================================================================
    if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
    {
        printf("bind() failed![%d:%s]\n", errno, strerror(errno));
        closesocket(serverSocket);
        return 0;
    }

    //=============================================================================================
    // 3.listen() - Mark the socket so it will listen for incoming connections
    //=============================================================================================
    if (listen(serverSocket, MAXPENDING) == SOCKET_ERROR)
    {
        printf("listen() failed![%d:%s]\n", errno, strerror(errno));
        closesocket(serverSocket);
        return 0;
    }

    char clientName[16];                 // String to contain client address
    int clientAddressLen = sizeof(clientAddress);

    printf("Waiting for connect...\n");

    for (;;)
    {
        clientName[0] = '\0'; // setempty

        //=========================================================================================
        // 4.accept() - Wait for a client to connect --> block mode
        //=========================================================================================
        clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
        if (clientSocket < 0)
        {
            printf("accept() failed![%d:%s]\n", errno, strerror(errno));
            continue;
        }

        // clientSocket is connected to a client!
        if (inet_ntop(AF_INET, &clientAddress.sin_addr.s_addr, clientName, sizeof(clientName)) == NULL)
        {
            printf("Unable to get client address![%d:%s]\n", errno, strerror(errno));
            closesocket(clientSocket);
            continue;
        }

        LPTHREADPARAM param = (LPTHREADPARAM)malloc(sizeof(THREADPARAM));
        strncpy(param->ip, clientName, 16);
        param->port = ntohs(clientAddress.sin_port);
        param->sock = clientSocket;

        _beginthreadex(NULL, 0, &ThreadDB, (void*)param, 0, NULL);
    }
    WSACleanup();

    return 1;
}
