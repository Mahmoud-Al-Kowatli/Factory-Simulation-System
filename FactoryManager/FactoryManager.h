#pragma once
#include "Libraries.h"
#include "OrdersManager.h"
#include "WarehouseManager.h"
#include "ProductionFloor.h"

class FactoryManager
{
	ProductionFloor productionFloor;
	static void addOrder();
	static void editOrder();
	static void printOrderDetailsForEditOrDelete(Order order);
	static void tryDeleteOrder();
	static void showHistory();
	static int choosingProductID();
	static int choosingClientID();
	static int checkIfNumber();
	static int checkIfNumber(int x, int y);
	static Order::Priority setPriority();

public:
	static void runSimulation();
};
