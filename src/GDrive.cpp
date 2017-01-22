#include <stdio.h>
#include <curl/curl.h>

#include "GDrive.h"

GDrive::GDrive(){
	GDrive::Service_Name = "GDrive";
}

int GDrive::Config(char* config_path){
	return system("python2 py/GDriveConfig.py");
}

int GDrive::Download(char* config_path, char* to_path, char* out_file){
	char buffer[256];
	sprintf(buffer, "python2 py/GDriveDownload.py %s %s %s", config_path, to_path, out_file);
	return system(buffer);
}

int GDrive::Upload(char* config_path, char* in_file){
	char buffer[256];
	sprintf(buffer, "python2 py/GDriveUpload.py %s %s", config_path, in_file);
	return system(buffer);
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