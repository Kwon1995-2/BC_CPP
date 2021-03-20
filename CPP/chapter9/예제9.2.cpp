#include <iostream>
using namespace std;
class Printer {  // �߻� Ŭ����
public :
	Printer() {}
	virtual void Method(char* buffer) = 0;
	virtual int Cpi() = 0;
};
class LaserPrinter : public Printer {   // �߻� Ŭ����
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
	//Printer p1; //-> ���� ���� �Լ��� �ڱ� ��ü ���� �Ұ�
	Printer* p2 = new Printer(); // �Լ� �����̰� �߻� Ŭ���� Ÿ���� �޸� �Ҵ� �Ұ�
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