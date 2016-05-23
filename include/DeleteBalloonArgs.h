#ifndef DELETEBALLOONARGS_H
#define DELETEBALLOONARGS_H
#include "Balloon.h"
#include "EventArgs.h"
class DeleteBalloonArgs: public EventArgs
{
    public:
        DeleteBalloonArgs(Balloon* object);
        virtual ~DeleteBalloonArgs();
        Balloon* getBalloon();
    protected:

    private:
        Balloon* balloon;

};

#endif // DELETEBALLOONARGS_H
