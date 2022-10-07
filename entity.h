#pragma once
#include <filesystem>

namespace fs = std::filesystem;

struct Entity
{
    std::filesystem::path path;

	std::string name;

	int size;

    std::string extension;
};

