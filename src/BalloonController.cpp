#include "BalloonController.h"
#include "Vector2.h"
#include "GameTime.h"
#include <algorithm>
#include "GreenBalloon.h"
#include "RedBalloon.h"
#include "YellowBalloon.h"
#include "Screen.h"
#include "Input.h"
BalloonController::BalloonController(){
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

template<class BalloonType>
void BalloonController::CreateBalloon(){
    BalloonType* object = new BalloonType();
    pause_time = ( object->get_height() )/ Balloon::GetSpeed();
    _balloons.push_back( object );
    BalloonType::InitializeCreationTime();
}

template<class BalloonType>
bool BalloonController::EvaluateCreation( float deltaTime){
    BalloonType::IncreaseCreationTime( deltaTime );
    float current_time = BalloonType::GetCreationTime();
    float current_frequency = BalloonType::GetCurrentFrequency();
    float min_frequency = BalloonType::GetMinFrequency();
    if ( current_frequency >= min_frequency && current_time >= current_frequency){
        CreateBalloon<BalloonType>();
        BalloonType::DecreaseBalloonFrequency();
        return true;
    } else if ( current_time >= current_frequency ){
       CreateBalloon<BalloonType>();
        return true;
    }
    return false;
}

void BalloonController::createBalloon(){
    float deltaTime = GameTime::GetDeltaTime();
    time_lapsed += deltaTime;
    if (time_lapsed > pause_time && EvaluateCreation<RedBalloon>( deltaTime )) time_lapsed = 0;
    else if (time_lapsed > pause_time && EvaluateCreation<YellowBalloon>( deltaTime )) time_lapsed = 0;
    else if ( time_lapsed > pause_time && EvaluateCreation<GreenBalloon>( deltaTime )) time_lapsed = 0;
}

void BalloonController::clickCheck(){
    for( int i=1; i<=4; i++)
     if ( Input::GetMouseButtonDown(i) ){
        onClick( Input::GetMousePosition() );
        break;
    }
}

void BalloonController::Update(){
    createBalloon();
    clickCheck();
    checkPosition();
    for (auto it : _balloons){
        it->Update();
    }
}

