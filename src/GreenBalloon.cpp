#include "GreenBalloon.h"
#include "Player.h"
#include "time.h"
GreenBalloon::GreenBalloon():Balloon("Assets/Images/green_balloon.png")
{

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
