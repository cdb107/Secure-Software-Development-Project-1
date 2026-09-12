#include <iostream>
#include "Validation.h"
using namespace std;

int main() {
    Validation validation("");

    cout << "Normal username: " << validation.SQLInjectionCheck("scientist") << endl;
    cout << "Forward slash: " << validation.SQLInjectionCheck("sci/entist") << endl;
    cout << "Hyphen: " << validation.SQLInjectionCheck("sci-entist") << endl;
    cout << "Semicolon: " << validation.SQLInjectionCheck("sci;entist") << endl;
    cout << "Quotation mark: " << validation.SQLInjectionCheck("sci\"entist") << endl;

    return 0;
}