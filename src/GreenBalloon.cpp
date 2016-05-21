#include "GreenBalloon.h"
#include "Player.h"
#include "time.h"
float GreenBalloon::_creation_time = 0;
float GreenBalloon::_current_frequency = 12;
float GreenBalloon::_min_frequency = 7;
GreenBalloon::GreenBalloon():Balloon("Assets/Images/green_balloon.png")
{

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
    srand( time(NULL) );
    int score_bonus = Player::BonusScoreTimes();
    int mode_bonus = Player::BonusModeTimes();
    if ( abs( score_bonus - mode_bonus)>=2 ){
        if( score_bonus > mode_bonus ){
            Player::EnableBonusMode();
            Player::IncreaseBonusModeTimes();
        } else{
        srand( time(NULL) );
        Player::IncreaseScore( rand()%151 + 50 );
        Player::IncreaseBonusScoreTimes();
        }
    } else{
        switch ( rand()%2 ){
        case 0:
            Player::EnableBonusMode();
            Player::IncreaseBonusModeTimes();
            break;
        case 1:{
            srand( time(NULL) );
            Player::IncreaseScore( rand()%151 + 50 );
            Player::IncreaseBonusScoreTimes();
        }
        }
    }
}

GreenBalloon* GreenBalloon::Clone(){
    return new GreenBalloon;
}
