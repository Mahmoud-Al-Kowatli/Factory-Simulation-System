#include"Libraries.h"
#include "Order.h"
#include "ProductUnit.h"


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
    id = 0;
    priority = NORMAL;
    requiredQuantity = 0;
    arrivalTime = time(0);
    totalValue = calculateValue();
    productID = 0;
	clientID = 0;
}


double Order::calculateValue() const {
    switch (priority)
    {
    case Order::NORMAL:
		return productPrice * requiredQuantity;
        break;
    case Order::VIP:
		return productPrice * requiredQuantity * 1.2;
        break;
    case Order::URGENT:
		return productPrice * requiredQuantity * 1.5;
        break;
    default:
        break;
    }
    return productPrice * requiredQuantity;
}

void Order::printOrder() const {
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
    // [Cross-Platform Compatibility] 
    // We use preprocessor directives to handle time string formatting 
    // because ctime_s is Microsoft-specific, while ctime is standard.
    #ifdef _WIN32
        char timeBuffer[26];
        ctime_s(timeBuffer, sizeof(timeBuffer), &arrivalTime);
        cout << "Arrival Time: " << timeBuffer;
    #else
        // Standard C++ for Linux (Arch) and macOS
        char* timeStr = ctime(&arrivalTime);
        cout << "Arrival Time: " << timeStr;
    #endif
    cout << "==============================================\n";
}

// Operator overloading

bool Order::operator<(const Order& other) const {
    return priority < other.priority;
}


// getters&setters

Order::Priority Order::getPriority() const {
    return priority;
}

void Order::setPriority(Priority p) {
    priority = p;
}

Product Order::getProduct() const
{
    return Product::getProduct(productID);
}

int Order::getProductID() const
{
    return productID;
}

int Order::getRequiredQuantity() const
{
    return requiredQuantity;
}

int Order::getID() const 
{
    return id;
}


int Order::getClientID() const
{
    return clientID;
}

Client Order::getClient() const
{
    return Client::getClient(clientID);
}

void Order::setQuantity(int newQuantity)
{
    requiredQuantity = newQuantity;
    totalValue = calculateValue();
}

double Order::getTotalValue() const
{
    return totalValue;
}


// Hussam wanted to show that he is a professor in C++ and taught me how to do this for_each
vector<pair<Material, int>> Order::getTotalRequiredMaterials()
{
    vector<pair<Material, int>> vMaterials = getProduct().getRequirements();
    
    for_each(vMaterials.begin(), vMaterials.end(), [=](pair<Material, int>& p) {

        p.second *= requiredQuantity;

        });

    return vMaterials;
}

void Order::setClientID(int clientID)
{
    this->clientID = clientID;
}
