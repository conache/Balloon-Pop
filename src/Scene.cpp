#include "Scene.h"
#include "BallObject.h"
#include <ctime>

Scene::Scene ()
{
	// Hardcoded construction of a new BallObject in the scene constructor
	// TODO: This need to be deleted (even as an example)
	//_objects.push_back (new BallObject ());
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

