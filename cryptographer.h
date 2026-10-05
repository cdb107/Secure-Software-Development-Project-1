#ifndef CRYPTOGRAPHER_H
#define CRYPTOGRAPHER_H

#include <string>
using namespace std;

/**
CEN 4078 Programming Exercise 2
File Name: cryptographer.h

Declares the cryptographer class used to encrypt and decrypt
text with the Vigenere algorithm.

@author Calvin Brewer
@version 1.0
*/

class cryptographer {
    public:
        string encryptVigenere(string alphakey, string cleartext);
        string decryptVigenere(string alphakey, string ciphertext);
        string encryptNumber(string numberkey, string cleartext);
        string decryptNumber(string numberkey, string ciphertext);
        string encryptCredential(string input);
        string decryptCredential(string input);
};

#endif