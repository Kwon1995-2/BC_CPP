
// MyBooksDlg.h: 헤더 파일
//

#pragma once

class myAuthor;

// CMyBooksDlg 대화 상자
class CMyBooksDlg : public CDialogEx
{
// 생성입니다.
public:
	CMyBooksDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CMyBooksDlg();

	CToolTipCtrl m_tooltip; //메모 뛰우기 위한 변수 지정
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYBOOKS_DIALOG };
#endif

	myAuthor* m_pAuthorDlg;

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
	CListCtrl m_ctrlList1;
	CString m_nbookID;
	CString m_nauthorID;
	CString m_nPubID;
	afx_msg void OnBnClickedBtnviewA();
	afx_msg void OnBnClickedBtnviewP();
	afx_msg void OnBnClickedBtnsearch();
	afx_msg void OnBnClickedBtnmodify();
	afx_msg void OnBnClickedBtndelete();
//	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedCcancel();
	afx_msg void OnBnClickedBtninsert();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedBtntest();
};
