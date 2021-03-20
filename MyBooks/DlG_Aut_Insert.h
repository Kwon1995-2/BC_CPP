#pragma once


// DlG_Aut_Insert 대화 상자

class DlG_Aut_Insert : public CDialogEx
{
	DECLARE_DYNAMIC(DlG_Aut_Insert)

public:
	DlG_Aut_Insert(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlG_Aut_Insert();
	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString str[5];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlG_Aut_Insert };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_strIN_AutID;
	CString m_strIN_AutName;
	CString m_strIN_AutPhone;
	CString m_strIN_AutEmail;
	CString m_strIN_AutSns;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit5();
};
