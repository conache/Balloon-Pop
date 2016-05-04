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
    float old_time = 0, min_frequency = 0.5, current_frequency = 3, current_speed = 75, max_speed = 500;
	while(running){

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
		create_objects(old_time, current_frequency, current_speed, _currentScene, min_frequency, max_speed);
		_currentScene->Display ();

		Screen::Render ();

		if(TICKS_PER_FRAME > GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()) {
			SDL_Delay(TICKS_PER_FRAME - (GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()));
		}
	}
}

void Game::create_objects(float& old_time, float& current_frequency, float& current_speed, Scene* _currentScene,float min_frequency,float max_speed){
    old_time += GameTime::GetDeltaTime();
    if ( current_frequency >= min_frequency && old_time >= current_frequency) {
        _currentScene -> push_object( new BallObject(current_speed));
        old_time = 0;
        current_frequency -= 0.1;
        if( current_speed <= max_speed ) current_speed += 5;
    } else if (old_time >= current_frequency){
        _currentScene -> push_object( new BallObject( current_speed ));
        old_time = 0;
        current_speed +=2;
    }
}
