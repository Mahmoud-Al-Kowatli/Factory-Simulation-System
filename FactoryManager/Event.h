#pragma once
#include "Libraries.h"


class Event
{
    public:
   
    string description;
    time_t timestamp;

    
    Event(string desc);

    ~Event();
};