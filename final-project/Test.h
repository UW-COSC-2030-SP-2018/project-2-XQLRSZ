#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

using namespace std;

class Test {
public:
	Test(string m = "", bool r = false, bool e = true);
	string getMessage() const;
	bool getResult() const;
	bool getExpected() const;
	void setMessage(string m);
	void setResult(bool r);
	void setExpected(bool e);
	friend ostream& operator<<(ostream& out, const Test& right);
private:
	string message;
	bool result;
	bool expected;
};
#endif