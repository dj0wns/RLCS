#include "FILE_IO.h"

size_t readBlock(FILE *fp, char *buffer, int size){
	return fread(buffer, sizeof(char), size, fp);
}

void writeBlock(FILE *fp, char *buffer, int size){
	fwrite(buffer, sizeof(char), size, fp);
}

