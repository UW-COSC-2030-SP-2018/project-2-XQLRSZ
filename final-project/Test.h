#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>

using namespace std;

class Test {
public:
	Test();
	Test(string m, bool r);
	string getMessage() const;
	bool getResult() const;
	void setMessage(string m);
	void setResult(bool r);
	void print() const;
private:
	string message;
	bool result;
};
#endif