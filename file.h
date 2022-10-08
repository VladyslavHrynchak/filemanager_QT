#pragma once
#include "entity.h"

namespace fs = std::filesystem;


class File: public Entity
{

public:

   File() = default;

   File(const std::filesystem::path &path_,const std::string &name_,const int size_,const std::string &extension_);

};


