
// std2WinDlg.h: 헤더 파일
//

#pragma once


// Cstd2WinDlg 대화 상자
class Cstd2WinDlg : public CDialogEx
{
// 생성입니다.
public:
	Cstd2WinDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STD2WIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedBtnFilerecv();
	afx_msg void OnBnClickedBtnMsgadd();
	afx_msg void OnBnClickedBtnMsgdel();
	afx_msg void OnBnClickedBtnMsgres();
	afx_msg void OnBnClickedBtnMsgsend();
	afx_msg void OnBnClickedBtnIpadd();
	afx_msg void OnBnClickedBtnIpdel();
	afx_msg void OnBnClickedBtnIpres();
	CListBox m_ctrlListMsg;
	CListBox m_ctrlListIp;
	CString m_strMsg;
	int m_nPort;
	CIPAddressCtrl m_IPADDRCtrl;
};
