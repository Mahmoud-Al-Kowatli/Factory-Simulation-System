#pragma once
#include "Libraries.h"

class Order {
public:
    int id;
    int priority;
    time_t arrivalTime;
    int requiredQuantity;
    int clientID;
    int productID;
    double totalValue;

    void calculateValue();
    
    bool operator<(const Order& other);
};
