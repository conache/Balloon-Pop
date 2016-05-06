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
    protected:

    private:
        static unsigned long long score;
        static short int lives;
        std::string name;
};

#endif // PLAYER_H
