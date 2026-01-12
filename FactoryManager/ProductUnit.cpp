#include "ProductUnit.h"


int ProductUnit::counter = 0;

ProductUnit::ProductUnit() : unitID(0), productID(0), parentOrderID(0), isFinished(false) {}

void ProductUnit::addEvent(string desc)
{
    Event e(desc);
    historyIDs.push_back(e.getID());
}

ProductUnit::ProductUnit(int parentOrderID, int productID)
{
    unitID = ++counter;
    this->productID = productID;
    this->parentOrderID = parentOrderID;
    isFinished = false;
}
