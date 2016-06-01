#ifndef GAME_H
#define GAME_H

#include "Scene.h"
#include "EventArgs.h"
class Game
{
public:
	Scene* _currentScene;

public:
	static Game* Instance ();
    void exitGame(EventArgs& args);
	void Start ();

private:
    bool running;
	Game ();
	~Game ();
	Game (const Game& other);
	Game& operator= (const Game& other);

};

#endif
