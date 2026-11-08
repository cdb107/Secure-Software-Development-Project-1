#include "PasswordHandler.h"
#include "Validation.h"
#include "DefaultPassword.h"
#include "cryptographer.h"
#include <iostream>
#include <conio.h>

using namespace std;

/**
CEN 4078 Programming Exercise 3
File Name: PasswordHandler.cpp

File to handle the PasswordHandler class used to coordinate
password-related operations in the login module.

@author Calvin Brewer
@version 3.0
*/

string PasswordHandler::getHiddenPassword() {
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

string PasswordHandler::createUserPassword() {
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
    return defaultPasswordCreator.createDefaultPassword();
}

bool PasswordHandler::validatePassword(string password) {
    Validation validation("");
    return validation.validate(password);
}

string PasswordHandler::encryptPassword(string password) {
    cryptographer crypto;
    return crypto.encryptCredential(password);
}

bool PasswordHandler::passwordMatches(string password, string storedPassword) {
    return encryptPassword(password) == storedPassword;
}