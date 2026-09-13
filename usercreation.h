#ifndef USERCREATION_H
#define USERCREATION_H

#include "Database.h"
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/
void createUser(Database& database);
bool loginUser(Database users[], int size, string username, string password, string mfaInput);
string getHiddenPassword();
void getLoginInput(string& username, string& password);

#endif
