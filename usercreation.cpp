#include "usercreation.h"
#include <iostream>
#include <conio.h>
#include "Validation.h"
#include "cryptographer.h"
#include "DefaultPassword.h"
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

string createUserPassword() {
    Validation validation("");

    for (int attempt = 1; attempt <= 2; ++attempt) {
        cout << "Create password (attempt " << attempt << " of 2): ";

        string attemptedPassword = getHiddenPassword();

        if (validation.passwordPolicyCheck(attemptedPassword)) {
            cout << "Password accepted." << endl;
            return attemptedPassword;
        }

        cout << "Password was not accepted." << endl;
    }

    DefaultPassword defaultPasswordCreator;
    string defaultPassword = defaultPasswordCreator.createDefaultPassword();

    return defaultPassword;
}

void getLoginInput(string& username, string& password) {
    cout << "Username: ";
    getline(cin, username);

    cout << "Password: ";
    password = getHiddenPassword();
}

bool loginUser(
    Database users[],
    int size,
    string username,
    string password,
    string mfaInput
) {
    Validation validation("");

    if (!validation.SQLInjectionCheck(username)) {
        return false;
    }

    if (!validation.validate(password)) {
        return false;
    }

    if (!validation.integerOverflowCheck(mfaInput)) {
        return false;
    }

    cryptographer crypto;
    string encryptedUsername = crypto.encryptCredential(username);
    string encryptedPassword = crypto.encryptCredential(password);

    if (encryptedUsername.empty() || encryptedPassword.empty()) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        if (encryptedUsername == users[i].getUsername() &&
            encryptedPassword == users[i].getPassword()) {
            return true;
        }
    }

    return false;
}