#include "WarehouseManager.h"

unordered_map<int, deque<Material>> WarehouseManager::storageBins = {};
unordered_map<int, int> WarehouseManager::inventoryCounts = {};
unordered_map<int, ProductUnit> WarehouseManager::finishedGoods = {};

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

bool WarehouseManager::getProductDetails(Product& product, int id)
{
	if (!Product::isFound(id))
		return false;
	product = Product::getProduct(id);
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

void WarehouseManager::addMaterial(Material material, int count)
{
	for (int i = 0; i < count; i++)
		addMaterial(material);
}

void WarehouseManager::addFinishedProductUnits(const unordered_map<int, ProductUnit>& units)
{
	Event event("Finished.");
	finishedGoods = units;
	for (auto& p : finishedGoods)
		p.second.addEvent(event.getID());
}

void WarehouseManager::showMaterials()
{
	Material::traverse([](Material material) {
		int materialID = material.getID();
		if (storageBins[materialID].empty())
		{
			cout << "The warehouse doesn't have any unit of " << material.getName() << endl;
			return;
		}
		cout << materialID << ") " << material.getName() << endl;
		cout << "---------------------------------------------\n";
		int count = 0;
		for (const Material& p : storageBins[materialID])
		{
			cout << "\tBox number: " << ++count << " has " << p.getQuantity() << endl;
		}
		cout << "---------------------------------------------\n\n";
		});
}

void WarehouseManager::traverseOnFinishedGoods(void(*function)(ProductUnit&))
{
	for (pair<int, ProductUnit> p : finishedGoods)
		function(p.second);
}
