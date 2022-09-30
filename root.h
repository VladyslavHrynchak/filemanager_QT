#ifndef ROOT_H
#define ROOT_H
#include <vector>
#include "entity.h"
#include <string>

struct Root
{
public:

	void saveDirectoty(const std::filesystem::path& path);

    void saveFile(const std::filesystem::path& path);

	void saveFolder(const std::filesystem::path& path);

    void addFile(const std::filesystem::path& path, const std::string& name);

    void addFolder(const std::filesystem::path& path, const std::string& name);

    void deleteFile(const std::filesystem::path& path, const std::string& name);
	
    void copy_file_or_folder(const std::filesystem::path& path,const std::string& name);

    void rename_file_or_folder(const std::filesystem::path& path,const std::string& name,const std::string& rename);

    void move_file_or_folder(const std::filesystem::path& path);

    void paste_file_or_folder(const std::filesystem::path& path);

    int size_of_folder(const std::filesystem::path& path);

	void clearDirectory();

    void sort_by_name();

    void sort_by_size();

    std::string buff_str;

    std::filesystem::path buff_path;

	std::vector<Entity*> search_file_or_folder(const std::string& name_of_file);
	
    std::vector<Entity> entities;
};

#endif


