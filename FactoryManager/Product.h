#pragma once
#include "Libraries.h"

class Product {
private:
    int id;
    string name;
    double unitPrice;
    vector<pair<int, int>> requirements; // {MaterialID, Quantity}
    static int counter;

public:
    Product();
    Product(string name, double unitPrice, vector<pair<int, int>> requirements);
    int getID() const;
    vector<pair<int, int>> getRequirements();
    double getPrice() const;
};