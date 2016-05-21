#ifndef BALLOONFACTORY_H
#define BALLOONFACTORY_H
#include "SceneObject.h"
#include "Balloon.h"
class BalloonFactory
{
    public:
        BalloonFactory();
        virtual ~BalloonFactory();
        Balloon* newBalloon();
    protected:

    private:
        float pause_time;
        float time_lapsed;
        template< class BalloonType> BalloonType* createBalloon();
        template<class BalloonType> bool EvaluateCreation( float deltaTime);
};

#endif // BALLOONFACTORY_H
