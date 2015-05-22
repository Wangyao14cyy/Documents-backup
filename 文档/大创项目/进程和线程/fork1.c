/*************************************************************************
    > File Name: fork1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月21日 星期六 20时20分00秒
    > Function: 学习fork函数的用法（使用了fork函数后，原程序也在运行） 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t pid;
	char *message;
	int n;
	
	printf("fork program starting\n");
	pid=fork();//当前程序进程中再创建一个新的进程，返回新进程pid值
	
	switch(pid){
	case -1:
		perror("fork failed");
		exit(-1);
	case 0:
		message="This is the child";
		n=5;
		break;
	default :
		message="This is the parent";
		n=3;
		break;
	}
	
	for(;n>0;n--){
		puts(message);
		sleep(1);
	}
	exit(0);
}



