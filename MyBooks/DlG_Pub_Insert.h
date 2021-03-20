#pragma once


// DlG_Pub_Insert 대화 상자

class DlG_Pub_Insert : public CDialogEx
{
	DECLARE_DYNAMIC(DlG_Pub_Insert)

public:
	DlG_Pub_Insert(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlG_Pub_Insert();
	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString str[5];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlG_Pub_Insert };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_str_PubID_In;
	CString m_str_PubName_In;
	CString m_str_PubPhone_In;
	CString m_str_PubEmail_In;
	CString m_str_PubAddr_In;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit5();
};
