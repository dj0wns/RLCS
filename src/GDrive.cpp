#include <stdio.h>
#include <curl/curl.h>

#include "GDrive.h"

GDrive::GDrive()
{
	GDrive::Service_Name = "GDrive";
}

int GDrive::Config()
{
	return 0;
}

int GDrive::Download(FILE &out_file)
{
	return 0;
}

int GDrive::Upload(FILE &in_file)
{
	return 0;
}

int GDrive::Remove(char* file_name)
{
	return 0;
}

int GDrive::List_Files(std::vector<std::string> &file_list)
{
	return 0;
}

int GDrive::Space_Free()
{
	return 0;
}

int GDrive::Space_Used()
{
	return 0;
}