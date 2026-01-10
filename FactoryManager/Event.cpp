#include<Event.h>

Event::Event(string description){
    this->description =description;
    timestamp=time(0);
}