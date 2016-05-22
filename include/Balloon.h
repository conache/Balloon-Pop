#ifndef Balloon_H
#define Balloon_H
#include "Image.h"
#include "SceneObject.h"
#include "Vector2.h"
class Balloon : public SceneObject
{
private:
	Image* _image;
	Vector2 _destination;
	static float _speed;
protected:
    Vector2 _position;
public:
	Balloon (std::string image_path);
	~Balloon ();
	virtual int get_width();
	virtual int get_height();
    virtual Vector2 get_position();
	virtual void Draw ();
	virtual void Update ();
	float GetSpeed();
};

#endif
