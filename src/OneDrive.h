#ifndef ONEDRIVE_H
#define ONEDRIVE_H

#include "Cloud_Storage_Base_Class.h"

class OneDrive : public Cloud_Storage_Base_Class{

public:
	OneDrive();

	int Config(char* path = NULL);
	
	int Download(FILE &out_file);
	int Upload(FILE &in_file);
	
	int Remove(char* file_name);

	int List_Files(std::vector<std::string> &file_list);

	int Space_Free();
	int Space_Used();

};

#endif
