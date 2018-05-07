#include "Test.h"

Test::Test(char m[], bool r) {
	setMessage(m);
	setResult(r);
}

char* Test::getMessage() const {
	return message;
}

bool Test::getResult() const {
	return result;
}

void Test::setMessage(char m[]) {
	*message = *m;
}

void Test::setResult(bool r) {
	result = r;
}

void Test::print() const {
	cout << getMessage() << ": " << getResult() << endl;
}