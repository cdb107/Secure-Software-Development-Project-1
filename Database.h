#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <fstream>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: Database.h

This file declares the Database class and the file-output 
function used to store usernames and passwords.

@author Calvin Brewer
@version 1.0
*/

class Database{
    private:
        string username;
        string password;
    public:
        Database(string username, string password) : username(username), password(password){};
        string getUsername();
        string getPassword();
};

bool saveUsersToFile(Database users[], int size);

#endif