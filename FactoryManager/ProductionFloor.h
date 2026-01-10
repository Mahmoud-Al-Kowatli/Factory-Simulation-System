#pragma once
#include "Libraries.h"
#include "Order.h"
#include "ProductUnit.h"

class ProductionFloor {
protected:
    vector<priority_queue<Order>> lines;
    unordered_map<int, ProductUnit> activeUnits;
    int emergencyLineIndex;

public:
    ProductionFloor(int numLines = 3);
    
    void assignOrder(int lineID, Order o);
    void handleLineBreakdown(int brokenLineID);
    void processNextOrder(int lineID);
    int findBestAvailableLine(int excludedLine);
    void displayStatus();
};