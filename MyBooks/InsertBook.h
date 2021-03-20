#pragma once


// InsertBook 대화 상자

class InsertBook : public CDialogEx
{
	DECLARE_DYNAMIC(InsertBook)

public:
	InsertBook(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~InsertBook();
	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString str[5];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strAut_In;
	CString m_strPub_In;
	CString m_strBookID;
	CString m_strBookTitle;
	CString m_strBookPrice;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	int m_nRadio_In;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedSelecta();
	afx_msg void OnBnClickedSelectb();
};
