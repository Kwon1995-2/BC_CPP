// Updatedlg.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "Updatedlg.h"
#include "afxdialogex.h"
#include "mysql.h"

// Updatedlg 대화 상자

IMPLEMENT_DYNAMIC(Updatedlg, CDialogEx)

Updatedlg::Updatedlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, m_bookID_up(_T(""))
	, m_booktitle_up(_T(""))
	, m_bookprice_up(_T(""))
	, m_strAut(_T(""))
	, m_strPub(_T(""))
{

}

Updatedlg::~Updatedlg()
{
}

void Updatedlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_bookID_up);
	DDX_Text(pDX, IDC_EDIT4, m_booktitle_up);
	DDX_Text(pDX, IDC_EDIT5, m_bookprice_up);
	//  DDX_Control(pDX, IDC_COMBO2, m_ctrlAutCom);
	//  DDX_Control(pDX, IDC_COMBO3, m_ctrlPubCom);
	DDX_CBString(pDX, IDC_COMBO2, m_strAut);
	DDX_CBString(pDX, IDC_COMBO3, m_strPub);
}


BEGIN_MESSAGE_MAP(Updatedlg, CDialogEx)
	ON_BN_CLICKED(IDCANCEL, &Updatedlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &Updatedlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Updatedlg 메시지 처리기


void Updatedlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

//Update 쿼리 날리기
void Updatedlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);
	
	//쿼리 변수 설정
	char query[250];
	memset(query, NULL, 250); //배열 초기화

	//기본키 변경 불가 조건
	/*if (str[0] != m_bookID_up) {
		mysql_close(&mysql);
		m_bookID_up = str[0];
		UpdateData(FALSE);
		AfxMessageBox("ID can't be changed!");
	}*/

	//질의 보내기
	Set(m_bookID_up,m_booktitle_up, m_bookprice_up, m_strAut, m_strPub);
	sprintf_s(query, "update book set book_title=\'%s\', book_price=%s, author_ID=%s, publisher_ID=%s where book_ID = %d", (LPCTSTR)str[1], (LPCTSTR)str[2], (LPCTSTR)str[3], (LPCTSTR)str[4], _ttoi(m_bookID_up)); //정수로 바꾸기
	if(mysql_query(&mysql, query)){
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		CDialogEx::OnCancel();
		return;
	}
	//질의 결과 오류 거르기
	/*MYSQL_RES* result = mysql_store_result(&mysql);
	if (!result)
	{
		
		mysql_close(&mysql);
		return;
	}*/
	mysql_close(&mysql);
	CDialogEx::OnOK();
}


BOOL Updatedlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CComboBox* pcbo = (CComboBox*)GetDlgItem(IDC_COMBO2); //다시 공부하기

	//원래 값 받아오기
	str[0] = m_bookID_up;
	str[1] = m_booktitle_up;
	str[2] = m_bookprice_up;
	str[3] = m_strAut;
	str[4] = m_strPub;

	pcbo->AddString("97");
	pcbo->AddString("98");
	pcbo->AddString("99");
	pcbo->AddString("100");
	pcbo->AddString("101");
	pcbo->AddString("102");

	pcbo = (CComboBox*)GetDlgItem(IDC_COMBO3);
	pcbo->AddString("1");
	pcbo->AddString("2");
	pcbo->AddString("3");
	pcbo->AddString("4");
	pcbo->AddString("5");
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void Updatedlg::Set(CString row0, CString row1, CString row2, CString  row3, CString  row4)
{
	str[0] = row0; str[1] = row1; str[2] = row2; str[3] = row3; str[4] = row4;
}
