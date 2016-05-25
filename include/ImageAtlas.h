#ifndef IMAGEATLAS_H
#define IMAGEATLAS_H
#include <map>
#include <vector>

class ImageAtlas
{
    public:
        static ImageAtlas* Instance();
        void Add(std::string animation_name, char* path);
    protected:

    private:
        static ImageAtlas* _instance;
        std::map< std::string, std::vector<std::string> > atlas;
        void directoryPhotos( std::vector< std::string>& photos, char* path);
        std::vector< std::string> getStripes( std::string animation_name);
        ImageAtlas();
        virtual ~ImageAtlas();
};

#endif // IMAGEATLAS_H
