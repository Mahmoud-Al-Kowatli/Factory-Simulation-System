#pragma once
#include "Libraries.h"
#include "Order.h"

class OrdersManager
{
    static list<Order> receptionQueue;
    static unordered_map<int, list<Order>::iterator> receptionIndex;
    static priority_queue<Order> shippingQueue;
	static unordered_map<int, Order> ordersDatabase;
public:
    static void receiveOrder(Order order);
    static bool getOrderByID(Order& order, int ID);
    static void getAllOrdersHistory();
    static void printOrderByClientID(int clientID);

};