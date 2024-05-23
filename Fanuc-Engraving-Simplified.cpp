/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

using namespace std;

vector<int> convertTextToNumbers(const string& text) {
    vector<int> numbers;
    for (char c : text) {
        if (c >= 'A' && c <= 'Z') {
            numbers.push_back(c - 'A' + 1);
        } else if (c == ' ') {
            numbers.push_back(40);
        } else {
            // Handle any non A-Z characters, if needed
            // For example, convert them to 0 or any specific value
            numbers.push_back(0);
        }
    }
    return numbers;
}

string getCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;
    int year = 1900 + ltm->tm_year;
    
    // Creating the formatted date string
    stringstream date_ss;
    date_ss << month << "/" << day << "/" << year;
    
    return date_ss.str();
}

string getCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    // Adjust to Eastern Time (ET)
    int hour_offset = -4; // Standard Time (UTC-5)
    // int hour_offset = -4; // Daylight Saving Time (UTC-4)
    ltm->tm_hour += hour_offset;
    
    mktime(ltm); // Normalize the time structure
    
    int hour = ltm->tm_hour;
    int minute = ltm->tm_min;
    int second = ltm->tm_sec;
    string am_pm = "AM";
    
    // Convert from 24-hour to 12-hour format
    if (hour >= 12) {
        am_pm = "PM";
        if (hour > 12) hour -= 12;
    } else if (hour == 0) {
        hour = 12;
    }
    
    // Creating the formatted time string
    stringstream time_ss;
    time_ss << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2) << setfill('0') << second << " " << am_pm;
    
    return time_ss.str();
}

int main()
{
    string textToEngrave;
    string programNumber;
    string toolNumber;
    string workOffset;
    string X;
    string Y;
    string spindleRPM;
    string plunge;
    string characterHeight;
    string engravingFr;
    string ClrPl;
    string engravingDepth;
    
    cout << "Enter Text to Engrave: ";
    getline(cin, textToEngrave);
    for (char &c : textToEngrave) {
        c = toupper(c);
    }
    cout << "Enter Program Number: ";
    cin >> programNumber;
    string date = getCurrentDate();
    string time = getCurrentTime();
    cout << "Enter tool number (EX: T01): ";
    cin >> toolNumber;
    cout << "Enter work offset: ";
    cin >> workOffset;
    cout << "Enter Start Position - X (EX: 1.0):  ";
    cin >> X;
    cout << "Enter Start Position - Y (EX: 1.0): ";
    cin >> Y;
    cout << "Enter Spindle RPM: ";
    cin >> spindleRPM;
    cout << "Enter Plunge Feedrate: ";
    cin >> plunge;
    cout << "Enter Engraving Feedrate: ";
    cin >> engravingFr;
    cout << "Enter Clearance Plane (EX: 0.05) ";
    cin >> ClrPl;
    cout << "Enter character height (EX: 0.125): ";
    cin >> characterHeight;
    cout << "Enter engraving depth (EX: -0.005): ";
    cin >> engravingDepth;
    
    vector<int> numbers = convertTextToNumbers(textToEngrave);
    
    ofstream file;
    file.open("output.txt");

    if (file.is_open()) {
        file << "%\n";
        file << "O" << programNumber << " (FANUC ENGRAVING PROGRAM)\n";
        file << "(FILE = FANUC ENGRAVING PROGRAM.NC)\n";
        file << "(DATE = " << date << ")\n";
        file << "(TIME = " << time << ")\n";
        file << "G00 G17 G20 G40 G49 G80 G90 G94\nG00 G91 G28 Z0.0 M09\n";
        file << toolNumber << " M06 (#00 CENTER DRILL)\n";
        file << "G00 G90 G" << workOffset << " X" << X << " Y" << Y << " S" << spindleRPM << " M03\nG00 G43 H" << toolNumber << " Z2.0 M08";
        file << "\n(ENGRAVE: TEXT TO ENGRAVE)";
        for (int i = 0; i < numbers.size(); i++) {
            file << "\nG65 P8802 H" << characterHeight << " E" << numbers[i] << " " << plunge << " D" << engravingFr << " R" << ClrPl << " Z" << engravingDepth;
        }
        file << "\nG00 G90 Z2.0 M05\nG00 G91 G28 Z0.0 M09\nG00 G91 G28 Y0.0\nM30\n%";
        file.close();
    } else {
        cout << "Unable to open file." << endl;
    }
    
    

    return 0;
}
