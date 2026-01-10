#pragma once
#include "Libraries.h"
#include "Order.h"
#include "Client.h"

class OrdersManager
{
    list<Order> receptionQueue;
    unordered_map<int, list<Order>::iterator> receptionIndex;
    priority_queue<Order> shippingQueue;
	unordered_map<int, Order> ordersDatabase;
public:
    void receiveOrder(Order order);
    void getAllOrdersHistory();
};