#ifndef REDBALLOON_H
#define REDBALLOON_H
#include "Balloon.h"
#include "EventArgs.h"
class RedBalloon: public Balloon
{
    private:
        static int lives_influence;
        static bool bonus_giver;
        static int bonus_mode_points;
        static int normal_mode_points;
    public:
        RedBalloon();
        virtual ~RedBalloon();
        bool BonusGiver();
        short getLivesInfluence();
        int getNormalPoints();
        int getBonusPoints();
        void Animate(EventArgs& args);
        void DeleteAnimation(EventArgs& args);
    protected:

};

#endif // REDBALLOON_H
