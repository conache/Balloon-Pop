#include "BalloonController.h"
#include "BalloonFactory.h"
#include "Vector2.h"
#include <algorithm>
#include "Screen.h"
#include "Input.h"
#include "Player.h"
#include "DeleteBalloonArgs.h"
#include "DeleteAnimationArgs.h"
#include "EventManager.h"

BalloonController::BalloonController(BalloonFactory* balloonGenerator, Player* current_player){

    factory = balloonGenerator;
    player = current_player;
    EventManager::Instance()->AddEvent("DeleteBalloon", player, &Player::UpdateStatus);
    EventManager::Instance()->AddEvent("DeleteBalloon", this, &BalloonController::BalloonDeletionCallBack);

}

BalloonController::~BalloonController(){
    for (auto it : _balloons)
        delete it;

}

void BalloonController::deleteObject( Balloon* object){
    _balloons.erase( std::remove( _balloons.begin(), _balloons.end(), object) , _balloons.end());
    delete object;
}

void BalloonController::BalloonDeletionCallBack( EventArgs& args){
    DeleteBalloonArgs* delete_args = dynamic_cast<DeleteBalloonArgs*>(&args);
    deleteObject(delete_args->getBalloon());
}

void BalloonController::runDeleteEvent( Balloon* object){
    DeleteBalloonArgs* args = new DeleteBalloonArgs(object, player);
    EventManager::Instance()->RunEvent("DeleteBalloon",*args);
    delete args;
}


void BalloonController::runDeleteAnimationEvent( Balloon* object){

    EventManager::Instance()->AddEvent("BalloonDestroy", object, &Balloon::Animate);
    DeleteAnimationArgs* args = new DeleteAnimationArgs;
    EventManager::Instance()->RunEvent("BalloonDestroy",*args);
    EventManager::Instance()->GetOutOfEvent( "BalloonDestroy",object,&Balloon::Animate);

}

void BalloonController::checkPosition(){
    for (auto it : _balloons){
        Vector2 object_position = it->get_position();
        float height = it->get_height();
        if( object_position.GetY() > ( Screen::GetHeight() + height-0.5) )
        runDeleteEvent( it );
    }
}

void BalloonController::onClick( Vector2 clickPosition ){
    float click_X = clickPosition.GetX();
    float click_Y = clickPosition.GetY();
    for (auto it : _balloons) {
        Vector2 object_position = it->get_position();
        if( ( click_X >= object_position.GetX() && click_X <= object_position.GetX() + it->get_width() ) &&
           ( click_Y <= object_position.GetY() && click_Y >= object_position.GetY() - it->get_height()) ) runDeleteAnimationEvent( it );
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
        if( it->getDeletable() ) runDeleteEvent( it );
        else it->Update();
    }

}

