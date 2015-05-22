/*************************************************************************
    > File Name: read.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月10日 星期三 14时19分03秒
 **********************************************************************/
#include <unistd.h>
#include <stdlib.h>
int main()
{
	char buffer[128];
	int nread;
	nread=read(0,buffer,128);
	if(nread==-1)
		write(2,"A read error has occurred\n",26);
	if(write(1,buffer,nread)!=nread)
		write(2,"A write error has occurred\n",27);
	return 0;
}
