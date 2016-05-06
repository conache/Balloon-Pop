#ifndef SCENE_H
#define SCENE_H

#include <vector>

#include "SceneObject.h"
class Scene
{
private:
	std::vector<SceneObject*> _objects;
    template<class BalloonType> bool EvaluateCreation ( float deltaTime);
    template<class BalloonType> void CreateBalloon();
    float pause_time;
    float time_lapsed;
public:
	Scene ();
	~Scene ();
	void Update ();
	void Display ();
	void Clear ();
	void delete_object(SceneObject* object);
	void SetBalloons( float deltaTime);
	SceneObject* identify_object( float x, float y);
};

#endif
