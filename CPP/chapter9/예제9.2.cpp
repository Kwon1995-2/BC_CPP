#include <iostream>
using namespace std;
class Printer {  // 추상 클래스
public :
	Printer() {}
	virtual void Method(char* buffer) = 0;
	virtual int Cpi() = 0;
};
class LaserPrinter : public Printer {   // 추상 클래스
public : 
	LaserPrinter() {}
	int Cpi() { return 300; }
};
class InkJetLaser : public LaserPrinter {
public : 
	InkJetLaser() {}
	void Method(char* buffer) {}
};

void main() {
	//Printer p1; //-> 순수 가상 함수는 자기 객체 생성 불가
	Printer* p2 = new Printer(); // 함수 형태이고 추상 클래스 타입의 메모리 할당 불가
	Printer* p3;
	Printer* p4 = new LaserPrinter();
	Printer* p5 = new InkJetLaser();

	InkJetLaser* lp2 = new Printer();
	InkJetLaser* lp3 = new LaserPrinter();
	InkJetLaser* lp4;

	InkJetLaser ip1;
	InkJetLaser& ip2 = ip1;
	InkJetLaser* ip3 = new Printer();
	InkJetLaser* ip4 = new LaserPrinter();
	InkJetLaser* ip5 = new InkJetLaser();
	InkJetLaser* ip6 = new InkJetLaser();
	Printer* p6 = (Printer*)ip6;

}