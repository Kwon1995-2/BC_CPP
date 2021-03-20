// 8-3.PUREVIRTUAL.CPP    8.6 virtual 함수와 동적 binding의 사용 예
#include <iostream>
using namespace std;
class Polygon{
public:
    int Creator(); 
    virtual void Moves(int delta_x, int delta_y);     
    virtual int Perimeter()=0; 
    virtual int Color()=0; 

protected:
    int creator;
    int x_pos, y_pos;
};

int Polygon::Creator(){
    cout << "Polygon의 Creator() : " << creator << endl;
    return creator;
}

void Polygon::Moves(int delta_x, int delta_y){
    cout << "Polygon의 Moves()" << endl;
    cout << "실행 전 x_pos : " << x_pos << "  y_pos : " << y_pos           << endl;
    x_pos += delta_x;
    y_pos += delta_y;
    cout << "실행 후 x_pos : " << x_pos << "  y_pos : " << y_pos           << endl;
}

class Rectangle : public Polygon{
public:
    ///* 주석 2
    int Perimeter(){
        cout << "Rectangle의 Perimeter() : " << 2*(height+base)               << endl;
        return 2*(height+base);
    }//*/
    int Color(){
        cout << "Rectangle의 Color() : " << color << endl;
        return color;
    }
    int Base(){
        cout << "Rectangle의 Base() : " << base << endl;
        return base;
    }
    int Height(){
        cout << "Rectangle의 Height() : " << height << endl;
        return height;
    }
private:
    int base, height;
    int color;
};

class Square : public Rectangle {
public:
    ///* 주석 3
    int Perimeter(){
        cout << "Square의 Perimeter() : " << "0" << endl;
        return 0;
    }
    int Color(){
        cout << "Square의 Color() : " << color << endl;
        return color;
    }
    int Color(int c){

        color = c;
        cout << "Square의 Colorl(int c) : " << color << endl;
        return color;
    }//*/
    void Moves(int delta_x, int delta_y) {
        cout << "Square:: Moves() is called" << endl;
        Polygon::Moves(delta_x, delta_y);
    }
private:
    int color;
};

void main(){

    ///* 주석1
    //Polygon p1;
    //Polygon *p1 = new Polygon(); // 순수가상클래스는 인스턴스를 만들 수 없음.
    Polygon *p2 = new Rectangle(); 
    cout << endl << "------ Polygon *p2 = new Rectangle() ------"           << endl;
    p2->Creator();
    p2->Perimeter();
    p2->Color();
    p2->Moves(1, 2);
    //*/
    Polygon *p3 = new Square();
    cout << endl << "------ Polygon *p3 = new Square() ------"           << endl;
    p3->Creator();
    p3->Perimeter();
    p3->Color();
    //p3->Color(10);
    p3->Moves(10, 20);	
	
    Rectangle *r1 = new Rectangle(); 
    cout << endl << "------ Rectangle *r1 = new Rectangle() ------"           << endl;
    r1->Creator();
    r1->Perimeter();
    r1->Color();
    //r1->Color(10); 
    r1->Moves(10, 20);
    r1->Base();
    r1->Height();

    Rectangle *r2 = new Square();
    cout << endl << "------ Rectangle *r2 = new Square() ------"           << endl;
    r2->Creator();
    r2->Perimeter();
    r2->Color();
    //r2->Color(10); 
    r2->Moves(10, 20);
    r2->Base();
    r2->Height();

    Square *s = new Square();
    cout << endl << "------ Square *s = new Square() ------" << endl;
    s->Creator();
    s->Perimeter();
    s->Color(); 
    s->Color(20);
    s->Moves(20, 30);
    s->Base();
    s->Height();
    system("pause");
}