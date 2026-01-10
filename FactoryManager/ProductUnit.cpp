#include "ProductUnit.h"


int ProductUnit::counter = 1;

ProductUnit::ProductUnit()
{
    unitID = counter++;
}

void ProductUnit::addEvent(string desc){
    Event newEvent(desc);
    history.push_back(newEvent);
}
ProductUnit::ProductUnit(int unitID ,int parentOrderID){
    this->unitID = unitID;
    this->parentOrderID = parentOrderID;
}
