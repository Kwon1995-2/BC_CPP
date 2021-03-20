// 8장-6.FOREIGN.CPP   8.2 동적 Binding의 소개   
#include <iostream>
using namespace std;
class Person{
protected:
    char * name;
public:
    Person (char* n) : name (n)
    { }
//    virtual void Print (){
	void Print() {
        cout << "Person::내 이름은 " << name << endl;
    }
};

class Foreigner : public Person{
public:
    Foreigner (char* n) : Person (n)
    { }    

    void Print (){
        cout << "Foreigner::My name is " << name << endl;
    }
} ;
void main(){
    Person * man;
    Person * woman;
//    Foreigner* woman;

    man = new Person ("John");
    woman = new Foreigner ("Paola");
    
    cout << "Prints the name of the man:" << endl;
    man -> Print ();
    cout << "Prints the name of the woman (a foreigner):" << endl;
    woman -> Print ();

    man = new Foreigner ("Mario");
    cout << endl;
    cout << "Re-prints the name of the man after the new assignment:"           << endl;
    man -> Print ();
	system("pause");
}