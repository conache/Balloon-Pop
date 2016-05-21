#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "SceneObject.h"
#include "Vector2.h"
 #include "Image.h"
class Background: public SceneObject
{
    public:
        Background();
        virtual ~Background();
        void Draw();
    protected:

    private:
        Vector2 _position;
        Image* _image;

};

#endif // BACKGROUND_H
