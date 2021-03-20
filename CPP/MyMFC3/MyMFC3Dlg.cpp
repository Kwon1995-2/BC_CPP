
// MyMFC3Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyMFC3.h"
#include "MyMFC3Dlg.h"
#include "afxdialogex.h"
#include "Myhash.h"

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


// CMyMFC3Dlg 대화 상자



CMyMFC3Dlg::CMyMFC3Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMFC3_DIALOG, pParent)
	, m_strName(_T(""))
	, m_strMobileTel(_T(""))
	, m_strOfficeTel(_T(""))
	, m_strHomeTel(_T(""))
	, m_strEmail(_T(""))
	, m_strBirth(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMFC3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_strMobileTel);
	DDX_Text(pDX, IDC_EDIT3, m_strOfficeTel);
	DDX_Text(pDX, IDC_EDIT4, m_strHomeTel);
	DDX_Text(pDX, IDC_EDIT5, m_strEmail);
	DDX_Text(pDX, IDC_EDIT6, m_strBirth);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList);
	DDX_Control(pDX, IDC_LIST2, m_ctrlList2);
}

BEGIN_MESSAGE_MAP(CMyMFC3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNLOAD, &CMyMFC3Dlg::OnBnClickedBtnload)
	ON_BN_CLICKED(IDC_BTNINSERT, &CMyMFC3Dlg::OnBnClickedBtninsert)
	ON_BN_CLICKED(IDC_BTNDELETE, &CMyMFC3Dlg::OnBnClickedBtndelete)
	ON_BN_CLICKED(IDC_BTNMODIFY, &CMyMFC3Dlg::OnBnClickedBtnmodify)
	ON_BN_CLICKED(IDC_BTNSAVE, &CMyMFC3Dlg::OnBnClickedBtnsave)
	ON_BN_CLICKED(IDCANCEL, &CMyMFC3Dlg::OnBnClickedCancel)
	ON_LBN_SELCHANGE(IDC_LIST1, &CMyMFC3Dlg::OnSelchangeList1)
END_MESSAGE_MAP()


// CMyMFC3Dlg 메시지 처리기

BOOL CMyMFC3Dlg::OnInitDialog()
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

void CMyMFC3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyMFC3Dlg::OnPaint()
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
HCURSOR CMyMFC3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMyMFC3Dlg::displayHashList() {
	//NODE** bucketArray = hash->getBucketArray();
	Node** bucketArray = hash.getBackArray();
	m_ctrlList.ResetContent();
	for (int i = 0; i < hash.getBucketSize(); i++) {
		Node* t = bucketArray[i];
		if (t == NULL) continue;
		while (1) {
			string str = t->name + "," + t->mobile_tel + "," + t->office_tel + "," + t->home_tel + "," + t->e_mail + "," + t->birth;
			
			m_ctrlList.AddString((LPCTSTR)str.c_str());

			t = t->next;
			if (t == NULL) break;
		
		}
	}
	//
	//Node** bucketArray = hash.getBackArray();
	/*m_ctrlList2.ResetContent();
	for (int i = 0; i < hash.getBucketSize(); i++) {
		Node* t = bucketArray[i];
		cout << "bucket[" << i << "]:";
		int j = 0;

		if (t == NULL) continue;
		while (1) {
			string str = t->name + ",";

			m_ctrlList2.AddString((LPCTSTR)str.c_str()); j++;

			t = t->next;
			if (t == NULL) break;

		}
		cout << j;
		cout << endl;
	}
	cout << endl;*/
}
void CMyMFC3Dlg::tockenstring(vector<string>& vec, char* pstr, size_t len) {
	string t = "";
	for (size_t i = 0; i < len; i++) {
		if (pstr[i] == ',') {
			vec.push_back(t);
			t = "";
			continue;
		}
		t += pstr[i];
	}
	vec.push_back(t);
}

void CMyMFC3Dlg::displayHashList2() {
	//NODE** bucketArray = hash->getBucketArray();
	Node** bucketArray = hash.getBackArray();
	m_ctrlList2.ResetContent();
	for (int i = 0; i < hash.getBucketSize(); i++) {
		Node* t = bucketArray[i];
		string str = "bucket["+ to_string(i)+ "]:";
		int j = 0;
		if (t == NULL) {
			str += "0";
		}
		else {
			while (1) {
				str += t->name + ",";
				j++;
				t = t->next;
				if (t == NULL) {
					break;
				}
			}
			str += to_string(j);
		}
		m_ctrlList2.AddString((LPCTSTR)str.c_str());
	}
	// 
}

void CMyMFC3Dlg::OnBnClickedBtnload()
{
	hash.dataload("contact.txt");
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//AfxMessageBox(_T("Load"));
	//FILE* fp;
	//errno_t err = fopen_s(&fp, "context.txt", "rt");
	//if (err != 0) {  //0이면 성공, 0이 아니면 실패
	//	AfxMessageBox(_T("Fail to open file!"));
	//	return;
	//}
	//int idx = 0;
	//
	//char fpln[64];
	//while (fgets(fpln, 64, fp) != NULL)
	//{
	//	int len = strlen(fpln);
	//	if (fpln[len - 1] == '\n')
	//		fpln[len - 1] = '\0';
	//	vector<string> vec;
	//	hash.tockenstring(vec, fpln, strlen(fpln));
	//	hash.insertNode(vec[idx], vec[idx + 1], vec[idx + 2], vec[idx + 3], vec[idx + 4], vec[idx + 5]);
	//	idx += 6;

	//	if (strlen(fpln) != 0) //if (0<strlen(fpln))
	//		m_ctrlList.AddString((LPCTSTR)fpln);
	//}
	//fclose(fp);
	
	displayHashList();
	displayHashList2();
}


void CMyMFC3Dlg::OnBnClickedBtninsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);

	CString str;
	
	for (int i = 0; i < m_ctrlList.GetCount(); i++) {
		m_ctrlList.GetText(i, str);
		vector<string> vec;
		tockenstring(vec, (LPSTR)(LPCTSTR)str, str.GetLength());

		if (vec[0].c_str() == m_strName) {
			AfxMessageBox(_T("Same name exists"));
			return;
		}
	}

	hash.insertNode((string)m_strName, (string)m_strMobileTel, (string)m_strOfficeTel,(string)m_strHomeTel,(string)m_strEmail,(string)m_strBirth);
	displayHashList();
	displayHashList2();
	m_strName = m_strMobileTel = m_strOfficeTel = m_strHomeTel = m_strEmail = m_strBirth = "";
	UpdateData(FALSE);
}


void CMyMFC3Dlg::OnBnClickedBtndelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	int ccel = m_ctrlList.GetCurSel(); //현재 선택된 놈을 가져와라
	vector<string> vec;
	CString str;
	if (ccel == LB_ERR) { // == 기억하자
		AfxMessageBox(_T("Nothing to delete! Select sentance or Out please."));
		return;
	}
	m_ctrlList.GetText(ccel, str);
	tockenstring(vec, (LPSTR)(LPCTSTR)str, str.GetLength());
	hash.deleteNode(vec[0]);
	displayHashList();
	displayHashList2();
}


void CMyMFC3Dlg::OnBnClickedBtnmodify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	
	//hash.deleteNode(vec[0]);
	
	UpdateData(TRUE);  //데이터 추출 - TRUE
	
	CString str;
	for (int i = 0; i < m_ctrlList.GetCount(); i++) {
		m_ctrlList.GetText(i, str);

		vector<string> vec;
		tockenstring(vec, (LPSTR)(LPCTSTR)str, str.GetLength());

		if (vec[0] == (string)m_strName) {
			//str = m_strName + "," + m_strMobileTel + "," + m_strOfficeTel + "," + m_strHomeTel + "," + m_strEmail + "," + m_strBirth;
			hash.modifyNode((string)m_strName, (string)m_strMobileTel, (string)m_strOfficeTel, (string)m_strHomeTel, (string)m_strEmail, (string)m_strBirth);
			//hash.insertNode((string)m_strName, (string)m_strMobileTel, (string)m_strOfficeTel, (string)m_strHomeTel, (string)m_strEmail, (string)m_strBirth);
			hash.deleteNode(vec[0]);
			displayHashList();
			displayHashList2();
			return;
		}
	}
	AfxMessageBox(_T("Can't find name. Nothing to modify."));

	//displayHashList();
}


void CMyMFC3Dlg::OnBnClickedBtnsave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	FILE* fp;
	errno_t err = fopen_s(&fp, "contact.txt", "wt");
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


void CMyMFC3Dlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

void CMyMFC3Dlg::OnSelchangeList1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	vector<string> vec;
	CString str;
	int nSel = m_ctrlList.GetCurSel();
	if (nSel == LB_ERR)return;
	
	m_ctrlList.GetText(nSel, str);
	tockenstring(vec, (LPSTR)(LPCTSTR)str, str.GetLength());
	
	m_strName = vec[0].c_str();
	m_strMobileTel = vec[1].c_str();
	m_strOfficeTel = vec[2].c_str();
	m_strHomeTel = vec[3].c_str();
	m_strEmail = vec[4].c_str();
	m_strBirth = vec[5].c_str();

	UpdateData(FALSE);
}



