#include <iostream>
#include "../Validation.h"
using namespace std;

int main() {
    Validation validation("");

    cout << "Normal username: " << validation.SQLInjectionCheck("scientist") << endl;
    cout << "Forward slash: " << validation.SQLInjectionCheck("sci/entist") << endl;
    cout << "Hyphen: " << validation.SQLInjectionCheck("sci-entist") << endl;
    cout << "Semicolon: " << validation.SQLInjectionCheck("sci;entist") << endl;
    cout << "Quotation mark: " << validation.SQLInjectionCheck("sci\"entist") << endl;

    cout << "\nPassword policy tests:\n";

    cout << "Valid password: " << validation.passwordPolicyCheck("Password1") << endl;
    cout << "Too short: " << validation.passwordPolicyCheck("Pass1") << endl;
    cout << "Too long: " << validation.passwordPolicyCheck("LongPassword123") << endl;
    cout << "No uppercase: " << validation.passwordPolicyCheck("password1") << endl;
    cout << "No lowercase: " << validation.passwordPolicyCheck("PASSWORD1") << endl;
    cout << "No number: " << validation.passwordPolicyCheck("Password") << endl;

    cout << "\nCombined password validation tests:\n";

    cout << "Valid password: " << validation.validate("Password1") << endl;
    cout << "Prohibited character: " << validation.validate("Password-1") << endl;
    cout << "Invalid password policy: " << validation.validate("password1") << endl;

    cout << "\nMFA integer validation tests:\n";
    
    cout << "Valid 10-digit number: " << validation.integerOverflowCheck("1234567890") << endl;
    cout << "Maximum signed integer: " << validation.integerOverflowCheck("2147483647") << endl;
    cout << "Integer overflow: " << validation.integerOverflowCheck("2147483648") << endl;
    cout << "Only 9 digits: " << validation.integerOverflowCheck("123456789") << endl;
    cout << "More than 10 digits: " << validation.integerOverflowCheck("12345678901") << endl;
    cout << "Contains letters: " << validation.integerOverflowCheck("12345abcde") << endl;
    cout << "Leading zero: " << validation.integerOverflowCheck("0123456789") << endl;

    return 0;
}