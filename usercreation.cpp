#include "usercreation.h"
#include <conio.h>
#include <iostream>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
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