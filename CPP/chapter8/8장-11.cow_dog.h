// 8장-11.cow_dog.h    8.8 유도된 class의 상세화
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
    Dog(char* n) : Animal(n) {};  //n을 인자로 받는 생성자 호출
    void Speak ();
};

Cow :: Cow (Point p): Animal (p)
{}
void Cow :: Speak (){
    MoveOutput ();
    Animal::Speak2(); //자식이 자기 부모의 Speak를 호출
    cout << "Cow::Cow sounded:: moo "<< endl;
}

Dog :: Dog (Point p) : Animal (p)
{}

void Dog :: Speak (){
    MoveOutput ();
    Animal::Speak2();
    cout << "Dog::Dog sounded::merngmerng "<< endl;
}