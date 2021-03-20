#include <iostream>
using namespace std;

class Note {
	//friend class NoteImpl;
	class NoteImpl* ni;
public:
	Note(int pitch, int duration);
	~Note();
	void Sound();
	void Increase(int delta);
	void Modulate(int cycles);

	friend istream& operator >> (istream& s, Note& n);
	friend ostream& operator << (ostream& s, Note& n);

	Note& operator++();
	Note& operator++(int);

	Note& operator=(const Note& src);

	Note(const Note& src);//copy constructor
};
class NoteImpl {
	friend class Note;
private:
	int pitch;
	int duration;
public:
	NoteImpl(int p, int d) :pitch(p), duration(d) {}
	void Sound() {
		cout << "Sound() : pitch = " << pitch << ", duration = " << duration << endl;
	}

	friend istream& operator >> (istream& s, NoteImpl* n);
	friend ostream& operator << (ostream& s, NoteImpl* n);
};

Note::Note(int pitch, int duration) {
	ni = new NoteImpl(pitch, duration); //?
}
Note::~Note() {
	delete ni;
}
void Note::Sound() {
	ni->Sound();
}
void Note::Increase(int delta) {
	ni->pitch += delta;
}
void Note::Modulate(int cycles) {
	for (int i = 1; i <= cycles; i++) {
		ni->pitch++;
		ni->duration = 1 + i % 2;
		ni->Sound();
	}
}

int main()
{
	Note n(5, 32);
	cout << "Press the button to play the sound" << endl;
	//cin >> n;
	cout << n;
	cout << n++;
	cout << ++n;
	Note t(3, 20);
	t = n;
	cout << t;

	Note a = t;
	cout << a;
	//n.Sound();
	//n.Increase(5);
	//n.Sound();
	//n.Modulate(50);
	cout << "Press the button to end the program" << endl;
	return 1;
}

istream& operator >> (istream& s, Note& n) {
	s >> n.ni;  
	return s;
}
ostream& operator << (ostream& s, Note& n) {
	s << n.ni;
	return s;
}
istream& operator >> (istream& s, NoteImpl* n) {
	s >> n->pitch >> n->duration;
	return s;
}
ostream& operator << (ostream& s, NoteImpl* n) {
	cout << "<<연산자 오버로딩"<<endl;
	cout << "pitch : ";
	s << n->pitch;
	cout << ", duration : ";
	s << n->duration << endl;

	return s;
}
//++연산자 오버로딩
//전위
Note& Note:: operator++() {
	ni->pitch += 1;
	ni->duration += 1;
	return *this;
}
//후위
Note& Note:: operator++(int) {
	//Note t(ni->pitch, ni->duration);
	////ni->pitch += 1;
	//ni->duration += 1;
	//return t;
	Note Oldone = *this;
	ni->pitch++;
	ni->duration++;
	return Oldone;
}
//대입 연산자 오버로딩
Note& Note::operator=(const Note& src) {
	cout << "대입 연산자 오버로딩" << endl;
	ni->pitch = src.ni->pitch;
	ni->duration = src.ni->duration;
	return *this;
}
Note::Note(const Note& src) {
	cout << "복사 생성자 호출" << endl;
	ni = new NoteImpl(src.ni->pitch, src.ni->duration);
	//*ni = *(src.ni); -> 이렇게 
}