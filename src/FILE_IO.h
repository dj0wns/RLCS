#ifndef FILE_IO_h
#define FILE_IO_h

#include <cstdlib>
#include <cstdio>

size_t readBlock(FILE *fp, char *buffer, int size);
void writeBlock(FILE *fp, char *buffer, int size);


#endif
