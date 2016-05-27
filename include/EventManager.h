#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H
#include <map>
#include <vector>
#include "EventArgs.h"
#include "EventHandlerBase.h"
#include "EventHandler.h"
#include <algorithm>
#include "iostream" //delete it
class EventManager
{
    private:
        std::map<std::string, std::vector<EventHandlerBase*> > EventMapper;
        static EventManager* current_manager;
        EventManager();
        virtual ~EventManager();
    public:
        static EventManager* Instance();

        template< typename Class>
        void AddEvent(std::string EventName, Class *obj, void (Class::*fp)(EventArgs& )){
            EventMapper[ EventName ].push_back( new EventHandler<Class>( obj, fp) );
        }

        template< typename Class>
        void GetOutOfEvent( std::string EventName, Class *obj, void (Class::*fp)(EventArgs& ) ){
            if( EventMapper.find( EventName ) != EventMapper.end() ){
                    typename std::vector<EventHandler<Class>*> converted_vector;
                    for(std::vector<EventHandlerBase*>::iterator it = EventMapper[ EventName ].begin(); it!= EventMapper[ EventName ].end(); ++it)
                        converted_vector.push_back( dynamic_cast< EventHandler<Class>* >( *it ));
                    typename std::vector<EventHandler<Class>*>::iterator second_it = converted_vector.begin();
                    int i=0;
                    for( ; second_it != converted_vector.end(); ++second_it, i++){
                        if( (*second_it)->getExecutedFunction() == fp){
                        std::cout<<"Hereeeeee\n"<<i<<" "<<EventMapper[ EventName ].size()<<std::endl;
                        EventMapper[ EventName ].erase(EventMapper[ EventName ].begin()+i);
                        std::cout<<"Hereeeeee\n"<<i<<" "<<EventMapper[ EventName ].size()<<std::endl;
                        delete *second_it;
                    }
                }
            }

}

void RunEvent( std::string EventName, EventArgs& args);
    protected:
};

#endif // EVENTMANAGER_H
