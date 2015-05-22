/*************************************************************************
    > File Name: thread1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月28日 星期六 16时56分15秒
    > Function: 简单的线程程序 
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);
char message[]="Hello world";//指针指向的字符串常量不可更改．不能用strcpy更改．

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res=pthread_create(&a_thread,NULL,thread_function,(void *)message);//函数名就是地址
	if(res!=0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish ...\n");
	res=pthread_join(a_thread,&thread_result);//thread_result指向线程的返回值，何为线程的返回值?
	if(res!=0)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined,it returned %s\n",(char *)thread_result);
	printf("Message is now %s\n",message);
	exit(EXIT_SUCCESS);
}
void *thread_function(void *arg)
{
	printf("thread_function is running.Argument was %s\n",(char *)arg);
	sleep(3);
	strcpy(message,"Bye!");
	pthread_exit("Thank you for the CPU time!");
}
