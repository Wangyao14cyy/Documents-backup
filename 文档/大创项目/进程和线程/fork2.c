/*************************************************************************
    > File Name: fork2.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月27日 星期五 19时10分24秒
    > Function: 让父进程等待子进程结束(改造为僵尸进程) 
 ************************************************************************/
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	pid_t pid;
	char *message;
	int n;
	int exit_code;
	
	printf("fork program starting\n");
	pid=fork();

	switch(pid)
	{
		case -1:
			perror("fork failed");
			exit(-1);
		case 0:
			message="This is the kid!\n";
			n=3;
			exit_code=38;
			break;
	    default:
			message="This is the parent\n";
			n=5;
			exit_code=0;
			break;
	}
	for(;n>0;n--){
		puts(message);
		sleep(1);
	}
	if(pid!=0){
		int stat_val;
		pid_t child_pid;
		child_pid=wait(&stat_val);//等到子进程结束，并返回子进程的pid
		printf("Child has finished :PID=%d\n",child_pid);
		if(WIFEXITED(stat_val))
			printf("Child exited with code %d\n",WEXITSTATUS(stat_val));
		else
			printf("Child terminated abnormally\n");
		}

		exit(exit_code);




}

