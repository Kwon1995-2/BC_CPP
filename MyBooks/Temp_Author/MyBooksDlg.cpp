
// MyBooksDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MyBooks.h"
#include "MyBooksDlg.h"
#include "afxdialogex.h"
#include "myAuthor.h"
#include "myPublisher.h"
#include "Updatedlg.h"
#include "InsertBook.h"
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
	//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMyBooksDlg::OnItemchangedList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMyBooksDlg::OnClickList1)
	ON_BN_CLICKED(IDCCANCEL, &CMyBooksDlg::OnBnClickedCcancel)
	ON_BN_CLICKED(IDC_BTNINSERT, &CMyBooksDlg::OnBnClickedBtninsert)
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
	// 비트 연산
	//m_ctrlList1.ModifyStyle(0, LVS_SHOWSELALWAYS);
	m_ctrlList1.SetExtendedStyle(m_ctrlList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_ctrlList1.ModifyStyle(0, LVS_SHOWSELALWAYS);
	//m_ctrlList1.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList1.InsertColumn(0, "도서 ID", LVCFMT_LEFT, int(rect.Width() * 0.1), -1);
	m_ctrlList1.InsertColumn(1, "제목", LVCFMT_LEFT, int(rect.Width() * 0.5), -1);
	m_ctrlList1.InsertColumn(2, "가격", LVCFMT_LEFT, int(rect.Width() * 0.2), -1);
	m_ctrlList1.InsertColumn(3, "저자 ID", LVCFMT_LEFT, int(rect.Width() * 0.1), -1);
	m_ctrlList1.InsertColumn(4, "출판사 ID", LVCFMT_LEFT, int(rect.Width() * 0.1), -1);


	m_tooltip.Create(this, TTS_ALWAYSTIP | TTS_BALLOON);
	m_tooltip.AddTool(GetDlgItem(IDC_KeySTATIC), "소설 : 1000~1999 | 과학 : 2000~2999 | 만화 : 3000~3999");
	m_tooltip.SetTipBkColor(RGB(255, 255, 0));
	m_tooltip.SetTipTextColor(RGB(0, 0, 0));


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


//author table 보기
void CMyBooksDlg::OnBnClickedBtnviewA()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	myAuthor dlg;
	//DoModal() -> Author 데이터 뛰우기

	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[100];
	memset(query, NULL, 100); //배열 초기화
	CString str = m_nauthorID.GetString();
	if (str == "") { //저자 ID에 아무것도 없을 때, 아무 수행도 하지 않음
		dlg.DoModal();
		mysql_close(&mysql);
		return;
	}
	//검색 단어 없으면 테이블 다 표시

	//질의 보내기
	sprintf_s(query, "select author_ID, name, phone, e_mail, sns from author where author_ID = %d", _ttoi(str)); //정수로 바꾸기
	mysql_query(&mysql, query);
	//dlg.m_ctrlList_Aut.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
	MYSQL_RES* result = mysql_store_result(&mysql); //질의 결과
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	//도서ID는 무조건 하나 -> listcontrol에 나타내기
	MYSQL_ROW row;
	int idx = 0;
	//while (row = mysql_fetch_row(result))
	//{
	//	dlg.m_ctrlList_Aut.InsertItem(idx, row[0]);
	//	for (int i = 1; i <= 4; i++)
	//	{
	//		dlg.m_ctrlList_Aut.SetItemText(idx, i, row[i]);
	//	}
	//	idx++;
	//}
	row = mysql_fetch_row(result);

	//m_ctrlList1.SetExtendedStyle(LVS_EX_CHECKBOXES);
	dlg.Set(row[0], row[1], row[2], row[3], row[4]);
	dlg.DoModal();
	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	UpdateData(FALSE);
}

//publisher table 보기
void CMyBooksDlg::OnBnClickedBtnviewP()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	myPublisher dlg2;

	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[100];
	memset(query, NULL, 100); //배열 초기화
	CString str = m_nPubID.GetString();
	if (str == "") { //출판사 ID에 아무것도 없을 때, 아무 수행도 하지 않음
		dlg2.DoModal();
		mysql_close(&mysql);
		return;
	}
	//검색 단어 없으면 테이블 다 표시

	//질의 보내기
	//if(str == "") sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher");
	//else          sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = %d", _ttoi(str)); //정수로 바꾸기 
	sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = %d", _ttoi(str));
	mysql_query(&mysql, query);
	//dlg.m_ctrlList_Aut.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
	MYSQL_RES* result = mysql_store_result(&mysql); //질의 결과
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	//도서ID는 무조건 하나 -> listcontrol에 나타내기

	MYSQL_ROW row;
	int idx = 0;
	row = mysql_fetch_row(result);
	//m_ctrlList1.SetExtendedStyle(LVS_EX_CHECKBOXES);
	dlg2.Set(row[0], row[1], row[2], row[3], row[4]);
	dlg2.DoModal();
	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	UpdateData(FALSE);
}


void CMyBooksDlg::OnBnClickedBtnsearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[100];
	memset(query, NULL, 100); //배열 초기화
	CString str = m_nbookID.GetString(); //1000

	if (str == "")
		sprintf_s(query, "select book_ID, book_title, book_price, author_ID, publisher_ID from book");
	else //검색 단어 없으면 테이블 다 표시
		sprintf_s(query, "select book_ID, book_title, book_price, author_ID, publisher_ID from book where book_ID = %d", _ttoi(str));//정수로 바꾸기 
	//질의 보내기
	mysql_query(&mysql, query);

	m_ctrlList1.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
	MYSQL_RES* result = mysql_store_result(&mysql); //질의 결과
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	//도서ID는 무조건 하나 -> listcontrol에 나타내기
	MYSQL_ROW row;
	int idx = 0;
	while (row = mysql_fetch_row(result))
	{
		m_ctrlList1.InsertItem(idx, row[0]);
		for (int i = 1; i <= 4; i++)
		{
			m_ctrlList1.SetItemText(idx, i, row[i]);
		}
		idx++;
	}

	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	m_nauthorID.SetString("");
	m_nPubID.SetString("");
	m_nbookID.SetString("");
	UpdateData(FALSE);
}


void CMyBooksDlg::OnBnClickedBtnmodify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	// book table에 대해서만 수정
	// 더블클릭하면 domodal()
	UpdateData(TRUE);
	Updatedlg dlg;

	int nSel = m_ctrlList1.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		AfxMessageBox("수정할 행을 선택해주세요.");
		return;
	}
	dlg.m_bookID_up = m_ctrlList1.GetItemText(nSel, 0);
	dlg.m_booktitle_up = m_ctrlList1.GetItemText(nSel, 1);
	dlg.m_bookprice_up = m_ctrlList1.GetItemText(nSel, 2);

	//콤보박스에 값 표시
	dlg.m_strAut = m_ctrlList1.GetItemText(nSel, 3);
	dlg.m_strPub = m_ctrlList1.GetItemText(nSel, 4);

	// 수정 후, 쿼리 작성한 것을 클래스 변수에 넣기
	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		OnBnClickedBtnsearch();
		AfxMessageBox("수정이 완료되었습니다.");
	}

}

void CMyBooksDlg::OnBnClickedBtninsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	InsertBook dlg;

	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		OnBnClickedBtnsearch();
		AfxMessageBox("추가가 완료되었습니다.");
	}

}


void CMyBooksDlg::OnBnClickedBtndelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	UpdateData(TRUE); //MFC -> 변수

	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[50];
	memset(query, NULL, 50); //배열 초기화
	int nSel = m_ctrlList1.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		mysql_close(&mysql);
		AfxMessageBox("삭제할 행을 선택해주세요.");
		return;
	}
	CString str = m_ctrlList1.GetItemText(nSel, 0);

	int ret = AfxMessageBox("정말로 삭제하시겠습니까?", MB_YESNO | MB_ICONQUESTION);
	if (ret != IDYES) {
		mysql_close(&mysql);
		return;
	}
	//질의 보내기
	sprintf_s(query, "delete from book where book_ID = %d", _ttoi(str)); //정수로 바꾸기
	if (mysql_query(&mysql, query))
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}

	mysql_close(&mysql);
	m_nauthorID.SetString("");
	m_nPubID.SetString("");
	m_ctrlList1.DeleteItem(nSel);
	UpdateData(FALSE);
	AfxMessageBox("삭제가 완료되었습니다."); //되도록 마지막에
}


//void CMyBooksDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	
//	AfxMessageBox("abcd");
//
//	*pResult = 0;
//}


void CMyBooksDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	NM_LISTVIEW* p = (NM_LISTVIEW*)pNMHDR;
	//int nSel = p->iItem; //인덱스 
	m_nauthorID = m_ctrlList1.GetItemText(p->iItem, 3);
	m_nPubID = m_ctrlList1.GetItemText(p->iItem, 4);
	//int idx = pNMItemActivate->iItem; //클릭한 아이템의 인덱스 가져옴
	//if (idx >= 0 && idx < m_ctrlList1.GetItemCount())
	//{
	//	//4열 저자ID를 edit2
	//	//5열 출판사ID를 edit3
	//}
	UpdateData(FALSE); //변수 -> MFC
	*pResult = 0;
}


void CMyBooksDlg::OnBnClickedCcancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


BOOL CMyBooksDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_tooltip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}
