// DlG_Pub_Insert.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "DlG_Pub_Insert.h"
#include "afxdialogex.h"
#include "mysql.h"


// DlG_Pub_Insert 대화 상자

IMPLEMENT_DYNAMIC(DlG_Pub_Insert, CDialogEx)

DlG_Pub_Insert::DlG_Pub_Insert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlG_Pub_Insert, pParent)
	, m_str_PubID_In(_T(""))
	, m_str_PubName_In(_T(""))
	, m_str_PubPhone_In(_T(""))
	, m_str_PubEmail_In(_T(""))
	, m_str_PubAddr_In(_T(""))
{

}

DlG_Pub_Insert::~DlG_Pub_Insert()
{
}

void DlG_Pub_Insert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_str_PubID_In);
	DDX_Text(pDX, IDC_EDIT4, m_str_PubName_In);
	DDX_Text(pDX, IDC_EDIT5, m_str_PubPhone_In);
	DDX_Text(pDX, IDC_EDIT6, m_str_PubEmail_In);
	DDX_Text(pDX, IDC_EDIT7, m_str_PubAddr_In);
}


BEGIN_MESSAGE_MAP(DlG_Pub_Insert, CDialogEx)
	ON_BN_CLICKED(IDOK, &DlG_Pub_Insert::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &DlG_Pub_Insert::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT5, &DlG_Pub_Insert::OnChangeEdit5)
END_MESSAGE_MAP()


// DlG_Pub_Insert 메시지 처리기

BOOL DlG_Pub_Insert::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_str_PubPhone_In.Format("000-000-0000");
	////////////////////////////////////////////////////////////////////////////
	int max = 0;
	//sql 연결
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//쿼리 변수 설정
	char query[100];
	memset(query, NULL, 100); //배열 초기화
	//쿼리 보내기
	sprintf_s(query, "select publisher_ID from publisher");
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
	m_str_PubID_In.Format("%d", max + 1);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void DlG_Pub_Insert::OnBnClickedOk()
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

	//질의 보내기
	Set(m_str_PubID_In, m_str_PubName_In, m_str_PubPhone_In, m_str_PubEmail_In, m_str_PubAddr_In);
	sprintf_s(query, "insert into publisher values (%s, \'%s\', \'%s\', \'%s\', \'%s\')", (LPCTSTR)str[0], (LPCTSTR)str[1], (LPCTSTR)str[2], (LPCTSTR)str[3], (LPCTSTR)str[4]);
	if (mysql_query(&mysql, query)) {
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		CDialogEx::OnCancel();
		return;
	}

	mysql_close(&mysql);
	CDialogEx::OnOK();
}

void DlG_Pub_Insert::Set(CString row0, CString row1, CString row2, CString  row3, CString  row4)
{
	str[0] = row0; str[1] = row1; str[2] = row2; str[3] = row3; str[4] = row4;
}


void DlG_Pub_Insert::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}





void DlG_Pub_Insert::OnChangeEdit5()
{
	UpdateData(TRUE);
	CEdit* pEdit = (CEdit*)GetDlgItem(IDC_EDIT5);
	
	CString post = m_str_PubPhone_In;
	DWORD start = pEdit->GetSel();
	if (LOWORD(start) == 3 || LOWORD(start) == 7) start += DWORD(1);
	post.Remove('-');
	int size = post.GetLength();
	//전화번호 입력 제한
	if (size > 10) m_str_PubPhone_In.Format(_T("%s-%s-%s"), post.Left(3), post.Mid(3, 3), post.Mid(6, 4));
	
	UpdateData(FALSE);
	pEdit->SetSel(LOWORD(start), LOWORD(start) + 1);
}
