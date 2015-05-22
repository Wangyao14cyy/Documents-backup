/*************************************************************************
    > File Name: write.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月10日 星期三 14时11分33秒
 **********************************************************************/
#include <stdlib.h>
#include <unistd.h>
int main()
{
if(write(1,"Here is some data\n",18)!=18)
	write(2,"A write error has occurred on file descriptor 1\n",46);
return 0;

}
