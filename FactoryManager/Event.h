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

    int getID() const;
   
    string getDescription();

    time_t getTimestamp() const;

    static bool tryGetEvent(Event& event, int id);

    static bool isFound(int eventID);

    static void registerEvent(Event event);

    static void printAllEvents();

	friend ostream& operator<<(ostream& os, const Event& event);

    ~Event();
};