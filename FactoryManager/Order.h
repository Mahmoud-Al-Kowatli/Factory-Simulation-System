#pragma once
#include"Libraries.h"
#include"Client.h"
#include"Product.h"

class Order {

public:
    enum Priority{NORMAL = 1, VIP = 2, URGENT = 3};

private:
    static int counter;
    int id;//is the order id
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

    bool operator<(const Order& other) const;

    Order(Priority priority, int requiredQuantity, Product product);

    Order();

    int getID();

    Priority getPriority();

    void setPriority(Priority p);

    Product getProduct();

    int getProductID();

    int getRequiredQuantity();

    int getClientID();

    void printOrder();

    void setQuantity(int newQuantity);

	double getTotalValue();

};
