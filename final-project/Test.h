#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

using namespace std;

class Test {
public:
	Test();
	Test(string m, bool r, bool e);
	string getMessage() const;
	bool getResult() const;
	bool getExpected() const;
	void setMessage(string m);
	void setResult(bool r);
	void setExpected(bool e);
	void print() const;
private:
	string message;
	bool result;
	bool expected;
};
#endif