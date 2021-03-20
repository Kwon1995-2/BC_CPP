#pragma once


// myAuthor 대화 상자

class myAuthor : public CDialogEx
{
	DECLARE_DYNAMIC(myAuthor)

public:
	myAuthor(int mode, CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~myAuthor();

	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString row[5];
	int m_mode;	// 입력모드면 1, 선택모드면 2
	//CString m_strIN_AutID;	// 리턴용 문자열(ID)

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_ctrlList_Aut;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnsearch();
	afx_msg void OnBnClickedBtnmodify();
	afx_msg void OnBnClickedBtninsert();
	afx_msg void OnBnClickedBtndelete();
	afx_msg void OnBnClickedOk();
};
