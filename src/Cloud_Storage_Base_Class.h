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

	virtual int Config(char* path = NULL);

	virtual int Download(FILE &out_file);
	virtual int Upload(FILE &in_file);
	
	virtual int Remove(char* file_name);

	virtual int List_Files(std::vector<std::string> &file_list);

	virtual int Space_Free();
	virtual int Space_Used();

};





#endif