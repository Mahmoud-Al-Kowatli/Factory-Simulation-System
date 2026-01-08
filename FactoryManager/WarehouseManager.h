#pragma once
#include "Libraries.h"
#include "Product.h"
#include"ProductUnit.h"
#include "Material.h"

class WarehouseManager {
private:
    unordered_map<int, deque<Material>> storageBins;
    unordered_map<int, int> inventoryCounts;
    unordered_map<int, ProductUnit> finishedGoods;
    unordered_map<int, Product> productCatalog;

public:
    WarehouseManager();
    void addProductToCatalog(Product p);
    Product getProductDetails(int id);
    bool consumeMaterialsForOrder(int productID, int qty);
};