#pragma once


// CMYDlg 대화 상자

class CMYDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMYDlg)

public:
	CMYDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMYDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CMYDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
