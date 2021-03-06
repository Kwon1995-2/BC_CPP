
// ContactManager2Dlg.h: 헤더 파일
//

#pragma once

#include <vector>
#include "MyHash.h"

// CContactManager2Dlg 대화 상자
class CContactManager2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CContactManager2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	~CContactManager2Dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTACTMANAGER2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	void displayHashtoList();
	void tockenstring(vector<string>& vec, char* pstr, size_t len);
	MyHash* hash;
	int bucketSize;

// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strName;
	CString m_strMobileTel;
	CString m_strOfficeTel;
	CString m_strHomeTel;
	CString m_strEmail;
	CString m_strBirth;
	CListBox m_ctrlList;
	afx_msg void OnBnClickedDataload();
	afx_msg void OnBnClickedDatainsert();
	afx_msg void OnBnClickedDatadelete();
	afx_msg void OnBnClickedDatamodify();
	afx_msg void OnBnClickedDatasave();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnSelchangeList1();
};
