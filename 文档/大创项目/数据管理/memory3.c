/*************************************************************************
    > File Name: memory3.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年02月06日 星期五 17时06分12秒
    > Function: 探查物理内存最大容量 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define ONE_K (1024)

int main()
{
	char *some_memory;	
	int size_to_allocate=ONE_K;
	int megs_obtained=0;
	int ks_obtained=0;
	
	while(1){
		for(ks_obtained=0;ks_obtained<1024;ks_obtained++){
			some_memory=(char *)malloc(size_to_allocate);
			if(some_memory==NULL)exit(EXIT_FAILURE);
			sprintf(some_memory,"Hello world");
		}
	megs_obtained++;
	printf("Now allocated %d Megabytes\n",megs_obtained);
	}
	exit(EXIT_SUCCESS);
}
