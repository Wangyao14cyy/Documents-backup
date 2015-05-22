/*************************************************************************
    > File Name: printdir.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月12日 星期五 14时28分41秒
    > Function: 目录遍历
 ************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir,int depth)
{//用depth来控制缩进，表现子目录和母目录的层次感。entry这个指针中的d_name存储的是文件名or目录名，d_name也是一个指针。lstat将entry与statbuf结合起来。（某种联系）
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp=opendir(dir))==NULL){
		fprintf(stderr,"cannot open directory:%s\n",dir);
		exit(-1);
	}//打开了还要进去
	chdir(dir);
	while((entry=readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);//有些疑惑
		if(S_ISDIR(statbuf.st_mode)){
			if(strcmp(".",entry->d_name)==0||strcmp("..",entry->d_name)==0)
				continue;
			printf("%*s%s/\n",depth,"",entry->d_name);
			printdir(entry->d_name,depth+4);
		}
		else printf("%*s%s\n",depth,"",entry->d_name);
	}
		chdir("..");
		closedir(dp);
}
int main(int argc,char **argv)
{
	char *topdir=".";
	if(argc>=2)
		topdir=argv[1];
	printf("Direntory scan of /home:\n");
	printdir(topdir,0);
	printf("done.\n");
	return 0;
}
