#pragma once
#include "entity.h"

class Folder:public Entity
{
public:

    Folder() = default;

    Folder(const std::filesystem::path &path_,const std::string &name_,const int size_);

};


