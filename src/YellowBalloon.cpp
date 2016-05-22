#include "YellowBalloon.h"
#include "Player.h"
#include "Screen.h"
#include <time.h>
YellowBalloon::YellowBalloon():Balloon("Assets/Images/yellow_balloon.png")
{

}
YellowBalloon::~YellowBalloon(){

    if ( _position.GetY() > Screen::GetHeight() ){
        if ( !Player::BonusMode() ) Player::DecreaseLives();
         else;
    }
    else if ( !Player::BonusMode() ) Player::IncreaseScore( 20 );
    else Player::IncreaseScore( 50 );
}

