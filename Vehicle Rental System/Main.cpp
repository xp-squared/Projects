#include <iostream>
#include "Admin.h"
#include "User.h"
#include "Vehicle.h"

using namespace std;

// NOTES  *********************
// fix beginning input, if you enter a string at entry screen it becomes infinite output
// in user and admin, we have the password and username section, possibly add to it where you can change the details of each

void entryScreen() {
    cout << "Welcome to Zane's Vehicle Rental System!" << endl;
    cout << "1. Admin Login" << endl;
    cout << "2. User Login" << endl;
    cout << "3. Create New User" << endl;
    cout << "4. Exit" << endl;
    cout << "Please enter your choice (1-4): ";
}

int getValidatedChoice() {
    int choice;
    cin >> choice;
    while (choice < 1 || choice > 4) {
        cout << "Invalid choice. Please try again.";
        cout << " Please enter your choice (1-4): ";
        cin >> choice;
        if (choice < 1 || choice > 4) {
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return choice;
}

int main() {
    int exit = 1;
    while (exit != 0) {
        entryScreen();
        int choice = getValidatedChoice();

        if (choice == 1) {

            Admin adminObj;
            string username, password;
            cout << "Enter Admin UserName: ";
            cin >> username;
            cout << "Enter Admin Password: ";
            cin >> password;

            if (adminObj.login(username, password)) {
                cout << "\nAuthenticated. Admin mode activated.\n" << endl;
                adminObj.adminMenu();
            }
            else {
                cout << "\nAuthentication failed.\n" << endl;
            }
        }

        // login as user
        else if (choice == 2) {
            User userObj;
            string username, password;
            cout << "Enter UserName: ";
            cin >> username;
            cout << "Enter Password: ";
            cin >> password;

            if (userObj.login(username, password)) {
                cout << "\nUser login successful!\n" << endl;
                userObj.userMenu();
            }
            else {
                cout << "\nLogin failed.\n" << endl;
            }
        }


        // create new user
        /*if (choice == 3) {
            Admin adminObj;
            string username, password;
        }*/

        if (choice == 4) {
            exit = 0;
        }
    }
}
