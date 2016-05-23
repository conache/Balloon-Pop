#include "PlayerIncreaseScoreArgs.h"

PlayerIncreaseScoreArgs::PlayerIncreaseScoreArgs(float value, Player* current_player)
{
    obtained_points = value;
    player = current_player;
}

Player* PlayerIncreaseScoreArgs::getPlayer(){
    return player;
}

float PlayerIncreaseScoreArgs::getPoints(){
    return obtained_points;
}

PlayerIncreaseScoreArgs::~PlayerIncreaseScoreArgs()
{
    //dtor
}
