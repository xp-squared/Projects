#pragma once
#include <string>
using namespace std;

class Admin {
public:
	bool login(const string &username, const string &password);
	void addCar();
	void removeCar();
	void viewReservations();
	void adminMenu();

private:
	string password;
	string adminName;

};
