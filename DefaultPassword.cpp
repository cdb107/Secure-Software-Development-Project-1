#include "DefaultPassword.h"
#include <algorithm>
#include <random>
#include <iostream>

/**
CEN 4078 Programming Exercise 2
File Name: DefaultPassword.cpp

File that implements the DefaultPassword class for when a user fails
to create a valid password within two attempts.

@author Calvin Brewer
@version 1.0
*/

string DefaultPassword::createDefaultPassword() {
    const string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const string lowercase = "abcdefghijklmnopqrstuvwxyz";
    const string numbers = "0123456789";
    const string allCharacters = uppercase + lowercase + numbers;

    random_device randomDevice;
    mt19937 generator(randomDevice());

    uniform_int_distribution<int> upperChoice(0, uppercase.length() - 1);
    uniform_int_distribution<int> lowerChoice(0, lowercase.length() - 1);
    uniform_int_distribution<int> numberChoice(0, numbers.length() - 1);
    uniform_int_distribution<int> characterChoice(0, allCharacters.length() - 1);

    string password = "";
    password += uppercase.at(upperChoice(generator));
    password += lowercase.at(lowerChoice(generator));
    password += numbers.at(numberChoice(generator));

    while (password.length() < 10) {
        password += allCharacters.at(characterChoice(generator));
    }

    shuffle(password.begin(), password.end(), generator);
    cout << "A default password has been set. " << "You will receive a secure email with the password." << endl;

    return password;
}