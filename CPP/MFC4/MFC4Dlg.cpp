
// MFC4Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC4.h"
#include "MFC4Dlg.h"
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


// CMFC4Dlg 대화 상자



CMFC4Dlg::CMFC4Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC4_DIALOG, pParent)
	, m_strSearchStr(_T(""))
	, m_strLoadFileName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_pTree = new TrieTree;
}
CMFC4Dlg::~CMFC4Dlg() {
	delete m_pTree;
}

void CMFC4Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strSearchStr);
	DDX_Text(pDX, IDC_EDIT2, m_strLoadFileName);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Control(pDX, IDC_LIST2, m_ctrlList2);
	DDX_Control(pDX, IDC_LIST3, m_ctrlList3);
}

BEGIN_MESSAGE_MAP(CMFC4Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNLoad, &CMFC4Dlg::OnBnClickedBtnload)
	ON_BN_CLICKED(IDC_BTNSearch, &CMFC4Dlg::OnBnClickedBtnsearch)
	ON_BN_CLICKED(IDCANCEL, &CMFC4Dlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CMFC4Dlg 메시지 처리기

BOOL CMFC4Dlg::OnInitDialog()
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

void CMFC4Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFC4Dlg::OnPaint()
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
HCURSOR CMFC4Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int CMFC4Dlg::tockenstring(vector<CString>& vec, vector<int>& idxs, CString& str) {//str->파일에 있는 글
	CString t = "";
	int cnt = -1;
	for (int i = 0; i < str.GetLength();i++) {
		char ch = str.GetAt(i);
		if (ch < 'A' || ch > 'Z') {
			if (t.GetLength() > 0) {
				vec.push_back(t);
				idxs.push_back(cnt);
				t = "";
			}
			cnt = -1;
			continue;
		}
		t += ch;
		if (cnt < 0) { 
			cnt = i;
		}
	}
	if (t.GetLength() > 0) { 
		vec.push_back(t); 
		idxs.push_back(cnt);
	}
	return idxs.size(); //몇번 짤랐냐를 리턴해야 함 -> simon 5가 리턴됨 그래서 오류가 남
}
void CMFC4Dlg::OnBnClickedBtnload()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	TCHAR szFilters[] = _T("Text Files (*.txt)|*.txt|All Files (*.*)|*.*||");
	CFileDialog fdlg(TRUE, _T("*.txt"), NULL, OFN_HIDEREADONLY, szFilters);
	if (fdlg.DoModal() != IDOK) return;
	
	m_strLoadFileName = fdlg.GetPathName();

	CStdioFile file;

	if (!file.Open(m_strLoadFileName, CFile::modeRead)) {
		AfxMessageBox("Fail to open file!");
		return;
	}

	m_ctrlList1.ResetContent();

	m_pTree->reset();//class 이름 trietree m_pTree

	int row = 0;
	CString str, tstr;
	while (file.ReadString(str)) {
		str.MakeUpper();
		tstr.Format(_T("[%d]%s"), row, (LPCTSTR)str);
		m_ctrlList1.AddString(tstr);

		//Trie에 삽입할 단어로 분리
		vector<CString> arr;
		vector<int> idxs;
		int cnt = tockenstring(arr, idxs, str);
		
		if (cnt > 0)
		{
			CString tstr;
			for (int i = 0; i < cnt; i++)
			{
				tstr.Format(_T("[%d][%d]%s"), row, idxs[i], (LPCTSTR)arr[i]);

				TrieTree* ret = m_pTree->find(arr[i]);

				if (ret) 
				{
					ret->insert(ret, row, idxs[i]);
				}
				else
				{
					m_pTree->insert(arr[i], row, idxs[i]);
				}
				m_ctrlList2.AddString(tstr);
			}
		}
		row++;
	}
	file.Close();
	UpdateData(FALSE);
	/*FILE* fp;
	errno_t err = fopen_s(&fp, "contact.txt", "rt");
	if (err != 0) {
		AfxMessageBox("Fail to open file!");
		return;
	}

	char fpln[64];
	while (fgets(fpln, 64, fp) != NULL)
	{
		int len = strlen(fpln);
		if (fpln[len - 1] == '\n')
			fpln[len - 1] = '\0';
		m_ctrlList1.AddString(fpln);
	}
	fclose(fp);*/
}


void CMFC4Dlg::OnBnClickedBtnsearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMFC4Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}
