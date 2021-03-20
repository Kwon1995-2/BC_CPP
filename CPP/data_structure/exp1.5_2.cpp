#include <iostream>
#include <string>
#include <vector>
using namespace std;
//class Vect {
//public:
//	Vect() { size = 10; data = new int[size]; }
//	Vect(int n);
//	~Vect();
//	Vect(const Vect& a);
//	Vect& operator=(const Vect& a);
//private:
//	int* data;
//	int size;
//};
//
//Vect::Vect(int n) {
//	size = n;
//	data = new int[n];
//}
//Vect::~Vect() {
//	delete [] data;
//}
//Vect::Vect(const Vect& a) {
//	size = a.size;
//	data = new int[size];
//	for (int i = 0; i < size; i++) {
//		data[i] = a.data[i];
//	}
//}
//Vect& Vect::operator=(const Vect& a) {
//	if (this != &a) {
//		delete[] data;
//		size = a.size;
//		data = new int[size];
//		for (int i = 0; i < size; i++) {
//			data[i] = a.data[i];
//		}
//	}
//	return *this;
//}
int main()
{
	/*Vect a(100);
	Vect b = a;
	Vect c;
	c = a;*/
	/*int i = 1;
	vector<int> scores(100);
	vector<char> buffer(500);
	cout << scores[i];
	buffer.at(i) = buffer.at(2 * i);
	vector<int> newScores = scores;
	scores.resize(scores.size() + 10);*/
	//vector<Passenger> passenList(20);

	string s = "a dog";
	s += " is a dog";
	cout << s.find("dog") << endl;
	cout << s.find("dog", 3) << endl;
	if (s.find("doug") == string::npos) {}
	cout << s.substr(7, 5) << endl;
	s.replace(2, 3, "frog");
	s.erase(6, 3);
	s.insert(0, "is ");
	cout << s << endl;
}
