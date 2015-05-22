/*************************************************************************
    > File Name: ctrlc1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月27日 星期五 20时19分38秒
    > Function: 信号模拟函数的处理
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n",sig);
	(void)signal(SIGINT,SIG_DFL);
}

int main()
{
	(void)signal(SIGINT,ouch);
	while(1)
	{
	printf("Hello World!\n");
	sleep(1);
	}


}
