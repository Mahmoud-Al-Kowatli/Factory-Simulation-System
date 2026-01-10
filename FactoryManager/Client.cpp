#include "Client.h"

int Client::counter = 1;

Client::Client()
{
    //autmoatically assigns IDs to Clients everytime a new Client is created
    this->id = counter++;
	this->name = "Guest";
}

Client::Client(string name)
{
    //autmoatically assigns IDs to Clients everytime a new Client is created
    this->id = counter++;
    this->name = name;
}

int Client::getID() const
{
    return id;
}

void Client::addOrderHistory(int ID)
{
	orderHistoryIDs.push_back(ID);
}
