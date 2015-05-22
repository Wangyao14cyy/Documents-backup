/*************************************************************************
    > File Name: memory5.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月02日 星期一 10时35分54秒
    > Function: 访问空指针 
 ************************************************************************/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main(){
	char *some_memory=(char *)0;//赋予空指针

	printf("A read from null %s\n",some_memory);
	sprintf(some_memory,"A write to null");
	exit(EXIT_SUCCESS);
}
