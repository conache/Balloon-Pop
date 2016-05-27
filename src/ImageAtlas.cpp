#include "ImageAtlas.h"
#include "dirent.h"
#include "iostream"
ImageAtlas* ImageAtlas::_instance( new ImageAtlas);
ImageAtlas::ImageAtlas(){
    //ctor
}

ImageAtlas* ImageAtlas::Instance(){
    return _instance;
}
void ImageAtlas::directoryPhotos( std::vector<std::string>& photos, char* path ){
    DIR *directory;
    struct dirent *current_file;
    directory = opendir(path);
    if( directory ){
        current_file = readdir( directory );
        while ( current_file != NULL) {
            std::string file_name = (std::string)current_file->d_name;
            if ( file_name.find(".png") != std::string::npos) photos.push_back( path+file_name );
            current_file = readdir( directory );
            }
        closedir (directory);

    } else{
        //couldn't open directory
    }
}

void ImageAtlas::Add( std::string animation_name, char* path){
    if( atlas[ animation_name ].empty() ){
        directoryPhotos( atlas[ animation_name ], path );
    }
}

std::vector< std::string > ImageAtlas::getStripes( std::string animation_name ){
    return atlas[ animation_name ];
}
ImageAtlas::~ImageAtlas()
{
    //dtor
}
