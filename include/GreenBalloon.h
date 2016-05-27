#ifndef GREENBALLOON_H
#define GREENBALLOON_H
#include "Balloon.h"
class GreenBalloon: public Balloon
{
    private:
        static int lives_influence;
        static bool bonus_giver;
        static int bonus_mode_points;
        static int normal_mode_points;
    public:
        GreenBalloon();
        virtual ~GreenBalloon();
        bool BonusGiver();
        int getNormalPoints();
        int getBonusPoints();
        short getLivesInfluence();
        void Animate(EventArgs& args);
        void DeleteAnimation( EventArgs& args);
    protected:
};
#endif // GREENBALLOON_H
