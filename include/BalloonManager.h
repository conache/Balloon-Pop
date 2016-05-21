#ifndef BALLOONMANAGER_H
#define BALLOONMANAGER_H
#include <vector>
#include "Balloon.h"
#include "Scene.h"
class BalloonManager
{
    public:
        static BalloonManager* instance(){
            return current_manager;
        }
         void onClick( float x, float y, Scene* _balloonScene );
         void checkPosition(Scene* _balloonScene);
         void AddBalloon( Balloon* _balloon);
         void AddBalloon( Scene* _balloonScene );
    protected:
    private:
        std::vector<Balloon*> _balloons;
        void deleteObject( Balloon* object, Scene* _balloonScene);
        static BalloonManager* current_manager;
        BalloonManager();
        ~BalloonManager();
};

#endif // BALLOONMANAGER_H
