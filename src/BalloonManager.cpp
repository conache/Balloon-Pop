#include "BalloonManager.h"
#include "Screen.h"
#include <algorithm>
BalloonManager* BalloonManager::current_manager( new BalloonManager);

BalloonManager::BalloonManager(){
}

void BalloonManager::onClick( float x, float y, Scene* _balloonScene ){
    for (auto it : _balloons) {
        Vector2 object_position = it->get_position();
        if( ( x >= object_position.GetX() && x<= object_position.GetX() + it->get_width() ) &&
           ( y <= object_position.GetY() && y >= object_position.GetY() - it->get_height()) )
           deleteObject( it, _balloonScene);
	}
}
void BalloonManager::AddBalloon( Balloon* object){
    _balloons.push_back( object );
}
void BalloonManager::deleteObject( Balloon* object, Scene* _balloonScene){
    _balloons.erase( std::remove( _balloons.begin(), _balloons.end(), object) , _balloons.end());
//    _balloonScene->delete_object( object );
}

void BalloonManager::checkPosition( Scene* _balloonScene){
    for (auto it : _balloons){
        Vector2 object_position = it->get_position();
        float height = it->get_height();
        if( object_position.GetY() > ( Screen::GetHeight() + height-1) ) deleteObject(it, _balloonScene);
    }
}
void BalloonManager::AddBalloon( Scene* _balloonScene ){

}
BalloonManager::~BalloonManager(){

}
