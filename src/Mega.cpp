#include <stdio.h>
#include <curl/curl.h>

#include "Mega.h"

Mega::Mega(){
	Mega::Service_Name = "Mega";
}

int Mega::Config(char* config_path){
	return 0;
}

int Mega::Download(char* config_path, char* to_path, FILE &out_file){
	return 0;
}

int Mega::Upload(char* config_path, FILE &in_file){
	return 0;
}

int Mega::Remove(char* file_name){
	return 0;
}

int Mega::List_Files(std::vector<std::string> &file_list){
	return 0;
}

int Mega::Space_Free(){
	return 0;
}

int Mega::Space_Used(){
	return 0;
}