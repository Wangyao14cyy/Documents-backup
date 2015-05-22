/*************************************************************************
    > File Name: argopt.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月14日 星期日 10时49分07秒
    > Function: 学习getopt函数的用法，对参数进行规范使用
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc,char **argv)
{
	int opt;
	while((opt=getopt(argc,argv,":if:lr"))!=-1)
		{
			switch(opt){
				case 'i':
				case 'l':
				case 'r':
					printf("option: %c\n",opt);break;
				case 'f':
					printf("filename: %s\n",optarg);break;
				case ':':
					printf("option needs a value\n");break;
				case '?':
					printf("unknown option: %c\n",optopt);break;
			}
		}
	for(;optind<argc;optind++)
		printf("argument:%s\n",argv[optind]);
	return 0;

	
	
}
