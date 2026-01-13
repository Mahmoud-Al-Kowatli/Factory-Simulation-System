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
	void editOrder();
	void printOrderDetailsForEditOrDelete(Order order);
	void deleteOrder(int orderID);
	void showHistory();
	Product choosingProduct();
	int choosingProductID();
	int choosingClientID();
	int checkIfNumber();
	int checkIfNumber(int x, int y);
	Order::Priority setPriority();
};
