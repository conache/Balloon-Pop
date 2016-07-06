#include "YellowBalloon.h"
#include "Screen.h"
#include "ImageAtlas.h"
#include "EventManager.h"
#include "iostream"
short YellowBalloon::lives_influence = 0;
bool YellowBalloon::bonus_giver = false;
int YellowBalloon::bonus_mode_points = 50;
int YellowBalloon::normal_mode_points = 20;

short  YellowBalloon::getLivesInfluence(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return -1;
    return lives_influence;
}

bool YellowBalloon::BonusGiver(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5  ) return false;
    return bonus_giver;
}

void YellowBalloon::DeleteAnimation(EventArgs& args){
    Balloon::UpdateSprites( ImageAtlas::Instance()->getStripes( "YellowBalloonDestroy" ) );
    Balloon::setDeleteAnimation( true );
}

void YellowBalloon::Animate(EventArgs& args){
    EventManager::Instance()->AddEvent( "YellowBalloonDestroy",this,&DeleteAnimation );
    EventManager::Instance()->RunEvent( "YellowBalloonDestroy", args);
    EventManager::Instance()->GetOutOfEvent( "YellowBalloonDestroy",this,&DeleteAnimation);

}

YellowBalloon::YellowBalloon():Balloon("Assets/Images/yellow_balloon.png"){

}

YellowBalloon::~YellowBalloon(){

}

int YellowBalloon::getNormalPoints(){
   if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return 0;
    return normal_mode_points;
}

int YellowBalloon::getBonusPoints(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 )  return 0;
        return bonus_mode_points;
}
