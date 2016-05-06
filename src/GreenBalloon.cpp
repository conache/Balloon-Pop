#include "GreenBalloon.h"
float GreenBalloon::_creation_time = 0;
float GreenBalloon::_current_frequency = 12;
float GreenBalloon::_min_frequency = 7;
GreenBalloon::GreenBalloon():Balloon("Assets/Images/green_balloon.png")
{
    //ctor
}

void GreenBalloon::IncreaseCreationTime(float new_value){
   _creation_time += new_value;
}

void GreenBalloon::InitializeCreationTime(){
    _creation_time = 0;
}

float GreenBalloon::GetMinFrequency(){
    return _min_frequency;
}

void GreenBalloon::DecreaseBalloonFrequency(){
    _current_frequency -= 0.1;
}

void GreenBalloon::SetBalloonFrequency( float new_value){
    _current_frequency = new_value;
}
float GreenBalloon::GetCreationTime(){
    return _creation_time;
}
float GreenBalloon::GetCurrentFrequency(){
    return _current_frequency;
}


GreenBalloon::~GreenBalloon()
{
    //dtor
}
