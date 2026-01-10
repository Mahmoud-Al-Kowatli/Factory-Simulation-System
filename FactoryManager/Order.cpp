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

Order::Order() {
    id = counter++;
    this->priority = NORMAL;
    this->requiredQuantity = 1;
    this->product = Product::OFFICER_CHAIR;
    arrivalTime = time(0);
    totalValue = calculateValue();
    this->productID = product.getID();
	this->clientID = client.getID();
}


double Order::calculateValue() {
    return product.getPrice() * requiredQuantity;
}

void Order::printOrder() {
    cout << "Order ID: " << id << endl;
    cout << "Client ID: " << clientID << endl;
    cout << "Product ID: " << productID << endl;
    cout << "Required Quantity: " << requiredQuantity << endl;
    cout << "Total Value: " << totalValue << endl;
    cout << "Priority: ";
    if (priority == NORMAL) {
        cout << "NORMAL" << endl;
    }
    else if (priority == VIP) {
        cout << "VIP" << endl;
    }
    else if (priority == URGENT) {
        cout << "URGENT" << endl;
    }
    //cout << "Arrival Time: " << ctime_s () << endl;
}

// Operator overloading

bool Order::operator<(const Order& other) const {
    return priority < other.priority;
}


// getters&setters

Order::Priority Order::getPriority() {
    return priority;
}

void Order::setPriority(Priority p) {
    priority = p;
}

Product Order::getProduct()
{
    return product;
}

int Order::getRequiredQuantity()
{
    return requiredQuantity;
}

int Order::getID() {

    return id;
}


int Order::getClientID()
{
    return clientID;
}

