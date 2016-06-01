#include "Player.h"
#include "EventManager.h"
#include "DeleteBalloonArgs.h"
#include "GameOverArgs.h"
#include <iostream> //remove it
#include "time.h"
#include "GameTime.h"
Player::Player(std::string PlayerName)
{
    name = PlayerName;
    score = 0;
    lives = 3;
    bonus_mode = false;
    bonus_time = 0;
    bonus_mode_count = 0;
    bonus_score_count = 0;

}

void Player::DisableBonusMode(){
    bonus_mode = false;
    bonus_time = 0;
    std::cout<<"Bonus mode disabled!\n";
}

void Player::Update(){

 if( bonus_mode ){
    if( bonus_time >=0 ) bonus_time -= GameTime::GetDeltaTime();
    else DisableBonusMode();
 }

}
void Player::IncreaseScore( int value ){
    score+=value;
}

void Player::UpdateLives( int value ){
    lives += value;
    std::cout<<"Player lives:"<<lives<<std::endl;
}

float Player::GetScore(){
    return score;
}
short int Player::GetLives(){
    return lives;
}
void Player::EnableBonusMode(){
    std::cout<<"Bonus mode enabled!\n";
    bonus_mode = true;
    bonus_time += 7;
    bonus_mode_count+= 1;
}

bool Player::BonusMode(){
    return bonus_mode;
}

std::string Player::getName(){
    return name;
}

void Player::setBonusScore(){
    srand( time(NULL) );
    score += rand() % 151 + 50;
    bonus_score_count +=1;
}

void Player::EnterBonusMode(){

    if( abs( bonus_score_count - bonus_mode_count) >=2 ){
        if( bonus_score_count > bonus_mode_count ) EnableBonusMode();
        else setBonusScore();
    } else{
        srand( time(NULL) );
        switch( rand()%2){
        case 0 :
            EnableBonusMode();
            break;
        case 1:
            setBonusScore();
            break;
        }
    }

}

void Player::UpdateStatus(EventArgs& args){
    DeleteBalloonArgs* delete_args = dynamic_cast<DeleteBalloonArgs*>(&args);
    Player& player = *delete_args->getPlayer();
    Balloon* balloon = delete_args->getBalloon();
    std::cout<<"Player name:"<<player.getName()<<std::endl;

    if ( !player.BonusMode() ){
        int lives_influence_value = balloon->getLivesInfluence();
        player.UpdateLives( lives_influence_value );
        player.IncreaseScore( balloon->getNormalPoints() );
        if( balloon->BonusGiver() ) EnterBonusMode();

    } else{
        player.IncreaseScore( balloon -> getBonusPoints() );
    }
    std::cout<<"Score:"<<player.GetScore()<<std::endl;
    if ( lives == 0){
            GameOverArgs* args = new GameOverArgs;
            EventManager::Instance()->RunEvent("GameOver",*args);
    }
}
Player::~Player()
{
    //dtor
}
