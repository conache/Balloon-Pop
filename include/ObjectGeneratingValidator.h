#ifndef OBJECTGENERATINGVALIDATOR_H
#define OBJECTGENERATINGVALIDATOR_H
#include <map>
#include <cstring>

class ObjectGeneratingValidator
{
    public:
        ObjectGeneratingValidator();
        virtual ~ObjectGeneratingValidator();
        void Add( std::string class_name, float min_frequency, float current_frequency);
        std::string generable( float deltaTime );
    protected:

    private:
        std::map< std::string, float> CreationTime, MinFrequency, CurrentFrequency;
        void increase_object_types_creationTime( float deltaTime );
        void decrease_object_type_frequency( std::string key, float value);
        std::string GetGenerableKey( std::map< std::string, float>CreationTime);
};

#endif // OBJECTGENERATINGVALIDATOR_H
