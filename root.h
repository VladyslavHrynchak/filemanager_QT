#pragma once
#include <vector>
#include "entity.h"
#include <string>

class Root
{
public:

	void saveDirectoty(const std::filesystem::path& path);

    void saveFile(const std::filesystem::path& path);

	void saveFolder(const std::filesystem::path& path);

    bool addFile(const std::filesystem::path& path, const std::string& name);

    bool addFolder(const std::filesystem::path& path, const std::string& name);

    bool deleteFile(const std::filesystem::path& path, const std::string& name);
	
    void copy_file_or_folder(const std::filesystem::path& path,const std::string& name);

    void rename_file_or_folder(const std::filesystem::path& path,const std::string& name,const std::string& rename);

    void move_file_or_folder(const std::filesystem::path& path);

    void paste_file_or_folder(const std::filesystem::path& path);

    size_t size_of_folder(const std::filesystem::path& path);

	void clearDirectory();

    void Sort(const std::string &sorting);

    void find_file(const std::string& name);

    std::string getBuff_str();

    std::filesystem::path getBuff_path();

    std::vector<std::filesystem::path> getSearch_directories();

    std::vector<Entity> getEntities();

private:
    bool isSearch_file(const std::string& path,const std::string& name_of_file);

    std::string buff_str;

    std::filesystem::path buff_path;

    std::vector<std::filesystem::path> search_directories;
	
    std::vector<Entity> entities;
};



