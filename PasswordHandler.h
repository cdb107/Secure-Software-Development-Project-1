#ifndef PASSWORDHANDLER_H
#define PASSWORDHANDLER_H
#include <string>

using namespace std;

/**
CEN 4078 Programming Exercise 3
File Name: PasswordHandler.h

Declares the PasswordHandler class used to control
password entry, creation, validation, default creation, and encryption.

@author Calvin Brewer
@version 3.0
*/

class PasswordHandler {
    public:
        string getHiddenPassword();
        string createUserPassword();
        bool validatePassword(string password);
        string encryptPassword(string password);
};

#endif