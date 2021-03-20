
// Client_Emulator_protocolDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Client_Emulator_protocol.h"
#include "Client_Emulator_protocolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CClientEmulatorprotocolDlg 대화 상자



CClientEmulatorprotocolDlg::CClientEmulatorprotocolDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLIENT_EMULATOR_PROTOCOL_DIALOG, pParent)
	, m_nPort(2500)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CClientEmulatorprotocolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_strlListGen);
	DDX_Text(pDX, IDC_Port, m_nPort);
	DDX_Control(pDX, IDC_IPADDRESS, m_IPADDR);
}

BEGIN_MESSAGE_MAP(CClientEmulatorprotocolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNGENR, &CClientEmulatorprotocolDlg::OnBnClickedBtngenr)
	ON_BN_CLICKED(IDC_BTNSAVE, &CClientEmulatorprotocolDlg::OnBnClickedBtnsave)
	ON_BN_CLICKED(IDC_BTNCNET, &CClientEmulatorprotocolDlg::OnBnClickedBtncnet)
	ON_BN_CLICKED(IDC_BTNSEND, &CClientEmulatorprotocolDlg::OnBnClickedBtnsend)
	ON_BN_CLICKED(IDCANCEL, &CClientEmulatorprotocolDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTNRESET, &CClientEmulatorprotocolDlg::OnBnClickedBtnreset)
END_MESSAGE_MAP()


// CClientEmulatorprotocolDlg 메시지 처리기

BOOL CClientEmulatorprotocolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_IPADDR.SetAddress(127, 0, 0, 1);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CClientEmulatorprotocolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CClientEmulatorprotocolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CClientEmulatorprotocolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CClientEmulatorprotocolDlg::OnBnClickedBtngenr()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	srand((unsigned int)time(NULL));

	DataManager dm;
	CString str;

	int seq = 0;
	while (seq < 10)
	{
		short count = rand() % 5 + 1;

		short id;

		for (int i = 0; i < count; i++)
		{
			id = rand() % 101 + 100;
			LPDATA pd = dm.GetData(id);
			if (pd == NULL)
			{
				LPDATA newpd = (LPDATA)malloc(sizeof(DATA));
				newpd->id = id;
				newpd->temp = rand() % 56 - 20;
				newpd->hum = rand() % 101;
				newpd->press = rand()% 601 + 600;

				dm.AddData(newpd);

				str.Format("%3d:%s", seq, dm.getString(newpd));
			}
			else
			{
				pd->temp += rand() % 5 - 2;
				pd->hum += rand() % 11 - 5;
				pd->press += rand() % 21 - 10;

				dm.SetData(pd);

				str.Format("%3d:%s", seq, dm.getString(pd));
			}
			m_strlListGen.AddString(str);
		}
		seq++;
		Sleep(10);
	}
}

int CClientEmulatorprotocolDlg::GetCountData(int seq, int start) //count를 맨 앞에 붙여줄 용도로 반환
{
	int ret = 0;
	CString str;
	int size = m_strlListGen.GetCount(); //list의 전체 행 개수
	for (int i = 0; i < size; i++)
	{
		m_strlListGen.GetText(i, str);
		int idx = str.Find(":");
		int s = atoi(str.Left(idx));
		if (s == seq) ret++;
	}
	return ret;
}


BYTE* CClientEmulatorprotocolDlg::makeBuff(BYTE* pbuf, int count, CStringArray& arr)
{
	int offset = 0;
	memcpy(pbuf, &count, sizeof(short)); offset += sizeof(short);
	CString str;
	for (int i = 0; i < count; i++)
	{
		str = arr.GetAt(i);

		int idx = str.Find(":");

		str = str.Mid(idx + 1);
		idx = str.Find(",");
		short id = atoi(str.Left(idx));
		memcpy(pbuf + offset, &id, sizeof(short)); offset += sizeof(short);

		str = str.Mid(idx + 1);
		idx = str.Find(",");
		int day = atoi(str.Left(idx));
		memcpy(pbuf + offset, &day, sizeof(int)); offset += sizeof(int);

		str = str.Mid(idx + 1);
		idx = str.Find(",");
		int tm = atoi(str.Left(idx));
		memcpy(pbuf + offset, &tm, sizeof(int)); offset += sizeof(int);

		str = str.Mid(idx + 1);
		idx = str.Find(",");
		short temp = atoi(str.Left(idx));
		memcpy(pbuf + offset, &temp, sizeof(short)); offset += sizeof(short);

		str = str.Mid(idx + 1);
		idx = str.Find(",");
		short hum = atoi(str.Left(idx));
		memcpy(pbuf + offset, &hum, sizeof(short)); offset += sizeof(short);

		str = str.Mid(idx + 1);
		//idx = str.Find(","); --> 마지막은 ,가 없다.
		short press = atoi(str); //atoi(str.Left(idx)); --> 앞쪽의 idx가 2였으니 두 자리만 저장됨
		memcpy(pbuf + offset, &press, sizeof(short)); offset += sizeof(short);
	}
	return pbuf;
}
void CClientEmulatorprotocolDlg::writeData(FILE* fp, CStringArray& arr)
{
	int count = arr.GetSize();
	int len = 2 + count * DATASIZE;

	BYTE* pbuf = (BYTE*)malloc(len);
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//int offset = 0;
	//memcpy(pbuf, &count, sizeof(short)); offset += sizeof(short);
	//CString str;
	//for (int i = 0; i < count; i++)
	//{
	//	str = arr.GetAt(i);

	//	int idx = str.Find(":");

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	short id = atoi(str.Left(idx));
	//	memcpy(pbuf+offset, &id, sizeof(short)); offset += sizeof(short);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	int day = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &day, sizeof(int)); offset += sizeof(int);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	int tm = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &tm, sizeof(int)); offset += sizeof(int);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	short temp = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &temp, sizeof(short)); offset += sizeof(short);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	short hum = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &hum, sizeof(short)); offset += sizeof(short);

	//	str = str.Mid(idx + 1);
	//	//idx = str.Find(","); --> 마지막은 ,가 없다.
	//	short press = atoi(str); //atoi(str.Left(idx)); --> 앞쪽의 idx가 2였으니 두 자리만 저장됨
	//	memcpy(pbuf + offset, &press, sizeof(short)); offset += sizeof(short);

	//}
	/*fwrite(pbuf, len, 1, fp);*/
	//////////////////////////////////////////////////////////////////////////////////////////////////
	BYTE* ppbuf = makeBuff(pbuf, count, arr); //BYTE --> unsinged char
	//에러 코드 확인
	
	fwrite(ppbuf, len, 1, fp);
	free(pbuf);
}

void CClientEmulatorprotocolDlg::sendData(SOCKET sock, CStringArray& arr)
{
	int count = arr.GetSize();
	int len = 2 + count * DATASIZE;

	BYTE* pbuf = (BYTE*)malloc(len);
	//////////////////////////////////////////////////////////////////////////////////////////////////
	//int offset = 0;
	//memcpy(pbuf, &count, sizeof(short)); offset += sizeof(short);
	//CString str;
	//for (int i = 0; i < count; i++)
	//{
	//	str = arr.GetAt(i);

	//	int idx = str.Find(":");

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	short id = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &id, sizeof(short)); offset += sizeof(short);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	int day = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &day, sizeof(int)); offset += sizeof(int);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	int tm = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &tm, sizeof(int)); offset += sizeof(int);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	short temp = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &temp, sizeof(short)); offset += sizeof(short);

	//	str = str.Mid(idx + 1);
	//	idx = str.Find(",");
	//	short hum = atoi(str.Left(idx));
	//	memcpy(pbuf + offset, &hum, sizeof(short)); offset += sizeof(short);

	//	str = str.Mid(idx + 1);
	//	//idx = str.Find(","); --> 마지막은 ,가 없다.
	//	short press = atoi(str); //atoi(str.Left(idx)); --> 앞쪽의 idx가 2였으니 두 자리만 저장됨
	//	memcpy(pbuf + offset, &press, sizeof(short)); offset += sizeof(short);
	//}
	//////////////////////////////////////////////////////////////////////////////////////////////////
	BYTE* ppbuf = makeBuff(pbuf, count, arr);
	send(sock, (const char*)ppbuf, len, 0);
	free(pbuf);
}

void CClientEmulatorprotocolDlg::OnBnClickedBtnsave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//CFile::typeBinary 
	
	/*long count = 5;
	CFile file("test.txt", CFile::modeCreate | CFile::modeWrite | CFile::typeBinary);
	file.Write((const void*)(&count), sizeof(long));

	printf("Binary mode Write : %d \n", count);*/
	/////////////////////////////////////////////////////////////////////////////////
	/*CFile file;
	if (!file.Open("test.bin", CFile::modeWrite | CFile::modeCreate)) return;*/
	FILE* fp;
	errno_t er = fopen_s(&fp, "test.bin", "wb"); //베타적 쓰기모드
	
	int seq;
	CString str;
	int size = m_strlListGen.GetCount(); 
	//if (size == 0) return;//AfxMessageBox("None text!!"); --> size가 0이면 loop 안 돈다.
	for (int i = 0; i < size; i++)
	{
		CStringArray arr;
		m_strlListGen.GetText(i, str); // -> list에 표시된 str이 온다.
		int idx = str.Find(":");
		seq = atoi(str.Left(idx)); //char to int : atoi
		//fprintf(fp, "%d\t%s\n", seq, str);
		arr.Add(str);

		int count = GetCountData(seq, i); //만든 함수
		for (int j = 1; j < count; j++)
		{
			m_strlListGen.GetText(++i, str);
			arr.Add(str);
		}
		writeData(fp, arr); //만든 함수
	}
	//file.Close();
	fclose(fp);
	/////////////////////////////////////////////////////////////////////////////////
	//CString str;
	//int n;
	//for (int i = 0; i < m_strlListGen.GetCount(); i++)
	//{
	//	//n = m_strlListGen.GetTextLen(i);
	//	//같은 시퀀스 갯수 
	//	m_strlListGen.GetText(i, str);
	//	//str 잘라서 : , --> 
	//	file.Write(&str, n);
	//}
}


void CClientEmulatorprotocolDlg::OnBnClickedBtncnet()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/////////////////////////////////////////////////////////
	//connect test
	////////////////////////////////////////////////////////
	// socket선언 및 연결
	int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)	AfxMessageBox("Socket Error!");

	sockaddr_in name;
	CString IP_addr;
	BYTE ip_1, ip_2, ip_3, ip_4;
	m_IPADDR.GetAddress(ip_1, ip_2, ip_3, ip_4);
	IP_addr.Format("%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
	memset(&name, 0x00, sizeof(name));
	name.sin_family = AF_INET;
	inet_pton(AF_INET, IP_addr, &name.sin_addr);
	name.sin_port = htons(m_nPort);

	// connect
	if (connect(sock, (sockaddr*)&name, sizeof(name)) == SOCKET_ERROR)
		AfxMessageBox("Connect Error!");
	
}


void CClientEmulatorprotocolDlg::OnBnClickedBtnsend()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_strlListGen.GetCount() == 0) return;

	/////////////////////////////////////////////////////////////////////////////////////

	int seq;
	CString str;
	int size = m_strlListGen.GetCount();
	if (size == 0) return;//AfxMessageBox("None text!!");

	for (int i = 0; i < size; i++)
	{
		// socket선언 및 연결
		int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sock == INVALID_SOCKET)	continue;

		sockaddr_in name;
		CString IP_addr;
		BYTE ip_1, ip_2, ip_3, ip_4;
		m_IPADDR.GetAddress(ip_1, ip_2, ip_3, ip_4);
		IP_addr.Format("%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
		memset(&name, 0x00, sizeof(name));
		name.sin_family = AF_INET;
		inet_pton(AF_INET, IP_addr, &name.sin_addr);
		name.sin_port = htons(m_nPort);

		// connect
		if (connect(sock, (sockaddr*)&name, sizeof(name)) == SOCKET_ERROR)
			break;
		///////////////////////////////////////////////////////////////////////////////////
		//list 내용을 --> buf를 만들어 보내기
		///////////////////////////////////////////////////////////////////////////////////
		CStringArray arr;
		m_strlListGen.GetText(i, str); // -> list에 표시된 str이 온다.
		int idx = str.Find(":");
		seq = atoi(str.Left(idx)); //char to int : atoi
		//fprintf(fp, "%d\t%s\n", seq, str);
		arr.Add(str);

		int count = GetCountData(seq, i); //만든 함수
		for (int j = 1; j < count; j++)
		{
			m_strlListGen.GetText(++i, str);
			arr.Add(str);
		}
		sendData(sock, arr); //만든 함수
		closesocket(sock);
		Sleep(1);
	}
}




void CClientEmulatorprotocolDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CClientEmulatorprotocolDlg::OnBnClickedBtnreset()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_strlListGen.ResetContent();
}
