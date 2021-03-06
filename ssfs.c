#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

static const char *dirpath = "/home/juwita/Documnets1";
char array[] = "9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO";
const int key = 13;

char *getExt (char *str) {
    char *ext = strrchr (str, '.');
    if (ext == NULL)
        ext = "";
    return ext;
}

void caesarenk(char *str){
	if(strcmp(str,".") == 0 || strcmp(str,"..") == 0) return;
	int len = strlen(getExt(str));
	for ( int i = 0; i < strlen(str)-len ;i++) {
		if(str[i] != '/'){
			for (int j = 0; j < strlen(array); j++) {
	     		if(str[i] == array[j]) {
	        		str[i] = array[(j+key) % strlen(array)];
	        		break;
        	}
			}
		}
	}
}

void caesardek(char *str){
	if(strcmp(str,".") == 0 || strcmp(str,"..") == 0) return;
	int f1 = 0;
	int f2 = 0;
	if(strncmp(str,"encv1_",6)==0){
		f1 = 1;
		f2 = 1;
	}
	int len = strlen(getExt(str));
	for ( int i = 0; i < strlen(str)-len; i++) {
		if(str[i] == '/'){
			f1=0;
		}
		if((f1 != 1 && str[i] != '/') && f2 == 1){
			for (int j = 0; j < strlen(array); j++) {
	     			if(str[i] == array[j]) {
	        			str[i] = array[(j+strlen(array)-key) % strlen(array)];
	        			break;
        			}
			}
		}
	}
}

void logs (char* cmd, char* deskripsi){
    char level[20],name[1000];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    FILE *file = fopen("/home/juwita/fs.log","a");

    if(strcmp(cmd,"RMDIR") == 0 || strcmp(cmd,"UNLINK") == 0){
      strcpy(level,"WARNING");
    }
    else{
      strcpy(level,"INFO");
    }
    int year = tm.tm_year+1900-2000;
    sprintf(name, "%s::%02d%02d%02d-%02d:%02d:%02d::%s::%s", level, year, tm.tm_mon + 1,
    tm.tm_mday,tm.tm_hour, tm.tm_min, tm.tm_sec, cmd, deskripsi);
    fprintf(file,"%s",name);
    fprintf(file,"\n");
    fclose(file);
}

static int xmp_getattr(const char *path, struct stat *stbuf){
	int res;
	char fpath[1000];
	char *encv1 = strstr(path,"encv1_");
	sprintf(fpath, "%s%s",dirpath,path);

	if(encv1 != NULL){
        	caesardek(encv1);
        	sprintf(fpath,"%s/%s",dirpath,encv1);
	}

	res = lstat(fpath, stbuf);
	if (res == -1)
		return -errno;

	return 0;
}

static int xmp_readdir(const char *path, void *buf, fuse_fill_dir_t filler,
		       off_t offset, struct fuse_file_info *fi){
	char fpath[1000];
	char *encv1 = strstr(path,"encv1_");
	sprintf(fpath, "%s%s",dirpath,path);
	if(strcmp(path,"/") == 0)
	{
		path = dirpath;
		sprintf(fpath,"%s",path);
	}
  	else
  	{
		if(encv1 != NULL ){
        	caesardek(encv1);
        	sprintf(fpath,"%s/%s",dirpath,encv1);
         }

  	}
	int res = 0;

	DIR *dp;
	struct dirent *de;

	(void) offset;
	(void) fi;

	dp = opendir(fpath);
	if (dp == NULL)
		return -errno;

	while ((de = readdir(dp)) != NULL) {
		struct stat st;
		memset(&st, 0, sizeof(st));
		st.st_ino = de->d_ino;
  		st.st_mode = de->d_type << 12;

		if(encv1 != NULL){
			caesarenk(de->d_name);
		}
    		res = (filler(buf, de->d_name, &st, 0));
		if(res!=0)
			break;
	}
	closedir(dp);
	return 0;
}



static int xmp_read(const char *path, char *buf, size_t size, off_t offset,
		    struct fuse_file_info *fi){
	int fd;
	int res;
    	char fpath[1000];
    	char *encv1 = strstr(path,"encv1_");
	sprintf(fpath, "%s%s",dirpath,path);

	if(encv1 != NULL){
		caesardek(encv1);
		sprintf(fpath,"%s/%s",dirpath,encv1);
	}

	(void) fi;

	fd = open(fpath, O_RDONLY);
	if (fd == -1)
		return -errno;
	res = pread(fd, buf, size, offset);
	if (res == -1)
		res = -errno;
	close(fd);
	return res;
}
static int xmp_mkdir(const char *path, mode_t mode){
    int res;
	char fullpath[1000];
	char *encv1 = strstr(path,"encv1_");
	sprintf(fullpath ,"%s%s",dirpath,path);

	if(encv1 != NULL){
		caesardek(encv1);
		sprintf(fullpath,"%s/%s",dirpath,encv1);
	}
	res = mkdir(fullpath, mode);
    	if (res == -1){
      		return -errno;
    	}
    	else{
      		char deskripsi[1000];
      		sprintf(deskripsi,"%s",fullpath);
      		logs("MKDIR", deskripsi);
    	}
    return 0;
}

static int xmp_rmdir(const char *path)
{
	int res;
    	char fullpath[1000];
    	sprintf(fullpath, "%s%s",dirpath,path);

    	res = rmdir(fullpath);
    	if (res == -1){
    	  return -errno;
    	}
    	else{
        	char deskripsi[1000];
        	sprintf(deskripsi,"%s",fullpath);
        	logs("RMDIR",deskripsi);
    	}
    return 0;
}

static int xmp_rename(const char *from, const char *to){
    	int res;
	char from1[1000];
	char to1[1000];
	char *ffrom = strstr(from,"encv1_");
	char *fto = strstr(from,"encv1_");
	sprintf(from1,"%s%s",dirpath,from);
	sprintf(to1,"%s%s",dirpath,to);

	if(ffrom != NULL && fto == NULL){
		sprintf(from1,"%s/%s",dirpath,ffrom);
	}
	else if(fto != NULL && ffrom == NULL){
		sprintf(to1,"%s/%s",dirpath,fto);
	}

    	res = rename(from1, to1);
    	if (res == -1){
     	 	return -errno;
    	}
    	else{
      		char deskripsi[1000];
      		sprintf(deskripsi,"%s::%s",from1, to1);
      		logs("RENAME", deskripsi);
   	}
    return 0;
}

static struct fuse_operations xmp_oper = {
	.getattr	= xmp_getattr,
	.readdir	= xmp_readdir,
	.mkdir		= xmp_mkdir,
  	.rmdir		= xmp_rmdir,
	.rename		= xmp_rename,
	.read		= xmp_read,
};

int main(int argc, char *argv[]){
	umask(0);
	return fuse_main(argc, argv, &xmp_oper, NULL);
}
