#include "ObjectGeneratingValidator.h"
#include "iostream"
ObjectGeneratingValidator::ObjectGeneratingValidator()
{
    //ctor
}

ObjectGeneratingValidator::~ObjectGeneratingValidator()
{
    //dtor
}

void ObjectGeneratingValidator::Add( std::string class_name, float min_frequency, float current_frequency){
    CreationTime[ class_name ] = 0;
    MinFrequency[ class_name ] = min_frequency;
    CurrentFrequency[ class_name ] = current_frequency;
}

std::string ObjectGeneratingValidator::generable( float deltaTime ){
    increase_object_types_creationTime( deltaTime );
    std::string generable_key = GetGenerableKey( CreationTime );
    if( !generable_key.empty() ) {
        if ( CurrentFrequency[ generable_key ] > MinFrequency[ generable_key ] ) decrease_object_type_frequency( generable_key, 0.1);
        if( CreationTime[ generable_key ] >= CurrentFrequency[ generable_key ] ){
            CreationTime[ generable_key ] = 0;
        }
    }
    return generable_key;
}

void ObjectGeneratingValidator::increase_object_types_creationTime(float deltaTime ){
    for( std::map< std::string, float>::iterator it = CreationTime.begin(); it != CreationTime.end(); ++it )
        CreationTime[ it->first ] += deltaTime;
}

void ObjectGeneratingValidator::decrease_object_type_frequency( std::string key, float value){
    if( CurrentFrequency[ key ] > MinFrequency[ key ] ) CurrentFrequency [ key ] -= value;
}

std::string ObjectGeneratingValidator::GetGenerableKey( std::map< std::string, float> CreationTime){
    float current_max = 0;
    std::string max_key="";
    for( std::map< std::string, float>::iterator it = CreationTime.begin(); it != CreationTime.end(); ++it )
        if (CreationTime[ it->first ] >= CurrentFrequency[ it->first ] && it->second > current_max ){
                max_key = it->first;
                current_max = it->second;
        }
    return max_key;
}
