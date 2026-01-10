#include "ProductUnit.h"


void ProductUnit::addEvent(string desc){
    Event newEvent(desc);
    history.push_back(newEvent);
}
ProductUnit::ProductUnit(int unitID ,int parentOrderID){
    this->unitID = unitID;
    this->parentOrderID = parentOrderID;
}