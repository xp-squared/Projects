#pragma once
#include <string>
using namespace std;

class User {
public:
	bool login(const string &username, const string &password);
	void userMenu();

private:
	string password;
	string username;

};
