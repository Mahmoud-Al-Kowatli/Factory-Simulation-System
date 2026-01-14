#include"Libraries.h"

class User
{
public:

    ~User();

    void login();


private:
    //static username&password 
    string username = "Admin";
    string password = "Admin123";
};
