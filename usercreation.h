#ifndef USERCREATION_H
#define USERCREATION_H

#include "Database.h"
/**
CEN 4078 Programming Exercise 1
File Name: usercreation.h

This file delcares the user input, user authentication, and hidden password methods
used to log in securely.

@author Calvin Brewer
@version 1.0
*/
bool loginUser(Database users[], int size, string username, string password, string mfaInput);
string getHiddenPassword();
void getLoginInput(string& username, string& password);

#endif
