#include "Cloud_Storage_Base_Class.h"

int Cloud_Storage_Base_Class::Config(char* config_path){
	return 0;
}

int Cloud_Storage_Base_Class::Download(char* config_path, char* to_path, FILE &out_file){
	return 0;
}
int Cloud_Storage_Base_Class::Upload(char* config_path, FILE &in_file){
	return 0;
}
	
int Cloud_Storage_Base_Class::Remove(char* file_name){
	return 0;
}

int Cloud_Storage_Base_Class::List_Files(std::vector<std::string> &file_list){
	return 0;
}

int Cloud_Storage_Base_Class::Space_Free(){
	return 0;
}
int Cloud_Storage_Base_Class::Space_Used(){
	return 0;
}