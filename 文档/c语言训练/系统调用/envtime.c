/*************************************************************************
    > File Name: envtime.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月14日 星期日 19时38分46秒
    > Function: 返回从unix开始至今所经历的秒数
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
int main(int argc,char **argv)
{
	int i;
	time_t the_time;
	for(i=1;i<=10;i++){
		the_time=time((time_t *)0);
		printf("The time is %ld\n",the_time);
		sleep(2);
	}
	return 0;
}
