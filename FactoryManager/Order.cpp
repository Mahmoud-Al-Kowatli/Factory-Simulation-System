#pragma once
#include"Libraries.h"
#include "Order.h"


int Order::counter = 1;

Order::Order(Priority priority, int requiredQuantity, int productID, int clientID)
{
    id = counter++;
    this->priority = priority;
    this->requiredQuantity = requiredQuantity;
    arrivalTime = time(0);
    this->productID = productID;
    this->clientID = clientID;
    productPrice = Product::getProduct(productID).getPrice();
    totalValue = calculateValue();
}

Order::Order() {
    id = counter++;
    priority = NORMAL;
    requiredQuantity = 1;
    arrivalTime = time(0);
    totalValue = calculateValue();
    productID = 1;
	clientID = 1;
}


double Order::calculateValue() {
    return productPrice * requiredQuantity;
}

void Order::printOrder() {
    cout << "==============================================\n";
    cout << "Order ID: " << id << endl;
    cout << "Client ID: " << clientID << endl;
    cout << "Product ID: " << productID << endl;
    cout << "Required Quantity: " << requiredQuantity << endl;
    cout << "Total Value: " << totalValue << endl;
    cout << "Priority: ";
    if (priority == NORMAL) {
        cout << "Normal" << endl;
    }
    else if (priority == VIP) {
        cout << "VIP" << endl;
    }
    else if (priority == URGENT) {
        cout << "Urgent" << endl;
    }
	char timeBuffer[26];
    ctime_s(timeBuffer, sizeof(timeBuffer), &arrivalTime);
    cout << "Arrival Time: " << timeBuffer;
    cout << "==============================================\n";
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
    return Product::getProduct(productID);
}

int Order::getProductID()
{
    return productID;
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

Client Order::getClient()
{
    return Client::getClient(clientID);
}

void Order::setQuantity(int newQuantity)
{
    requiredQuantity = newQuantity;
    totalValue = calculateValue();
}

double Order::getTotalValue()
{
    return totalValue;
}

void Order::setClientID(int clientID)
{
    this->clientID = clientID;
}
