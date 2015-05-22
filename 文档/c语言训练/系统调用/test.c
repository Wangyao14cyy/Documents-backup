/*************************************************************************
    > File Name: test.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月12日 星期五 15时55分00秒
    > Function: 测试对目录遍历的熟练程度
 ************************************************************************/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
void printdir(char *dir,int depth);
int	main(int argc,char **argv)
{
		char *topdir=".";
		if(argc>=2)
			topdir=argv[1];

		printf("Directory scan is:%s\n",topdir);
		printdir(topdir,0);
		printf("done.\n");
}
void printdir(char *dir,int depth)
{
	DIR *dp;
	struct dirent *entry;
	struct stat statbuf;
	if((dp=opendir(dir))==NULL)
	{
		printf("The %s can't open'",dir);
		exit(-1);
	}
	chdir(dir);
	while((entry=readdir(dp))!=NULL){
		lstat(entry->d_name,&statbuf);
		if(S_ISDIR(statbuf.st_mode))
		if(strcmp(".",entry->d_name)==0||strcmp("..",entry->d_name)==0)
			continue;
		else	
		{
			printf("%*s%s\n",depth,"",entry->d_name);
			printdir(entry->d_name,depth+4);
		}

		else 
			printf("%*s%s\n",depth,"",entry->d_name);
	}
	chdir("..");//chdir函数的参数是字符串类型的指针。
	closedir(dp);	
}
