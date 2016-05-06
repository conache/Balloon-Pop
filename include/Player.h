#ifndef PLAYER_H
#define PLAYER_H

#include <string>
class Player
{
    public:
        Player(std::string PlayerName);
        virtual ~Player();
        static void IncreaseScore(int value);
        static void IncreaseLives(int value);
        static void DecreaseLives();
        static unsigned long long GetScore();
        static short int GetLives();
        static void EnableBonusMode();
        static void DisableBonusMode();
        static bool BonusMode();
        static void DecreaseBonusTime( float value );
        static float BonusTime();
        static void IncreaseBonusModeTimes();
        static void IncreaseBonusScoreTimes();
        static int BonusModeTimes();
        static int BonusScoreTimes();
    protected:

    private:
        static unsigned long long score;
        static short int lives;
        static bool bonus_mode;
        static float bonus_time;
        static int bonus_mode_count;
        static int bonus_score_count;
        std::string name;
};

#endif // PLAYER_H
