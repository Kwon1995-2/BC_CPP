// 6-4.OVERLOAD.CPP
// overloading�� member function ȣ��� non-member �Լ� ȣ���� ���̸� �ǽ�
#include <iostream>
#include<string>
using namespace std;
// public member�� ���� class 
struct Complex {
    int r;    // ���Ҽ��� �Ǽ���
	int i;    // ���Ҽ��� �����

	Complex(){
		r = 0;
		i = 0;
	}
  // overloading�� member �Լ�
    void Add (Complex c){
        r += c.r;
        i += c.i;
    }
    void  Add (Complex * pc){
        r += (*pc).r;
        i += (*pc).i;
    }
    void Add (int a, int b = 0){   // �ι�° ���� �� �ָ� default�� 0 �־��
        r += a;
        i += b;
    }

    Complex operator+(Complex b);
   /* {
        Complex c;
        c.r = r + b.r;
        c.i = i + b.i;
        return c;
    }*/

    Complex operator++();
    Complex operator++(int);
};
// overloading�� non-member �Լ�
Complex Multiply (Complex c1, Complex c2){
    Complex c3;
    c3.r = c1.r * c2.r - c1.i * c2.i;
    c3.i = c1.r * c2.i + c1.i * c2.r;
    return c3;
}
Complex Multiply (Complex c, int n){
    c.r *= n;
    c.i *= n;
    return c;
}
// overloading�� non-member �Լ��� �ٸ� ��
void Print (Complex c){
    cout << c.r << "+" << c.i << "i" << endl;
}
void Print (int n){
    cout << n << endl;
}
void Print (const char * string){
    cout << string << endl;
}
void Print ( ){
    cout << endl;
}

Complex Complex::operator+(Complex b) {
    Complex c;
    c.r = r + b.r;
    c.i = i + b.i;
    return c;
}

Complex Complex::operator++() {
    Complex c;
    c.r = r + 1; //c.r=r++;
    c.i = i + 1; //c.i=i++;
    return c;
}

Complex Complex::operator++(int) {
    Complex c;
    ++c;
    return c;
}
/*
class Complex {
private:
	float real;
	float imaginary;
public:
	Complex& operator+(Complex&);//�Լ� body�� ������ �� �־�� �Ѵ�
	//c = a + b + c; ������ ������ �ڵ� �ۼ� �Ʒ�
	friend ostream& operator<<(ostream&, Complex &);//member �Լ��� ������ �� ���� ����: ostream class�� ��ĥ �� ���� �����̴�
	//friend ostream& operator<<(Complex &);//member �Լ� �����ε� ostream class�� ��ĥ �� ���� ������ ��� ����

};
*/
// main �Լ��� ��� ���ǵ� overloading�� �Լ��� �̿��Ѵ�.
void main(){

	Complex x; x.Add(3, 1);//operator +()�� ����� �ڵ�� ������ �ǽ� ����
    Complex y; y.Add(1, 2);
    Complex q; q = x.operator+(y); //x+y;
    cout << "operator+ :"; Print(q); // cout << : ����ü ��ȯ�� �� �ֵ��� operator overloading �ؾ� ��
    int z = 4;
   	Print ("Sum of the complex numbers:");
    cout<<"x = "; Print (x);//cout <<x;�� ����� �ǽ����� �����ϱ�
    cout<<"y = "; Print (y);
       // �� ���Ҽ��� ��: Add()�Լ��� ù ��° version
	x.Add (y);
    Print ("----");
    cout<<"x+y = ";Print (x);
       // ���Ҽ��� �Ǽ��� ��: Add ()�Լ��� �� ��° version
	y.Add (z);
     // �ٸ� �� �Լ��� �̿��Ͽ� �� ���� ����Ѵ�.
	cout<<"After y.Add(z)::y = "; Print(y);

	Complex product1, product2;
	int v = 7;
	product1 = Multiply (x, y);//�ΰ��� ���Ҽ��� ���ϱ�
    product2 = Multiply (x, v);//���Ҽ� X�� ���Ͽ� ���� V ���ϱ�
        // �ʱ� ���� ��� ���� ����Ѵ�.
	Print (); Print ();
    Print ("x equals to:");
    Print (x); Print ();
    Print ("y equals to:");
    Print (y); Print ();
    Print ("v equals to: ");
        // Print(x)�� �ٸ� �Լ��� ȣ��ȴ�.
	Print (v);
        // ������ ����� ����Ѵ�. 
	Print ();
    Print ("x * y = ");
    Print (product1);
    Print ();
    Print ("x * v = ");
    Print (product2);
	system("pause");
}