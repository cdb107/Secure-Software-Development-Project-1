#include "Validation.h"
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

bool Validation::validate(string password){
    if (password.length() < 8 || password.length() > 12){
        return false;
    }

    if (!SQLInjectionCheck(password)) {
    return false;
}

    if (!hasUpper(password)){return false;}
    if (!hasLower(password)){return false;}
    if (!hasInt(password)){return false;}

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
    return false;;
}

bool Validation::hasInt(string password){
    for (unsigned int i = 0; i < password.length(); ++i){
        if (isdigit(password.at(i))){
            return true;
        }
    }
    cout << "Password must include at least one digit.\n";
    return false;
}