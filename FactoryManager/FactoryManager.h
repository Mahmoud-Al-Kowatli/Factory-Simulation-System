#pragma once
#include "Libraries.h"
#include "OrdersManager.h"
#include "WarehouseManager.h"
#include "ProductionFloor.h"

class FactoryManager
{
	static void addOrder();
	static void editOrder();
	static void printOrderDetailsForEditOrDelete(Order order);
	static void tryDeleteOrder();
	static void showHistory();
	static int choosingProductID();
	static int choosingClientID();
	static int checkIfNumber();
	static void processOrder();
	static int checkIfNumber(int x, int y);
	static void startProduction();
	static void handleLineBreakdown();
	static void registerOrder();
	static void buyMaterial();
	static Order::Priority setPriority();

public:
	static void seedInitialData();
	static void runSimulation();
};
