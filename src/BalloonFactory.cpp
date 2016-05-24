#include "BalloonFactory.h"
#include "GameTime.h"
#include "Balloon.h"
#include "CloneManager.h"
BalloonFactory::BalloonFactory(ObjectGeneratingValidator* generatingValidator)
{
    validator = generatingValidator;
    time_lapsed = pause_time = 0;
}

BalloonFactory::~BalloonFactory()
{
    delete validator;
}

Balloon* BalloonFactory::newItem(){

    float deltaTime = GameTime::GetDeltaTime();
    time_lapsed += deltaTime;
    std::string generableObjectType = validator->generable( deltaTime );
    if ( time_lapsed > pause_time && !generableObjectType.empty()){
        time_lapsed = 0;
        Balloon* object = dynamic_cast<Balloon*>( CloneManager::Instance()->getCreator(generableObjectType)() );
        pause_time = object->get_height()/ object->GetSpeed();
        return object;
    }
    return NULL;

}
