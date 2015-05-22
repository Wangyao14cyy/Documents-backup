/*************************************************************************
    > File Name: alarm.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月27日 星期五 21时13分05秒
    > Function: 模拟一个闹钟 
 ************************************************************************/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static int alarm_fired=0;

void ding(int sig)
{
	alarm_fired=1;	
}

int main()
{
	pid_t pid;
	
	printf("alarm application starting\n");
	
	pid=fork();
	
	switch(pid)
	{	
		case -1:
			perror("fork fialed");
			exit(1);
		case 0:
			sleep(5);
			kill(getppid(),SIGALRM);
			exit(0);
	}
	printf("waiting for alarm to go off\n");

	(void)signal(SIGALRM,ding);

	pause();
	if(alarm_fired)
	printf("Ding!\n");
	printf("Done\n");
	exit(0);
}
