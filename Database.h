#include <string>
using namespace std;

class Database{
    private:
        string username;
        string password;
    public:
        Database();
        Database(string username, string password) : username(username), password(password){};
        string getUsername();
        string getPassword();
};
