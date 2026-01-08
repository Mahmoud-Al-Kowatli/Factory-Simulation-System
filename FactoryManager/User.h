#include"Libraries.h"

class User
{
public:
	User();
	~User();

	void login();

	void logout();

private:
	//staic username&password 
	string username = "Admin";
	string password = "Admin123";
};


