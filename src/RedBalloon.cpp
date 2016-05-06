#include "RedBalloon.h"
#include "Player.h"
#include "Screen.h"
float RedBalloon::_creation_time = 0;
float RedBalloon::_current_frequency = 8;
float RedBalloon::_min_frequency = 4;
RedBalloon::RedBalloon():Balloon("Assets/Images/red_balloon.png")
{

}

void RedBalloon::IncreaseCreationTime(float new_value){
   _creation_time += new_value;
}

void RedBalloon::InitializeCreationTime(){
    _creation_time = 0;
}

float RedBalloon::GetMinFrequency(){
    return _min_frequency;
}

void RedBalloon::DecreaseBalloonFrequency(){
    _current_frequency -= 0.1;
}

void RedBalloon::SetBalloonFrequency( float new_value){
    _current_frequency = new_value;
}
float RedBalloon::GetCreationTime(){
    return _creation_time;
}
float RedBalloon::GetCurrentFrequency(){
    return _current_frequency;
}


RedBalloon::~RedBalloon()
{
    if( _position.GetY() <= Screen::GetHeight() ) Player::DecreaseLives();
}
