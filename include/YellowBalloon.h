#ifndef YELLOWBALLOON_H
#define YELLOWBALLOON_H
#include "Balloon.h"
class YellowBalloon: public Balloon
{   private:
    static float _creation_time;
    static float _min_frequency;
    static float _current_frequency;
    public:
        YellowBalloon();
        static void IncreaseCreationTime( float new_value);
        static void InitializeCreationTime();
        static float GetMinFrequency();
        static void SetBalloonFrequency(float new_value);
        static void DecreaseBalloonFrequency();
        static float GetCreationTime();
        static float GetCurrentFrequency();
        virtual ~YellowBalloon();
};

#endif // YELLOWBALLOON_H
