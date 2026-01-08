#pragma once
#include"Libraries.h"
#include"Client.h"
#include"Product.h"

class Order {

private:
    static int counter;
    int id;
    int priority;
    time_t arrivalTime;
    int requiredQuantity;
    int clientID;
    int productID;
    double totalValue;
    Client client;
    Product product;

public:

    double calculateValue();

    bool operator<(const Order& other);

    Order(int priority, int requiredQuantity, Product product);



};