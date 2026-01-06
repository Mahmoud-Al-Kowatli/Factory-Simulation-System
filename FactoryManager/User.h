#pragma once
#include"Libraries.h"

class User
{
public:
	User();
	~User();

	void login();

	void logout();

private:
	string username;
	string password;
};


