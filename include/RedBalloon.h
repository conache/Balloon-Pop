#ifndef REDBALLOON_H
#define REDBALLOON_H
#include "Balloon.h"

class RedBalloon: public Balloon
{
    private:
    static float _creation_time;
    static float _min_frequency;
    static float _current_frequency;
    public:
        RedBalloon();
        static void IncreaseCreationTime( float new_value);
        static void InitializeCreationTime();
        static float GetMinFrequency();
        static void SetBalloonFrequency(float new_value);
        static void DecreaseBalloonFrequency();
        static float GetCreationTime();
        static float GetCurrentFrequency();
        virtual ~RedBalloon();

    protected:

    private:
};

#endif // REDBALLOON_H
