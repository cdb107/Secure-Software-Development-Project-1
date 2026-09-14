#include "usercreation.h"
#include <iostream>
#include <conio.h>
#include "Validation.h"
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: usercreation.cpp

This file handles the login prompt, input validation, hidden password, and credentail comparison.

@author Calvin Brewer
@version 1.0
*/
//Below Method made with the assistance of AI 
string getHiddenPassword() {
    string password;
    char character;

    while ((character = _getch()) != '\r') {
        if (character == '\b' && !password.empty()) {
            password.pop_back();
            cout << "\b \b";
        }
        else if (character != '\b') {
            password += character;
            cout << '*';
        }
    }

    cout << endl;
    return password;
}

void getLoginInput(string& username, string& password) {
    cout << "Username: ";
    getline(cin, username);

    cout << "Password: ";
    password = getHiddenPassword();
}

bool loginUser(Database users[], int size, string username, string password, string mfaInput) {
    Validation validation;

    if (!validation.SQLInjectionCheck(username)) {return false;}

    if (!validation.validate(password)) {return false;}

    if (!validation.integerOverflowCheck(mfaInput)) {return false;}

    for (int i = 0; i < size; ++i) {
        if (username == users[i].getUsername() &&
            password == users[i].getPassword()) {
            return true;
        }
    }

    return false;
}