#ifndef FUSEBINDINGS_H
#define FUSEBINDINGS_H

#include <ctype.h>
#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <fuse.h>
#include <libgen.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/xattr.h>

#ifdef __cplusplus
extern "C" {
#endif

void set_rootdir(const char *path);

int FUSE_Bindings_getattr(const char *path, struct stat *statbuf);
int FUSE_Bindings_readlink(const char *path, char *link, size_t size);
int FUSE_Bindings_mknod(const char *path, mode_t mode, dev_t dev);
int FUSE_Bindings_mkdir(const char *path, mode_t mode);
int FUSE_Bindings_unlink(const char *path);
int FUSE_Bindings_rmdir(const char *path);
int FUSE_Bindings_symlink(const char *path, const char *link);
int FUSE_Bindings_rename(const char *path, const char *newpath);
int FUSE_Bindings_link(const char *path, const char *newpath);
int FUSE_Bindings_chmod(const char *path, mode_t mode);
int FUSE_Bindings_chown(const char *path, uid_t uid, gid_t gid);
int FUSE_Bindings_truncate(const char *path, off_t newSize);
int FUSE_Bindings_utime(const char *path, struct utimbuf *ubuf);
int FUSE_Bindings_open(const char *path, struct fuse_file_info *fileInfo);
int FUSE_Bindings_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo);
int FUSE_Bindings_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo);
int FUSE_Bindings_statfs(const char *path, struct statvfs *statInfo);
int FUSE_Bindings_flush(const char *path, struct fuse_file_info *fileInfo);
int FUSE_Bindings_release(const char *path, struct fuse_file_info *fileInfo);
int FUSE_Bindings_fsync(const char *path, int datasync, struct fuse_file_info *fi);
int FUSE_Bindings_setxattr(const char *path, const char *name, const char *value, size_t size, int flags);
int FUSE_Bindings_getxattr(const char *path, const char *name, char *value, size_t size);
int FUSE_Bindings_listxattr(const char *path, char *list, size_t size);
int FUSE_Bindings_removexattr(const char *path, const char *name);
int FUSE_Bindings_opendir(const char *path, struct fuse_file_info *fileInfo);
int FUSE_Bindings_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fileInfo);
int FUSE_Bindings_releasedir(const char *path, struct fuse_file_info *fileInfo);
int FUSE_Bindings_fsyncdir(const char *path, int datasync, struct fuse_file_info *fileInfo);
int FUSE_Bindings_init(struct fuse_conn_info *conn);

#ifdef __cplusplus
}
#endif

#endif //FUSE_Bindings_hh

