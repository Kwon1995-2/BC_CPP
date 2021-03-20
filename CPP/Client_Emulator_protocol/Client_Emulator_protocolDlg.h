
// Client_Emulator_protocolDlg.h: 헤더 파일
//

#pragma once
//#include <iostream>
//#include <ctime>
#include <vector>
#include <string>
//#include <windows.h>

#define DATASIZE 16
using namespace std;

typedef struct _DATA_
{
	short id;
	int day;
	int tm;
	short temp;
	short hum;
	short press;
}DATA, * LPDATA;

class DataManager
{
public :
	DataManager() {}
	~DataManager() {
		int size = array.size();
		for (int i = 0; i < size; i++)
			free(array[i]);
	}

	vector<LPDATA> array;

	LPDATA GetData(int id)
	{
		int size = array.size();
		for (int i = 0; i < array.size(); i++)
		{
			if (array[i]->id == id) return array[i];
		}
		return NULL;
	}

	void AddData(LPDATA pd)
	{
		SetData(pd);
		array.push_back(pd);
	}

	void SetData(LPDATA pd)
	{
		CTime tm = CTime::GetCurrentTime();
		int y = tm.GetYear();
		int m = tm.GetMonth();
		int d = tm.GetDay();
		int h = tm.GetHour();
		int M = tm.GetMinute();
		int s = tm.GetSecond();

		pd->day = y * 10000 + m * 100 + d;
		pd->tm = h * 10000 + M * 100 + s;
	}

	CString getString(LPDATA pd)
	{
		CString str;
		str.Format("%d,%d,%d,%d,%d,%d", pd->id, pd->day, pd->tm, pd->temp, pd->hum, pd->press);
		return str;
	}

};
// CClientEmulatorprotocolDlg 대화 상자
class CClientEmulatorprotocolDlg : public CDialogEx
{
// 생성입니다.
public:
	CClientEmulatorprotocolDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.
	int GetCountData(int seq, int start);
	void writeData(FILE* fp, CStringArray& arr);
	void sendData(SOCKET sock, CStringArray& arr);
	BYTE* CClientEmulatorprotocolDlg::makeBuff(BYTE* pbuf, int count, CStringArray& arr);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLIENT_EMULATOR_PROTOCOL_DIALOG };
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
public:
	afx_msg void OnBnClickedBtngenr();
	afx_msg void OnBnClickedBtnsave();
	afx_msg void OnBnClickedBtncnet();
	afx_msg void OnBnClickedBtnsend();
	CListBox m_strlListGen;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedBtnreset();
	int m_nPort;
	CIPAddressCtrl m_IPADDR;
};
