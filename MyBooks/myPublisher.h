#pragma once


// myPublisher 대화 상자

class myPublisher : public CDialogEx
{
	DECLARE_DYNAMIC(myPublisher)

public:
	myPublisher(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~myPublisher();

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
};
