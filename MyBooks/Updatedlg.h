#pragma once


// Updatedlg 대화 상자

class Updatedlg : public CDialogEx
{
	DECLARE_DYNAMIC(Updatedlg)

public:
	Updatedlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~Updatedlg();
	void Set(CString row0, CString row1, CString row2, CString  row3, CString  row4);
	CString str[5];
	//CString cstr[5];
	//CString str[5];

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CString m_bookID_up;
	CString m_booktitle_up;
	CString m_bookprice_up;
//	CComboBox m_ctrlAutCom;
//	CComboBox m_ctrlPubCom;
	CString m_strAut;
	CString m_strPub;
};
