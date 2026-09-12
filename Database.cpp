#include "Database.h"
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/


// need an array for the passwords and usernames
//char username[4][50];
//char password[4][20];

string Database::getUsername(){
    return username;
}

string Database::getPassword(){
    return password;
}

bool saveUsersToFile(Database users[], int size) {
    ofstream file("credentials.txt");

    if (!file.is_open()) {
        return false;
    }

    for (int i = 0; i < size; ++i) {
        file << users[i].getUsername() << " " << users[i].getPassword() << endl;
    }

    file.close();
    return true;
}