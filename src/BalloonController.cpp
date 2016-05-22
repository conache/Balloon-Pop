#include "BalloonController.h"
#include "BalloonFactory.h"
#include "Vector2.h"
#include <algorithm>
#include "Screen.h"
#include "Input.h"
BalloonController::BalloonController(BalloonFactory* balloonGenerator){
    factory = balloonGenerator;
}

BalloonController::~BalloonController(){
    for (auto it : _balloons) {
		delete it;
	}
}

void BalloonController::deleteObject( Balloon* object){
    _balloons.erase( std::remove( _balloons.begin(), _balloons.end(), object) , _balloons.end());
    delete object;
}

void BalloonController::checkPosition(){
    for (auto it : _balloons){
        Vector2 object_position = it->get_position();
        float height = it->get_height();
        if( object_position.GetY() > ( Screen::GetHeight() + height-0.1) ) deleteObject(it);
    }
}

void BalloonController::onClick( Vector2 clickPosition ){
    float click_X = clickPosition.GetX();
    float click_Y = clickPosition.GetY();
    for (auto it : _balloons) {
        Vector2 object_position = it->get_position();
        if( ( click_X >= object_position.GetX() && click_X <= object_position.GetX() + it->get_width() ) &&
           ( click_Y <= object_position.GetY() && click_Y >= object_position.GetY() - it->get_height()) )
           deleteObject( it);
	}
}
void BalloonController::Draw(){
    for (auto it : _balloons){
        it->Draw();
    }
}

void BalloonController::clickCheck(){
    for( int i=1; i<=4; i++)
     if ( Input::GetMouseButtonDown(i) ){
        onClick( Input::GetMousePosition() );
        break;
    }
}
void BalloonController::factoryInterrogation(){
    Balloon* value = factory -> newItem();
    if ( value) _balloons.push_back( value );
}

void BalloonController::Update(){
    factoryInterrogation();
    clickCheck();
    checkPosition();
    for (auto it : _balloons){
        it->Update();
    }

}

