/*************************************************************************
    > File Name: memory1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年02月02日 星期一 16时49分01秒
    > Function: 简单的内存分配 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define A_MEGABYTE (1024*1024)
int main()
{
	char *some_memory;
	int megabyte=A_MEGABYTE;
	int exit_code=EXIT_FAILURE;
	
	some_memory=(char *)malloc(megabyte);
	if(some_memory!=NULL){
		sprintf(some_memory,"Hello world\n");
		printf("%s",some_memory);
		exit_code=EXIT_SUCCESS;
	}
	exit(exit_code);
}
