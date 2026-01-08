#include "OrdersManager.h"

void OrdersManager::registerClient(Client client)
{
	clientsDatabase[client.getID()] = client;
}

void OrdersManager::receiveOrder(Order order)
{

	list<Order>::iterator insertedIt;

	//if Urgent it adds it at the beggining of the list
	if (order.getPriority() == Order::Priority::URGENT)
	{
		receptionQueue.push_front(order);
		insertedIt = receptionQueue.begin();
	}
	//if Normal it adds it at the end of the list
	else if (order.getPriority() == Order::Priority::NORMAL)
	{
		receptionQueue.push_back(order);
		insertedIt = --receptionQueue.end();
	}

	//if VIP it adds it after the last Urgent "basically when it finds the first Normal Order it inserts it after it"
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