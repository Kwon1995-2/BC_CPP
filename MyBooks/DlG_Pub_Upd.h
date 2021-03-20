#pragma once


// DlG_Pub_Upd 대화 상자

class DlG_Pub_Upd : public CDialogEx
{
	DECLARE_DYNAMIC(DlG_Pub_Upd)

public:
	DlG_Pub_Upd(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~DlG_Pub_Upd();
	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString str[5];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DlG_Pub_Upd };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_str_PubID_Up;
	CString m_str_PubName_Up;
	CString m_str_PubPhone_Up;
	CString m_str_PubEmail_Up;
	CString m_str_PubAddr_Up;
};
