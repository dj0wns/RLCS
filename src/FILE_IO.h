#ifndef FILE_IO_h
#define FILE_IO_h

#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <stdlib.h>
#include <cstring>
#include <thread>

#include "Globals.h"
#include "Crypto.h"
#include "Cloud_Storage_Base_Class.h"

#define BLOCK_SIZE 4

size_t readBlock(FILE *fp, char *buffer, int size);
void writeBlock(FILE *fp, char *buffer, int size);

void split_file(const char *path, const char *manifest,const  char *name, 
		FILE *fp, std::vector<Cloud_Storage_Base_Class*> &cloud_drives);

void combine_file(const char *path, FILE *fp,
 	std::vector<Cloud_Storage_Base_Class*> &cloud_drives,
	std::vector<std::string> &in_files);

#endif
