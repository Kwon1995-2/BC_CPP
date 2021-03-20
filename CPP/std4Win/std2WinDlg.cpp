
// std2WinDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "std2Win.h"
#include "std2WinDlg.h"
#include "afxdialogex.h"
#include "MYDlg.h"
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


// Cstd2WinDlg 대화 상자



Cstd2WinDlg::Cstd2WinDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STD2WIN_DIALOG, pParent)
	, m_strMsg(_T(""))
	, m_nPort(2500)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cstd2WinDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_MSG, m_ctrlListMsg);
	DDX_Control(pDX, IDC_LIST_IP, m_ctrlListIp);
	DDX_Text(pDX, IDC_EDIT_MSG, m_strMsg);
	DDX_Text(pDX, IDC_EDIT_PORT, m_nPort);
	DDX_Control(pDX, IDC_IPADDRESS1, m_IPADDRCtrl);
}

BEGIN_MESSAGE_MAP(Cstd2WinDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_FILERECV, &Cstd2WinDlg::OnBnClickedBtnFilerecv)
	ON_BN_CLICKED(IDC_BTN_MSGADD, &Cstd2WinDlg::OnBnClickedBtnMsgadd)
	ON_BN_CLICKED(IDC_BTN_MSGDEL, &Cstd2WinDlg::OnBnClickedBtnMsgdel)
	ON_BN_CLICKED(IDC_BTN_MSGRES, &Cstd2WinDlg::OnBnClickedBtnMsgres)
	ON_BN_CLICKED(IDC_BTN_MSGSEND, &Cstd2WinDlg::OnBnClickedBtnMsgsend)
	ON_BN_CLICKED(IDC_BTN_IPADD, &Cstd2WinDlg::OnBnClickedBtnIpadd)
	ON_BN_CLICKED(IDC_BTN_IPDEL, &Cstd2WinDlg::OnBnClickedBtnIpdel)
	ON_BN_CLICKED(IDC_BTN_IPRES, &Cstd2WinDlg::OnBnClickedBtnIpres)
END_MESSAGE_MAP()


// Cstd2WinDlg 메시지 처리기

BOOL Cstd2WinDlg::OnInitDialog()
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
	m_IPADDRCtrl.SetAddress(127, 0, 0, 1);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void Cstd2WinDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void Cstd2WinDlg::OnPaint()
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
HCURSOR Cstd2WinDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}





void Cstd2WinDlg::OnBnClickedBtnFilerecv()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlListMsg.ResetContent();
	static TCHAR BASED_CODE szFilter[] = _T("텍스트 파일(*.txt) | *.txt |모든파일(*.*)|*.*||");

	CFileDialog dlg(TRUE, _T("txt"), _T("*.txt"), OFN_HIDEREADONLY, szFilter);
	if (dlg.DoModal() != IDOK)	return;

	CString pathName = dlg.GetPathName();

	CStdioFile file;
	if (!file.Open(pathName, CFile::modeRead))
	{
		AfxMessageBox("Error");
		return;
	}
	CString rstr;
	while (file.ReadString(rstr))
	{
		m_ctrlListMsg.AddString(rstr);
	}
	file.Close();

	//FILE* fp;
	//errno_t err = fopen_s(&fp, pathName, "rt");
	//if (err != 0) {  //0이면 성공, 0이 아니면 실패
	//	AfxMessageBox("Fail to open file!");
	//	return;
	//}

	//m_ctrlListMsg.ResetContent();

	//char fpln[64];
	//while (fgets(fpln, 64, fp) != NULL)
	//{
	//	int len = strlen(fpln);
	//	if (fpln[len - 1] == '\n')
	//		fpln[len - 1] = '\0';

	//	if (strlen(fpln) != 0) //if (0<strlen(fpln))
	//		m_ctrlListMsg.AddString((LPCTSTR)fpln);
	//}
	//fclose(fp);
}


void Cstd2WinDlg::OnBnClickedBtnMsgadd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrlListMsg.AddString(m_strMsg);
	m_strMsg.Empty();
	UpdateData(FALSE);
}


void Cstd2WinDlg::OnBnClickedBtnMsgdel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int cel = m_ctrlListMsg.GetCurSel();
	if (cel == LB_ERR) {
		AfxMessageBox("Delete Error");
		return;
	}
	m_ctrlListMsg.DeleteString(cel);

}


void Cstd2WinDlg::OnBnClickedBtnMsgres()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlListMsg.ResetContent();
	//UpdateData(FALSE);
}

void Cstd2WinDlg::OnBnClickedBtnIpadd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString IP_addr, port;
	BYTE ip_1, ip_2, ip_3, ip_4;

	m_IPADDRCtrl.GetAddress(ip_1, ip_2, ip_3, ip_4);
	IP_addr.Format("%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
	port.Format("%d", m_nPort);
	//port error처리
	//m_ctrlListIp.AddString(IP_addr + ":" + port);
	//int nindex = 0;
	if ( m_ctrlListIp.FindString(0, IP_addr) == LB_ERR) //추가하고자 하는 문자열이 없어야 추가
	{
		m_ctrlListIp.AddString(IP_addr + ":" + port);
		return;
	}
	else AfxMessageBox("Inset Error");
	
	/*else {
		m_ctrlListIp.AddString(IP_addr + ":" + port);
	}*/
}


void Cstd2WinDlg::OnBnClickedBtnIpdel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int cel = m_ctrlListIp.GetCurSel();
	if (cel == LB_ERR) {
		AfxMessageBox("Delete Error");
		return;
	}
	m_ctrlListIp.DeleteString(cel);
}


void Cstd2WinDlg::OnBnClickedBtnIpres()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_ctrlListIp.ResetContent();
}

//void Cstd2WinDlg::OnBnClickedBtnMsgsend()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	for (int i = 0; i < m_ctrlListIp.GetCount(); i++) {
//		UpdateData(TRUE);
//		// socket
//		int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//		if (sock == INVALID_SOCKET)
//		{
//			AfxMessageBox("socket() failed![%d]\n", WSAGetLastError());
//			UpdateData(FALSE);
//			return;
//		}
//
//		sockaddr_in name;
//		CString IP_addr;
//		BYTE ip_1, ip_2, ip_3, ip_4;
//		m_IPADDRCtrl.GetAddress(ip_1, ip_2, ip_3, ip_4);
//		IP_addr.Format("%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
//		memset(&name, 0x00, sizeof(name));
//		name.sin_family = AF_INET;
//		inet_pton(AF_INET, IP_addr, &name.sin_addr);
//		name.sin_port = htons(m_nPort);
//
//		// connect
//		if (connect(sock, (sockaddr*)&name, sizeof(name)) == SOCKET_ERROR)
//		{
//			AfxMessageBox("socket() failed![%d]\n", WSAGetLastError());
//			UpdateData(FALSE);
//			closesocket(sock);
//			return;
//		}
//
//		for (int i = 0; i < m_ctrlListMsg.GetCount(); i++) {
//			//소켓 열기
//
//			CString str;
//			m_ctrlListMsg.GetText(i, str);
//
//			// send
//			if (send(sock, str, str.GetLength(), 0) == SOCKET_ERROR) //if (send(sock, m_strMsg, m_strMsg.GetLength(), 0) == SOCKET_ERROR)
//			{
//				AfxMessageBox("send() failed![% d]\n", WSAGetLastError());
//				return;
//			}
//			//else
//			//	AfxMessageBox("success\n");
//	//		UpdateData(FALSE);
//			//소켓 닫기
//			closesocket(sock);
//		}
//		closesocket(sock);
//	}
//}

//한 줄씩 출력하는 함수
void Cstd2WinDlg::OnBnClickedBtnMsgsend()
{
	CString str;

	/*CMYDlg Dlg;
	if (Dlg.DoModal() != IDOK)
		return;*/

	// IP:Port 하나씩 읽어온다.
	for (int i = 0; i < m_ctrlListIp.GetCount(); i++)
	{
		for (int j = 0; j < m_ctrlListMsg.GetCount(); j++)
		{
			m_ctrlListMsg.GetText(j, str);

			// socket
			int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sock == INVALID_SOCKET)	continue;

			sockaddr_in name;
			CString IP_addr;
			BYTE ip_1, ip_2, ip_3, ip_4;
			m_IPADDRCtrl.GetAddress(ip_1, ip_2, ip_3, ip_4);
			IP_addr.Format("%d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4);
			memset(&name, 0x00, sizeof(name));
			name.sin_family = AF_INET;
			inet_pton(AF_INET, IP_addr, &name.sin_addr);
			name.sin_port = htons(m_nPort);

			// connect
			if (connect(sock, (sockaddr*)&name, sizeof(name)) == SOCKET_ERROR)
				break;

			// send
			send(sock, str, str.GetLength(), 0);
			closesocket(sock);
		}
	}
}