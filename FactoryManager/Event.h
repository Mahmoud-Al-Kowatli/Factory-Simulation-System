#pragma once
#include "Libraries.h"


class Event
{
private:
    static int counter;
    int id;
    string description;
    time_t timestamp;
    static unordered_map<int, Event> eventDatabase;

public:
    Event();

    Event(string desc);

    int getID();
   
    string getDescription();

    time_t getTimestamp();

    static bool tryGetEvent(Event& event, int id);

    static bool isFound(int eventID);

    static void registerEvent(Event event);

	friend ostream& operator<<(ostream& os, const Event& event);

    ~Event();
};