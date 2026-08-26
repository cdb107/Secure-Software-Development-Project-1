#include <string>
using namespace std;

class Validation{
    private:
        char unallowed[4] = {'/','!','-','&'};
        bool hasUpper(string password);
        bool hasLower(string password);
        bool hasInt(string password);
    public:
        Validation();
        bool validate(string password);
};