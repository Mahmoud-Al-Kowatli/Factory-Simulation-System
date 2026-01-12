#pragma once
#include "Libraries.h"

class Client
{
    static int counter;
    int id;
    string name;
	static unordered_map<int, Client> clientsDatabase;
    vector<int> orderHistoryIDs;
public:
    Client();
    Client(string name);
    static Client getClient(int ID);
    static void registerClient(Client client);
    int getID() const;
    void addOrderHistory(int ID);
    void printClientInfo() const;

    //Some data for testing
	static Client CLIENT_1;
	static Client CLIENT_2;

};
