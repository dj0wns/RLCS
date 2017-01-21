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

	virtual int Config()=0;

	virtual int Download(FILE &out_file)=0;
	virtual int Upload(FILE &in_file)=0;
	
	virtual int Remove(char* file_name)=0;

	virtual int List_Files(std::vector<std::string> &file_list)=0;

	virtual int Space_Free()=0;
	virtual int Space_Used()=0;

};





#endif