#include "Test.h"

Test::Test(string m, bool r, bool e) {
	setMessage(m);
	setResult(r);
	setExpected(e);
}

string Test::getMessage() const {
	return message;
}

bool Test::getResult() const {
	return result;
}

bool Test::getExpected() const {
	return expected;
}

void Test::setMessage(string m) {
	message = m;
}

void Test::setResult(bool r) {
	result = r;
}

void Test::setExpected(bool e) {
	expected = e;
}

ostream& operator<<(ostream& out, const Test& right) {
	out << right.getMessage() << " : " << ((right.result == right.expected) ? "Passing" : "Failing");
	return out;
}