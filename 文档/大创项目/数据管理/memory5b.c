/*************************************************************************
    > File Name: memory5b.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
	> Created Time: 2015年03月02日 星期一 10时47分13秒
    > Function: 不调用GNU C函数库进行测试
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char z=*(const char *)0;
	printf("I read from location zero\n");
	exit(EXIT_SUCCESS);
}
