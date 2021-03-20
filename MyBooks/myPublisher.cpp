// myPublisher.cpp: 구현 파일
//

#include "pch.h"
#include "MyBooks.h"
#include "myPublisher.h"
#include "afxdialogex.h"


// myPublisher 대화 상자

IMPLEMENT_DYNAMIC(myPublisher, CDialogEx)

myPublisher::myPublisher(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
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
	m_ctrlList_Pub.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList_Pub.InsertColumn(0, "P_ID", LVCFMT_LEFT, rect_p.Width() * 0.1, -1);
	m_ctrlList_Pub.InsertColumn(1, "Name", LVCFMT_LEFT, rect_p.Width() * 0.2, -1);
	m_ctrlList_Pub.InsertColumn(2, "Phone_num", LVCFMT_LEFT, rect_p.Width() * 0.2, -1);
	m_ctrlList_Pub.InsertColumn(3, "E_mail", LVCFMT_LEFT, rect_p.Width() * 0.2, -1);
	m_ctrlList_Pub.InsertColumn(3, "Address", LVCFMT_LEFT, rect_p.Width() * 0.3, -1);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
