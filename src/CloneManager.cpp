#include "CloneManager.h"
#include <map>
CloneManager* CloneManager::current_manager( new CloneManager);


CloneManager::fptr CloneManager::getCreator( std::string key){
    if( ObjectCreator.find( key ) != ObjectCreator.end())
        return ObjectCreator[ key ];
    return NULL;
}
CloneManager* CloneManager::Instance(){
    return current_manager;
}

CloneManager::CloneManager()
{
    //ctor
}

CloneManager::~CloneManager()
{
    //dtor
}
