#include "Validation.h"
using namespace std;
/**
CEN 4078 Programming Exercise 1
File Name: 

REPLACE THIS WITH EXPLANATION OF FILE
@author 
@version 1.0
*/

bool Validation::validate(string password){
    if (password.length() < 8 || password.length() > 12){
        return false;
    }

    for (unsigned int i = 0; i < 4; ++i){
        for (unsigned int j = 0; i < password.length(); ++j){
            if (unallowed[i] == password.at(j)){
                return false;
            }
        }
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