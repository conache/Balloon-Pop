#ifndef BALLOONFACTORY_H
#define BALLOONFACTORY_H
#include "ObjectFactory.h"
#include "Balloon.h"
#include "ObjectGeneratingValidator.h"
class BalloonFactory:public ObjectFactory
{
    public:
        BalloonFactory( ObjectGeneratingValidator* generatingValidator);
        virtual ~BalloonFactory();
        Balloon* newItem();
    protected:

    private:
        float pause_time, time_lapsed;
        ObjectGeneratingValidator* validator;
};

#endif // BALLOONFACTORY_H
