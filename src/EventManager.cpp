#include "EventManager.h"
#include "EventHandlerBase.h"
#include "iostream"
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
    std::map<std::string, std::vector<EventHandlerBase*> >::iterator it = EventMapper.find( EventName ) ;
    if( it != EventMapper.end() ){

        for( std::vector<EventHandlerBase*>::iterator second_it= EventMapper[ it->first ].begin(); second_it != EventMapper[ it->first ].end(); ++second_it)
            (*second_it)->RunEvent( args );
    }
    else return;
}
