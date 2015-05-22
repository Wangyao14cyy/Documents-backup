/*************************************************************************
    > File Name: memory6.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月02日 星期一 11时13分57秒
    > Function: 释放内存
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define ONE_K (1024)

int main(){
	char *some_memory;
	int exit_code=EXIT_FAILURE;//-1异常退出，此为字符常量
	
	some_memory=(char *)malloc(ONE_K);
	if(some_memory!=NULL){
		free(some_memory);
		printf("Memory allocated and freed again\n");
		exit_code=EXIT_SUCCESS;
	}
	exit(exit_code);
}
