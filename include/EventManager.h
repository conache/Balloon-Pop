#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <map>
#include "EventArgs.h"
#include "EventHandlerBase.h"
#include "EventHandler.h"
class EventManager
{
    private:
        std::map<std::string, EventHandlerBase*> EventMapper;
        static EventManager* current_manager;
        EventManager();
        virtual ~EventManager();
    public:
        static EventManager* Instance();
        template< typename Class>
        void AddEvent(std::string EventName, Class *obj, void (Class::*fp)(EventArgs& )){
            if( EventMapper.find( EventName ) == EventMapper.end() ) EventMapper[ EventName ] = new EventHandler<Class>( obj, fp);

        }
        void RunEvent( std::string EventName, EventArgs& args);
    protected:
};

#endif // EVENTMANAGER_H
