#include"Libraries.h"

class User
{
public:

    ~User();

    void login();


private:
    //staic username&password 
    string username = "Admin";
    string password = "Admin123";
};
