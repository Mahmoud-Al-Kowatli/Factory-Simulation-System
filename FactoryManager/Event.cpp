#include"Event.h"

int Event::counter = 1;

unordered_map<int, Event> Event::eventDatabase = {};

Event::Event() : id(0), description(""), timestamp(0) {}

Event::Event(string description)
{
    id = counter++;
    this->description = description;
    timestamp = time(0);
    registerEvent(*this);
}

Event::~Event()
{
}

int Event::getID() const
{
    return id;
}

string Event::getDescription()
{
    return description;
}

time_t Event::getTimestamp() const
{
    return timestamp;
}

bool Event::isFound(int eventID)
{
    return eventDatabase.find(eventID) != eventDatabase.end();
}

bool Event::tryGetEvent(Event& event, int id)
{
    if (!isFound(id))
        return false;
    event = eventDatabase[id];
    return true;
}

void Event::registerEvent(Event event)
{
    eventDatabase[event.getID()] = event;
}

ostream& operator<<(ostream& os, const Event& event)
{
    char timeBuffer[26];
    ctime_s(timeBuffer, sizeof(timeBuffer), &event.timestamp);
    os << "Event Description: " << event.description
        << ", Timestamp: " << timeBuffer;
    return os;
}