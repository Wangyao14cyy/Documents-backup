/*************************************************************************
    > File Name: memory4.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月02日 星期一 10时05分52秒
    > Function: 滥用内存的使用调查 
 ************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#define ONE_K (1024)
int main()
{
	char *some_memory;
	char *scan_ptr;
	
	some_memory=(char *)malloc(ONE_K);
	if(some_memory==NULL)exit(EXIT_FAILURE);
	
	scan_ptr=some_memory;
	while(1){
		*scan_ptr='\0';
		printf("HELLO WORLD!\n");
		scan_ptr++;
	}
	exit(EXIT_SUCCESS);
}
