#include "Test.h"

Test::Test() {
	setMessage("");
	setResult(-1);
}

Test::Test(string m, bool r) {
	setMessage(m);
	setResult(r);
}

string Test::getMessage() const {
	return message;
}

bool Test::getResult() const {
	return result;
}

void Test::setMessage(string m) {
	message = m;
}

void Test::setResult(bool r) {
	result = r;
}

void Test::print() const {
	cout << getMessage() << ": " << getResult() << endl;
}