/*************************************************************************
    > File Name: copy_block.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月10日 星期三 19时52分17秒
 **********************************************************************/
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char **argv)
{	
	clock_t start,end;
	double last;
	start=clock();
	char block[1024];
	int in,out;
	int nread;
	in=open("file.in",O_RDONLY);
	out=open("file.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	while((nread=read(in,block,sizeof(block)))>0)
		write(out,block,nread);
	end=clock();
	last=(double)(end-start)/CLOCKS_PER_SEC;
	printf("total time is %lf\n",last);
	return 0;

}
