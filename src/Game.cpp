#include "Game.h"

#if defined(__linux__) || defined(__APPLE__)
	#include <SDL2/SDL.h>
#elif defined(_WIN32)
	#include <SDL.h>
#endif

#include "GameTime.h"
#include "Input.h"
#include "Screen.h"
#include "Player.h"
#include  <tgmath.h>
#define FRAMES_PER_SECOND 1000
#define TIME_PER_FRAME (1000 / FRAMES_PER_SECOND)
#define TICKS_PER_FRAME (1.0 / FRAMES_PER_SECOND)
#include <string>
#include "CloneManager.h"
#include "GreenBalloon.h"
#include "RedBalloon.h"
#include "YellowBalloon.h"
#include "ImageAtlas.h"
Game::Game ()
{
    _currentScene = new Scene ();
    CloneManager::Instance()->Add<GreenBalloon>("GreenBalloon");
    CloneManager::Instance()->Add<RedBalloon>("RedBalloon");
    CloneManager::Instance()->Add<YellowBalloon>("YellowBalloon");
    ImageAtlas::Instance()->Add("RedBalloonDestroy","c:\\Users\\Cristian\\Desktop\\game graphics\\RedBalloon\\");
}

Game::~Game ()
{

}

Game* Game::Instance (){

	static Game instance;

	return &instance;
}

void Game::Start ()
{
	bool running=true;
	while(running){
		Screen::Clear ();
		GameTime::UpdateFrame ();
		Input::UpdateState ();
        if (Input::GetQuit () || Input::GetKeyDown (27)) {
        	running = false;
        	continue;
        }
		_currentScene->Update();
		_currentScene->Display();
		Screen::Render();
		if(TICKS_PER_FRAME > GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()) {
			SDL_Delay(TICKS_PER_FRAME - (GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()));
		}
	}
}
