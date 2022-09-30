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
            paths.push(path);
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
