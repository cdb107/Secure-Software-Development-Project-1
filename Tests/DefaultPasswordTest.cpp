#include <iostream>
#include "../DefaultPassword.h"
#include "../Validation.h"
using namespace std;

int main() {
    DefaultPassword defaultPasswordCreator;
    Validation validation("");

    bool allPasswordsPassed = true;

    for (int i = 0; i < 5; ++i) {
        string password = defaultPasswordCreator.createDefaultPassword();

        if (!validation.passwordPolicyCheck(password)) {
            allPasswordsPassed = false;
        }
    }

    string testPassword = defaultPasswordCreator.createDefaultPassword();

    cout << "Generated password length: " << testPassword.length() << endl;
    cout << "Generated password meets policy: " << validation.passwordPolicyCheck(testPassword) << endl;
    cout << "Five generated passwords passed: " << allPasswordsPassed << endl;

    return 0;
}