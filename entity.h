#pragma once
#include <filesystem>

namespace fs = std::filesystem;

class Entity
{

public:
    Entity() = default;

    Entity(const std::filesystem::path &path_,const std::string &name_,const int size_);

    Entity(const std::filesystem::path &path_,const std::string &name_,const int size_,const std::string &extension_);

    std::filesystem::path getPath();

    std::string getName();

    int getSize();

    std::string getExtension();


protected:

    std::filesystem::path path;

    std::string name;

    int size;

    std::string extension;
};

