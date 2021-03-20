#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
using std::ostream;
#include <string>
using std::string;
class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; }
	string getMessage() const { return errorMsg; }
};
inline ostream& operator<<(ostream& out, const RuntimeException& e) { return out << e.getMessage(); }

class StackEmpty : public RuntimeException {
public:
	StackEmpty(const string& err) :RuntimeException(err) {}
};

class StackFull : public RuntimeException {
public:
	StackFull(const string& err) :RuntimeException(err) {}
};

#endif
