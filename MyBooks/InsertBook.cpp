// InsertBook.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "InsertBook.h"
#include "afxdialogex.h"
#include "DlG_Aut_Insert.h"
#include "DlG_Pub_Insert.h"
#include "mysql.h"
#include "myAuthor.h"
#include "myPublisher.h"


// InsertBook 대화 상자

IMPLEMENT_DYNAMIC(InsertBook, CDialogEx)

InsertBook::InsertBook(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG4, pParent)
	, m_strAut_In(_T(""))
	, m_strPub_In(_T(""))
	, m_strBookID(_T(""))
	, m_strBookTitle(_T(""))
	, m_strBookPrice(_T(""))
	, m_nRadio_In(0)
{

}

InsertBook::~InsertBook()
{
}

void InsertBook::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO2, m_strAut_In);
	DDX_CBString(pDX, IDC_COMBO3, m_strPub_In);
	DDX_Text(pDX, IDC_EDIT1, m_strBookID);
	DDX_Text(pDX, IDC_EDIT4, m_strBookTitle);
	DDX_Text(pDX, IDC_EDIT5, m_strBookPrice);
	DDX_Radio(pDX, IDC_RADIO1, m_nRadio_In);
}


BEGIN_MESSAGE_MAP(InsertBook, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &InsertBook::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &InsertBook::OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, &InsertBook::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &InsertBook::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO3, &InsertBook::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_SELECTA, &InsertBook::OnBnClickedSelecta)
	ON_BN_CLICKED(IDC_SELECTB, &InsertBook::OnBnClickedSelectb)
END_MESSAGE_MAP()


// InsertBook 메시지 처리기


void InsertBook::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void InsertBook::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[200];
	memset(query, NULL, 200); //배열 초기화

	//질의 보내기
	Set(m_strBookID, m_strBookTitle, m_strBookPrice, m_strAut_In, m_strPub_In);
	sprintf_s(query, "insert into book values (%s, \'%s\', %d, %s, %s)", (LPCTSTR)str[0], (LPCTSTR)str[1], _ttoi(str[2]), (LPCTSTR)str[3], (LPCTSTR)str[4]);
	if (mysql_query(&mysql, query)) {
		AfxMessageBox("오류 발생!\n입력한 정보를 다시 확인해주세요.");
		//AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		//CDialogEx::OnCancel();
		return;
	}
	
	mysql_close(&mysql);
	//AfxMessageBox("Insert Complete!"); //되도록 마지막에
	CDialogEx::OnOK();
}

void InsertBook::Set(CString row0, CString row1, CString row2, CString  row3, CString  row4)
{
	str[0] = row0; str[1] = row1; str[2] = row2; str[3] = row3; str[4] = row4;
}


BOOL InsertBook::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	//저자 콤보박스 가져오기
	CComboBox* pcbo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pcbo->ResetContent();
	MYSQL ComboAut;
	mysql_init(&ComboAut);
	mysql_real_connect(&ComboAut, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);
	char query2[100];
	memset(query2, NULL, 100);
	sprintf_s(query2, "select author_ID from author");
	mysql_query(&ComboAut, query2);
	MYSQL_RES* result2 = mysql_store_result(&ComboAut); //질의 결과
	if (!result2)
	{
		AfxMessageBox(mysql_error(&ComboAut));
		mysql_close(&ComboAut);
		return FALSE;
	}

	MYSQL_ROW row2;
	while (row2 = mysql_fetch_row(result2))
	{
		pcbo->AddString((LPCTSTR)row2[0]);
	}

	mysql_free_result(result2); //질의 결과 메모리 해제
	mysql_close(&ComboAut);
	UpdateData(FALSE);

	/*pcbo->AddString("97");
	pcbo->AddString("98");
	pcbo->AddString("99");
	pcbo->AddString("100");
	pcbo->AddString("101");
	pcbo->AddString("102");*/
	/////////////////////////////////////////////////////////////////////////////////////
	//출판사 콤보 박스 가져오기
	pcbo = (CComboBox*)GetDlgItem(IDC_COMBO3);
	pcbo->ResetContent();
	MYSQL ComboPub;
	mysql_init(&ComboPub);
	mysql_real_connect(&ComboPub, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);
	char query3[100];
	memset(query3, NULL, 100);
	sprintf_s(query3, "select publisher_ID from publisher");
	mysql_query(&ComboPub, query3);

	MYSQL_RES* result3 = mysql_store_result(&ComboPub); //질의 결과
	if (!result3)
	{
		AfxMessageBox(mysql_error(&ComboPub));
		mysql_close(&ComboPub);
		return FALSE;
	}

	MYSQL_ROW row3;
	while (row3 = mysql_fetch_row(result3))
	{
		pcbo->AddString((LPCTSTR)row3[0]);
	}

	mysql_free_result(result3); //질의 결과 메모리 해제
	mysql_close(&ComboPub);
	UpdateData(FALSE);

	/*pcbo = (CComboBox*)GetDlgItem(IDC_COMBO3);
	pcbo->AddString("1");
	pcbo->AddString("2");
	pcbo->AddString("3");
	pcbo->AddString("4");
	pcbo->AddString("5");*/
	/////////////////////////////////////////////////////////////////////////////////////
	int max = 0;
	MYSQL mysql; 
	mysql_init(&mysql); 
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0); 

	//쿼리 변수 설정
	char query[100]; 
	memset(query, NULL, 100); /*배열 초기화*/ 
	//쿼리 보내기
	sprintf_s(query, "select book_ID from book"); 
	mysql_query(&mysql, query);

	MYSQL_RES* result = mysql_store_result(&mysql); //질의 결과
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return FALSE;
	}

	MYSQL_ROW row;
	int idx = 0;
	while (row = mysql_fetch_row(result))
	{
		if (atoi(row[idx]) >= max)
			max = atoi(row[idx]);
	}

	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	m_strBookID.Format("%d", max + 1);
	UpdateData(FALSE);
	/////////////////////////////////////////////////////////////////////////////////////
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void InsertBook::OnBnClickedRadio1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//숫자별로 분류했을 경우, Auto increment 하면 안 됨 
	UpdateData(TRUE); // index : 0,1,2
	//query 문 -> loop -> 구간별 max 값 가져오기
	//m_strBookID = "";
	//type 설정
	int typemax = 0; //타입별 최고 숫자 ID 받아오는 변수
	int min=1000, max=1999; //조건절에 들어갈 변수
	int Ridx = m_nRadio_In; //radio 인덱스 받아오는 변수
	switch (Ridx) {
		case 0:
			min = 1000; max = 1999;
			break;
		case 1:
			min = 2000; max = 2999;
			break;
		case 2:
			min = 3000; max = 3999;
			break;
	}
	//sql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[100];
	memset(query, NULL, 100); //배열 초기화
	//쿼리 보내기
	sprintf_s(query, "select book_ID from book where book_ID between %d and %d", min, max);
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
		if (atoi(row[idx]) >= typemax)
			typemax = atoi(row[idx]);
	}
	typemax = typemax + 1;
	if (typemax == 1) typemax = min; //질의 결과가 없을 때

	mysql_free_result(result); //질의 결과 메모리 해제
	mysql_close(&mysql);
	m_strBookID.Format("%d", typemax);
	UpdateData(FALSE);
}

void InsertBook::OnBnClickedSelecta() //저자입력 버튼
{	//이거 고치기
	DlG_Aut_Insert dlg;
	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		m_strAut_In = dlg.m_strIN_AutID;
		UpdateData(FALSE);
	}

	//myAuthor dlg(2);
	//int ret = (int)dlg.DoModal();
	//if (ret == IDOK) {
	//	//MYSQL mysql;
	//	//mysql_init(&mysql);
	//	//mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//	//char query[100];
	//	//memset(query, NULL, 100); //배열 초기화
	//	////쿼리 보내기
	//	//sprintf_s(query, "select max(author_ID) from author");
	//	//mysql_query(&mysql, query);

	//	//MYSQL_RES* result = mysql_store_result(&mysql); //질의 결과
	//	//if (!result)
	//	//{
	//	//	AfxMessageBox(mysql_error(&mysql));
	//	//	mysql_close(&mysql);
	//	//	return;
	//	//}
	//	////도서ID는 무조건 하나 -> listcontrol에 나타내기
	//	//MYSQL_ROW row;
	//	//row = mysql_fetch_row(result);
	//	//m_strAut_In = row[0];
	//	//mysql_free_result(result); //질의 결과 메모리 해제
	//	//mysql_close(&mysql);
	//	//UpdateData(FALSE);
	//	//OnInitDialog();
	//	m_strAut_In = dlg.m_strIN_AutID;
	//	UpdateData(FALSE);
	//}
}


void InsertBook::OnBnClickedSelectb()
{
	DlG_Pub_Insert dlg;
	int ret = dlg.DoModal();
	if (ret == IDOK) {
		m_strPub_In = dlg.m_str_PubID_In;
		UpdateData(FALSE);
	}

	//myPublisher dlg(2);
	//int ret = (int)dlg.DoModal();
	//if (ret == IDOK) {
	//	//MYSQL mysql;
	//	//mysql_init(&mysql);
	//	//mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//	//char query[100];
	//	//memset(query, NULL, 100); //배열 초기화
	//	////쿼리 보내기
	//	//sprintf_s(query, "select max(publisher_ID) from publisher");
	//	//mysql_query(&mysql, query);

	//	//MYSQL_RES* result = mysql_store_result(&mysql); //질의 결과
	//	//if (!result)
	//	//{
	//	//	AfxMessageBox(mysql_error(&mysql));
	//	//	mysql_close(&mysql);
	//	//	return;
	//	//}
	//	////도서ID는 무조건 하나 -> listcontrol에 나타내기
	//	//MYSQL_ROW row;
	//	//row = mysql_fetch_row(result);
	//	//m_strPub_In = row[0];
	//	//mysql_free_result(result); //질의 결과 메모리 해제
	//	//mysql_close(&mysql);
	//	//UpdateData(FALSE);
	//	//OnInitDialog();
	//	m_strPub_In = dlg.m_str_PubID_In;
	//	UpdateData(FALSE);
	//}
}
