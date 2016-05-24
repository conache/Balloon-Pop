#include "YellowBalloon.h"
#include "Screen.h"
short YellowBalloon::lives_influence = 0;
bool YellowBalloon::bonus_giver = false;
int YellowBalloon::bonus_mode_points = 50;
int YellowBalloon::normal_mode_points = 20;

YellowBalloon::YellowBalloon():Balloon("Assets/Images/yellow_balloon.png"){

}
short  YellowBalloon::getLivesInfluence(){
    if( _position.GetY() > Screen::GetHeight() ) return -1;
    return lives_influence;
}

bool YellowBalloon::BonusGiver(){
    return bonus_giver;
}

YellowBalloon::~YellowBalloon(){
}

int YellowBalloon::getNormalPoints(){
    if( _position.GetY() > Screen::GetHeight() ) return 0;
    return normal_mode_points;
}

int YellowBalloon::getBonusPoints(){
    if( _position.GetY() > Screen::GetHeight() )  return 0;
        return bonus_mode_points;
}
