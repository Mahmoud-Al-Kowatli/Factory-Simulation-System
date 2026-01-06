#pragma once
#include "Libraries.h"
#include "Event.h"

class ProductUnit
{
private:
    int unitID;
    int parentOrderID;
    vector<Event> history;

public:
    void addEvent(string desc);
}