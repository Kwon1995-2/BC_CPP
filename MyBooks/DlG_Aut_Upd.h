#pragma once


// DlG_Aut_Upd 대화 상자

class DlG_Aut_Upd : public CDialogEx
{
	DECLARE_DYNAMIC(DlG_Aut_Upd)

public:
	DlG_Aut_Upd(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlG_Aut_Upd();
	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString str[5];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlG_Aut_Upd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	//afx_msg void OnEnChangeEdit7();
	CString m_str_AutID;
	CString m_str_AutName;
	CString m_str_AutPhone;
//	CEdit m_str_AutEmail;
	CString m_str_AutEmail;
	CString m_str_AutSns;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
