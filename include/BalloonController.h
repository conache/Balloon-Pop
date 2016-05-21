#ifndef BALLOONCONTROLLER_H
#define BALLOONCONTROLLER_H
#include "SceneObject.h"
#include <vector>
#include "Balloon.h"
#include "BalloonFactory.h"
class BalloonController: public SceneObject
{
    public:
        BalloonController();
        virtual ~BalloonController();
        virtual void Draw();
        virtual void Update();
    protected:

    private:
        BalloonFactory* factory;
        std::vector<Balloon*> _balloons;
        void deleteObject( Balloon* object);
        void onClick( Vector2 clickPosition );
        void checkPosition();
        void clickCheck();
        void factoryInterrogation();
};


#endif // BALLOONCONTROLLER_H
