#include "DeleteBalloonArgs.h"

DeleteBalloonArgs::DeleteBalloonArgs(Balloon* object)
{
    balloon = object;
}

DeleteBalloonArgs::~DeleteBalloonArgs()
{
    //dtor
}

Balloon* DeleteBalloonArgs::getBalloon(){
    return balloon;
}
