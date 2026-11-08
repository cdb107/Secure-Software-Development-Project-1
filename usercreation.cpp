#include "usercreation.h"
#include "Validation.h"
#include "cryptographer.h"
#include "PasswordHandler.h"
#include <iostream>
using namespace std;

/**
CEN 4078 Programming Exercise 3
File Name: usercreation.cpp

This file handles the login prompt, input validation, hidden password, and credentail comparison.

@author Calvin Brewer
@version 3.0
*/

void getLoginInput(string& username, string& password) {
    PasswordHandler passwordHandler;

    cout << "Username: ";
    getline(cin, username);

    cout << "Password: ";
    password = passwordHandler.getHiddenPassword();
}

bool loginUser(
    Database users[],
    int size,
    string username,
    string password,
    string mfaInput
) {
    Validation validation("");
    PasswordHandler passwordHandler;

    if (!validation.SQLInjectionCheck(username)) {
        return false;
    }

    if (!passwordHandler.validatePassword(password)) {
        return false;
    }

    if (!validation.integerOverflowCheck(mfaInput)) {
        return false;
    }

    cryptographer crypto;

    string encryptedUsername = crypto.encryptCredential(username);

    if (encryptedUsername.empty()) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        if (encryptedUsername == users[i].getUsername() &&
            passwordHandler.passwordMatches(password, users[i].getPassword())) {
            return true;
        }
    }

    return false;
}