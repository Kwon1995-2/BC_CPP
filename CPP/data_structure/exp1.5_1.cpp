#include <iostream>
#include <string>
using namespace std;

//class Counter {
//public:
//	Counter();
//	int getCounter();
//	void increaseBy(int x);
//private:
//	int count;
//};
//Counter::Counter() { count = 0; }
//int Counter::getCounter() {
//	return count;
//}
//void Counter::increaseBy(int x) {
//	count += x;
//}
enum MealType { None, REGULAR, NO_PREF};
class Passenger {
public:
	Passenger();
	Passenger(const string& nm, MealType mp, const string& ffn = "NONE");
	Passenger(const Passenger& pass);
	bool isFrequentFlyer() const;
	void makeFrequentFlyer(const string& newFreqFlyerNo);
private:
	string name;
	MealType mealPref;
	bool isFreqFlyer;
	string freqFlyerNo;
};
bool Passenger::isFrequentFlyer() const {
	return isFreqFlyer;
}
void Passenger::makeFrequentFlyer(const string& newFreqFlyerNo) {
	isFreqFlyer = true;
	freqFlyerNo = newFreqFlyerNo;
}

Passenger::Passenger() {
	name = "--NO NAME--";
	mealPref = NO_PREF;
	isFreqFlyer = false;
	freqFlyerNo = "NONE";
}
Passenger::Passenger(const string& nm, MealType mp, const string& ffn = "NONE") {
	name = nm;
	mealPref = mp;
	isFreqFlyer = (ffn != "NONE");
	freqFlyerNo = ffn;
}
//Passenger::Passenger(const string& nm, MealType mp, const string& ffn = "NONE") : name(nm), mealPref(mp), isFreqFlyer(ffn != "NONE") {
//	freqFlyerNo = ffn;
//}
Passenger::Passenger(const Passenger& pass) {
	name = pass.name;
	mealPref = pass.mealPref;
	isFreqFlyer = pass.isFreqFlyer;
	freqFlyerNo = pass.freqFlyerNo;
}
int main()
{
	/*Counter ctr;
	cout << ctr.getCounter() << endl;
	ctr.increaseBy(3);
	cout << ctr.getCounter() << endl;
	ctr.increaseBy(5);
	cout << ctr.getCounter() << endl;*/

	Passenger p1;
	Passenger p2("Jhon", REGULAR, "2934");
	Passenger p3("Pdd", REGULAR);
	Passenger p4(p3);  //복사생성자 호출
	Passenger p5 = p2; //복사생성자 호출
	Passenger* pp2 = new Passenger("Joe", NO_PREF);

}