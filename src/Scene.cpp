#include "Scene.h"
#include "BallObject.h"
#include "Screen.h"
#include <algorithm>
Scene::Scene ()
{
	// Hardcoded construction of a new BallObject in the scene constructor
	// TODO: This need to be deleted (even as an example)
    _objects.push_back (new BallObject (50));
	// _objects.push_back (new BallObject ());
	// _objects.push_back (new BallObject ());
	// _objects.push_back (new BallObject ());
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
void Scene::push_object(SceneObject* object){
    _objects.push_back (object);
}

void Scene::delete_object(SceneObject* object){

    _objects.erase(std::remove(_objects.begin(), _objects.end(), object), _objects.end());
    delete object;
}
