#include "Scene.h"
#include "BalloonController.h"
#include "BalloonFactory.h"
#include "Player.h"
#include "ObjectGeneratingValidator.h"
#include "Background.h"
Scene::Scene ()
{
	// Hardcoded construction of a new Balloon in the scene constructor
	// TODO: This need to be deleted (even as an example)
    ObjectGeneratingValidator* generatingValidator = new ObjectGeneratingValidator;
    generatingValidator->Add( "RedBalloon", 4, 8);
    generatingValidator->Add( "GreenBalloon", 7, 12);
    generatingValidator->Add( "YellowBalloon", 0.7, 4);
    Player* player = new Player("TestPlayer");
    BalloonFactory* factory = new BalloonFactory( generatingValidator );
	_objects.push_back( new Background());
	_objects.push_back ( new BalloonController( factory, player) );
}

Scene::~Scene (){
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
