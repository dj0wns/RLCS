#include <stdio.h>
#include <curl/curl.h>

#include "Dropbox.h"

Dropbox::Dropbox(){
	Dropbox::Service_Name = "Dropbox";
}

int Dropbox::Config(char* path){
	char buffer[256];
	sprintf(buffer, "python2 py/DropboxConfig.py %s", path);
	return system(buffer);
}

int Dropbox::Download(FILE &out_file){
	return 0;
}

int Dropbox::Upload(FILE &in_file){
	return 0;
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