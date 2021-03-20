#pragma once


// myAuthor 대화 상자

class myAuthor : public CDialogEx
{
	DECLARE_DYNAMIC(myAuthor)

public:
	myAuthor(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~myAuthor();

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
};
