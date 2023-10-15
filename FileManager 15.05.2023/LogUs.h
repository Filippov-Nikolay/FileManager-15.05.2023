#pragma once

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

class LogUs {
public:
	void CreateLogUs() const;
	void InputLogUsRegistration(int, string, string, string, string, bool, bool) const;
	void InputLogUsAuthorization(string, string, string, bool, bool) const;
	void Encryption(string&);

	bool SearchFirstName(string) const;
	bool SearchLastName(string) const;
	bool SearchLogin(string) const;
	bool SearchPassword(string) const;
	bool Authorization(string, string) const;
};

