#include "RedBalloon.h"
#include "Screen.h"
#include "ImageAtlas.h"
#include "EventManager.h"
int RedBalloon::lives_influence = -1;
bool RedBalloon::bonus_giver = false;
int RedBalloon::bonus_mode_points = 0;
int RedBalloon::normal_mode_points = 0;
RedBalloon::RedBalloon():Balloon("Assets/Images/red_balloon.png"){
}
RedBalloon::~RedBalloon(){
}


void RedBalloon::DeleteAnimation(EventArgs& args){
    Balloon::UpdateSprites( ImageAtlas::Instance()->getStripes( "RedBalloonDestroy" ) );
    Balloon::setDeleteAnimation( true );
}

void RedBalloon::Animate(EventArgs& args){

    EventManager::Instance()->AddEvent( "RedBalloonDestroy",this,&DeleteAnimation );
    EventManager::Instance()->RunEvent( "RedBalloonDestroy", args);
    EventManager::Instance()->GetOutOfEvent( "RedBalloonDestroy",this,&DeleteAnimation);

}


short RedBalloon::getLivesInfluence(){
    if( _position.GetY() <= Screen::GetHeight()+get_height()-0.5 ) return lives_influence;
    return 0;
}

bool RedBalloon::BonusGiver(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return false;
    return bonus_giver;
}

int RedBalloon::getNormalPoints(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return 0;
    return normal_mode_points;
}

int RedBalloon::getBonusPoints(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return 0;
    return bonus_mode_points;
}
