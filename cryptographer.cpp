#include "cryptographer.h"
#include <cctype>

/**
CEN 4078 Programming Exercise 2
File Name: cryptographer.cpp

Implements the cryptographer class used to encrypt and decrypt
text with the Vigenere algorithm.

@author Calvin Brewer
@version 1.0
*/

string cryptographer::encryptVigenere(string alphakey, string cleartext) {
    if (alphakey.empty() || cleartext.empty()) {
        return "";
    }

    string ciphertext = "";

    for (unsigned int i = 0; i < cleartext.length(); ++i) {
        if (!isalpha(cleartext.at(i)) || !isalpha(alphakey.at(i % alphakey.length()))) {
            return "";
        }

        char letter = cleartext.at(i);
        char base = isupper(letter) ? 'A' : 'a';
        
        int clearValue = letter - base;
        int keyValue = toupper(alphakey.at(i % alphakey.length())) - 'A';

        char encryptedLetter = static_cast<char>(base + (clearValue + keyValue) % 26);
        ciphertext += encryptedLetter;
    }

    return ciphertext;
}

string cryptographer::decryptVigenere(string alphakey, string ciphertext) {
    if (alphakey.empty() || ciphertext.empty()) {
        return "";
    }

    string cleartext = "";

    for (unsigned int i = 0; i < ciphertext.length(); ++i) {
        if (!isalpha(ciphertext.at(i)) || !isalpha(alphakey.at(i % alphakey.length()))) {
            return "";
        }

        char letter = ciphertext.at(i);
        char base = isupper(letter) ? 'A' : 'a';

        int encryptedValue = letter - base;
        int keyValue = toupper(alphakey.at(i % alphakey.length())) - 'A';

        char decryptedLetter = static_cast<char>(base + (encryptedValue - keyValue + 26) % 26);
        cleartext += decryptedLetter;
    }

    return cleartext;
}

//below method made with the assistance of ai
string cryptographer::encryptNumber(string numberkey, string cleartext) {
    if (numberkey.empty() || cleartext.empty()) {
        return "";
    }

    string ciphertext = "";

    for (unsigned int i = 0; i < cleartext.length(); ++i) {
        if (!isdigit(cleartext.at(i)) || !isdigit(numberkey.at(i % numberkey.length()))) {
            return "";
        }

        int clearValue = cleartext.at(i) - '0';
        int keyValue = numberkey.at(i % numberkey.length()) - '0';
        int encryptedValue = (clearValue - keyValue + 10) % 10;

        ciphertext += static_cast<char>('0' + encryptedValue);
    }

    return ciphertext;
}

string cryptographer::decryptNumber(string numberkey, string ciphertext) {
    if (numberkey.empty() || ciphertext.empty()) {
        return "";
    }

    string cleartext = "";

    for (unsigned int i = 0; i < ciphertext.length(); ++i) {
        if (!isdigit(ciphertext.at(i)) || !isdigit(numberkey.at(i % numberkey.length()))) {
            return "";
        }

        int encryptedValue = ciphertext.at(i) - '0';
        int keyValue = numberkey.at(i % numberkey.length()) - '0';
        int clearValue = (encryptedValue + keyValue) % 10;

        cleartext += static_cast<char>('0' + clearValue);
    }

    return cleartext;
}

string cryptographer::encryptCredential(string input) {
    const string alphakey = "ARGOSROCK";
    const string numberkey = "1963";

    string encrypted = "";
    unsigned int letterPosition = 0;
    unsigned int numberPosition = 0;

    for (unsigned int i = 0; i < input.length(); ++i) {
        if (isalpha(input.at(i))) {
            string letter(1, input.at(i));
            string key(1, alphakey.at(letterPosition % alphakey.length()));

            encrypted += encryptVigenere(key, letter);
            ++letterPosition;
        }
        else if (isdigit(input.at(i))) {
            string number(1, input.at(i));
            string key(1, numberkey.at(numberPosition % numberkey.length()));
            encrypted += encryptNumber(key, number);
            ++numberPosition;
        }
        else {
            return "";
        }
    }

    return encrypted;
}

string cryptographer::decryptCredential(string input) {
    const string alphakey = "ARGOSROCK";
    const string numberkey = "1963";

    string decrypted = "";
    unsigned int letterPosition = 0;
    unsigned int numberPosition = 0;

    for (unsigned int i = 0; i < input.length(); ++i) {
        if (isalpha(input.at(i))) {
            string letter(1, input.at(i));
            string key(1, alphakey.at(letterPosition % alphakey.length()));
            decrypted += decryptVigenere(key, letter);
            ++letterPosition;
        }
        else if (isdigit(input.at(i))) {
            string number(1, input.at(i));
            string key(1, numberkey.at(numberPosition % numberkey.length()));
            decrypted += decryptNumber(key, number);
            ++numberPosition;
        }
        else {
            return "";
        }
    }

    return decrypted;
}