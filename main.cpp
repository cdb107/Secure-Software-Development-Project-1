#include <iostream> 
#include "Database.h"
#include "usercreation.h"
#include "Validation.h"
#include <exception>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: main.cpp

This file creates the user database, write the credentials file,, collets 
login information, authenticates the user, and displays a safe success or fail message.

@author Calvin Brewer
@version 1.0
*/

int main(){
    try { 
        Database users[3] = {
            Database("scientist", "Scientist1"),
            Database("engineer", "Engineer2"),
            Database("security", "Security3")
        };

        if (!saveUsersToFile(users, 3)) {
            cout << "Application failed." << endl;
            return 1;
        }

        string enteredUsername;
        string enteredPassword;
        string enteredMfaToken;
        getLoginInput(enteredUsername, enteredPassword);
        
        cout << "MFA Token: ";
        getline(cin, enteredMfaToken);

        bool loginSuccessful = loginUser(users, 3, enteredUsername, enteredPassword, enteredMfaToken);

        if (loginSuccessful) {
            cout << "Welcome, " << enteredUsername << "!" << endl;
        }
        else {
                cout << "Login failed." << endl;    
        }

    }
    catch (const exception&) {
        cout << "Application error." << endl;
        return 1;
    }

    return 0;
}