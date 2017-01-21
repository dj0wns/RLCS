#include "Crypto.h"

void GenerateKey(char key[KEY_SIZE]){
    
    if( syscall(SYS_getrandom, key, KEY_SIZE, 0) == -1){
        printf("AES Key Generation Failed!");
                   
    }          
}

void Encrypt (std::string &path, char key[KEY_SIZE]){
//	system ("ccrypt 

}
