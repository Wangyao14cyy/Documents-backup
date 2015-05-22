/*************************************************************************
    > File Name: args.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月14日 星期日 10时22分16秒
    > Function: linux程序设计4.1 115页（对参数进行检查）
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv)
{
	int arg;
	for(arg=0;arg<argc&&argc>=2;arg++)
	{
		if(argv[arg][0]=='-')
		printf("option: %s\n",argv[arg]+1);
		else 
		printf("argumen %d:%s\n",arg,argv[arg]);
	}
	return 0;
}

