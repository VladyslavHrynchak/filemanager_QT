#include "filemanager.h"
#include <iostream>

using namespace std;

FileManager::FileManager()
{
    directory.saveDirectoty(path);
}

void FileManager::go_the_other_path()
{
    bool isAddPath = false;
    while (!isAddPath)
    {
        try
        {
            directory.clearDirectory();
            directory.saveDirectoty(path);
            isAddPath = true;
        }
        catch (const std::exception& ex)
        {
            return;
        }
    }

}

void FileManager::go_the_other_path(const string& next_dir)
{
    bool isAddPath = false;
    while (!isAddPath)
    {
        try
        {
            paths_for_button_back.push(path);
            path /= next_dir;
            directory.clearDirectory();

            directory.saveDirectoty(path);

            isAddPath = true;
        }
        catch (const std::exception& ex)
        {
            return;
        }
    }

}

stack<std::filesystem::path> FileManager::getPaths_for_button_back()
{
    return paths_for_button_back;
}




