/*************************************************************************
    > File Name: ctrlc2.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月27日 星期五 22时31分52秒
    > Function: 用sigaction接口来代替signal
 ************************************************************************/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("OUCH! - I got signal %d\n",sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler=ouch;//从结构中提取变量
	sigemptyset(&act.sa_mask);
	act.sa_flags=0;
	
	sigaction(SIGINT,&act,0);
	
	while(1){
		printf("Hello world!\n");
		sleep(1);
	}
}
