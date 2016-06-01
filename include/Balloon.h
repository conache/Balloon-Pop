#ifndef Balloon_H
#define Balloon_H
#include "Image.h"
#include "SceneObject.h"
#include "Vector2.h"
#include <vector>
#include "EventArgs.h"
class Balloon : public SceneObject
{
private:
	Vector2 _destination;
	static float _speed;
    std::vector<Image*>sprite;
    bool deletable;
    Image* _image;
protected:

     bool animation;
    Vector2 _position;
public:
	Balloon (std::string image_path);
	~Balloon ();
	virtual short  getLivesInfluence()=0;
    virtual bool BonusGiver()=0;
    virtual int getNormalPoints()=0;
    virtual int getBonusPoints()=0;
    virtual void Animate(EventArgs& args)=0;
    virtual void DeleteAnimation( EventArgs& args)=0;
	virtual int get_width();
	virtual int get_height();
    virtual Vector2 get_position();
	virtual void Draw ();
	virtual void Update ();
    bool getDeletable();
    void setDeleteAnimation( bool attribute);
	float GetSpeed();
    void UpdateSprites( std::vector< std::string >newSprites);

};

#endif
