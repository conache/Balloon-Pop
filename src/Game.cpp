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
Game::Game ()
{
    _currentScene = new Scene ();
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
	bool game_over = false;
	while(running){
		Screen::Clear ();
		GameTime::UpdateFrame ();
		Input::UpdateState ();
        if (Input::GetQuit () || Input::GetKeyDown (27)) {
        	running = false;
        	continue;
        } else if ( !Player::GetLives() ) game_over = true; // when the player is dead

       // if ( !game_over ){

        if ( Input::GetMouseButtonDown(1) ){
            float mouse_X = Input::GetMousePosition().GetX();
            float mouse_Y = Input::GetMousePosition().GetY();
            SceneObject* matching_object = _currentScene -> identify_object( mouse_X, mouse_Y);
            if ( matching_object ) _currentScene -> delete_object( matching_object );
            }
		// if (Input::GetResizeEvent () != Vector2::Zero) {
		// 	OnWindowResize (Input::GetResizeEvent ());
		// }
		if( Player::BonusMode() )
                if ( Player::BonusTime() > 0 )
                        Player::DecreaseBonusTime( GameTime::GetDeltaTime() );
                else Player::DisableBonusMode();
        else;
		_currentScene->Update ();
		_currentScene -> SetBalloons( GameTime::GetDeltaTime() );
		_currentScene->Display ();
		Screen::Render ();

		if(TICKS_PER_FRAME > GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()) {
			SDL_Delay(TICKS_PER_FRAME - (GameTime::GetElapsedTimeMS () - GameTime::GetTimeMS ()));
		}
	}
}
