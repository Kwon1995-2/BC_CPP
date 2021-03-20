
// PatternMatchingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "PatternMatching.h"
#include "PatternMatchingDlg.h"
#include "afxdialogex.h"
#include <string>
using namespace std;
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


// CPatternMatchingDlg 대화 상자



CPatternMatchingDlg::CPatternMatchingDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PATTERNMATCHING_DIALOG, pParent)
	, m_strPString(_T("abacab"))
	, m_nType(0)
	, m_strText(_T("abacaabaccabacabaabbabacaabaccabacabaabbabacaabaccabacabaabb"))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPatternMatchingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strPString);

	DDX_Control(pDX, IDC_LIST2, m_ctrlList2);
	DDX_Radio(pDX, IDC_RADIO1, m_nType);
	DDX_Text(pDX, IDC_EDIT2, m_strText);
}

BEGIN_MESSAGE_MAP(CPatternMatchingDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNSEARCH, &CPatternMatchingDlg::OnBnClickedBtnsearch)
	ON_BN_CLICKED(IDCANCEL, &CPatternMatchingDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CPatternMatchingDlg 메시지 처리기

BOOL CPatternMatchingDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CPatternMatchingDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPatternMatchingDlg::OnPaint()
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
HCURSOR CPatternMatchingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPatternMatchingDlg::OnBnClickedBtnsearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/*if (m_nType == 0) {
		string str = "";
		PatternMatch* pm = new Brute_Force;
		str += "BF:";
		int idx = pm->patternmatch((LPSTR)(LPCTSTR)m_strText, (LPSTR)(LPCTSTR)m_strText);
		str += to_string(idx);
		m_ctrlList2.AddString((LPCTSTR)str.c_str());
	}
	else {

	}*/
	UpdateData(TRUE);
	m_ctrlList2.ResetContent();
	PatternMatch* pm;
	if (m_nType == 0) pm = new Brute_Force;
	else pm = new Boyer_Moore;

	const char* pText = (LPCTSTR)m_strText;
	const char* pPtrn = (LPCTSTR)m_strPString;

	int offset = 0;
	CString str;
	while (1)
	{
		int i = pm->patternmatch(pText + offset, pPtrn); //pText에서 offset을 더한 번째의 원소를 호출
		if (i < 0) break; //같은 것이 없다는 뜻

		i += offset;
		str.Format("%s%d", pm->getTypeName(), i); // BF: or BM:
		m_ctrlList2.AddString(str);

		offset = i + strlen(pPtrn); //찾게 된 같은 문자열에서 패턴 문자열을 더한, 즉 아직 비교하지 않은 문자열부터 비교 시작
	}
	delete pm;
}



void CPatternMatchingDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}
