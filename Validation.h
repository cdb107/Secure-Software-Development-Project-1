#ifndef VALIDATION_H
#define VALIDATION_H
#include <string>
#include <iostream>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/

class Validation{
    private:
        char unallowed[4] = {'/','-',';','\"'};
        bool hasUpper(string password);
        bool hasLower(string password);
        bool hasInt(string password);
        string password;
    public:
        Validation(string password);
        bool validate(string password);
};

#endif