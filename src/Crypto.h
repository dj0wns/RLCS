#ifndef CRYPTO_H
#define CRYPTO_H

#define KEY_SIZE 32 //(256/8)

#include <unistd.h>
#include <sys/syscall.h>
#include <string>
#include <linux/random.h>
#include <cstdio>

void GenerateKey(char key[KEY_SIZE]);

void Encrypt(std::string &infile, char key[KEY_SIZE]);

void Decrypt(std::string &infile, char key[KEY_SIZE]);

#endif
