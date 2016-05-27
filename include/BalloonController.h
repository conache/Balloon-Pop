#ifndef BALLOONCONTROLLER_H
#define BALLOONCONTROLLER_H
#include "SceneObject.h"
#include <vector>
#include "Balloon.h"
#include "BalloonFactory.h"
#include "Player.h"
#include "EventArgs.h"
class BalloonController: public SceneObject
{
    public:
        BalloonController( BalloonFactory* balloonGenerator, Player* current_player);
        virtual ~BalloonController();
        virtual void Draw();
        virtual void Update();
    protected:

    private:
        BalloonFactory* factory;
        Player* player;
        std::vector<Balloon*> _balloons;
        void BalloonDeletionCallBack( EventArgs& args );
        void deleteObject( Balloon* object);
        void onClick( Vector2 clickPosition );
        void checkPosition();
        void clickCheck();
        void factoryInterrogation();
        void runDeleteEvent( Balloon* object);
        void runDeleteAnimationEvent( Balloon* object);
};


#endif // BALLOONCONTROLLER_H
