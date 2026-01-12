#include "Client.h"
#include "OrdersManager.h"

int Client::counter = 1;

//initialization of the static member
unordered_map<int, Client> Client::clientsDatabase = {};

Client::Client()
{
    //autmoatically assigns IDs to Clients everytime a new Client is created
    this->id = counter++;
	this->name = "Guest";
    registerClient(*this);
}

Client::Client(string name)
{
    //autmoatically assigns IDs to Clients everytime a new Client is created
    this->id = counter++;
    this->name = name;
    registerClient(*this);
}

int Client::getID() const
{
    return id;
}

void Client::addOrderHistory(int ID)
{
	orderHistoryIDs.push_back(ID);
}

void Client::printClientInfo() const
{
	cout << "Client ID: " << id << endl;
	cout << "Client Name: " << name << endl;
    cout << "Client Orders: ";
    OrdersManager::printOrderByClientID(id);
    cout << endl;
}

Client Client::getClient(int ID)
{
    return clientsDatabase[ID];
}

void Client::registerClient(Client client)
{
    clientsDatabase[client.getID()] = client;
}

//Some data for testing
Client Client::CLIENT_1 = Client("Client A");

Client Client::CLIENT_2 = Client("Client B");
