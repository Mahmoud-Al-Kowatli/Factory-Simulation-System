#pragma once
#include "Libraries.h"
#include "OrdersManager.h"
#include "WarehouseManager.h"
#include "ProductionFloor.h"

class FactoryManager
{
private:
public:
	FactoryManager();
	~FactoryManager();
	OrdersManager orderManager;
	WarehouseManager warehouseManager;
	ProductionFloor productionFloor;
	void runSimulation();
	void AddOrder();
	void editOrder(int orderID);
	void deleteOrder(int orderID);
	void showHistory();
	Product choosingProduct();
	int checkIfNumber();
	int checkIfNumber(int x, int y);
	Order::Priority setPriority();
};
