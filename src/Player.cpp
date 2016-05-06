#include "Player.h"
#include <string>
unsigned long long Player::score = 0;
short int Player::lives = 3;
Player::Player(std::string PlayerName)
{
    name = PlayerName;

}
void Player::IncreaseScore( int value ){
    score+=value;
}
void Player::IncreaseLives( int value ){
    lives+=value;
}
void Player::DecreaseLives(){
    lives -= 1;
}
unsigned long long Player::GetScore(){
    return score;
}
short int Player::GetLives(){
    return lives;
}

Player::~Player()
{
    //dtor
}
