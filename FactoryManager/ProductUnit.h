#pragma once
#include "Libraries.h"
#include "Event.h"

class ProductUnit
{
private:
    static int counter;
    int unitID;
    int parentOrderID;
    vector<Event> history;

public:
    ProductUnit();
    ProductUnit(int unitId, int parentOrderID);
    void addEvent(string desc);
};