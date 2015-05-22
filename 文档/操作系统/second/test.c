/*************************************************************************
    > File Name: test.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年04月15日 星期三 21时59分14秒
    > Function: 测试用户级线程的弊端 
 ************************************************************************/
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *fun1(void *arg)
{
	int pig;
	int file_descripter;
	read(stdin,pig,sizeof(int));	
	printf("%d\n",pig);
	pthread_exit(NULL);
}
void *fun2(void *arg)
{
	printf("Finished\n");
	pthread_exit(NULL);
}
int main(int argc, char const *argv[])
{
	int status;
	void *thread_result;
	pthread_t thread1,thread2;
	status=pthread_create(&thread1,NULL,fun1,(void *)0);
	sleep(3);
	if(status!=0)
	{
		printf("Failed\n");
		exit(-1);
	}
	status=pthread_create(&thread2,NULL,fun2,(void *)0);
	if(status!=0)
	{
		printf("Failed\n");
		exit(-1);
	}
	pthread_join(thread1,&thread_result);
	pthread_join(thread2,&thread_result);
	return 0;
}
