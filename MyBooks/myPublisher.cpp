// myPublisher.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "myPublisher.h"
#include "afxdialogex.h"
#include "DlG_Pub_Upd.h"
#include "DlG_Pub_Insert.h"
#include "mysql.h"


// myPublisher 대화 상자

IMPLEMENT_DYNAMIC(myPublisher, CDialogEx)

myPublisher::myPublisher(int mode, CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, m_mode(mode)
{

}

myPublisher::~myPublisher()
{
}

void myPublisher::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList_Pub);
}


BEGIN_MESSAGE_MAP(myPublisher, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &myPublisher::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BTNSEARCH, &myPublisher::OnBnClickedBtnsearch)
	ON_BN_CLICKED(IDC_BTNMODIFY, &myPublisher::OnBnClickedBtnmodify)
	ON_BN_CLICKED(IDC_BTNINSERT, &myPublisher::OnBnClickedBtninsert)
	ON_BN_CLICKED(IDC_BTNDELETE, &myPublisher::OnBnClickedBtndelete)
	//ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &myPublisher::OnLvnItemchangedList1)
END_MESSAGE_MAP()


// myPublisher 메시지 처리기


void myPublisher::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}




BOOL myPublisher::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	CRect rect_p;
	m_ctrlList_Pub.GetClientRect(rect_p);
	m_ctrlList_Pub.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_ctrlList_Pub.ModifyStyle(0, LVS_SHOWSELALWAYS);
	//m_ctrlList_Pub.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList_Pub.InsertColumn(0, "P_ID", LVCFMT_LEFT, int(rect_p.Width() * 0.1), -1);
	m_ctrlList_Pub.InsertColumn(1, "Name", LVCFMT_LEFT, int(rect_p.Width() * 0.2), -1);
	m_ctrlList_Pub.InsertColumn(2, "Phone_num", LVCFMT_LEFT, int(rect_p.Width() * 0.2), -1);
	m_ctrlList_Pub.InsertColumn(3, "E_mail", LVCFMT_LEFT, int(rect_p.Width() * 0.2), -1);
	m_ctrlList_Pub.InsertColumn(4, "Address", LVCFMT_LEFT, int(rect_p.Width() * 0.3), -1);

	m_ctrlList_Pub.InsertItem(0, row[0]);
	m_ctrlList_Pub.SetItemText(0, 1, row[1]);
	m_ctrlList_Pub.SetItemText(0, 2, row[2]);
	m_ctrlList_Pub.SetItemText(0, 3, row[3]);
	m_ctrlList_Pub.SetItemText(0, 4, row[4]);

	if (m_mode == 1)	// 입력모드면
	{
		GetDlgItem(IDC_BTNSEARCH)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BTNMODIFY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BTNINSERT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BTNDELETE)->ShowWindow(SW_SHOW);
		//GetDlgItem(IDOK)->ShowWindow(SW_HIDE);
	}
	else				// 선택모드면 --> 필요없는 코드
	{
		GetDlgItem(IDC_BTNSEARCH)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BTNMODIFY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_BTNINSERT)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_BTNDELETE)->ShowWindow(SW_HIDE);
		//GetDlgItem(IDOK)->ShowWindow(SW_SHOW);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void myPublisher::Set(CString row0, CString row1, CString row2, CString  row3, CString  row4)
{
	row[0] = row0;
	row[1] = row1;
	row[2] = row2;
	row[3] = row3;
	row[4] = row4;
}


void myPublisher::OnBnClickedBtnsearch()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[150];
	memset(query, NULL, 150); //배열 초기화

	sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher");
	//질의 보내기
	mysql_query(&mysql, query);

	m_ctrlList_Pub.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
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
		m_ctrlList_Pub.InsertItem(idx, row[0]);
		for (int i = 1; i <= 4; i++)
		{
			m_ctrlList_Pub.SetItemText(idx, i, row[i]);
		}
		idx++;
	}
	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	UpdateData(FALSE);
}


void myPublisher::OnBnClickedBtnmodify()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	DlG_Pub_Upd dlg;

	int nSel = m_ctrlList_Pub.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		AfxMessageBox("수정할 행을 선택해주세요.");
		return;
	}
	dlg.m_str_PubID_Up = m_ctrlList_Pub.GetItemText(nSel, 0);
	dlg.m_str_PubName_Up = m_ctrlList_Pub.GetItemText(nSel, 1);
	dlg.m_str_PubPhone_Up = m_ctrlList_Pub.GetItemText(nSel, 2);

	//콤보박스에 값 표시
	dlg.m_str_PubEmail_Up = m_ctrlList_Pub.GetItemText(nSel, 3);
	dlg.m_str_PubAddr_Up = m_ctrlList_Pub.GetItemText(nSel, 4);

	// 수정 후, 쿼리 작성한 것을 클래스 변수에 넣기
	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		//OnBnClickedBtnsearch(); // --> 모두 보이기
		// --> 수정한 행만 보이기 --> 코드 줄이기
		m_ctrlList_Pub.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
		MYSQL mysql;
		mysql_init(&mysql);
		mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);
		char query[200];
		memset(query, NULL, 200); //배열 초기화
		//sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = (select max(publisher_ID) from publisher)");
		sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = %d ", _ttoi(dlg.m_str_PubID_Up));
		mysql_query(&mysql, query);
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
			m_ctrlList_Pub.InsertItem(idx, row[0]);
			for (int i = 1; i <= 4; i++)
			{
				m_ctrlList_Pub.SetItemText(idx, i, row[i]);
			}
			idx++;
		}
		mysql_free_result(result); //질의 결과 메모리 해제
		mysql_close(&mysql);
		UpdateData(FALSE);
		AfxMessageBox("수정이 완료되었습니다.");
	}
}


void myPublisher::OnBnClickedBtninsert()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	DlG_Pub_Insert dlg;

	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		m_ctrlList_Pub.DeleteAllItems(); //리스트 컨트롤에 이전에 입력되어 있는 데이터 제거
		MYSQL mysql;
		mysql_init(&mysql);
		mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);
		char query[200];
		memset(query, NULL, 200); //배열 초기화
		//sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = (select max(publisher_ID) from publisher)");
		sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = %d ", _ttoi(dlg.m_str_PubID_In));
		mysql_query(&mysql, query);
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
			m_ctrlList_Pub.InsertItem(idx, row[0]);
			for (int i = 1; i <= 4; i++)
			{
				m_ctrlList_Pub.SetItemText(idx, i, row[i]);
			}
			idx++;
		}
		mysql_free_result(result); //질의 결과 메모리 해제
		mysql_close(&mysql);
		UpdateData(FALSE);
		AfxMessageBox("추가가 완료되었습니다.");
		/*m_str_PubID_In = dlg.m_str_PubID_In;
		CDialogEx::OnOK();*/
	}
}


void myPublisher::OnBnClickedBtndelete()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE); //MFC -> 변수

	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[50];
	memset(query, NULL, 50); //배열 초기화
	int nSel = m_ctrlList_Pub.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		mysql_close(&mysql);
		AfxMessageBox("삭제할 행을 선택해주세요.");
		return;
	}
	CString str = m_ctrlList_Pub.GetItemText(nSel, 0);
	int ret = AfxMessageBox("정말로 삭제하시겠습니까?", MB_YESNO | MB_ICONQUESTION);
	if (ret != IDYES) {
		mysql_close(&mysql);
		return;
	}

	//질의 보내기
	sprintf_s(query, "delete from publisher where publisher_ID = %d", _ttoi(str)); //정수로 바꾸기
	if (mysql_query(&mysql, query))
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}

	mysql_close(&mysql);
	m_ctrlList_Pub.DeleteItem(nSel);
	UpdateData(FALSE);
	AfxMessageBox("삭제가 완료되었습니다."); //되도록 마지막에
}

