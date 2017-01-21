#ifndef CLOUDSTORAGEBASECLASS_H
#define CLOUDSTORAGEBASECLASS_H


class Cloud_Storage_Base_Class{

	virtual int Download(FILE &out_file);
	virtual int Upload(FILE &in_file);
	
	virtual int Remove(char* file_name);

	virtual int List_Files(std::vector<std::string> &file_list);

	virtual int Space_Free();
	virtual int Space_Used();

};





#endif