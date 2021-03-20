// myAuthor.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "myAuthor.h"
#include "afxdialogex.h"
#include "DlG_Aut_Upd.h"
#include "DlG_Aut_Insert.h"
#include "mysql.h"


// myAuthor 대화 상자

IMPLEMENT_DYNAMIC(myAuthor, CDialogEx)

myAuthor::myAuthor(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	
}

myAuthor::~myAuthor()
{
}

void myAuthor::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList_Aut);
}


BEGIN_MESSAGE_MAP(myAuthor, CDialogEx)
	ON_BN_CLICKED(IDC_BTNSEARCH, &myAuthor::OnBnClickedBtnsearch)
	ON_BN_CLICKED(IDC_BTNMODIFY, &myAuthor::OnBnClickedBtnmodify)
	ON_BN_CLICKED(IDC_BTNINSERT, &myAuthor::OnBnClickedBtninsert)
	ON_BN_CLICKED(IDC_BTNDELETE, &myAuthor::OnBnClickedBtndelete)
END_MESSAGE_MAP()


// myAuthor 메시지 처리기


BOOL myAuthor::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect_a;
	m_ctrlList_Aut.GetClientRect(rect_a);
	m_ctrlList_Aut.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_ctrlList_Aut.ModifyStyle(0, LVS_SHOWSELALWAYS);
	//m_ctrlList_Aut.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList_Aut.InsertColumn(0, _T("A_ID"), LVCFMT_LEFT, int(rect_a.Width() * 0.1), -1);
	m_ctrlList_Aut.InsertColumn(1, _T("Name"), LVCFMT_LEFT, int(rect_a.Width() * 0.15), -1);
	m_ctrlList_Aut.InsertColumn(2, _T("Phone"), LVCFMT_LEFT, int(rect_a.Width() * 0.25), -1);
	m_ctrlList_Aut.InsertColumn(3, _T("E-mail"), LVCFMT_LEFT, int(rect_a.Width() * 0.25), -1);
	m_ctrlList_Aut.InsertColumn(4, _T("SNS"), LVCFMT_LEFT, int(rect_a.Width() * 0.25), -1);

	m_ctrlList_Aut.InsertItem(0, row[0]);
	m_ctrlList_Aut.SetItemText(0, 1, row[1]);
	m_ctrlList_Aut.SetItemText(0, 2, row[2]);
	m_ctrlList_Aut.SetItemText(0, 3, row[3]);
	m_ctrlList_Aut.SetItemText(0, 4, row[4]);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void myAuthor::Set(CString row0, CString row1, CString row2, CString  row3, CString  row4)
{
	row[0] = row0;
	row[1] = row1;
	row[2] = row2;
	row[3] = row3;
	row[4] = row4;
}

void myAuthor::OnBnClickedBtnsearch()
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

	sprintf_s(query, "select author_ID, name, phone, e_mail, sns from author");
	//질의 보내기
	mysql_query(&mysql, query);

	m_ctrlList_Aut.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
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
		m_ctrlList_Aut.InsertItem(idx, row[0]);
		for (int i = 1; i <= 4; i++)
		{
			m_ctrlList_Aut.SetItemText(idx, i, row[i]);
		}
		idx++;
	}
	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	UpdateData(FALSE);
}


void myAuthor::OnBnClickedBtnmodify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	DlG_Aut_Upd dlg;

	int nSel = m_ctrlList_Aut.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		AfxMessageBox("수정할 행을 선택해주세요.");
		return;
	}
	dlg.m_str_AutID = m_ctrlList_Aut.GetItemText(nSel, 0);
	dlg.m_str_AutName = m_ctrlList_Aut.GetItemText(nSel, 1);
	dlg.m_str_AutPhone = m_ctrlList_Aut.GetItemText(nSel, 2);

	//콤보박스에 값 표시
	dlg.m_str_AutEmail = m_ctrlList_Aut.GetItemText(nSel, 3);
	dlg.m_str_AutSns = m_ctrlList_Aut.GetItemText(nSel, 4);

	// 수정 후, 쿼리 작성한 것을 클래스 변수에 넣기
	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		OnBnClickedBtnsearch();
		AfxMessageBox("수정이 완료되었습니다.");
	}
}


void myAuthor::OnBnClickedBtninsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	DlG_Aut_Insert dlg;

	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		OnBnClickedBtnsearch();
		AfxMessageBox("추가가 완료되었습니다.");
	}
}


void myAuthor::OnBnClickedBtndelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); //MFC -> 변수
	

	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[50];
	memset(query, NULL, 50); //배열 초기화
	int nSel = m_ctrlList_Aut.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		mysql_close(&mysql);
		AfxMessageBox("삭제할 행을 선택해주세요.");
		return;
	}
	//int ret = (int)Adel.DoModal();
	CString str = m_ctrlList_Aut.GetItemText(nSel, 0);
	int ret = AfxMessageBox("정말로 삭제하시겠습니까?", MB_YESNO | MB_ICONQUESTION);
	if (ret != IDYES) {
		mysql_close(&mysql);
		return;
	}
	
	//질의 보내기
	sprintf_s(query, "delete from author where author_ID = %d", _ttoi(str)); //정수로 바꾸기
	if (mysql_query(&mysql, query))
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	
	mysql_close(&mysql);
	m_ctrlList_Aut.DeleteItem(nSel);
	UpdateData(FALSE);
	AfxMessageBox("삭제가 완료되었습니다."); //되도록 마지막에
}
