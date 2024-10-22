#include "Balloon.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

#include <cstdlib>
#include <string>
#define MAX_BALLOON_SPEED 500
float Balloon::_speed = 75;

Balloon::Balloon (std::string image_path)
{
	_image = Resources::LoadImage ( image_path );
    if ( _speed < MAX_BALLOON_SPEED ) _speed += 5;
    else _speed += 2;
	// This need to be deleted too
	_position = Vector2 (161803398 * rand() % ( Screen::GetWidth() - 50 ),0);
	_destination.SetX(_position.GetX());
	_destination.SetY (Screen::GetHeight () + _image->GetHeight() );
}

Balloon::~Balloon ()
{
	delete _image;
}

Vector2 Balloon::get_position(){
    return _position;
}
int Balloon::get_width(){
    return _image -> GetWidth();
}
int Balloon::get_height(){
    return _image->GetHeight();
}
void Balloon::Draw ()
{
	Screen::Draw (_image, _position);
}

void Balloon::Update ()
{
//	 Uncomment this to switch the controls of the ball to keyboard

//	 Vector2 velocity = Vector2::Zero;
//
//	 if (Input::GetKey ('w')) {
//	 	velocity += Vector2::Up;
//	 }
//	 if (Input::GetKey ('d')) {
//	 	velocity += Vector2::Right;
//	 }
//	 if (Input::GetKey ('s')) {
//	 	velocity += Vector2::Down;
//	 }
//	 if (Input::GetKey ('a')) {
//	 	velocity += Vector2::Left;
//	 }
//
//	 if (velocity == Vector2::Zero) {
//	 	return;
//	 }
//
//	 velocity.Normalize ();
//
//	 _position += velocity * _speed * GameTime::GetDeltaTime ();
   // std::cout<<_destination.GetX()<<" "<<_destination.GetY()<<"\n";
	Vector2 velocity = _destination - _position;
	if (velocity.SqrMagnitude () < 0.1f) {
        return;
	} else{
	velocity.Normalize ();
	_position += velocity * _speed * GameTime::GetDeltaTime ();
	}
}
float Balloon::GetSpeed(){
    return _speed;
}
