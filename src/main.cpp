#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <fuse.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <fstream>

#include "Crypto.h"
#include "FILE_IO.h"
#include "FUSE_Bindings.h"

//Cloud Services
#include "Cloud_Storage_Base_Class.h"
#include "Dropbox.h"
#include "GDrive.h"
#include "Mega.h"
#include "OneDrive.h"



#define USER_FOLDER "/.rlcs"
#define CONFIG_FILE "/config"
#define MANIFEST_FILE "/manifest"
#define DIR_FILE "/dir"

struct fuse_operations fuse_oper;
void check_user_dir(const char *user_folder_path, const char *config_file, 
		const char *manifest_file, const char *dir_file);
void config(char* config_file, std::vector<Cloud_Storage_Base_Class*> &cloud_drives);
int launch_fs(int argc, char ** argv, const char *manifest, const char *dir);

int main(int argc, char ** argv){
	char *homedir = getenv("HOME");
	char user_folder_path[256] = "";
	char config_file[256] = "";
	char manifest_file[256] = "";
	char dir_file[256] = "";
	std::vector<Cloud_Storage_Base_Class*> cloud_drives;
	cloud_drives.push_back(new Dropbox());
	//cloud_drives.push_back(GDrive());

	strcat(user_folder_path, homedir);
	strcat(user_folder_path, USER_FOLDER);
	
	strcat(config_file, user_folder_path);
	strcat(config_file, CONFIG_FILE);

	strcat(manifest_file, user_folder_path);
	strcat(manifest_file, MANIFEST_FILE);

	strcat(dir_file, user_folder_path);
	strcat(dir_file, DIR_FILE);

	check_user_dir(user_folder_path, config_file, manifest_file, dir_file);

	config(config_file, cloud_drives);
//	system ("python py/Dropbox.py");	
//	launch_fs(argc, argv, manifest_file, dir_file);
	return 0;
}

void check_user_dir(const char *user_folder_path, const char *config_file, 
		const char *manifest_file, const char *dir_file ){
	struct stat st = {0};
	if (stat(user_folder_path, &st) == -1) {
		mkdir(user_folder_path, 0700);
	}
	if (stat(config_file , &st) == -1){
		FILE *fp = fopen(config_file, "ab+");
		fclose(fp);
	}
	if (stat(manifest_file, &st) == -1){	
		FILE *fp = fopen(manifest_file, "ab+");
		fclose(fp);
	}
	if (stat(dir_file, &st) == -1){	
		std::string temp;
		std::ifstream fin (manifest_file, std::ifstream::in);
		std::ofstream fout (dir_file, std::ofstream::out);
		while(fin.good()){
			fin >> temp;
			fout << temp << std::endl;
			fin.ignore(256,'\n');
		}	
		fin.close();
		fout.close();
	
	}
}

void config(char* config_file, std::vector<Cloud_Storage_Base_Class*> &cloud_drives)
{
	for(auto cloud_drive : cloud_drives)
	{
		// TODO
	}
}

int launch_fs(int argc, char ** argv, const char *manifest){
	int i, fuse_stat;
	set_manifest(manifest);
	fuse_oper.getattr = FUSE_Bindings_getattr;
	fuse_oper.readlink = FUSE_Bindings_readlink;
	fuse_oper.getdir = NULL;
	fuse_oper.mknod = FUSE_Bindings_mknod;
	fuse_oper.mkdir = FUSE_Bindings_mkdir;
	fuse_oper.unlink = FUSE_Bindings_unlink;
	fuse_oper.rmdir = FUSE_Bindings_rmdir;
	fuse_oper.symlink = FUSE_Bindings_symlink;
	fuse_oper.rename = FUSE_Bindings_rename;
	fuse_oper.link = FUSE_Bindings_link;
	fuse_oper.chmod = FUSE_Bindings_chmod;
	fuse_oper.chown = FUSE_Bindings_chown;
	fuse_oper.truncate = FUSE_Bindings_truncate;
	fuse_oper.utime = FUSE_Bindings_utime;
	fuse_oper.open = FUSE_Bindings_open;
	fuse_oper.read = FUSE_Bindings_read;
	fuse_oper.write = FUSE_Bindings_write;
	fuse_oper.statfs = FUSE_Bindings_statfs;
	fuse_oper.flush = FUSE_Bindings_flush;
	fuse_oper.release = FUSE_Bindings_release;
	fuse_oper.fsync = FUSE_Bindings_fsync;
	fuse_oper.setxattr = FUSE_Bindings_setxattr;
	fuse_oper.getxattr = FUSE_Bindings_getxattr;
	fuse_oper.listxattr = FUSE_Bindings_listxattr;
	fuse_oper.removexattr = FUSE_Bindings_removexattr;
	fuse_oper.opendir = FUSE_Bindings_opendir;
	fuse_oper.readdir = FUSE_Bindings_readdir;
	fuse_oper.releasedir = FUSE_Bindings_releasedir;
	fuse_oper.fsyncdir = FUSE_Bindings_fsyncdir;
	fuse_oper.init = FUSE_Bindings_init;
	
	printf("mounting file system...\n");
	
	for(i = 1; i < argc && (argv[i][0] == '-'); i++) {
	        if(i == argc) {
	                return (-1);
	        }
	}
	
	//realpath(...) returns the canonicalized absolute pathname
	set_rootdir(realpath(argv[i], NULL));
	
	for(; i < argc; i++) {
	        argv[i] = argv[i+1];
	}
	argc--;
	
	fuse_stat = fuse_main(argc, argv, &fuse_oper, NULL);
	
	printf("fuse_main returned %d\n", fuse_stat);
	
	return fuse_stat;
}

