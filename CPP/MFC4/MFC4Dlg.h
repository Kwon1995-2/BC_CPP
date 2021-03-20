
// MFC4Dlg.h: 헤더 파일
//

#pragma once
#include "TrieTree.h"
#include <string>
// CMFC4Dlg 대화 상자
class CMFC4Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFC4Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CMFC4Dlg();
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC4_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	TrieTree* m_pTree;
public:
	afx_msg void OnBnClickedBtnload();
	afx_msg void OnBnClickedBtnsearch();
	afx_msg void OnBnClickedCancel();
	CString m_strSearchStr;
	CString m_strLoadFileName;
	CListBox m_ctrlList1;
	CListBox m_ctrlList2;
	CListBox m_ctrlList3;
	int tockenstring(vector<CString>& vec, vector<int>& idxs, CString& str);
};
