#pragma once
#include"Libraries.h"
#include"Client.h"
#include"Product.h"

class Order {

public:
    enum Priority{NORMAL = 1, VIP = 2, URGENT = 3};

private:
    static int counter;
    int id;
    time_t arrivalTime;
    int requiredQuantity;
    int clientID;
    int productID;
    double totalValue;
    Client client;
    Product product;
    Priority priority;

public:
    double calculateValue();

    bool operator<(const Order& other);

    Order(Priority priority, int requiredQuantity, Product product);

    int getID();

    Priority getPriority();

    void setPriority(Priority p);


};
