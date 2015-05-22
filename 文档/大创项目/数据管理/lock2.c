/*************************************************************************
    > File Name: lock2.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月02日 星期一 13时18分09秒
    > Function: 协调性锁文件 
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>

const char *lock_file="/tmp/LCK.test2";

int main(){
	int file_desc;
	int tries=10;
	while(tries--){
		file_desc=open(lock_file,O_RDWR | O_CREAT | O_EXCL,0444);
		if(file_desc==-1){
			printf("%d-Lock already present\n",getpid());
			sleep(3);
		}else{
			printf("%d-I have exclusive access\n",getpid());
			sleep(1);
			(void)close(file_desc);
			(void)unlink(lock_file);
			sleep(2);
		}
	}
	exit(EXIT_SUCCESS);
	}
