#ifndef PLAYERINCREASESCOREARGS_H
#define PLAYERINCREASESCOREARGS_H
#include "EventArgs.h"
#include "Player.h"
class PlayerIncreaseScoreArgs: public EventArgs
{
    public:
        PlayerIncreaseScoreArgs(float value, Player* current_player);
        virtual ~PlayerIncreaseScoreArgs();
        Player* getPlayer();
        float getPoints();
    protected:

    private:
        float obtained_points;
        Player* player;
};

#endif // PLAYERINCREASESCOREARGS_H
