#pragma once
#include "Libraries.h"
#include "Product.h"
#include"ProductUnit.h"
#include "Material.h"
#include "Order.h"

class WarehouseManager {
private:
    unordered_map<int, deque<Material>> storageBins; //{MaterialID, deque<Material>}
    unordered_map<int, int> inventoryCounts; //{MaterialID, TotalQunatity}
    unordered_map<int, ProductUnit> finishedGoods;
    void consumeFromStorageBins(int storageBinID, int quantity);

public:
    WarehouseManager();
    bool getProductDetails(Product& product, int id);
    bool consumeMaterialsForOrder(Order order);
    void addMaterial(Material material);
};