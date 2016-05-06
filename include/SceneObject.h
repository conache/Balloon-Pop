#ifndef SCENEOBJECT_H
#define SCENEOBJECT_H

#include "Object.h"
#include "Vector2.h"
class SceneObject : public Object
{
public:
	SceneObject ();
	virtual ~SceneObject ();
	virtual int get_width();
	virtual int get_height();
	virtual Vector2 get_position();
	virtual void Update ();
	virtual void Draw ();
};

#endif
