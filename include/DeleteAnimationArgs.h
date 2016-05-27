#ifndef DELETEANIMATIONARGS_H
#define DELETEANIMATIONARGS_H
#include "EventArgs.h"
#include "string"
class DeleteAnimationArgs:public EventArgs
{
    public:
        DeleteAnimationArgs();
        std::string getAnimation();
        virtual ~DeleteAnimationArgs();

    protected:

    private:
        std::string animation_name;
};

#endif // DELETEANIMATIONARGS_H
