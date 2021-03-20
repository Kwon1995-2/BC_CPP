// MYDlg.cpp: 구현 파일
//

#include "pch.h"
#include "std2Win.h"
#include "MYDlg.h"
#include "afxdialogex.h"


// CMYDlg 대화 상자

IMPLEMENT_DYNAMIC(CMYDlg, CDialogEx)

CMYDlg::CMYDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CMYDlg, pParent)
{

}

CMYDlg::~CMYDlg()
{
}

void CMYDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMYDlg, CDialogEx)
END_MESSAGE_MAP()


// CMYDlg 메시지 처리기
