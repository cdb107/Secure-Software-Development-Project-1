#include <iostream> 
#include "Database.h"
#include "usercreation.h"
#include "Validation.h"
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/

int main(){
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
    getLoginInput(enteredUsername, enteredPassword);
    string enteredMfaToken;

    cout << "MFA Token: ";
    getline(cin, enteredMfaToken);
    bool loginSuccessful = loginUser(users, 3, enteredUsername, enteredPassword, enteredMfaToken);

    return 0;
}