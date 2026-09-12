#include "Validation.h"
#include <climits>
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/

Validation::Validation(string password) {
    this->password = password;
}

bool Validation::SQLInjectionCheck(string input){
    for(unsigned int i = 0; i < input.length(); ++i){
        for (unsigned int j = 0; j < 4; ++j){
            if (input.at(i) == unallowed[j]) {
                return false;
            }
        }
    }
    return true;
}

bool Validation::passwordPolicyCheck(string input) {
    if (input.length() < 8 || input.length() > 12) {
        return false;
    }

    if (!hasUpper(input)) {return false;}
    if (!hasLower(input)) {return false;}
    if (!hasInt(input)) {return false;}

    return true;
}

bool Validation::integerOverflowCheck(string input) {
    if (input.length() != 10) {
        return false;
    }

    for (unsigned int i = 0; i < input.length(); ++i) {
        if (!isdigit(input.at(i))) {return false;}
    }
    if (input.at(0) == '0') {return false;}

    long long number = stoll(input);
    if (number > INT_MAX) {return false;}

    signed int mfaToken = static_cast<signed int>(number);
    if (mfaToken < 1000000000) {return false;}

    return true;    
}

bool Validation::validate(string password){
    if (!SQLInjectionCheck(password)) {
        return false;
    }

    if (!passwordPolicyCheck(password)) {
        return false;
    }
    
    return true;
}

bool Validation::hasUpper(string password){
    for (unsigned int i = 0; i < password.length(); ++i){
        if (isupper(password.at(i))){
            return true;
        }
    }
    cout << "Password must include at least one uppercase letter.\n";
    return false;
}

bool Validation::hasLower(string password){
    for (unsigned int i = 0; i < password.length(); ++i){
        if (islower(password.at(i))){
            return true;
        }
    }
    cout << "Password must include at least one lowercase letter.\n";
    return false;
}

bool Validation::hasInt(string password) {
    for (unsigned int i = 0; i < password.length(); ++i) {
        if (isdigit(password.at(i))) {
            return true;
        }
    }

    return false;
}