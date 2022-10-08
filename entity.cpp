#include "entity.h"

using namespace std;


Entity::Entity(const std::filesystem::path &path_,const std::string &name_,const int size_):path(path_),name(name_),size(size_)
{

}

Entity::Entity(const std::filesystem::path &path_,const std::string &name_, int size_,const std::string &extension_):path(path_),name(name_),size(size_),extension(extension_)
{

}

std::filesystem::path Entity::getPath()
{
    return path;
}

std::string Entity::getName()
{
    return name;
}

int Entity::getSize()
{
    return size;
}

std::string Entity::getExtension()
{
    return extension;
}






