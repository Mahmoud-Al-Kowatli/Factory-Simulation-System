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
            system("cls");
			cout << "Login successful!" << endl;
            system("pause>0");
            system("cls");
            FactoryManager::seedInitialData();
            FactoryManager::runSimulation();
        }
        else
        {
			system("cls");
            cout << "Login failed please try again\n";
        }

    } while (inputUsername != USERNAME || inputPassword != PASSWORD);

}
