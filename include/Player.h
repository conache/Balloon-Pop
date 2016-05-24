#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include "EventArgs.h"
#include "SceneObject.h"
class Player: public SceneObject
{
    public:

        Player(std::string PlayerName);
        virtual ~Player();
        std::string getName();
        void UpdateStatus(EventArgs& args);
        float GetScore();
        short int GetLives();
        void Update();

    protected:


    private:
        int score;
        int lives;
        bool bonus_mode;
        float bonus_time;
        int bonus_mode_count;
        int bonus_score_count;
        std::string name;
        void IncreaseScore(int value);
        void UpdateLives( int value );
        bool BonusMode();
        void EnterBonusMode();
        void setBonusScore();
        void EnableBonusMode();
        void DisableBonusMode();
};

#endif // PLAYER_H
