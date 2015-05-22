/*************************************************************************
    > File Name: badterm.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年02月01日 星期日 15时26分20秒
    > Function: setupterm函数的使用
 ************************************************************************/
#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>
int main()
{
	setupterm("unlisted",fileno(stdout),(int *)0);
	printf("Done.\n");
	return 0;






}
