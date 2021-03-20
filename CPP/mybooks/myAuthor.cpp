// myAuthor.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "myAuthor.h"
#include "afxdialogex.h"


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
END_MESSAGE_MAP()


// myAuthor 메시지 처리기


BOOL myAuthor::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CRect rect_a;
	m_ctrlList_Aut.GetClientRect(rect_a);
	m_ctrlList_Aut.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList_Aut.InsertColumn(0, _T("A_ID"), LVCFMT_LEFT, rect_a.Width() * 0.1, -1);
	m_ctrlList_Aut.InsertColumn(1, _T("Name"), LVCFMT_LEFT, rect_a.Width() * 0.2, -1);
	m_ctrlList_Aut.InsertColumn(2, _T("Phone_num"), LVCFMT_LEFT, rect_a.Width() * 0.3, -1);
	m_ctrlList_Aut.InsertColumn(3, _T("SNS"), LVCFMT_LEFT, rect_a.Width() * 0.4, -1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
