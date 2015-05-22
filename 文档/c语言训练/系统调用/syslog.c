/*************************************************************************
    > File Name: syslog.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月15日 星期一 15时59分23秒
    > Function: 打开一个不存在的文件，在日志文件中获得记录，并且查看日志文件。 
 ************************************************************************/
#include <stdio.h>
#include <syslog.h>
#include <stdlib.h>

int main()
{
	FILE *f;
	f=fopen("not,here","r");
	if(!f)
	syslog(LOG_ERR|LOG_USER,"oops - %m\n");
	return 0;
	
	
}
