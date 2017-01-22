#ifndef DROPBOX_H
#define DROPBOX_H

#include "Cloud_Storage_Base_Class.h"

class Dropbox : public Cloud_Storage_Base_Class{

public:
	Dropbox();

	int Config(char* config_path = NULL);

	int Download(char* config_path, char* to_path, FILE &out_file);
	int Upload(char* config_path, FILE &in_file);
	
	int Remove(char* file_name);

	int List_Files(std::vector<std::string> &file_list);

	int Space_Free();
	int Space_Used();

};

#endif
