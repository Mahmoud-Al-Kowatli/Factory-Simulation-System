#include "OrdersManager.h"

void OrdersManager::registerClient(Client client)
{
	clientsDatabase[client.getID()] = client;
}

void OrdersManager::receiveOrder(Order order)
{

	list<Order>::iterator insertedIt;

	if (order.getPriority() == Order::Priority::URGENT)
	{
		receptionQueue.push_front(order);
		insertedIt = receptionQueue.begin();
	}
	else if (order.getPriority() == Order::Priority::NORMAL)
	{
		receptionQueue.push_back(order);
		insertedIt = --receptionQueue.end();
	}
	else
	{

		list<Order>::iterator it = receptionQueue.begin();
		
		while (it != receptionQueue.end()) {
			if (it->getPriority() == Order::Priority::NORMAL)
			{
				break;
			}
			it++;
		}

		insertedIt = receptionQueue.insert(it, order);
	}


	receptionIndex[order.getID()] = insertedIt;

}