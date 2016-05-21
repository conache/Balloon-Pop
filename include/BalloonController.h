#ifndef BALLOONCONTROLLER_H
#define BALLOONCONTROLLER_H
#include "SceneObject.h"
#include <vector>
#include "Balloon.h"
class BalloonController: public SceneObject
{
    public:
        BalloonController();
        virtual ~BalloonController();
        virtual void Draw();
        virtual void Update();
    protected:

    private:
        float pause_time;
        float time_lapsed;
        std::vector<Balloon*> _balloons;
        void deleteObject( Balloon* object);
        void onClick( Vector2 clickPosition );
        void checkPosition();
        void createBalloon();
        void clickCheck();
        template<class BalloonType> bool EvaluateCreation ( float deltaTime);
        template<class BalloonType> void CreateBalloon();
};

#endif // BALLOONCONTROLLER_H
