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

    //Some data for testing
	static const Client CLIENT_1;
	static const Client CLIENT_2;

};
