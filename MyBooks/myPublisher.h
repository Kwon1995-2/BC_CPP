#pragma once


// myPublisher 대화 상자

class myPublisher : public CDialogEx
{
	DECLARE_DYNAMIC(myPublisher)

public:
	myPublisher(int mode, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~myPublisher();

	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString row[5];
	int m_mode;	// 입력모드면 1, 선택모드면 2
	//CString m_str_PubID_In; //리턴용
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlList_Pub;
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnsearch();
	afx_msg void OnBnClickedBtnmodify();
	afx_msg void OnBnClickedBtninsert();
	afx_msg void OnBnClickedBtndelete();
	//afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
};
