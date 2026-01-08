#pragma once
#include"Libraries.h"
#include "Order.h"


int Order::counter = 1;

Order::Order(int priority, int requiredQuantity, Product product)
{
    /*
    int clientID;
    int productID;
    double totalValue;
    */
    this->product = product;
    this->productID;
    id = counter++;
    this->priority = priority;
    this->requiredQuantity = requiredQuantity;
    arrivalTime = time(0);
    totalValue = calculateValue();
    this->productID = product.getID();
    this->clientID = client.getID();

}


double Order::calculateValue() {
    return product.getPrice() * requiredQuantity;
}

bool Order::operator<(const Order& other) {
    return this->priority < other.priority;
}