#include "GreenBalloon.h"
#include "Screen.h"
int GreenBalloon::lives_influence = 0;
bool GreenBalloon::bonus_giver = true;
int GreenBalloon::bonus_mode_points = 0;
int GreenBalloon::normal_mode_points = 0;
GreenBalloon::GreenBalloon():Balloon("Assets/Images/green_balloon.png")
{

}
short GreenBalloon::getLivesInfluence(){
    return lives_influence;
}

bool GreenBalloon::BonusGiver(){
    return bonus_giver;
}
GreenBalloon::~GreenBalloon(){
}

int GreenBalloon::getNormalPoints(){
    if( _position.GetY() > Screen::GetHeight() ) return 0;
    return normal_mode_points;
}

int GreenBalloon::getBonusPoints(){
    if( _position.GetY() > Screen::GetHeight() ) return 0;
    return bonus_mode_points;
}
