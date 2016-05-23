#ifndef EVENTHANDLERBASE_H
#define EVENTHANDLERBASE_H
#include "EventArgs.h"

class EventHandlerBase
{
    public:
        EventHandlerBase();
        virtual ~EventHandlerBase();
        virtual void RunEvent(EventArgs& args) = 0;
    protected:

    private:
};

#endif // EVENTHANDLERBASE_H
