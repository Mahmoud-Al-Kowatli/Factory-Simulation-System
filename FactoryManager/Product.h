#pragma once
#include "Libraries.h"
#include "Material.h"

class Product {
private:
    int id;
    string name;
    double unitPrice;
    vector<pair<Material, int>> requirements; // {MaterialID, Quantity}
    static int counter;
    static unordered_map<int, Product> productDatabase;
    
public:
    Product();
    Product(string name, double unitPrice, vector<pair<Material, int>> requirements);
    int getID() const;
    string getName();
    vector<pair<Material, int>> getRequirements();
    double getPrice() const;
    static Product getProduct(int id);
    static void registerProduct(const Product& product);
    static void traverse(void(*function)(Product product));
    static bool isFound(int id);
    static const Product OFFICER_CHAIR;
    static const Product WOODEN_DESK;
    static const Product GAMING_DESK;
    static const Product BOOKSHELF;
    static const Product DRAWER_CABINET;
};