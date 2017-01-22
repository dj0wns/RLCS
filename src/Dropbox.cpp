#include <stdio.h>
#include <curl/curl.h>

#include "Dropbox.h"

Dropbox::Dropbox(){
	Dropbox::Service_Name = "Dropbox";
}

int Dropbox::Config(char* config_path){
	char buffer[256];
	sprintf(buffer, "python2 py/DropboxConfig.py %s", config_path);
	return system(buffer);
}

int Dropbox::Download(char* config_path, char* to_path, char* out_file){
	char buffer[256];
	sprintf(buffer, "python2 py/DropboxDownload.py %s %s out_file", config_path, to_path);
	return system(buffer);
}

int Dropbox::Upload(char* config_path, char* in_file){
	char buffer[256];
	sprintf(buffer, "python2 py/DropboxUpload.py %s in_file", config_path);
	return system(buffer);
}

int Dropbox::Remove(char* file_name){
	return 0;
}

int Dropbox::List_Files(std::vector<std::string> &file_list){
	return 0;
}

int Dropbox::Space_Free(){
	return 0;
}

int Dropbox::Space_Used(){
	return 0;
}