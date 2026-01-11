#pragma once
#include"User.h"


void User::login()
{
    cout << "Please enter username: ";
    string inputUsername;
    cin >> inputUsername;
    cout << "Please enter password: ";
    string inputPassword;
    cin >> inputPassword;
    if (inputUsername == username && inputPassword == password) {
        cout << "Login successful!" << endl;
    }
    else {
        cout << "Login failed!" << endl;
    }
}


User::~User()
{

}