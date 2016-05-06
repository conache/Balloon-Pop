#include "Scene.h"
#include "Balloon.h"
#include "RedBalloon.h"
#include "GreenBalloon.h"
#include "YellowBalloon.h"
#include "Screen.h"
#include <algorithm>
#include <float.h>
Scene::Scene ()
{
    time_lapsed = 0;
    pause_time = 0;
	// Hardcoded construction of a new Balloon in the scene constructor
	// TODO: This need to be deleted (even as an example)
    //_objects.push_back (new Balloon (50));
	// _objects.push_back (new Balloon ());
	// _objects.push_back (new Balloon ());
	// _objects.push_back (new Balloon ());
}

Scene::~Scene ()
{
	Clear ();
}

void Scene::Update ()
{
	for (auto it : _objects) {
		it->Update ();
		Vector2 object_position = it -> get_position();
        //std::cout<<object_position.GetX()<<" "<<object_position.GetY()<<" "<<it -> get_width()<<" "<< it->get_height()<<"\n";
		if( object_position.GetY() > (Screen::GetHeight()+45) ) delete_object(it); //modify 45 here with the height of image
	}
}

void Scene::Display ()
{
	for (auto it : _objects) {
		it->Draw ();
	}
}
void Scene::Clear ()
{
	for (auto it : _objects) {
		delete it;
	}
}

void Scene::delete_object(SceneObject* object){
    _objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());
    delete object;
}

SceneObject* Scene::identify_object(float x, float y){
    for (auto it : _objects) {
        Vector2 object_position = it->get_position();
        if( ( x >= object_position.GetX() && x<= object_position.GetX() + it->get_width() ) &&
           ( y <= object_position.GetY() && y >= object_position.GetY() - it->get_height()) )
           return it;
	}
	return NULL;
}

template<class BalloonType>
void Scene::CreateBalloon(){
    BalloonType* object = new BalloonType();
    pause_time = ( object->get_height() )/ Balloon::GetSpeed();
    _objects.push_back (object);
    BalloonType::InitializeCreationTime();
}

template<class BalloonType>
bool Scene::EvaluateCreation( float deltaTime){
    BalloonType::IncreaseCreationTime( deltaTime );
    float current_time = BalloonType::GetCreationTime();
    float current_frequency = BalloonType::GetCurrentFrequency();
    float min_frequency = BalloonType::GetMinFrequency();
    if ( current_frequency >= min_frequency && current_time >= current_frequency){
        CreateBalloon<BalloonType>();
        BalloonType::DecreaseBalloonFrequency();
        return true;
    } else if ( current_time >= current_frequency ){
       CreateBalloon<BalloonType>();
        return true;
    }
    return false;
}

void Scene::SetBalloons( float deltaTime){
    time_lapsed += deltaTime;
    if (time_lapsed > pause_time && EvaluateCreation<RedBalloon>( deltaTime )) time_lapsed = 0;
    else if (time_lapsed > pause_time && EvaluateCreation<YellowBalloon>( deltaTime )) time_lapsed = 0;
    else if ( time_lapsed > pause_time && EvaluateCreation<GreenBalloon>( deltaTime )) time_lapsed = 0;
}
