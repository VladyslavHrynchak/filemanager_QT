#include <filesystem> 
#include "root.h"
#include "file.h"
#include "folder.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <thread>
#include <mutex>
#include <queue>
#include <atomic>

namespace fs = std::filesystem;

using namespace std;

void Root::clearDirectory()
{
    entities.clear();
}

void Root::addFile(const std::filesystem::path& path, const string& name)
{
    if(!name.empty())
    {
        std::filesystem::path newpath = path;
        newpath /= name;
        fs::create_directories(newpath.parent_path());
        std::ofstream ofs(newpath);
        ofs << " ";
        ofs.close();
        saveFile(newpath);
    }
}

void Root::addFolder(const std::filesystem::path& path ,const string& name)
{

	std::filesystem::path newpath = path;
    newpath /= name;
	fs::create_directories(newpath);
	saveFolder(newpath);

}

void Root::saveDirectoty(const std::filesystem::path& path)
{

    for (const auto& entry : fs::directory_iterator(path))
	{
		if (fs::is_regular_file(entry))
		{
			File newfile;
			newfile.path = entry.path();
            newfile.name = entry.path().filename();
            newfile.size = fs::file_size(entry.path());
            newfile.extension = entry.path().extension();
            entities.push_back(newfile);
		}
		else
		{
			Folder newfolder;
			newfolder.path = entry.path();
            newfolder.name = entry.path().filename();
            newfolder.size = size_of_folder(entry.path());
            entities.push_back(newfolder);
		}

	}

}

void Root::saveFile(const std::filesystem::path& path)
{

	File newfile;
	newfile.path = path;
    newfile.name = path.filename();
	newfile.size = fs::file_size(path);
    newfile.extension = path.extension();
    entities.push_back(newfile);
}


void Root::saveFolder(const std::filesystem::path& path)
{

	Folder newfolder;
	newfolder.path = path;
    newfolder.name = path.filename();
    newfolder.size = size_of_folder(path);
    entities.push_back(newfolder);

}


void Root::deleteFile(const std::filesystem::path& path, const string& name)
{

	bool isAddPath = false;
    int index_to_delete = 0;
	while (!isAddPath)
	{
		try
		{
			std::filesystem::path newpath = path;
            newpath /= name;
			if (!fs::exists(newpath))
			{
                return;
			}
            for (size_t i = 0; i < entities.size(); i++)
			{
                if (entities[i].path == newpath)
				{
                    entities[i].path = " ";
                    entities[i].name = " ";
                    entities[i].size = 0;
                    entities[i].extension = " ";
                    index_to_delete = i;
				}
			}
            entities.erase( entities.begin() +  index_to_delete);
			fs::remove(newpath);
            isAddPath = true;
            saveDirectoty(path);
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

}

void Root::copy_file_or_folder(const std::filesystem::path& path,const string& name)
{
	bool isAddPath = false;
	while (!isAddPath)
	{
		try
		{			
		    std::filesystem::path curr_path = path;

            curr_path /= name;
			if (!fs::exists(curr_path))
			{
                throw std::logic_error("You enter wrong name");
			}
            buff_path = curr_path.c_str();
            buff_str = name;

			isAddPath = true;
		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << endl;
		}
	}
}
void Root::paste_file_or_folder(const std::filesystem::path& path)
{

    std::filesystem::path curr_path = path;
    curr_path /= buff_str;
    fs::copy(buff_path, curr_path, fs::copy_options::overwrite_existing);
    saveDirectoty(path);

}

void Root::rename_file_or_folder(const std::filesystem::path& path,const string& name,const string& rename)
{

    try
    {
        std::filesystem::path curr_path = path;
        std::filesystem::path newpath = path;
        curr_path /= name;
        if (!fs::exists(curr_path))
        {
            throw std::logic_error("You enter wrong name");
            return;
        }
            newpath /= rename;
            fs::rename(curr_path, newpath);
            entities.clear();
            saveDirectoty(path);
        }
    catch (const std::exception& ex)
    {
        cout << ex.what() << endl;
    }

}

void Root::move_file_or_folder(const std::filesystem::path& path)
{

    std::filesystem::path curr_path = path;
    curr_path /= buff_str;
    fs::copy(buff_path, curr_path, fs::copy_options::overwrite_existing);
    saveDirectoty(path);

}

int Root::size_of_folder(const std::filesystem::path& path)
{
    int size = 0;

    for (const auto& entry : fs::directory_iterator(path))
    {
        if (fs::is_regular_file(entry))
        {
           size += entry.file_size();
        }

    }
    return size;
}

void Root::sort_by_name()
{

    sort(entities.begin(),entities.end(),[](const Entity &first,const Entity &second)
    {
        return (first.name < second.name);
    });

}

void Root::sort_by_size()
{

    sort(entities.begin(),entities.end(),[](const Entity &first,const Entity &second)
    {
        return (first.size < second.size);
    });

}

bool Root::search_file(const string& path,const string& name_of_file)
{
   for (const auto& entry : fs::recursive_directory_iterator(path,filesystem::directory_options::skip_permission_denied))
   {
        if (entry.path().filename().string() == name_of_file)
        {
            search_directories.push_back(entry.path());
            return true;
        }
    }
    return false;
}

void Root::find_file(const std::string& name)
{
    search_directories.clear();
    const string rootPath = "/home";
    const uint maxThreads = 8;

    atomic_bool stop = false;
    vector<thread> threads;

    queue<string> subdirs;
    mutex m;

    for (const auto& entry : fs::directory_iterator(rootPath))
    {
        if(entry.is_directory())
        {
            subdirs.push(entry.path().string());
        }
    }

    threads.reserve(maxThreads);
    for (int i = 0; i < maxThreads; ++i)
    {
       threads.push_back(thread([&]()
       {
          while(true)
          {

             if(stop)
               return;

             string path;
             m.lock();
             if(!subdirs.empty())
             {
                path = subdirs.front();
                subdirs.pop();
             }
             else
             {
                m.unlock();
                return;
             }
             m.unlock();

             if(search_file(path,name))
                stop = true;
          }
        }));
    }

    for (auto &t : threads)
        t.join();
}





