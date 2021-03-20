
// MFCApplication4View.h: CMFCApplication4View 클래스의 인터페이스
//

#pragma once

class CMFCApplication4View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication4View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication4View)

// 특성입니다.
public:
	CMFCApplication4Doc* GetDocument() const;

// 작업입니다.
public:
	CString	m_strPos;
	CArray<CPoint> m_ptArray;

	CDC* m_pBufferDC;
	CBitmap* m_pBitmap;

	BOOL m_bPanMode;
	CPoint m_pt;
	CPoint m_curpt;

	void drawPath(CDC* pDC, int linetype, int linewidth, COLORREF col);

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication4View.cpp의 디버그 버전
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif

