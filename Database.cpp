#include "Database.h"
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: Database.cpp

This file writes the credential array to a text file and 
implements access to those stored usernames and passwords.

@author Calvin Brewer
@version 1.0
*/

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