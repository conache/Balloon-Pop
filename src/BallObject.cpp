#include "BallObject.h"

#include "Resources.h"

#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"

#include <cstdlib>

#define BALL_SPEED 200
BallObject::BallObject (float speed)
{
	_image = Resources::LoadImage ("Assets/Images/Ball.png");
    _speed = speed;
	// This need to be deleted too
	_position = Vector2 (161803398 * rand() % ( Screen::GetWidth() - 50 ),0);
	_destination.SetX(_position.GetX());
	_destination.SetY (Screen::GetHeight () + _image->GetHeight() );
}

BallObject::~BallObject ()
{
    std::cout<<"Destroyed";
	delete _image;
}

void BallObject::Draw ()
{
	Screen::Draw (_image, _position);
}

void BallObject::Update ()
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
	}

	velocity.Normalize ();
	_position += velocity * _speed * GameTime::GetDeltaTime ();
}
