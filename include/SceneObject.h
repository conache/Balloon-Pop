#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Object.h"
#include "Vector2.h"
class SceneObject : public Object
{
public:
	SceneObject ();
	virtual ~SceneObject ();
	virtual Vector2 get_position();
	virtual void Update ();
	virtual void Draw ();
};

#endif
