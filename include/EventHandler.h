#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include "EventArgs.h"
#include "EventHandlerBase.h"
#include "iostream"
template< class Class>

class EventHandler: public EventHandlerBase
{
    private:
    typedef void( Class::*function_ptr)(EventArgs&);
    Class *object;
    function_ptr fp;
    public:

        EventHandler(Class* obj, function_ptr fptr){
            object = obj;
            fp = fptr;

        }

        void RunEvent(EventArgs& args){
            (object->*fp)(args);
        }

        function_ptr getExecutedFunction(){
            return fp;
        }

    protected:


};

#endif // EVENTHANDLER_H
