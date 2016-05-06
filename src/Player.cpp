#include "Player.h"
#include <string>
#include <iostream> //remove it
unsigned long long Player::score = 0;
short int Player::lives = 3;
bool Player::bonus_mode = false;
float Player::bonus_time = 0;
int Player::bonus_mode_count = 0;
int Player::bonus_score_count = 0;
Player::Player(std::string PlayerName)
{
    name = PlayerName;

}
void Player::IncreaseScore( int value ){
    score+=value;
    std::cout<<"Player score:"<<score<<"\n";
}
void Player::IncreaseLives( int value ){
    lives+=value;
}
void Player::DecreaseLives(){
    lives -= 1;
    std::cout<<"Player lives:"<<lives<<"\n";
}
unsigned long long Player::GetScore(){
    return score;
}
short int Player::GetLives(){
    return lives;
}
void Player::EnableBonusMode(){
    std::cout<<"Bonus mode enabled!\n";
    bonus_mode = true;
    bonus_time += 7;
}
void Player::DisableBonusMode(){
    bonus_mode = false;
    bonus_time = 0;
    std::cout<<"Bonus mode disabled!\n";
}
bool Player::BonusMode(){
    return bonus_mode;
}
void Player::DecreaseBonusTime( float value ){
    bonus_time -= value;
}
float Player::BonusTime(){
    return bonus_time;
}
void Player::IncreaseBonusScoreTimes(){
    bonus_score_count += 1;
}
void Player::IncreaseBonusModeTimes(){
    bonus_mode_count += 1;
}
int Player::BonusModeTimes(){
    return bonus_mode_count;
}
int Player::BonusScoreTimes(){
    return bonus_score_count;
}
Player::~Player()
{
    //dtor
}
