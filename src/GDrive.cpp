#include <stdio.h>
#include <curl/curl.h>

#include "GDrive.h"

GDrive::GDrive(){
	GDrive::Service_Name = "GDrive";
}

int GDrive::Config(char* config_path){
	return system("python2 py/GDriveConfig.py");
}

int GDrive::Download(char* config_path, char* to_path, FILE &out_file){
	return 0;
}

int GDrive::Upload(char* config_path, FILE &in_file){
	return 0;
}

int GDrive::Remove(char* file_name){
	return 0;
}

int GDrive::List_Files(std::vector<std::string> &file_list){
	return 0;
}

int GDrive::Space_Free(){
	return 0;
}

int GDrive::Space_Used(){
	return 0;
}