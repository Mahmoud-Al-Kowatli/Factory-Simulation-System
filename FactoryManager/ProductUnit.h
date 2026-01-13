#pragma once
#include "Libraries.h"
#include "Event.h"
#include "Product.h"

class ProductUnit
{
private:
    static int counter;
    int unitID;
    int productID;
    int parentOrderID;
    bool isFinished;
    vector<int> historyIDs;

public:
    ProductUnit();
    ProductUnit(int parentOrderID, int productID);
    void addEvent(int eventID);
    void showProductUnitEvents();
    void finish();
};