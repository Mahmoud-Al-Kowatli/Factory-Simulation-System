#include "ProductUnit.h"


int ProductUnit::counter = 0;

ProductUnit::ProductUnit() : unitID(0), productID(0), parentOrderID(0), isFinished(false) {}

void ProductUnit::addEvent(int eventID)
{
    if (Event::isFound(eventID))
        historyIDs.push_back(eventID);
}

void ProductUnit::showProductUnitEvents()
{
    Event event;
    for (const int& i : historyIDs)
    {
        Event::tryGetEvent(event, i);
        cout << event << endl;
    }
}

void ProductUnit::finish()
{
    isFinished = true;
}

ProductUnit::ProductUnit(int parentOrderID, int productID)
{
    unitID = ++counter;
    this->productID = productID;
    this->parentOrderID = parentOrderID;
    isFinished = false;
}
