#ifndef PASSWORDHANDLER_H
#define PASSWORDHANDLER_H
#include <string>
#include <stdexcept>

using namespace std;

/**
CEN 4078 Programming Exercise 3
File Name: PasswordHandler.h

Declares the PasswordHandler class used to control
password entry, creation, validation, default creation, and encryption.

@author Calvin Brewer
@version 3.0
*/

class PasswordPolicyException : public runtime_error {
    public:
        PasswordPolicyException() : runtime_error("Password policy failure") {}
};

class PasswordValidationException : public runtime_error {
    public:
        PasswordValidationException() : runtime_error("Password validation failure") {}
};

class DefaultPasswordException : public runtime_error {
    public:
        DefaultPasswordException() : runtime_error("Default password failure") {}
};

class PasswordHandler {
    public:
        string getHiddenPassword();
        string createUserPassword();
        bool validatePassword(string password);
        string encryptPassword(string password);
        bool passwordMatches(string password, string storedPassword);
};

#endif