#include <iostream>

using namespace std;

class Printer {
public : 
	Printer() {}
	virtual void Method(char* buffer) = 0;
	virtual int Dpi() = 0;
};
class LaserPrinter : public Printer {   // (1)번 문제 답 = 추상 클래스
	int nDots;
public:
	LaserPrinter(int n) : nDots(n) {}

	void Method(char* buffer) {
		sprintf(buffer, "Laser printer with %d pins", nDots);
	}
};
class DotMatrixPrinter : public Printer {
	int nDots;
public:

	DotMatrixPrinter(int n) : nDots(n) {}

	void Method(char* buffer) {
		sprintf(buffer, "Dot matrix printer with %d pins", nDots);
	}
	int Dpi() {
		switch (nDots) {
		case 8: return 150;
		case 9: return 160;
		case 24: return 300;
		default: return 100;
		}
	}
};
class DotPrinter : public DotMatrixPrinter {
	int nDots;
public:
	
	void Method(char* buffer) {
		sprintf(buffer, "Dot printer with %d pins", nDots);
	}
	int Dpi() {
		switch (nDots) {
		case 8: return 150;
		case 9: return 160;
		case 24: return 300;
		default: return 100;
		}
	}
};

void main()
{
	//LaserPrinter lp;
	Printer* dp;
	dp = new DotPrinter; //오류

	
}