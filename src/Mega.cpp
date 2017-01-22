#include <stdio.h>
#include <curl/curl.h>

#include "Mega.h"

Mega::Mega(){
	Mega::Service_Name = "Mega";
}

int Mega::Config(){
	return 0;
}

int Mega::Download(FILE &out_file){
	return 0;
}

int Mega::Upload(FILE &in_file){
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