// std1Svr.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
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
#define STRINGBUFSIZE 1024 //#�ѹ��� �о���� ���� ������ ����

typedef struct _THREADPARAM
{
	char ip[16];
	int port;
	SOCKET sock; //unsigned int typedef �� ��
}THREADPARAM, * LPTHREADPARAM;

//Thread Function
unsigned __stdcall ThreadFunc1(void* data)
{
	char recvBuffer[STRINGBUFSIZE] = ""; //receive Buffer
	LPTHREADPARAM param = (LPTHREADPARAM)data;

	printf("[%s:%d]connected!\n", param->ip, param->port);

	while (1)
	{
		//client�κ��� receive message ����

		int numBytesRcvd = recv(param->sock, recvBuffer, STRINGBUFSIZE, 0);
		if (0 < numBytesRcvd)
		{	// �� ���� ���ۿ� ���ڿ� �Ҵ�
			if (STRINGBUFSIZE <= numBytesRcvd) recvBuffer[STRINGBUFSIZE - 1] = '\0';
			else recvBuffer[numBytesRcvd] = '\0';
			printf("[%s:%d]recv:[%s]\n", param->ip, param->port, recvBuffer);
		}
		else break;
	}

	closesocket(param->sock); //client ���� ���� -> ������ ȣ���ϰ� �ݰ� �� ȣ���ϰ� �ݰ� �ݺ�
	printf("[%s:%d]disconnected!\n", param->ip, param->port);
	_endthreadex(0); //process ��� �ʿ�
	return 0;
}

int main(int argc, char* argv[])
{
	WSADATA wsaData; //������ ���� �ʱ�ȭ ���� ���� ���� ����ü
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
	//���� ���̺귯�� �ʱ�ȭ + error ó��
	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
	{
		printf("WSAStartup() Error!\n");
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//int port = 2500; //#1024~40000�� ����
	int servPort = atoi(argv[1]); //���ڿ��� ������ ��ȯ�Ͽ� ������ ����
	////////////////////////////////////////////////////////////////////////////////////
	//#IPv4 TCP ������ ���� ���� serverSocket�� �Ҵ�
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
	serverAddress.sin_addr.s_addr = htonl(INADDR_ANY); //long �� ������ ����Ʈ ������ �ٲپ��ִ� �Լ�
	////////////////////////////////////////////////////////////////////////////////////
	//sock.bind(("", port)) #bind()
	//bind error ó��
	if (bind(serverSocket, (SOCKADDR*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR)
	{
		printf("bind() failed![%d:%s]\n", errno, strerror(errno));
		closesocket(serverSocket);
		return 0;
	}
	////////////////////////////////////////////////////////////////////////////////////
	//listen error ó��
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
		//accept error ó��
		clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLen);
		if (clientSocket < 0)
		{
			printf("accept() failed![%d:%s]\n", errno, strerror(errno)); //errno : �Լ�? return int*
			//closesocket(clientSocket);
			continue;
		}

		if (inet_ntop(AF_INET, &clientAddress.sin_addr.s_addr, clientAddrname, sizeof(clientAddrname)) == NULL)
		{
			printf("Unable to get client address![%d:%s]\n", errno, strerror(errno));
			//strerror ���ڷ� ���� �μ���ȣ�� �˸��� ���� ���ڿ� ��ȯ
			closesocket(clientSocket);
			continue;
		}

		LPTHREADPARAM param = (LPTHREADPARAM)malloc(sizeof(THREADPARAM));
		strncpy(param->ip, clientAddrname, 16); //���ڿ� 16�ڸ���ŭ ����
		param->port = ntohs(clientAddress.sin_port);
		param->sock = clientSocket;

		_beginthreadex(NULL , 0, &ThreadFunc1, (void*)param, 0, NULL);
		//_beginthreadex(_security, _stacksize, _startaddress, _argList, initFlag, _thrdaddr);
		////////////////////////////////////////////////////////////////////////////////////
		//printf("[%s:%d]", clientName, ntohs(clientAddress.sin_port));
		////Network���� Host�� short�� �������� ����Ʈ ������ �ٲپ��ִ� �Լ�
		//////////////////////////////////////////////////////////////////////////////////////
		//int numBytesRcvd = recv(clientSocket, recvBuffer, STRINGBUFSIZE, 0);
		//if (0 < numBytesRcvd)
		//{
		//	if (STRINGBUFSIZE <= numBytesRcvd) recvBuffer[STRINGBUFSIZE - 1] = '\0';//������ ���ڿ��� null���� �ְ� �ڸ���
		//	else recvBuffer[numBytesRcvd] = '\0';
		//	printf("recv[%s]\n", recvBuffer);
		//}
		//else
		//	printf("recv:[]\n"); //�Էµ� ���� ������ ���ڿ� ���� ���

		//closesocket(clientSocket);
	}
	////////////////////////////////////////////////////////////////////////////////////	
	WSACleanup();//WSAStartup �ϸ鼭 ������ ���� ����
	return 0;
}