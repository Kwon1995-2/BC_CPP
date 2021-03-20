// 8��-11.cow_dog.h    8.8 ������ class�� ��ȭ
#include <iostream> 
using namespace std;
class Cow : public Animal {
public:
    Cow (Point p = Point (10, 10));
    Cow(char* n) : Animal(n) {};
    void Speak ();
};

class Dog : public Animal{
public:
    Dog (Point p = Point (20, 20));
    Dog(char* n) : Animal(n) {};  //n�� ���ڷ� �޴� ������ ȣ��
    void Speak ();
};

Cow :: Cow (Point p): Animal (p)
{}
void Cow :: Speak (){
    MoveOutput ();
    Animal::Speak2(); //�ڽ��� �ڱ� �θ��� Speak�� ȣ��
    cout << "Cow::Cow sounded:: moo "<< endl;
}

Dog :: Dog (Point p) : Animal (p)
{}

void Dog :: Speak (){
    MoveOutput ();
    Animal::Speak2();
    cout << "Dog::Dog sounded::merngmerng "<< endl;
}