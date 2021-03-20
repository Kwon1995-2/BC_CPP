
// PatternMatchingDlg.h: 헤더 파일
//

#pragma once
#include <vector>

// CPatternMatchingDlg 대화 상자
class CPatternMatchingDlg : public CDialogEx
{
// 생성입니다.
public:
	CPatternMatchingDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PATTERNMATCHING_DIALOG };
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
	CString m_strPString;
	
	CListBox m_ctrlList2;
	afx_msg void OnBnClickedBtnsearch();
	afx_msg void OnBnClickedCancel();
	BOOL m_nType;
	CString m_strText;
};

class PatternMatch {
public:
	virtual int patternmatch(const char* pText, const char* pPtrn) = 0;
	virtual CString getTypeName() = 0;
};

class Brute_Force : public PatternMatch {
public:
	int patternmatch(const char* pText, const char* pPtrn) {
		//pText : n개의 문자를 가진 문자열 T
	//pPtrn : m개의 문자를 가진 문자열 P(패턴)
		int n = (int)strlen(pText);//sizeof(*pText); //Text String 
		int m = (int)strlen(pPtrn);//sizeof(*pPtrn); //Pattern String
		int j;
		for (int i = 0; i < n - m; i++) {
			j = 0;
			while ((j < m) && (pText[i+j] == pPtrn[j])) {
				//pText[i+j]
				//i++; -> i가 움직이면 비교하지 않는 값이 생겨버림
				j = j + 1;
				if (j == m) return i;//-m;
				//else break;
			}
		}
		//"pPtrn과 일치하는 pText의 문자열이 없다."
		return -1;
	}
	CString getTypeName() { return CString("BF:"); }
};
class Boyer_Moore : public PatternMatch {
public:
	std::vector<int> buildLastFunction(const char* pPtrn) {
		int lenPtrn = (int)strlen(pPtrn);

		const int N_ASCII = 128;
		std::vector<int> last(N_ASCII); //128개의 원소를 가지는 vector last 생성
		for (int i = 0; i < N_ASCII; i++) {
			last[i] = -1; //128칸에 모두 -1로 초기화
		}
		for (int i = 0; i < lenPtrn; i++) {
			last[pPtrn[i]] = i; //if(pPtrn="abc") -> last(97, 98, 99)번째에 0, 1, 2가 들어감
		}
		return last;
	}

	int patternmatch(const char* pText, const char* pPtrn)
	{
		int lenText = (int)strlen(pText); //10칸이라 가정
		int lenPtrn = (int)strlen(pPtrn); //3칸이라 가정

		std::vector<int> last = buildLastFunction(pPtrn); //128칸 짜리가 last로 들어온다.
		int i = lenPtrn - 1; //2칸
		if (lenText - 1 < i) { // 9 < 2 -> 패턴보다 작으면 같지 않으니까 -1 반환
			return -1;
		}

		int j = lenPtrn - 1;  //j=2칸
		do { //처음에 무조건 실행->이후는 while문과 동일
			if (pPtrn[j] == pText[i]) //pPtrn[2] == pText[2] -> if(if or else) 계속 if문 안으로 들어오면 같은 문자열의 시작점 반환할 것
				if (j == 0) return i;
				else { i--; j--; }
			else {
				i = i + lenPtrn - min(j, 1 + last[pText[i]]); //1,2 + 3부터 - (j(1,2) or -1 or 0, 1, 2)
				j = lenPtrn - 1; //j는 여전히 2로 세팅됨
			}
		} while (i <= lenText - 1); //i<=9 :: i가 전체 비교 평문보다 작을 때 while문 돈다.
		return -1;
	}

	CString getTypeName() { return CString("BM:"); }
};
