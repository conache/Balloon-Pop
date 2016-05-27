#include "Balloon.h"
#include "Resources.h"
#include "Screen.h"
#include "Input.h"
#include "GameTime.h"
#include "Vector2.h"
#include <cstdlib>
#define MAX_BALLOON_SPEED 500
#include "iostream"
float Balloon::_speed = 60;
Balloon::Balloon(std::string image_path)
{
    delete_animation = false;
    deletable = false;
	_image = Resources::LoadImage ( image_path );
	sprite.push_back( _image );
    if ( _speed < MAX_BALLOON_SPEED ) _speed += 3;
    else _speed += 1;
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
	Screen::Draw ( sprite.front() , _position);

}

void Balloon::Update (){


	Vector2 velocity = _destination - _position;
	if (velocity.SqrMagnitude () < 0.1f) {
        return;
	} else{
	velocity.Normalize ();
	_position += velocity * _speed * GameTime::GetDeltaTime ();
	}
/*
      if( delete_animation ) {
            _position.SetX( _position.GetX() - 10);
            _position.SetY( _position.GetY() + 5);
    }
*/
	if ( sprite.size() > 1 ) sprite.erase( sprite.begin() );
    else if( delete_animation && sprite.size() == 1 ){
            sprite.erase( sprite.begin());
            deletable = true;
            delete_animation = false;
    }

}

float Balloon::GetSpeed(){
    return _speed;
}
void Balloon::UpdateSprites(std::vector<std::string> newSprites){
    std::vector< Image* > new_image;
    for(int i=0; i< newSprites.size(); i++) {
            sprite.push_back( Resources::LoadImage ( (std::string)newSprites[i]) );
    }
  //  for(int i=0; i<sprite.size(); i++) std::cout<<sprite[i]<<std::endl;
}

bool Balloon::getDeletable(){
    return deletable;
}

void Balloon::setDeleteAnimation( bool attribute ){
    delete_animation = attribute;
}
