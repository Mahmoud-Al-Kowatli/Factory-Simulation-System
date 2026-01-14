#pragma once
#include "Libraries.h"
#include "Order.h"
#include "ProductUnit.h"

class ProductionFloor 
{
    static vector<priority_queue<Order>> lines;
    static unordered_map<int, ProductUnit> activeUnits;
    static int emergencyLineIndex;
    static vector<Order> processedOrders;
    static void loadOrdersForShipping();
    static void loadProductUnitForShipping();

public:
    static void setNumberOfLines(int linesNum);
    static void getLines();
    static int getNoOfLines();
    static void assignOrder(int lineID, Order o);
    static void handleLineBreakdown(int brokenLineID);
	static bool isLineEmpty(int lineID);
    static void processNextOrder(int lineID);
    static int findBestAvailableLine(int excludedLine);
    static void displayStatus();
    static bool tryLoadForShipping();
    static void showActiveUnits();
};