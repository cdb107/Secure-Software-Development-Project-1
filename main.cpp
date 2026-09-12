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

    return 0;
}