#pragma once
#include <filesystem> 
#include <stack>
#include "root.h"

using namespace std;

namespace fs = std::filesystem;

class FileManager
{

public:

    FileManager();

    void go_the_other_path();

    void go_the_other_path(const string& next_dir);

    stack<std::filesystem::path> getPaths_for_button_back();

    Root directory;

    std::filesystem::path path = "/home";

private:

    stack<std::filesystem::path> paths_for_button_back;

};

