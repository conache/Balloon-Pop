#ifndef DELETEBALLOONARGS_H
#define DELETEBALLOONARGS_H
#include "Balloon.h"
#include "Player.h"
#include "EventArgs.h"
class DeleteBalloonArgs: public EventArgs
{
    public:
        DeleteBalloonArgs(Balloon* object, Player* current_player);
        virtual ~DeleteBalloonArgs();
        Balloon* getBalloon();
        Player* getPlayer();
    protected:

    private:
        Balloon* balloon;
        Player* player;

};

#endif // DELETEBALLOONARGS_H
