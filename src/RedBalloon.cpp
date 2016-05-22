#include "RedBalloon.h"
#include "Player.h"
#include "Screen.h"
RedBalloon::RedBalloon():Balloon("Assets/Images/red_balloon.png"){
}
RedBalloon::~RedBalloon(){
    if( _position.GetY() <= Screen::GetHeight() ) Player::DecreaseLives();
}

