#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstdio>
#include <fuse.h>

#include "Crypto.h"
#include "FILE_IO.h"
#include "FUSE_Bindings.h"

//Cloud Services
#include "Cloud_Storage_Base_Class.h"
#include "Dropbox.h"
#include "GDrive.h"
#include "Mega.h"
#include "OneDrive.h"

struct fuse_operations fuse_oper;
int launch_fs(int argc, char ** argv);

int main(int argc, char ** argv){
	
	launch_fs(argc, argv);
	return 0;
}

int launch_fs(int argc, char ** argv){
	int i, fuse_stat;
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

