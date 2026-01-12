#pragma once
#include "Libraries.h"


class Event
{
private:
    string description;
    time_t timestamp;

public:
   
    string getDescription();

    time_t getTimestamp();

    Event(string desc);

	friend ostream& operator<<(ostream& os, const Event& event);

    ~Event();
};