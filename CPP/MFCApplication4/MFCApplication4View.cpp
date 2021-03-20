
// MFCApplication4View.cpp: CMFCApplication4View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCApplication4View 생성/소멸

CMFCApplication4View::CMFCApplication4View() noexcept
{
	m_strPos = _T("");

	m_bPanMode = FALSE;

	m_pBufferDC = NULL;
	m_pBitmap = NULL;
}

CMFCApplication4View::~CMFCApplication4View()
{
	if (m_pBufferDC)
	{
		m_pBufferDC->DeleteDC();
		delete m_pBufferDC;
	}
	if(m_pBitmap)
	{
		m_pBitmap->DeleteObject();
		delete m_pBitmap;
	}
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View 그리기

void CMFCApplication4View::drawPath(CDC* pDC, int linetype, int linewidth, COLORREF col)
{
	int nSize = m_ptArray.GetSize();

	CPen pen;
	pen.CreatePen(linetype, linewidth, col);
	CPen* pOldPen = pDC->SelectObject(&pen);

	pDC->MoveTo(m_ptArray.GetAt(0));
	for (int i = 1; i < nSize; i++)
	{
		pDC->LineTo(m_ptArray.GetAt(i));
	}
	pDC->SelectObject(pOldPen);
	pen.DeleteObject();
}

void CMFCApplication4View::OnDraw(CDC* pDC)
{
	CRect rc;
	GetClientRect(rc);

	if (!m_pBufferDC)
	{
		m_pBufferDC = new CDC;
		m_pBufferDC->CreateCompatibleDC(pDC);
		m_pBitmap = new CBitmap;
		m_pBitmap->CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
		m_pBufferDC->SelectObject(m_pBitmap);

		m_pBufferDC->FillSolidRect(rc, RGB(255, 255, 255));
	}

	if (m_bPanMode)
	{
		int dx = m_curpt.x - m_pt.x;
		int dy = m_curpt.y - m_pt.y;

		CDC tdc;
		tdc.CreateCompatibleDC(pDC);
		CBitmap bmp;
		bmp.CreateCompatibleBitmap(pDC, rc.Width(), rc.Height());
		tdc.SelectObject(&bmp);

		tdc.FillSolidRect(rc, RGB(255, 255, 255));

		tdc.BitBlt(dx, dy, rc.Width(), rc.Height(), m_pBufferDC, 0, 0, SRCCOPY);
		tdc.TextOutA(0, 0, m_strPos);

		pDC->BitBlt(0, 0, rc.Width(), rc.Height(), &tdc, 0, 0, SRCCOPY);

		tdc.DeleteDC();
		bmp.DeleteObject();

		return;
	}
	else
	{
		m_pBufferDC->FillSolidRect(rc, RGB(255, 255, 255));

		int nSize = m_ptArray.GetSize();
		if (1 < nSize)
			drawPath(m_pBufferDC, PS_SOLID, 4, RGB(255, 0, 0));

		pDC->BitBlt(0, 0, rc.Width(), rc.Height(), m_pBufferDC, 0, 0, SRCCOPY);
	}
	pDC->TextOutA(0, 0, m_strPos);
}

// CMFCApplication4View 인쇄
BOOL CMFCApplication4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCApplication4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCApplication4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCApplication4View 진단

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View 메시지 처리기

void CMFCApplication4View::OnMouseMove(UINT nFlags, CPoint point)
{
	CView::OnMouseMove(nFlags, point);
	if (m_bPanMode)	m_curpt = point;

	m_strPos.Format("%d,%d", point.x, point.y);
	Invalidate(FALSE);
}

void CMFCApplication4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CView::OnLButtonDown(nFlags, point);

	m_ptArray.Add(point);
	Invalidate(FALSE);
}

void CMFCApplication4View::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CView::OnLButtonDblClk(nFlags, point);

	m_ptArray.RemoveAll();
	Invalidate(FALSE);
}

void CMFCApplication4View::OnRButtonDown(UINT nFlags, CPoint point)
{
	CView::OnRButtonDown(nFlags, point);

	m_bPanMode = TRUE;
	m_pt = point;
}


void CMFCApplication4View::OnRButtonUp(UINT nFlags, CPoint point)
{
	CView::OnRButtonUp(nFlags, point);

	m_bPanMode = FALSE;

	int dx = m_curpt.x - m_pt.x;
	int dy = m_curpt.y - m_pt.y;

	int nSize = m_ptArray.GetSize();
	for (int i = 0; i < nSize; i++)
	{
		CPoint pt = m_ptArray.GetAt(i);
		pt.x += dx;
		pt.y += dy;
		m_ptArray.SetAt(i, pt);
	}
	Invalidate(FALSE);
}
