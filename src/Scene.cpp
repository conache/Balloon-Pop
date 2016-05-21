#include "Scene.h"
#include "BalloonController.h"
#include "Background.h"
Scene::Scene ()
{
	// Hardcoded construction of a new Balloon in the scene constructor
	// TODO: This need to be deleted (even as an example)
	_objects.push_back( new Background());
	_objects.push_back (new BalloonController());
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
