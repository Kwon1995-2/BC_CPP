// DlG_Pub_Upd.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "DlG_Pub_Upd.h"
#include "afxdialogex.h"
#include "mysql.h"


// DlG_Pub_Upd 대화 상자

IMPLEMENT_DYNAMIC(DlG_Pub_Upd, CDialogEx)

DlG_Pub_Upd::DlG_Pub_Upd(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlG_Pub_Upd, pParent)
	, m_str_PubID_Up(_T(""))
	, m_str_PubName_Up(_T(""))
	, m_str_PubPhone_Up(_T(""))
	, m_str_PubEmail_Up(_T(""))
	, m_str_PubAddr_Up(_T(""))
{

}

DlG_Pub_Upd::~DlG_Pub_Upd()
{
}

void DlG_Pub_Upd::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str_PubID_Up);
	DDX_Text(pDX, IDC_EDIT4, m_str_PubName_Up);
	DDX_Text(pDX, IDC_EDIT5, m_str_PubPhone_Up);
	DDX_Text(pDX, IDC_EDIT6, m_str_PubEmail_Up);
	DDX_Text(pDX, IDC_EDIT7, m_str_PubAddr_Up);
}


BEGIN_MESSAGE_MAP(DlG_Pub_Upd, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlG_Pub_Upd::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DlG_Pub_Upd::OnBnClickedCancel)
END_MESSAGE_MAP()


// DlG_Pub_Upd 메시지 처리기


void DlG_Pub_Upd::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	//mysql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[300];
	memset(query, NULL, 300); //배열 초기화

	//기본키 변경 불가 조건
	/*if (str[0] != m_bookID_up) {
		mysql_close(&mysql);
		m_bookID_up = str[0];
		UpdateData(FALSE);
		AfxMessageBox("ID can't be changed!");
	}*/

	//질의 보내기
	Set(m_str_PubID_Up, m_str_PubName_Up, m_str_PubPhone_Up, m_str_PubEmail_Up, m_str_PubAddr_Up);
	sprintf_s(query, "update publisher set name=\'%s\', phone=\'%s\', e_mail=\'%s\', address=\'%s\'  where publisher_ID = %d", (LPCTSTR)str[1], (LPCTSTR)str[2], (LPCTSTR)str[3], (LPCTSTR)str[4], _ttoi(str[0])); //정수로 바꾸기
	if (mysql_query(&mysql, query)) {
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		CDialogEx::OnCancel();
		return;
	}
	mysql_close(&mysql);
	CDialogEx::OnOK();
}

void DlG_Pub_Upd::Set(CString row0, CString row1, CString row2, CString  row3, CString  row4)
{
	str[0] = row0; str[1] = row1; str[2] = row2; str[3] = row3; str[4] = row4;
}

void DlG_Pub_Upd::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}
