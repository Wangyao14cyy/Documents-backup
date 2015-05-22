/*************************************************************************
    > File Name: execlp.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月20日 星期五 20时20分19秒
    > Function: execlp函数的调用
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	printf("Running ps with execlp\n");
	execlp("ps","ps","ax",(char *)0);	
	printf("Done.\n");
	exit(0);
	
	
	
}
