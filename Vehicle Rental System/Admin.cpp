#include "Admin.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool Admin::login(const string& username, const string& password) {
	ifstream inFile("Admins.txt"); // open the file to read it
	if (!inFile) {
		cerr << "Unable to open Admins.txt";
		return false; // if file is unable to be open just stops process
	}
	string line, storedUsername, storedPassword; 
	// now we read each line from the file to see if this a proper admin name and password
	while (getline(inFile, line)) {
		istringstream iss(line);
		iss >> storedUsername >> storedPassword; 
		if (username == storedUsername && password == storedPassword) { // looks for a match
			return true;
		}
	}
	return false;
}

void Admin::addCar() {
	cout << "\nAdding a new car to the fleet." << endl;
	// Your business logic here NOT DONE, USE COMPOSITON
}

void Admin::removeCar() {
	cout << "\nRemoving a car from the fleet." << endl;
	// Your business logic here NOT DONE
}

void Admin::viewReservations() {
	cout << "\nViewing current reservations." << endl;
	// Your business logic here NOT DONE
}

void Admin::adminMenu() {
    int choice;
    do {
        cout << "Admin Menu" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Remove Car" << endl;
        cout << "3. View Reservations" << endl;
        cout << "4. Log Out" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addCar();
        }
        else if (choice == 2) {
            removeCar();
        }
        else if (choice == 3) {
            viewReservations();
        }
        else if (choice == 4) {
            cout << "\nLogging out...\n" << endl;
            return; // Exit the loop and the function
        }
        else {
            cout << "\nInvalid choice. Please try again.\n" << endl;
        }

    } while (choice != 4);
}
