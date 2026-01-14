#pragma once
#include "Libraries.h"
#include "ProductUnit.h"
#include "Order.h"


class OrdersManager
{
    static list<Order> receptionQueue;
    static unordered_map<int, list<Order>::iterator> receptionIndex;
    static priority_queue<Order> shippingQueue;
	static unordered_map<int, Order> ordersDatabase;
    static void addDeliveredEvent(ProductUnit& p);
public:
    static void receiveOrder(Order order);
    static bool tryDeleteOrder(int orderID);
    static bool tryDeleteFromList();
    static bool tryGetTopOrder(Order& order);
    static bool getOrderByID(Order& order, int ID);
    static void getAllOrdersHistory();
    static void printOrderByClientID(int clientID);
    static void traverse(void(*function)(Order));
    static int getOrdersNumber();
    static void saveOrdersForShipping(vector<Order>& orders);
    static void changeOrder(Order order);
    static bool tryGetTopOrderReadyForShipping(Order& order);
    static void printOrdersWithItsEvents();
    static void shipTopOrder();
};