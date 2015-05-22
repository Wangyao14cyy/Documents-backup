/*************************************************************************
    > File Name: lock1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月02日 星期一 12时25分39秒
    > Function: 创建锁文件 
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>

int main()
{
	int file_desc;
	int save_errno;

	file_desc=open("/tmp/LCK.test",O_RDWR | O_CREAT | O_EXCL,0444);//创建文件禁止用户 组 其他用户进行读的操作
	if(file_desc==-1){
		save_errno=errno;
		printf("Open failed with error %d\n",save_errno);
	}
	else{
		printf("Open success");
	}
	exit(EXIT_SUCCESS);


}
