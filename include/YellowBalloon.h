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
        void Animate(EventArgs& args);
        void DeleteAnimation(EventArgs& args);
};

#endif // YELLOWBALLOON_H
