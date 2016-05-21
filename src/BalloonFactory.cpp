#include "BalloonFactory.h"
#include "GameTime.h"
#include "Balloon.h"
#include "GreenBalloon.h"
#include "RedBalloon.h"
#include "YellowBalloon.h"
BalloonFactory::BalloonFactory()
{
    time_lapsed = pause_time = 0;
}

BalloonFactory::~BalloonFactory()
{
    //dtor
}

template<class BalloonType>
BalloonType* BalloonFactory::createBalloon(){
    time_lapsed = 0;
    BalloonType* object = new BalloonType();
    pause_time = ( object->get_height() )/ Balloon::GetSpeed();
    return object;
}

template<class BalloonType>
bool BalloonFactory::EvaluateCreation( float deltaTime){
     BalloonType::IncreaseCreationTime( deltaTime );
    float current_time = BalloonType::GetCreationTime();
    float current_frequency = BalloonType::GetCurrentFrequency();
    float min_frequency = BalloonType::GetMinFrequency();
    if ( current_time >= current_frequency){
        if( current_frequency >= min_frequency ) BalloonType::DecreaseBalloonFrequency();
        BalloonType::InitializeCreationTime();
        return true;
    }

    return false;
}

Balloon* BalloonFactory::newBalloon(){

    float deltaTime = GameTime::GetDeltaTime();
    time_lapsed += deltaTime;
    if (time_lapsed > pause_time && EvaluateCreation<RedBalloon>( deltaTime  )) return createBalloon<RedBalloon>();
    else if (time_lapsed > pause_time && EvaluateCreation<YellowBalloon>( deltaTime )) return createBalloon<YellowBalloon>();
    else if ( time_lapsed > pause_time && EvaluateCreation<GreenBalloon>( deltaTime )) return createBalloon<GreenBalloon>();
    return NULL;
}
