#include "Client.h"

int Client::counter = 1;


Client::Client(string name)
{
	//autmoatically assigns IDs to Clients everytime a new Client is created
	this->id = counter++;
	this->name = name;
}
