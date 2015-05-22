/*************************************************************************
    > File Name: copy_system.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月10日 星期三 18时53分40秒
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc,char **argv)
{
	char c;
	int in,out;
	in=open("file.in",O_RDONLY);
	out=open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while(read(in,&c,1)==1)
		write(out,&c,1);
	return 0;
}
