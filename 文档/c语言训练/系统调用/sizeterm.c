/*************************************************************************
    > File Name: sizeterm.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年02月02日 星期一 15时49分05秒
    > Function:查看终端显示区的大小
 ************************************************************************/
#include <stdio.h>
#include <term.h>
#include <curses.h>
#include <stdlib.h>
int main()
{
	int nrows,ncolumns;
	setupterm(NULL,fileno(stdout),(int *)0);
	nrows=tigetnum("lines");
	ncolumns=tigetnum("cols");
	printf("This terminal has %d columns and %d rows\n",ncolumns,nrows);
	return 0;
}
