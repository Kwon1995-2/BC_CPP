
// MyBooksDlg.cpp: ���� ����
//

#include "pch.h"
#include "framework.h"
#include "MyBooks.h"
#include "MyBooksDlg.h"
#include "afxdialogex.h"
#include "myAuthor.h"
#include "myPublisher.h"
#include "Updatedlg.h"
#include "InsertBook.h"
#include "mysql.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMyBooksDlg ��ȭ ����



CMyBooksDlg::CMyBooksDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYBOOKS_DIALOG, pParent)
	, m_nbookID(_T(""))
	, m_nauthorID(_T(""))
	, m_nPubID(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyBooksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ctrlList1);
	DDX_Text(pDX, IDC_EDIT1, m_nbookID);
	DDX_Text(pDX, IDC_EDIT2, m_nauthorID);
	DDX_Text(pDX, IDC_EDIT3, m_nPubID);
}

BEGIN_MESSAGE_MAP(CMyBooksDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTNVIEW_A, &CMyBooksDlg::OnBnClickedBtnviewA)
	ON_BN_CLICKED(IDC_BTNVIEW_P, &CMyBooksDlg::OnBnClickedBtnviewP)
	ON_BN_CLICKED(IDC_BTNSEARCH, &CMyBooksDlg::OnBnClickedBtnsearch)
	ON_BN_CLICKED(IDC_BTNMODIFY, &CMyBooksDlg::OnBnClickedBtnmodify)
	ON_BN_CLICKED(IDC_BTNDELETE, &CMyBooksDlg::OnBnClickedBtndelete)
	//	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CMyBooksDlg::OnItemchangedList1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, &CMyBooksDlg::OnClickList1)
	ON_BN_CLICKED(IDCCANCEL, &CMyBooksDlg::OnBnClickedCcancel)
	ON_BN_CLICKED(IDC_BTNINSERT, &CMyBooksDlg::OnBnClickedBtninsert)
END_MESSAGE_MAP()


// CMyBooksDlg �޽��� ó����

BOOL CMyBooksDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CRect rect;
	m_ctrlList1.GetClientRect(rect);
	// ��Ʈ ����
	//m_ctrlList1.ModifyStyle(0, LVS_SHOWSELALWAYS);
	m_ctrlList1.SetExtendedStyle(m_ctrlList1.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_INFOTIP | LVS_EX_ONECLICKACTIVATE | LVS_EX_GRIDLINES);
	m_ctrlList1.ModifyStyle(0, LVS_SHOWSELALWAYS);
	//m_ctrlList1.SetExtendedStyle(LVS_EX_FULLROWSELECT);
	m_ctrlList1.InsertColumn(0, "���� ID", LVCFMT_LEFT, int(rect.Width() * 0.1), -1);
	m_ctrlList1.InsertColumn(1, "����", LVCFMT_LEFT, int(rect.Width() * 0.5), -1);
	m_ctrlList1.InsertColumn(2, "����", LVCFMT_LEFT, int(rect.Width() * 0.2), -1);
	m_ctrlList1.InsertColumn(3, "���� ID", LVCFMT_LEFT, int(rect.Width() * 0.1), -1);
	m_ctrlList1.InsertColumn(4, "���ǻ� ID", LVCFMT_LEFT, int(rect.Width() * 0.1), -1);


	m_tooltip.Create(this, TTS_ALWAYSTIP | TTS_BALLOON);
	m_tooltip.AddTool(GetDlgItem(IDC_KeySTATIC), "�Ҽ� : 1000~1999 | ���� : 2000~2999 | ��ȭ : 3000~3999");
	m_tooltip.SetTipBkColor(RGB(255, 255, 0));
	m_tooltip.SetTipTextColor(RGB(0, 0, 0));


	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CMyBooksDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���ø����̼��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CMyBooksDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CMyBooksDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//author table ����
void CMyBooksDlg::OnBnClickedBtnviewA()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	myAuthor dlg;
	//DoModal() -> Author ������ �ٿ��

	UpdateData(TRUE);
	//mysql ����
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//���� ���� ����
	char query[100];
	memset(query, NULL, 100); //�迭 �ʱ�ȭ
	CString str = m_nauthorID.GetString();
	if (str == "") { //���� ID�� �ƹ��͵� ���� ��, �ƹ� ���൵ ���� ����
		dlg.DoModal();
		mysql_close(&mysql);
		return;
	}
	//�˻� �ܾ� ������ ���̺� �� ǥ��

	//���� ������
	sprintf_s(query, "select author_ID, name, phone, e_mail, sns from author where author_ID = %d", _ttoi(str)); //������ �ٲٱ�
	mysql_query(&mysql, query);
	//dlg.m_ctrlList_Aut.DeleteAllItems(); //����Ʈ ��Ʈ�ѿ� ������ �ԷµǾ� �ִ� ������ ����
	MYSQL_RES* result = mysql_store_result(&mysql); //���� ���
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	//����ID�� ������ �ϳ� -> listcontrol�� ��Ÿ����
	MYSQL_ROW row;
	int idx = 0;
	//while (row = mysql_fetch_row(result))
	//{
	//	dlg.m_ctrlList_Aut.InsertItem(idx, row[0]);
	//	for (int i = 1; i <= 4; i++)
	//	{
	//		dlg.m_ctrlList_Aut.SetItemText(idx, i, row[i]);
	//	}
	//	idx++;
	//}
	row = mysql_fetch_row(result);

	//m_ctrlList1.SetExtendedStyle(LVS_EX_CHECKBOXES);
	dlg.Set(row[0], row[1], row[2], row[3], row[4]);
	dlg.DoModal();
	mysql_free_result(result); //���� ��� �޸� ����
	mysql_close(&mysql);
	UpdateData(FALSE);
}

//publisher table ����
void CMyBooksDlg::OnBnClickedBtnviewP()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	myPublisher dlg2;

	UpdateData(TRUE);
	//mysql ����
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//���� ���� ����
	char query[100];
	memset(query, NULL, 100); //�迭 �ʱ�ȭ
	CString str = m_nPubID.GetString();
	if (str == "") { //���ǻ� ID�� �ƹ��͵� ���� ��, �ƹ� ���൵ ���� ����
		dlg2.DoModal();
		mysql_close(&mysql);
		return;
	}
	//�˻� �ܾ� ������ ���̺� �� ǥ��

	//���� ������
	//if(str == "") sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher");
	//else          sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = %d", _ttoi(str)); //������ �ٲٱ� 
	sprintf_s(query, "select publisher_ID, name, phone, e_mail, address from publisher where publisher_ID = %d", _ttoi(str));
	mysql_query(&mysql, query);
	//dlg.m_ctrlList_Aut.DeleteAllItems(); //����Ʈ ��Ʈ�ѿ� ������ �ԷµǾ� �ִ� ������ ����
	MYSQL_RES* result = mysql_store_result(&mysql); //���� ���
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	//����ID�� ������ �ϳ� -> listcontrol�� ��Ÿ����

	MYSQL_ROW row;
	int idx = 0;
	row = mysql_fetch_row(result);
	//m_ctrlList1.SetExtendedStyle(LVS_EX_CHECKBOXES);
	dlg2.Set(row[0], row[1], row[2], row[3], row[4]);
	dlg2.DoModal();
	mysql_free_result(result); //���� ��� �޸� ����
	mysql_close(&mysql);
	UpdateData(FALSE);
}


void CMyBooksDlg::OnBnClickedBtnsearch()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	//mysql ����
	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//���� ���� ����
	char query[100];
	memset(query, NULL, 100); //�迭 �ʱ�ȭ
	CString str = m_nbookID.GetString(); //1000

	if (str == "")
		sprintf_s(query, "select book_ID, book_title, book_price, author_ID, publisher_ID from book");
	else //�˻� �ܾ� ������ ���̺� �� ǥ��
		sprintf_s(query, "select book_ID, book_title, book_price, author_ID, publisher_ID from book where book_ID = %d", _ttoi(str));//������ �ٲٱ� 
	//���� ������
	mysql_query(&mysql, query);

	m_ctrlList1.DeleteAllItems(); //����Ʈ ��Ʈ�ѿ� ������ �ԷµǾ� �ִ� ������ ����
	MYSQL_RES* result = mysql_store_result(&mysql); //���� ���
	if (!result)
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}
	//����ID�� ������ �ϳ� -> listcontrol�� ��Ÿ����
	MYSQL_ROW row;
	int idx = 0;
	while (row = mysql_fetch_row(result))
	{
		m_ctrlList1.InsertItem(idx, row[0]);
		for (int i = 1; i <= 4; i++)
		{
			m_ctrlList1.SetItemText(idx, i, row[i]);
		}
		idx++;
	}

	mysql_free_result(result); //���� ��� �޸� ����
	mysql_close(&mysql);
	m_nauthorID.SetString("");
	m_nPubID.SetString("");
	m_nbookID.SetString("");
	UpdateData(FALSE);
}


void CMyBooksDlg::OnBnClickedBtnmodify()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	// book table�� ���ؼ��� ����
	// ����Ŭ���ϸ� domodal()
	UpdateData(TRUE);
	Updatedlg dlg;

	int nSel = m_ctrlList1.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		AfxMessageBox("������ ���� �������ּ���.");
		return;
	}
	dlg.m_bookID_up = m_ctrlList1.GetItemText(nSel, 0);
	dlg.m_booktitle_up = m_ctrlList1.GetItemText(nSel, 1);
	dlg.m_bookprice_up = m_ctrlList1.GetItemText(nSel, 2);

	//�޺��ڽ��� �� ǥ��
	dlg.m_strAut = m_ctrlList1.GetItemText(nSel, 3);
	dlg.m_strPub = m_ctrlList1.GetItemText(nSel, 4);

	// ���� ��, ���� �ۼ��� ���� Ŭ���� ������ �ֱ�
	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		OnBnClickedBtnsearch();
		AfxMessageBox("������ �Ϸ�Ǿ����ϴ�.");
	}

}

void CMyBooksDlg::OnBnClickedBtninsert()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	InsertBook dlg;

	int ret = (int)dlg.DoModal();
	if (ret == IDOK) {
		OnBnClickedBtnsearch();
		AfxMessageBox("�߰��� �Ϸ�Ǿ����ϴ�.");
	}

}


void CMyBooksDlg::OnBnClickedBtndelete()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	UpdateData(TRUE); //MFC -> ����

	MYSQL mysql;
	mysql_init(&mysql);
	mysql_real_connect(&mysql, "localhost", "root", "tiger", "mybooks", 0, NULL, 0);

	//���� ���� ����
	char query[50];
	memset(query, NULL, 50); //�迭 �ʱ�ȭ
	int nSel = m_ctrlList1.GetNextItem(-1, LVNI_SELECTED);
	if (nSel == -1)
	{
		mysql_close(&mysql);
		AfxMessageBox("������ ���� �������ּ���.");
		return;
	}
	CString str = m_ctrlList1.GetItemText(nSel, 0);

	int ret = AfxMessageBox("������ �����Ͻðڽ��ϱ�?", MB_YESNO | MB_ICONQUESTION);
	if (ret != IDYES) {
		mysql_close(&mysql);
		return;
	}
	//���� ������
	sprintf_s(query, "delete from book where book_ID = %d", _ttoi(str)); //������ �ٲٱ�
	if (mysql_query(&mysql, query))
	{
		AfxMessageBox(mysql_error(&mysql));
		mysql_close(&mysql);
		return;
	}

	mysql_close(&mysql);
	m_nauthorID.SetString("");
	m_nPubID.SetString("");
	m_ctrlList1.DeleteItem(nSel);
	UpdateData(FALSE);
	AfxMessageBox("������ �Ϸ�Ǿ����ϴ�."); //�ǵ��� ��������
}


//void CMyBooksDlg::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult)
//{
//	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
//	
//	AfxMessageBox("abcd");
//
//	*pResult = 0;
//}


void CMyBooksDlg::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);

	NM_LISTVIEW* p = (NM_LISTVIEW*)pNMHDR;
	//int nSel = p->iItem; //�ε��� 
	m_nauthorID = m_ctrlList1.GetItemText(p->iItem, 3);
	m_nPubID = m_ctrlList1.GetItemText(p->iItem, 4);
	//int idx = pNMItemActivate->iItem; //Ŭ���� �������� �ε��� ������
	//if (idx >= 0 && idx < m_ctrlList1.GetItemCount())
	//{
	//	//4�� ����ID�� edit2
	//	//5�� ���ǻ�ID�� edit3
	//}
	UpdateData(FALSE); //���� -> MFC
	*pResult = 0;
}


void CMyBooksDlg::OnBnClickedCcancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


BOOL CMyBooksDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_tooltip.RelayEvent(pMsg);
	return CDialogEx::PreTranslateMessage(pMsg);
}
