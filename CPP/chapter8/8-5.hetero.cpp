//8-5.HETERO.cpp   8.10 이질적인 데이터 구조 
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal(){
        name = " ";
	}
    //*
	Animal(char* a){
        name = a;
    }
    //*/
    //virtual ~Animal();

    virtual void Speak();
protected:
	char* name;
    /*
    Animal(char* a) {
        name = a;
    }
    */
};


void Animal::Speak(){
    cout<<"Animal::The animal is making his verse"<<endl;
}


class Cow : public Animal{
public:
    Cow(char* a);
    void Speak();
};

class Dog : public Animal{
public:
    Dog(char* a);
    void Speak();
};

Cow::Cow(char* a):
Animal(a){}

void Cow::Speak(){
    cout <<"Cow::"<< name << " says moo" << endl;
}

Dog::Dog(char* a):
Animal(a){}

void Dog::Speak(){
    cout<<"Dog::"<< name << " says arf" <<endl;
}


void main(){
    Animal* mixedFlock[10];
    mixedFlock[0] = new Cow("Tom");
    mixedFlock[1] = new Dog("Thomas");
    mixedFlock[2] = new Dog("Ashley");
    mixedFlock[3] = new Dog("Ryan");
    mixedFlock[4] = new Dog("Daniel");
    mixedFlock[5] = new Cow("Matthew");
    mixedFlock[6] = new Cow("Samuel");
    mixedFlock[7] = new Cow("William");
    mixedFlock[8] = new Animal("Sophie");
    mixedFlock[9] = new Dog("Jessica");

    for(int i=0; i< 10;i++)
        mixedFlock[i]->Speak();
    system("pause");
}