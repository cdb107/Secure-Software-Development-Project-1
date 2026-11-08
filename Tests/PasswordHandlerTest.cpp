#include <iostream>
#include "../PasswordHandler.h"
using namespace std;

/**
CEN 4078 Programming Exercise 3
File Name: PasswordHandlerTest.cpp

Tests password handling and password policy, 
validation, and default-password failures.

@author Calvin Brewer
@version 3.0
*/

int main() {
    PasswordHandler passwordHandler;

    cout << "Valid password meets policy: " << passwordHandler.meetsPasswordPolicy("Password1") << endl;
    cout << "Password policy failure handled: " << !passwordHandler.meetsPasswordPolicy("short") << endl;
    cout << "Valid password passes validation: " << passwordHandler.validatePassword("Password1") << endl;
    cout << "Password validation failure handled: " << !passwordHandler.validatePassword("password1") << endl;
    cout << "Valid default password accepted: " << passwordHandler.defaultPasswordIsValid("Password1") << endl;
    cout << "Default password failure handled: " << !passwordHandler.defaultPasswordIsValid("invalid") << endl;

    string encryptedPassword = passwordHandler.encryptPassword("Password1");

    cout << "Correct password matches: " << passwordHandler.passwordMatches("Password1", encryptedPassword) << endl;
    cout << "Incorrect password rejected: " << !passwordHandler.passwordMatches("WrongPass1", encryptedPassword) << endl;

    return 0;
}