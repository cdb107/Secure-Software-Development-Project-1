#ifndef DATABASE_H
#define DATABASE_H
#include <string>
#include <fstream>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/

class Database{
    private:
        string username;
        string password;
    public:
        Database();
        Database(string username, string password) : username(username), password(password){};
        string getUsername();
        string getPassword();
};

#endif