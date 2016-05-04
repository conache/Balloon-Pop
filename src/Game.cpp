#include "Game.h"

#if defined(__linux__) || defined(__APPLE__)
	#include <SDL2/SDL.h>
#elif defined(_WIN32)
	#include <SDL.h>
#endif

#include "GameTime.h"
#include "Input.h"
#include "Screen.h"
#include "BallObject.h"
#include  <tgmath.h>
#define FRAMES_PER_SECOND 1000
#define TIME_PER_FRAME (1000 / FRAMES_PER_SECOND)
#define TICKS_PER_FRAME (1.0 / FRAMES_PER_SECOND)

Game::Game ()
{
    _currentScene = new Scene ();
	GameTime::Init();
}

Game::~Game ()
{

}

Game* Game::Instance ()
{
	static Game instance;

	return &instance;
}

void Game::Start ()
{
	bool running=true;
    float old_time = 0, frequency = 3;
	while(running)
	{
		Screen::Clear ();

		GameTime::UpdateFrame ();
		Input::UpdateState ();

        if (Input::GetQuit () || Input::GetKeyDown (27)) {
        	running = false;
        	continue;
        }

		// if (Input::GetResizeEvent () != Vector2::Zero) {
		// 	OnWindowResize (Input::GetResizeEvent ());
		// }

		_currentScene->Update ();
        old_time += GameTime::GetDeltaTime();
		std::cout<< GameTime::GetTime()<<" "<<trunc(old_time)<<"\n";
        if (frequency>=0.7 && old_time >= frequency) {
                _currentScene -> push_object( new BallObject());
                old_time = 0;
                frequency -=0.1;
            }
        else if (old_time >= frequency){
             _currentScene -> push_object( new BallObject());
                old_time = 0;
        }
		_currentScene->Display ();

		Screen::Render ();

		if(TICKS_PER_FRAME > GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()) {
			SDL_Delay(TICKS_PER_FRAME - (GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()));
		}
	}
}
