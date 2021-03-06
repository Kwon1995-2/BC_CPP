// std1Svr.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <process.h>   
#pragma comment(lib, "ws2_32.lib")

#define MAXPENDING 5 //maximum connection
#define STRINGBUFSIZE 1024 //#한번에 읽어들일 버퍼 사이즈 지정

typedef struct _THREADPARAM
{
	char ip[16];
	int port;
	SOCKET sock; //unsigned int typedef 한 것
}THREADPARAM, * LPTHREADPARAM;

//Thread Function
unsigned __stdcall ThreadFunc1(void* data)
{
	char recvBuffer[STRINGBUFSIZE] = ""; //receive Buffer
	LPTHREADPARAM param = (LPTHREADPARAM)data;

	printf("[%s:%d]connected!\n", param->ip, param->port);

	while (1)
	{
		//client로부터 receive message 받음

		int numBytesRcvd = recv(param->sock, recvBuffer, STRINGBUFSIZE, 0);
		if (0 < numBytesRcvd)
		{	// 더 작은 버퍼에 문자열 할당
			if (STRINGBUFSIZE <= numBytesRcvd) recvBuffer[STRINGBUFSIZE - 1] = '\0';
			else recvBuffer[numBytesRcvd] = '\0';
			printf("[%s:%d]recv:[%s]\n", param->ip, param->port, recvBuffer);
		}
		else break;
	}

	closesocket(param->sock); //client 소켓 닫음 -> 스레드 호출하고 닫고 또 호출하고 닫고 반복
	printf("[%s:%d]disconnected!\n", param->ip, param->port);
	_endthreadex(0); //process 헤더 필요
	return 0;
}

int main(int argc, char* argv[])
{
	WSADATA wsaData; //윈도우 소켓 초기화 정보 저장 위한 구조체
	SOCKET serverSocket, clientSocket;
	SOCKADDR_IN serverAddress, clientAddress;
	////////////////////////////////////////////////////////////////////////////////////
	//argument error
	if (argc != 2)
	{
		printf("std1Svr <Server Port>\n");
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//소켓 라이브러리 초기화 + error 처리
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup() Error!\n");
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//int port = 2500; //#1024~40000번 안쪽
	int servPort = atoi(argv[1]); //문자열을 정수로 변환하여 변수에 저장
	////////////////////////////////////////////////////////////////////////////////////
	//#IPv4 TCP 소켓을 만들어서 변수 serverSocket에 할당
	//sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	//SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
	//serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket == INVALID_SOCKET) {
		printf("socket() failed[%d:%s]\n", errno, strerror(errno));
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//SOCKADDR_IN svr = {};
	memset(&serverAddress, 0, sizeof(serverAddress));
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(servPort);
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); //long 형 데이터 바이트 오더를 바꾸어주는 함수
	////////////////////////////////////////////////////////////////////////////////////
	//sock.bind(("", port)) #bind()
	//bind error 처리
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		printf("bind() failed![%d:%s]\n", errno, strerror(errno));
		closesocket(serverSocket);
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//listen error 처리
	if (listen(serverSocket, MAXPENDING) == SOCKET_ERROR)
	{
		printf("listen() failed![%d:%s]\n", errno, strerror(errno));
		closesocket(serverSocket);
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	/*char clientName[STRINGBUFSIZE];
	char recvBuffer[STRINGBUFSIZE];*/
	char clientAddrname[16]; //string to contain client address
	int clientAddressLen = sizeof(clientAddress);
	////////////////////////////////////////////////////////////////////////////////////
	for (;;)
	{
		clientAddrname[0] = '\0';
		//recvBuffer[0] = '\0';
		////////////////////////////////////////////////////////////////////////////////////
		//accept error 처리
		clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
		if (clientSocket < 0)
		{
			printf("accept() failed![%d:%s]\n", errno, strerror(errno)); //errno : 함수? return int*
			//closesocket(clientSocket);
			continue;
		}

		if (inet_ntop(AF_INET, &clientAddress.sin_addr.s_addr, clientAddrname, sizeof(clientAddrname)) == NULL)
		{
			printf("Unable to get client address![%d:%s]\n", errno, strerror(errno));
			//strerror 인자로 받은 인수번호에 알맞은 오류 문자열 반환
			closesocket(clientSocket);
			continue;
		}

		LPTHREADPARAM param = (LPTHREADPARAM)malloc(sizeof(THREADPARAM));
		strncpy(param->ip, clientAddrname, 16); //문자열 16자리만큼 복사
		param->port = ntohs(clientAddress.sin_port);
		param->sock = clientSocket;

		_beginthreadex(NULL , 0, &ThreadFunc1, (void*)param, 0, NULL);
		//_beginthreadex(_security, _stacksize, _startaddress, _argList, initFlag, _thrdaddr);
		////////////////////////////////////////////////////////////////////////////////////
		//printf("[%s:%d]", clientName, ntohs(clientAddress.sin_port));
		////Network에서 Host로 short형 데이터의 바이트 오더를 바꾸어주는 함수
		//////////////////////////////////////////////////////////////////////////////////////
		//int numBytesRcvd = recv(clientSocket, recvBuffer, STRINGBUFSIZE, 0);
		//if (0 < numBytesRcvd)
		//{
		//	if (STRINGBUFSIZE <= numBytesRcvd) recvBuffer[STRINGBUFSIZE - 1] = '\0';//마지막 문자열에 null문자 넣고 자르기
		//	else recvBuffer[numBytesRcvd] = '\0';
		//	printf("recv[%s]\n", recvBuffer);
		//}
		//else
		//	printf("recv:[]\n"); //입력된 것이 없으니 문자열 없이 출력

		//closesocket(clientSocket);
	}
	////////////////////////////////////////////////////////////////////////////////////	
	WSACleanup();//WSAStartup 하면서 지정한 내용 지움
	return 0;
}