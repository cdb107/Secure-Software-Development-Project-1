#include "Validation.h"
using namespace std;

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
    bool hasUpper = false;
    for (unsigned int i = 0; i < password.length(); ++i){
        if (isupper(password.at(i))){
            hasUpper = true;
        }
    }

    return hasUpper;
}

bool Validation::hasLower(string password){
    bool hasLower = false;
    for (unsigned int i = 0; i < password.length(); ++i){
        if (islower(password.at(i))){
            hasLower = true;
        }
    }

    return hasLower;
}

bool Validation::hasInt(string password){
    bool hasNum = false;
    for (unsigned int i = 0; i < password.length(); ++i){
        if (isdigit(password.at(i))){
            hasNum = true;
        }
    }
    return hasNum;
}