
// MyMFC2Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyMFC2.h"
#include "MyMFC2Dlg.h"
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


// CMyMFC2Dlg 대화 상자



CMyMFC2Dlg::CMyMFC2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMFC2_DIALOG, pParent)
	, m_strName(_T("Hong"))
	, m_strMobileTel(_T("01012341234"))
	, m_strOfficeTel(_T("051123123"))
	, m_strHomeTel(_T("051123123"))
	, m_strEmail(_T("qwer1234@daum.net"))
	, m_strBirth(_T("20050419"))
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMFC2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_strMobileTel);
	DDX_Text(pDX, IDC_EDIT3, m_strOfficeTel);
	DDX_Text(pDX, IDC_EDIT4, m_strHomeTel);
	DDX_Text(pDX, IDC_EDIT5, m_strEmail);
	DDX_Text(pDX, IDC_EDIT6, m_strBirth);
	//  DDX_LBString(pDX, IDC_LIST1, m_ctrlList);
	//  DDX_Control(pDX, IDC_LIST1, m_crtlList);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
}

BEGIN_MESSAGE_MAP(CMyMFC2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNLOAD, &CMyMFC2Dlg::OnBnClickedBtnload)
	ON_BN_CLICKED(IDC_BTNINSERT, &CMyMFC2Dlg::OnBnClickedBtninsert)
	ON_BN_CLICKED(IDC_BTNDELETE, &CMyMFC2Dlg::OnBnClickedBtndelete)
	ON_BN_CLICKED(IDC_BTNMODIFY, &CMyMFC2Dlg::OnBnClickedBtnmodify)
	ON_BN_CLICKED(IDC_BTNSAVE, &CMyMFC2Dlg::OnBnClickedBtnsave)
	ON_BN_CLICKED(IDCANCEL, &CMyMFC2Dlg::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyMFC2Dlg::OnSelchangeList1)
END_MESSAGE_MAP()


// CMyMFC2Dlg 메시지 처리기

BOOL CMyMFC2Dlg::OnInitDialog()
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

void CMyMFC2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyMFC2Dlg::OnPaint()
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
HCURSOR CMyMFC2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyMFC2Dlg::tockenstring(CStringArray& arr, CString& str) {
	CString t = "";
	for (int i = 0; i < str.GetLength(); i++) {
		char s = str.GetAt(i);
		if (s == ',') {
			arr.Add(t);
			t = "";
			continue;
		}
		t += s;
	}
	arr.Add(t);
}

void CMyMFC2Dlg::OnBnClickedBtnload()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("Load"));
	FILE* fp;
	errno_t err = fopen_s(&fp, "context.txt", "rt");
	if (err != 0) {  //0이면 성공, 0이 아니면 실패
		AfxMessageBox(_T("Fail to open file!"));
		return;
	}

	m_ctrlList.ResetContent();

	char fpln[64];
	while (fgets(fpln, 64, fp) != NULL)
	{
		int len = strlen(fpln);
		if (fpln[len - 1] == '\n')
			fpln[len - 1] = '\0';

		if (strlen(fpln) != 0) //if (0<strlen(fpln))
			m_ctrlList.AddString((LPCTSTR)fpln);
	}
	fclose(fp);
}


void CMyMFC2Dlg::OnBnClickedBtninsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("Insert"));
	UpdateData(TRUE);  //데이터를 적용해라 명령
	//같은 이름 있는지 검사
	CString str;
	for (int i = 0; i < m_ctrlList.GetCount(); i++) {
		m_ctrlList.GetText(i, str);

		CStringArray arr;
		tockenstring(arr, str);

		if (arr.GetAt(0) == m_strName) {
			AfxMessageBox(_T("Same name exists"));
			return;
		}
	}
	//같은 이름 없으면 list에 추가
	m_ctrlList.AddString(m_strName + "," + m_strMobileTel + "," + m_strOfficeTel + "," + m_strHomeTel + "," + m_strEmail + "," + m_strBirth);
	
}


void CMyMFC2Dlg::OnBnClickedBtndelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("Delete"));
	
	int ccel = m_ctrlList.GetCurSel(); //현재 선택된 놈을 가져와라
	if (ccel == LB_ERR) { // == 기억하자
		AfxMessageBox(_T("Nothing to delete! Select sentance or Out please."));
		return;
	} 

	m_ctrlList.DeleteString(ccel);
}


void CMyMFC2Dlg::OnBnClickedBtnmodify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("Modify"));
	UpdateData(TRUE);  //데이터 추출 - TRUE
	CString str;
	for (int i = 0; i < m_ctrlList.GetCount(); i++) {
		m_ctrlList.GetText(i, str);
		
		CStringArray arr;
		tockenstring(arr, str);

		if (arr.GetAt(0) == m_strName) {
			str = m_strName + "," + m_strMobileTel + "," + m_strOfficeTel + "," + m_strHomeTel + "," + m_strEmail + "," + m_strBirth;
			m_ctrlList.DeleteString(i);
			m_ctrlList.InsertString(i, str);
			
			return;
		}
	}
	AfxMessageBox(_T("Can't find name. Nothing to modify."));
	//이름 바꾸면 나타나는 오류 문구 - 이름이 키로 작용하기 때문
}


void CMyMFC2Dlg::OnBnClickedBtnsave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("Save"));
	FILE* fp;
	errno_t err = fopen_s(&fp, "context.txt", "wt");
	if (err != 0) {  //0이면 성공, 0이 아니면 실패
		AfxMessageBox(_T("Fail to open file!"));
		return;
	}
	CString str;
	for (int i = 0; i < m_ctrlList.GetCount(); i++) {
		m_ctrlList.GetText(i, str);
		fprintf(fp, "%s\n", str);
	}
	fclose(fp);
	AfxMessageBox(_T("Save Succefully"));

}


void CMyMFC2Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

//변수에 있는 값을 컨트롤에 보여라
void CMyMFC2Dlg::OnSelchangeList1() 
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int nSel = m_ctrlList.GetCurSel();
	if (nSel == LB_ERR)return;

	CString str;
	m_ctrlList.GetText(nSel, str);

	CStringArray arr;
	tockenstring(arr, str);

	m_strName = arr.GetAt(0);
	m_strMobileTel = arr.GetAt(1);
	m_strOfficeTel = arr.GetAt(2);
	m_strHomeTel = arr.GetAt(3);
	m_strEmail = arr.GetAt(4);
	m_strBirth = arr.GetAt(5);

	UpdateData(FALSE);
}
