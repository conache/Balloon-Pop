#include "GreenBalloon.h"
#include "Screen.h"
#include "ImageAtlas.h"
#include "EventManager.h"
int GreenBalloon::lives_influence = 0;
bool GreenBalloon::bonus_giver = true;
int GreenBalloon::bonus_mode_points = 0;
int GreenBalloon::normal_mode_points = 0;
GreenBalloon::GreenBalloon():Balloon("Assets/Images/green_balloon.png")
{

}

void GreenBalloon::DeleteAnimation(EventArgs& args){
    Balloon::UpdateSprites( ImageAtlas::Instance()->getStripes( "GreenBalloonDestroy" ) );
    Balloon::setDeleteAnimation( true );
}

void GreenBalloon::Animate(EventArgs& args){

    EventManager::Instance()->AddEvent( "GreenBalloonDestroy",this,&DeleteAnimation );
    EventManager::Instance()->RunEvent( "GreenBalloonDestroy", args);
    EventManager::Instance()->GetOutOfEvent( "GreenBalloonDestroy",this,&DeleteAnimation);

}



short GreenBalloon::getLivesInfluence(){
    return lives_influence;
}

bool GreenBalloon::BonusGiver(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return false;
    return bonus_giver;
}

GreenBalloon::~GreenBalloon(){
}

int GreenBalloon::getNormalPoints(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return 0;
    return normal_mode_points;
}

int GreenBalloon::getBonusPoints(){
    if( _position.GetY() > Screen::GetHeight()+get_height()-0.5 ) return 0;
    return bonus_mode_points;
}

