#include <iostream>
#include "../Database.h"
#include "../usercreation.h"
using namespace std;

/**
CEN 4078 Programming Exercise 1
File Name: LoginTest.cpp

This file tests authentication caused by invalid credentials or invalid input
showing whether they passed or failed.

@author Calvin Brewer
@version 1.0
*/

int main() {
    Database users[3] = {
        Database("scientist", "Scientist1"),
        Database("engineer", "Engineer2"),
        Database("security", "Security3")
    };

    cout << "Valid login: " << loginUser(users, 3, "scientist", "Scientist1", "1234567890") << endl;
    cout << "Unknown username: " << loginUser(users, 3, "visitor", "Scientist1", "1234567890") << endl;
    cout << "Incorrect password: " << loginUser(users, 3, "scientist", "WrongPass1", "1234567890") << endl;
    cout << "Invalid username characters: " << loginUser(users, 3, "scientist;", "Scientist1", "1234567890") << endl;
    cout << "Invalid password characters: " << loginUser(users, 3, "scientist", "Scientist-1", "1234567890") << endl;
    cout << "Overflowing MFA token: " << loginUser(users, 3, "scientist", "Scientist1", "1111111111") << endl;

    return 0;
}