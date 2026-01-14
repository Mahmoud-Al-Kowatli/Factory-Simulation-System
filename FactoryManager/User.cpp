#include"User.h"

User::User()
{
	login();
}

void User::login()
{

    string inputUsername = "";


    string inputPassword = "";

    do 
    {
        cout << "Please enter username: ";
        cin >> inputUsername;

        cout << "Please enter password: ";
        cin >> inputPassword;

        if (inputUsername == USERNAME && inputPassword == PASSWORD)
        {
			cout << "Login successful!" << endl;
            FactoryManager::seedInitialData();
            FactoryManager::runSimulation();
        }
        else
        {
			system("cls");
            cout << "Login failed please try again\n";
        }

    } while (inputUsername != USERNAME && inputPassword != PASSWORD);

}
