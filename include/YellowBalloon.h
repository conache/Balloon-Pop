#ifndef YELLOWBALLOON_H
#define YELLOWBALLOON_H
#include "Balloon.h"
class YellowBalloon: public Balloon
{   private:
        static short lives_influence;
        static bool bonus_giver;
        static int bonus_mode_points;
        static int normal_mode_points;
    public:
        YellowBalloon();
        virtual ~YellowBalloon();
        bool BonusGiver();
        getNormalPoints();
        getBonusPoints();
        short getLivesInfluence();
};

#endif // YELLOWBALLOON_H
