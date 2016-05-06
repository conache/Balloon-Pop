#include "YellowBalloon.h"
#include "Player.h"
float YellowBalloon::_creation_time = 0;
float YellowBalloon::_current_frequency = 3;
float YellowBalloon::_min_frequency = 0.5;
YellowBalloon::YellowBalloon():Balloon("Assets/Images/yellow_balloon.png")
{

}

void YellowBalloon::IncreaseCreationTime(float new_value){
   _creation_time += new_value;
}

void YellowBalloon::InitializeCreationTime(){
    _creation_time = 0;
}

float YellowBalloon::GetMinFrequency(){
    return _min_frequency;
}

void YellowBalloon::DecreaseBalloonFrequency(){
    _current_frequency -= 0.1;
}

void YellowBalloon::SetBalloonFrequency( float new_value){
    _current_frequency = new_value;
}
float YellowBalloon::GetCreationTime(){
    return _creation_time;
}
float YellowBalloon::GetCurrentFrequency(){
    return _current_frequency;
}


YellowBalloon::~YellowBalloon(){
    Player::IncreaseScore(20);
    std::cout<<"Scor:"<<Player::GetScore()<<"\n";
}

