/*************************************************************************
    > File Name: system.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月18日 星期三 21时28分17秒
    > Function: 测试system函数的使用方法(打开新进程)
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Running ps with system\n");
	system("ps ax &");
	printf("Done.\n");
	exit(0);
}

