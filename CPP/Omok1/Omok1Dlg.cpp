
// Omok1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "Omok1.h"
#include "Omok1Dlg.h"
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


// COmok1Dlg 대화 상자



COmok1Dlg::COmok1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_OMOK1_DIALOG, pParent)
	, m_nPort(4000)
	, m_strResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COmok1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_nPort);
	DDX_Text(pDX, IDC_EDIT2, m_strResult);
	DDX_Control(pDX, IDC_IPADDRESS1, m_ctrlIPAddress);
}

BEGIN_MESSAGE_MAP(COmok1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_BN_CLICKED(IDC_BTNRESTART, &COmok1Dlg::OnBnClickedBtnrestart)
	ON_BN_CLICKED(IDCANCEL, &COmok1Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// COmok1Dlg 메시지 처리기

BOOL COmok1Dlg::OnInitDialog()
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

	OnBnClickedBtnrestart();
	m_ctrlIPAddress.SetAddress(127, 0, 0, 1);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void COmok1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void COmok1Dlg::OnPaint()
{
	CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	if (IsIconic())
	{
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
		dc.SelectStockObject(DC_BRUSH);
		dc.SetDCBrushColor(RGB(225, 128, 0));
		for (int i = 0; i < 18; i++)
			for (int j = 0; j < 18; j++)
				dc.Rectangle(15 + 30 * i, 15 + 30 * j, 46 + 30 * i, 46 + 30 * j);
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR COmok1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

int COmok1Dlg::winloss(int index, int indey, int turn, int i, int j)
{
	int score = 0;
	/*for (int p = -4; p < 0; p++)
		score = save[4 + indey + i * p][4 + index + j * p];

	for (int q = 0; q < 5; q++)
	{
		score = score + save[4 + indey + i * q][4 + index + j * q];
		if (score != turn * 5)
			score = score - save[4 + indey + i * (4 - q)][4 + index + j * (4 - q)];
		else return turn;
	}
	return 0;*/
	for (int k = 0; k < 5; k++)
	{
		for (int p = 0; p < 5; p++)
		{
			score = score + save[4 + indey + i * (k - p)][4 + index + j * (k - p)];
		}
		if (score != turn * 5) score = 0;
		else				   return turn;
	}
	return 0;
}
  
void COmok1Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	int index = point.x / 30;
	int indey = point.y / 30;

	if (index < 19 && indey < 19 && !save[indey + 4][index + 4])
	{
		save[indey + 4][index + 4] = turn;
		CClientDC dc(this);
		dc.SelectStockObject(DC_BRUSH);
		dc.SetDCBrushColor(0X00FFFFFF * (turn - 6));
		dc.Ellipse(30 * index, 30 * indey, 30 + 30 * index, 30 + 30 * indey);

		int Winner = 0;
		for (int i = -1; i < 1; i++)
			Winner = Winner + winloss(index, indey, turn, i, 1);

		for (int q = 0; q < 2; q++)
			Winner = Winner + winloss(index, indey, turn, 1, q);
		
		if (Winner == 0) turn = 13 - turn; //승패가 나지 않으면
		else if (Winner % 7) AfxMessageBox("흑이 이겼습니다!!!"); //Winner가 0이 아니면 흑 Win
		else				 AfxMessageBox("백이 이겼습니다!!!"); //Winner가 0이면 백 Win
	}
	else AfxMessageBox("다른 곳에 두시오!");

	CDialogEx::OnLButtonDown(nFlags, point);
}


void COmok1Dlg::OnBnClickedBtnrestart()
{
	//바둑판 초기화
	memset(save, 0, sizeof(int) * (18 + 8) * (18 + 8));
	turn = 6;

	Invalidate(TRUE); // 화면 그리기 갱신
	//Invalidate(FALSE); //화면 덮어쓰기
}


void COmok1Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}




