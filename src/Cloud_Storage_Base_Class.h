#ifndef CLOUDSTORAGEBASECLASS_H
#define CLOUDSTORAGEBASECLASS_H

#include <vector>
#include <cstdio>
#include <string>

class Cloud_Storage_Base_Class{

public:

	std::string OAuth_Key;
	std::string Service_Name;

	Cloud_Storage_Base_Class(): OAuth_Key(""){};

	virtual int Config(char* config_path = NULL);

	virtual int Download(const char* config_path,const  char* to_path, const char* out_file);
	virtual int Upload(const char* config_path, const char* in_file);
	
	virtual int Remove(char* file_name);

	virtual int List_Files(std::vector<std::string> &file_list);

	virtual int Space_Free();
	virtual int Space_Used();

};





#endif
