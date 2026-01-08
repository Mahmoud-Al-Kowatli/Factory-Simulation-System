#include "WarehouseManager.h"

WarehouseManager::WarehouseManager()
{
}

void WarehouseManager::addProductToCatalog(Product p)
{
	productCatalog[p.getID()] = p;
}

Product WarehouseManager::getProductDetails(int id)
{
	if (productCatalog.find(id) != productCatalog.end())
		return productCatalog[id];
}

bool WarehouseManager::consumeMaterialsForOrder(int productID, int qty)
{
	return false;
}
