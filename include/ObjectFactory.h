#ifndef OBJECTFACTORY_H
#define OBJECTFACTORY_H
#include "SceneObject.h"

class ObjectFactory: public SceneObject
{
    public:
        ObjectFactory();
        virtual ~ObjectFactory();
        virtual SceneObject* newItem()=0;
    protected:

    private:
};

#endif // OBJECTFACTORY_H
