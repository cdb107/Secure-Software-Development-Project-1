#ifndef VALIDATION_H
#define VALIDATION_H
#include <string>
#include <iostream>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: Validation.h

This file declares the Validation class and the SQl Injection, password policy, 
and integer overflow methods.

@author Calvin Brewer
@version 1.0
*/

class Validation{
    private:
        char unallowed[4] = {'/','-',';','\"'};
        bool hasUpper(string password);
        bool hasLower(string password);
        bool hasInt(string password);
    public:
        bool validate(string password);
        bool SQLInjectionCheck(string input);
        bool passwordPolicyCheck(string input);
        bool integerOverflowCheck(string input);
};

#endif