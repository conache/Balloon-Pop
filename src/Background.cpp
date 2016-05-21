#include "Background.h"
#include "Resources.h"
#include "Screen.h"
Background::Background()
{
    _image = Resources::LoadImage ( "Assets/Images/background.png" );
    _position =Vector2(0,Screen::GetHeight());
}
void Background::Draw(){
    Screen::Draw (_image, _position);
}

Background::~Background()
{
    delete _image;
}

