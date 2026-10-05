#include <iostream>
#include "../Database.h"
#include "../usercreation.h"
#include "../cryptographer.h"
using namespace std;

int main() {
    cryptographer crypto;

    Database users[3] = {
        Database(
            crypto.encryptCredential("scientist"),
            crypto.encryptCredential("Scientist1")
        ),
        Database(
            crypto.encryptCredential("engineer"),
            crypto.encryptCredential("Engineer2")
        ),
        Database(
            crypto.encryptCredential("security"),
            crypto.encryptCredential("Security3")
        )
    };

    cout << "Encrypted input username matches stored username: " << (crypto.encryptCredential("scientist") == users[0].getUsername()) << endl;
    cout << "Encrypted input password matches stored password: " << (crypto.encryptCredential("Scientist1") == users[0].getPassword()) << endl;
    cout << "Decrypted username matches cleartext: " << (crypto.decryptCredential(users[0].getUsername()) == "scientist") << endl;
    cout << "Decrypted password matches cleartext: " << (crypto.decryptCredential(users[0].getPassword()) == "Scientist1") << endl;
    cout << "\nLogin tests:" << endl;
    cout << "Valid login: " << loginUser(users, 3, "scientist", "Scientist1", "1234567890") << endl;
    cout << "Unknown username: " << loginUser(users, 3, "visitor", "Scientist1", "1234567890") << endl;
    cout << "Incorrect password: " << loginUser(users, 3, "scientist", "WrongPass1", "1234567890") << endl;
    cout << "Invalid username characters: " << loginUser(users, 3, "scientist;", "Scientist1", "1234567890") << endl;
    cout << "Invalid password characters: " << loginUser(users, 3, "scientist", "Scientist-1", "1234567890") << endl;
    cout << "Overflowing MFA token: " << loginUser(users, 3, "scientist", "Scientist1", "2147483648") << endl;

    return 0;
}