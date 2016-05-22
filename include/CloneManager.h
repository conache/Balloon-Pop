#ifndef CLONEMANAGER_H
#define CLONEMANAGER_H
#include <map>
#include "SceneObject.h"
class CloneManager
{

    protected:

    private:
        typedef SceneObject* (*fptr)();
        std::map< std::string, fptr>ObjectCreator;
        static CloneManager* current_manager;
        CloneManager();
        virtual ~CloneManager();
     public:
        static CloneManager* Instance();
        template< class ObjectType>
        void Add( std::string key){
            if(ObjectCreator.find(key) == ObjectCreator.end()) ObjectCreator[ key ] = []() -> SceneObject* { return new ObjectType();};
        }
        fptr getCreator( std::string key);
};

#endif // CLONEMANAGER_H
