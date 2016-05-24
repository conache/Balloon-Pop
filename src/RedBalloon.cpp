#include "RedBalloon.h"
#include "Screen.h"
int RedBalloon::lives_influence = -1;
bool RedBalloon::bonus_giver = false;
int RedBalloon::bonus_mode_points = 0;
int RedBalloon::normal_mode_points = 0;
RedBalloon::RedBalloon():Balloon("Assets/Images/red_balloon.png"){
}
RedBalloon::~RedBalloon(){
}

short RedBalloon::getLivesInfluence(){
    if( _position.GetY() <= Screen::GetHeight() ) return lives_influence;
    return 0;
}

bool RedBalloon::BonusGiver(){
    return bonus_giver;
}

int RedBalloon::getNormalPoints(){
    if( _position.GetY() > Screen::GetHeight() ) return 0;
    return normal_mode_points;
}

int RedBalloon::getBonusPoints(){
    if( _position.GetY() > Screen::GetHeight() ) return 0;
    return bonus_mode_points;
}
