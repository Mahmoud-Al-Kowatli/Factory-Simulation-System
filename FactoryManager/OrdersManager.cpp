#include "OrdersManager.h"

unordered_map<int, Order> OrdersManager::ordersDatabase = {};
unordered_map<int, list<Order>::iterator> OrdersManager::receptionIndex = {};
list<Order> OrdersManager::receptionQueue = {};
priority_queue<Order> OrdersManager::shippingQueue = {};

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
	ordersDatabase[order.getID()] = order;
	Client::getClient(order.getClientID()).addOrderHistory(order.getID());
}

bool OrdersManager::getOrderByID(Order& order, int ID)
{
	if (ordersDatabase.find(ID) == ordersDatabase.end())
		return false;
	order = ordersDatabase[ID];
	return true;
}


void OrdersManager::getAllOrdersHistory()
{
	for (auto& i : ordersDatabase)
	{
		i.second.printOrder();
	}
}

void OrdersManager::printOrderByClientID(int clientID)
{
	for (auto& i : ordersDatabase)
	{
		if (i.second.getClientID() == clientID)
		{
			i.second.printOrder();
		}
	}
}
