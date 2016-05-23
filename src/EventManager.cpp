#include "EventManager.h"
EventManager* EventManager::current_manager( new EventManager);
EventManager* EventManager::Instance(){
    return current_manager;
}

EventManager::EventManager()
{
    //ctor
}

EventManager::~EventManager()
{
    //dtor
}
void EventManager::RunEvent(std::string EventName, EventArgs& args){
    std::map<std::string, EventHandlerBase* >::iterator it = EventMapper.find( EventName ) ;
    if( it != EventMapper.end() ){
        EventHandlerBase* eventHandler = it->second;
        eventHandler->RunEvent(args);
    }
    else return;
}
