#ifndef EVENTHANDLERBASE_H
#define EVENTHANDLERBASE_H
#include "EventArgs.h"

class EventHandlerBase
{
     private:
    public:
        EventHandlerBase();
        virtual ~EventHandlerBase();
        virtual void RunEvent(EventArgs& args) = 0;
    protected:


};

#endif // EVENTHANDLERBASE_H
