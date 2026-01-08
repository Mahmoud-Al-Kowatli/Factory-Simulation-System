#pragma once
#include"Libraries.h"
#include "Order.h"


int Order::counter = 1;

Order::Order(Priority priority, int requiredQuantity, Product product)
{
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
    return priority < other.priority;
}

Order::Priority Order::getPriority() {
    return priority;
}

void Order::setPriority(Priority p) {
    priority = p;
}

int Order::getID() {

    return id;
}



