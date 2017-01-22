#include <stdio.h>
#include <curl/curl.h>

#include "OneDrive.h"

OneDrive::OneDrive(){
	OneDrive::Service_Name = "OneDrive";
}

int OneDrive::Config(char* config_path){
	return 0;
}

int OneDrive::Download(char* config_path, char* to_path, char* out_file){
	return 0;
}

int OneDrive::Upload(char* config_path, char* in_file){
	return 0;
}

int OneDrive::Remove(char* file_name){
	return 0;
}

int OneDrive::List_Files(std::vector<std::string> &file_list){
	return 0;
}

int OneDrive::Space_Free(){
	return 0;
}

int OneDrive::Space_Used(){
	return 0;
}