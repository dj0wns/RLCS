#include "FUSE_Bindings.h"
#include "FUSE_Definitions.h"

void set_rootdir(const char *path) {
	FUSE_Definitions::Instance()->setRootDir(path);
}

void set_manifest(const char *path) {
	FUSE_Definitions::Instance()->setManifest(path);
}

int FUSE_Bindings_getattr(const char *path, struct stat *statbuf) {
	return FUSE_Definitions::Instance()->Getattr(path, statbuf);
}

int FUSE_Bindings_readlink(const char *path, char *link, size_t size) {
	return FUSE_Definitions::Instance()->Readlink(path, link, size);
}

int FUSE_Bindings_mknod(const char *path, mode_t mode, dev_t dev) {
	return FUSE_Definitions::Instance()->Mknod(path, mode, dev);
}
int FUSE_Bindings_mkdir(const char *path, mode_t mode) {
	return FUSE_Definitions::Instance()->Mkdir(path, mode);
}
int FUSE_Bindings_unlink(const char *path) {
	return FUSE_Definitions::Instance()->Unlink(path);
}
int FUSE_Bindings_rmdir(const char *path) {
	return FUSE_Definitions::Instance()->Rmdir(path);
}
int FUSE_Bindings_symlink(const char *path, const char *link) {
	return FUSE_Definitions::Instance()->Symlink(path, link);
}
int FUSE_Bindings_rename(const char *path, const char *newpath) {
	return FUSE_Definitions::Instance()->Rename(path, newpath);
}
int FUSE_Bindings_link(const char *path, const char *newpath) {
	return FUSE_Definitions::Instance()->Link(path, newpath);
}
int FUSE_Bindings_chmod(const char *path, mode_t mode) {
	return FUSE_Definitions::Instance()->Chmod(path, mode);
}
int FUSE_Bindings_chown(const char *path, uid_t uid, gid_t gid) {
	return FUSE_Definitions::Instance()->Chown(path, uid, gid);
}
int FUSE_Bindings_truncate(const char *path, off_t newSize) {
	return FUSE_Definitions::Instance()->Truncate(path, newSize);
}
int FUSE_Bindings_utime(const char *path, struct utimbuf *ubuf) {
	return FUSE_Definitions::Instance()->Utime(path, ubuf);
}
int FUSE_Bindings_open(const char *path, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Open(path, fileInfo);
}
int FUSE_Bindings_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Read(path, buf, size, offset, fileInfo);
}
int FUSE_Bindings_write(const char *path, const char *buf, size_t size, off_t offset, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Write(path, buf, size, offset, fileInfo);
}
int FUSE_Bindings_statfs(const char *path, struct statvfs *statInfo) {
	return FUSE_Definitions::Instance()->Statfs(path, statInfo);
}
int FUSE_Bindings_flush(const char *path, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Flush(path, fileInfo);
}
int FUSE_Bindings_release(const char *path, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Release(path, fileInfo);
}
int FUSE_Bindings_fsync(const char *path, int datasync, struct fuse_file_info *fi) {
	return FUSE_Definitions::Instance()->Fsync(path, datasync, fi);
}
int FUSE_Bindings_setxattr(const char *path, const char *name, const char *value, size_t size, int flags) {
	return FUSE_Definitions::Instance()->Setxattr(path, name, value, size, flags);
}
int FUSE_Bindings_getxattr(const char *path, const char *name, char *value, size_t size) {
	return FUSE_Definitions::Instance()->Getxattr(path, name, value, size);
}
int FUSE_Bindings_listxattr(const char *path, char *list, size_t size) {
	return FUSE_Definitions::Instance()->Listxattr(path, list, size);
}
int FUSE_Bindings_removexattr(const char *path, const char *name) {
	return FUSE_Definitions::Instance()->Removexattr(path, name);
}
int FUSE_Bindings_opendir(const char *path, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Opendir(path, fileInfo);
}
int FUSE_Bindings_readdir(const char *path, void *buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Readdir(path, buf, filler, offset, fileInfo);
}
int FUSE_Bindings_releasedir(const char *path, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Releasedir(path, fileInfo);
}
int FUSE_Bindings_fsyncdir(const char *path, int datasync, struct fuse_file_info *fileInfo) {
	return FUSE_Definitions::Instance()->Fsyncdir(path, datasync, fileInfo);
}
void* FUSE_Bindings_init(struct fuse_conn_info *conn) {
	return FUSE_Definitions::Instance()->Init(conn);
}

