#include "WarehouseManager.h"

void WarehouseManager::consumeFromStorageBins(int storageBinID, int quantity)
{
	deque<Material>& storageBin = storageBins[storageBinID];
	while (quantity > 0)
	{
		Material& material = storageBin.back();
		if (quantity >= material.getQuantity())
		{
			quantity -= material.getQuantity();
			storageBin.pop_back();
		}
		else
		{
			material.setQuantity(material.getQuantity() - quantity);
			break;
		}
	}
}

WarehouseManager::WarehouseManager()
{
	addProductToCatalog(Product::BOOKSHELF);
	addProductToCatalog(Product::DRAWER_CABINET);
	addProductToCatalog(Product::GAMING_DESK);
	addProductToCatalog(Product::OFFICER_CHAIR);
	addProductToCatalog(Product::WOODEN_DESK);
}

void WarehouseManager::addProductToCatalog(Product p)
{
	productCatalog[p.getID()] = p;
}

bool WarehouseManager::getProductDetails(Product& product, int id)
{
	if (productCatalog.find(id) == productCatalog.end())
		return false;
	productCatalog[id] = product;
	return true;
}

bool WarehouseManager::consumeMaterialsForOrder(Order order)
{
	Product product = order.getProduct();
	int rq = order.getRequiredQuantity();
	vector<pair<Material, int>> requirements = product.getRequirements();
	for (pair<Material, int> requirement : requirements)
	{
		int materialQuantity = requirement.second;
		int materialID = requirement.first.getID();
		int totalQuantity = order.getRequiredQuantity() * materialQuantity;
		if (totalQuantity > inventoryCounts[materialID])
			return false;
	}
	for (pair<Material, int> requirement : requirements)
	{
		int materialQuantity = requirement.second;
		int materialID = requirement.first.getID();
		int totalQuantity = order.getRequiredQuantity() * materialQuantity;
		consumeFromStorageBins(materialID, totalQuantity);
	}
	return true;
}

void WarehouseManager::addMaterial(Material material)
{
	if (storageBins.find(material.getID()) == storageBins.end())
		storageBins[material.getID()] = deque<Material>{ material };
	else
		storageBins[material.getID()].push_front(material);
	inventoryCounts[material.getID()] += material.getQuantity();
}

void WarehouseManager::removeMaterial(Material material)
{
}


