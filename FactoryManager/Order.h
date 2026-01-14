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
    int productPrice;
    double totalValue;
    Priority priority;

public:
    double calculateValue() const;

    bool operator<(const Order& other) const;
    
    // change the constructor
    Order(Priority priority, int requiredQuantity, int productID, int clientID);

    Order();

    int getID() const;

    Priority getPriority() const;

    void setPriority(Priority p);

    Product getProduct() const;

    int getProductID() const;

    int getRequiredQuantity() const;

    int getClientID() const;

    Client getClient() const;

    void printOrder() const;

    void setQuantity(int newQuantity);

	double getTotalValue() const;

    vector<pair<Material,int>> getTotalRequiredMaterials();

    void setClientID(int clientID);
};
