//8.2 dynamicBinding.cpp   8.5 virtual 함수
#include <iostream>
using namespace std;

class Person{
protected:
    char* name;
public:
    Person(char* n):name(n){}
    virtual void Print(){
        cout<<"\tPerson::Print(): name is "<<name<<endl;
    }
    virtual void Print(char* ch){
        cout<<"\tPerson::Print(char*ch): name is "<<ch<<endl;
    }
};

class Foreigner : public Person{
public:
    Foreigner(char* n):Person(n){}
//주석1   
/*
    void Print(){
        cout<<"\tForeigner::Print(): name = "<<name<<endl;
    }
*/
//주석2
/*
     virtual void Print(){
        cout<<"\tForeigner::virtual_Print():name = " <<name << endl;
    }
*/	 
    void Print(char* ch){
		Person::Print(ch);
        cout<<"\tForeigner::Print(char* ch):name = " << ch << endl;
    }
};
class ChinaForeigner : public Foreigner{
public:
    ChinaForeigner(char* n):Foreigner(n){}
    void Print(){
        cout<<"\tChinaForeigner::Print():name - "<<name<<endl;
    }
};

void main(){
    Person* wp;
    Person* wf;
    Person* wc;

    wp = new Person("John");
    wf = new Foreigner("elintoo");
    wc = new ChinaForeigner("chailyn");

    cout<<"Prints the name : "<<endl;
    wp->Print();
    wf->Print();
    wc->Print();
    wc->Person::Print();
	cout << "After wp = wf;" << endl;
    wp = wf;
    wp->Print();

	cout << "After wp = wc;" << endl;
    wp = wc;
    wp->Print();
	wf->Print("Sera"); 
    wc->Print("Sera"); 
	cout << "wp = new Foreigner(Mario);" << endl;
    wp = new Foreigner("Mario");
    cout<<endl << "Re-prints the name of the man after the new assignment:"<<endl;
    wp->Print();
    system("pause");
}

