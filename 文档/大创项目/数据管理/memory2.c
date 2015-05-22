/*************************************************************************
    > File Name: memory2.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年02月06日 星期五 15时59分16秒
    > Function: 比机器物理内存容量更多的内存
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_MEGABYTE (1024*1024)
#define PHY_MEM_MEGS 1024
int main()
{	
	char *some_memory;
	size_t size_to_allocate=A_MEGABYTE;
	int megs_obtained=0;
	
	while(megs_obtained<(PHY_MEM_MEGS*2)){
		some_memory=(char *)malloc(size_to_allocate);
		if(some_memory!=NULL){
			megs_obtained++;
			sprintf(some_memory,"Hello world");//将后面的内容放入some_memory中
			printf("%s - now allocated %d Megabyte\n",some_memory,megs_obtained);
		}
		else{
			exit(EXIT_FAILURE);
		}
	}
exit(EXIT_SUCCESS);
}
