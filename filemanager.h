#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <filesystem> 
#include <stack>
#include "root.h"

using namespace std;

namespace fs = std::filesystem;

struct FileManager
{

	FileManager();

    Root directory;

    stack<std::filesystem::path> paths;

    std::filesystem::path path = "/home";

	void go_the_other_path();

    void go_the_other_path(const string& next_dir);

};
#endif
