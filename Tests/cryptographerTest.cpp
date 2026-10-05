#include <iostream>
#include "../cryptographer.h"
using namespace std;

int main() {
    cryptographer crypto;

    string encrypted = crypto.encryptVigenere("ARGOSROCK", "Scientist");

    cout << "Cleartext: Scientist" << endl;
    cout << "Alphakey: ARGOSROCK" << endl;
    cout << "Ciphertext: " << encrypted << endl;
    cout << "Expected ciphertext: Stosfkwud" << endl;
    cout << "Encryption passed: " << (encrypted == "Stosfkwud") << endl;
    cout << "Invalid input rejected: " << crypto.encryptVigenere("ARGOSROCK", "Scientist1").empty() << endl;

    cout << "\nAlphabetic decryption tests:" << endl;

    string decrypted = crypto.decryptVigenere("ARGOSROCK", encrypted);

    cout << "Ciphertext: " << encrypted << endl;
    cout << "Decrypted text: " << decrypted << endl;
    cout << "Expected text: Scientist" << endl;
    cout << "Decryption passed: " << (decrypted == "Scientist") << endl;
    cout << "Invalid ciphertext rejected: " << crypto.decryptVigenere("ARGOSROCK", "Stosfkwud1").empty() << endl;

    cout << "\nNumerical encryption tests:" << endl;

    string encryptedNumber = crypto.encryptNumber("1963", "1234567890");

    cout << "Cleartext number: 1234567890" << endl;
    cout << "Numberkey: 1963" << endl;
    cout << "Encrypted number: " << encryptedNumber << endl;
    cout << "Expected number: 0371471581" << endl;
    cout << "Number encryption passed: " << (encryptedNumber == "0371471581") << endl;
    cout << "Non-numerical input rejected: " << crypto.encryptNumber("1963", "12345A7890").empty() << endl;

    cout << "\nNumerical decryption tests:" << endl;

    string decryptedNumber = crypto.decryptNumber("1963", encryptedNumber);

    cout << "Encrypted number: " << encryptedNumber << endl;
    cout << "Decrypted number: " << decryptedNumber << endl;
    cout << "Expected number: 1234567890" << endl;
    cout << "Number decryption passed: " << (decryptedNumber == "1234567890") << endl;
    cout << "Invalid ciphertext rejected: " << crypto.decryptNumber("1963", "03714A1581").empty() << endl;

    cout << "\nComplete credential tests:" << endl;

    string encryptedCredential = crypto.encryptCredential("Scientist1");
    string decryptedCredential = crypto.decryptCredential(encryptedCredential);

    cout << "Original credential: Scientist1" << endl;
    cout << "Encrypted credential: " << encryptedCredential << endl;
    cout << "Decrypted credential: " << decryptedCredential << endl;
    cout << "Credential encryption passed: " << (encryptedCredential == "Stosfkwud0") << endl;
    cout << "Credential decryption passed: " << (decryptedCredential == "Scientist1") << endl;

    return 0;
}