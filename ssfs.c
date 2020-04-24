#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

#define key 10
static const char *dirpath = "/home/juwita/sisop/modul4";
char array[110];

void caesarenk(char str[])
{
	char kar;
	for(int i = 0; i < strlen(str); i++)
	{
		kar = str[i];
		for(int j = 0; j < strlen(array)+key ; j++)
		{
			if (kar == array[j])
			{
				kar = cip[j+key];
				str[i]=kar;
				break;
			}
		}
	}
	printf("hasil enkripsi : %s\n", str);
}

void caesardek(char str[])
{
	char kar;
	for(int i = strlen(str)-1; i >= 0; i--)
	{
		kar = str[i];
		for(int j = caesar+kunci-1; j >=0 ; j--)
		{
			if (kar == cip[j])
			{
				kar = cip[j-key];
				str[i]=kar;
				break;
			}
		}
	}
}
static  int  xmp_getattr(const char *path, struct stat *stbuf){
	int res;
	char fpath[1000];
	sprintf(fpath,"%s%s",dirpath,path);
	res = lstat(fpath, stbuf);
	if (res == -1)
		return -errno;
	return 0;
}

static int xmp_mkdir(const char *path, mode_t mode) {
    	int res;
	char fpath[1000];	
	sprintf(fpath,"%s%s",dirpath,path);
     	res = mkdir(path, mode);
    	if(res == -1)
         	return -errno;
    	return 0;
}

static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,off_t offset, struct fuse_file_info *fi){
	char fpath[1000];
	printf("readdir path %s, dirpath %s\n",path,dirpath);
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
	//sprintf(fpath, "%s%s",dirpath,path);
	int res = 0;
	DIR *dp;
	struct dirent *de;
	(void) offset;
	(void) fi;

	dp = opendir(path);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
		st.st_mode = de->d_type << 12;
		if (filler(buf, de->d_name, &st, 0))
			break;
	}
	closedir(dp);
	return 0;
}

static int xmp_read(const char *path, char *buf, size_t size, off_t offset, struct fuse_file_info *fi){
	char fpath[1000];
	printf("readdir path %s, dirpath %s\n",path,dirpath);
	if(strcmp(path,"/") == 0)
	{
		path=dirpath;
		sprintf(fpath,"%s",path);
	}
  //sprintf(fpath, "%s%s",dirpath,path);
	int fd;
	int res;
	(void) fi;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return -errno;
	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;
	close(fd);
	return res;
}
static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.mkdir		= xmp_mkdir,
	.rename		= xmp_rename,
	.open		= xmp_open.
};
int main(int argc, char *argv[])
{
	strcpy(array,"9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO");
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}
