#include "DeleteBalloonArgs.h"

DeleteBalloonArgs::DeleteBalloonArgs(Balloon* object, Player* current_player)
{
    balloon = object;
    player = current_player;
}

DeleteBalloonArgs::~DeleteBalloonArgs()
{
    //dtor
}

Balloon* DeleteBalloonArgs::getBalloon(){
    return balloon;
}

Player* DeleteBalloonArgs::getPlayer(){
    return player;
}
