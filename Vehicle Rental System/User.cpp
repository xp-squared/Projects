#include "User.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

bool User::login(const string& username, const string& password) {
    ifstream inFile("Users.txt"); // open the file to read it
    if (!inFile) {
        cerr << "Unable to open Users.txt";
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


void User::userMenu() {
    int choice;
    do {
        cout << "User Menu" << endl;
        // need user functions
        cout << "4. Log Out" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "\nLogging out...\n" << endl;
            return; // Exit the loop and the function
        }
        else {
            cout << "\nInvalid choice. Please try again.\n" << endl;
        }

    } while (choice != 4);
}
