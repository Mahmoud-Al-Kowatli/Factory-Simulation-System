#pragma once
#include "Libraries.h"
#include "Order.h"
#include "Client.h"

class OrdersManager
{
	list<Order> receptionQueue;
	unordered_map<int, list<Order>::iterator> receptionIndex;
	priority_queue<Order> shippingQueue;
	unordered_map<int, Client> clientsDatabase;
public:
	void registerClient(Client c);
	void receiveOrder(Order o);
};

