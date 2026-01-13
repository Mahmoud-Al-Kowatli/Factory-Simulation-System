#pragma once
#include "Libraries.h"
#include "Product.h"
#include"ProductUnit.h"
#include "Material.h"
#include "Order.h"

class WarehouseManager {
private:
    static unordered_map<int, deque<Material>> storageBins; //{MaterialID, deque<Material>}
    static unordered_map<int, int> inventoryCounts; //{MaterialID, TotalQunatity}
	static unordered_map<int, ProductUnit> finishedGoods; //{ProductUnitID, ProductUnit}
    static void consumeFromStorageBins(int storageBinID, int quantity);

public:
    static bool getProductDetails(Product& product, int id);
    static bool consumeMaterialsForOrder(Order order);
    static void addMaterial(Material material);
    static void addMaterial(Material material, int count);
};