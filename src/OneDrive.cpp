#include <stdio.h>
#include <curl/curl.h>

#include "OneDrive.h"

OneDrive::OneDrive()
{
	OneDrive::Service_Name = "OneDrive";
}

int OneDrive::Download(FILE &out_file)
{
	return 0;
}

int OneDrive::Upload(FILE &in_file)
{
	return 0;
}

int OneDrive::Remove(char* file_name)
{
	return 0;
}

int OneDrive::List_Files(std::vector<std::string> &file_list)
{
	return 0;
}

int OneDrive::Space_Free()
{
	return 0;
}

int OneDrive::Space_Used()
{
	return 0;
}