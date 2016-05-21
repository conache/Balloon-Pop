#ifndef GREENBALLOON_H
#define GREENBALLOON_H

#include "Balloon.h"
class GreenBalloon: public Balloon
{
private:
static float _creation_time;
static float _min_frequency;
static float _current_frequency;
    public:
        GreenBalloon();
        static void IncreaseCreationTime( float new_value);
        static void InitializeCreationTime();
        static float GetMinFrequency();
        static void SetBalloonFrequency(float new_value);
        static void DecreaseBalloonFrequency();
        static float GetCreationTime();
        static float GetCurrentFrequency();
        GreenBalloon* Clone();
        virtual ~GreenBalloon();

    protected:

    private:
};

#endif // GREENBALLOON_H
