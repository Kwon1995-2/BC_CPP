
// MyBooksDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyBooks.h"
#include "MyBooksDlg.h"
#include "afxdialogex.h"
#include "myAuthor.h"
#include "myPublisher.h"
#include "mysql.h"

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


// CMyBooksDlg 대화 상자



CMyBooksDlg::CMyBooksDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYBOOKS_DIALOG, pParent)
	, m_nbookID(_T(""))
	, m_nauthorID(_T(""))
	, m_nPubID(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyBooksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Text(pDX, IDC_EDIT1, m_nbookID);
	DDX_Text(pDX, IDC_EDIT2, m_nauthorID);
	DDX_Text(pDX, IDC_EDIT3, m_nPubID);
}

BEGIN_MESSAGE_MAP(CMyBooksDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNVIEW_A, &CMyBooksDlg::OnBnClickedBtnviewA)
	ON_BN_CLICKED(IDC_BTNVIEW_P, &CMyBooksDlg::OnBnClickedBtnviewP)
	ON_BN_CLICKED(IDC_BTNSEARCH, &CMyBooksDlg::OnBnClickedBtnsearch)
	ON_BN_CLICKED(IDC_BTNMODIFY, &CMyBooksDlg::OnBnClickedBtnmodify)
	ON_BN_CLICKED(IDC_BTNDELETE, &CMyBooksDlg::OnBnClickedBtndelete)
END_MESSAGE_MAP()


// CMyBooksDlg 메시지 처리기

BOOL CMyBooksDlg::OnInitDialog()
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
	CRect rect;
	m_ctrlList1.GetClientRect(rect);
	m_ctrlList1.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList1.InsertColumn(0, "book_ID", LVCFMT_LEFT, rect.Width()*0.1, -1);
	m_ctrlList1.InsertColumn(1, "title", LVCFMT_LEFT, rect.Width() * 0.5, -1);
	m_ctrlList1.InsertColumn(2, "price", LVCFMT_LEFT, rect.Width() * 0.2, -1);
	m_ctrlList1.InsertColumn(3, "author_ID", LVCFMT_LEFT, rect.Width() * 0.1, -1);
	m_ctrlList1.InsertColumn(4, "publisher_ID", LVCFMT_LEFT, rect.Width() * 0.1, -1);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMyBooksDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyBooksDlg::OnPaint()
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
HCURSOR CMyBooksDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyBooksDlg::OnBnClickedBtnviewA()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	myAuthor dlg;
	dlg.DoModal();
}


void CMyBooksDlg::OnBnClickedBtnviewP()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	myPublisher dlg2;
	dlg2.DoModal();
}


void CMyBooksDlg::OnBnClickedBtnsearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//mysql DB 조회

	mysql_close(&mysql);
	UpdateData(FALSE);
}


void CMyBooksDlg::OnBnClickedBtnmodify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMyBooksDlg::OnBnClickedBtndelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
