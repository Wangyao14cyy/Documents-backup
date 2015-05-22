/*************************************************************************
    > File Name: 递归效率检测.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月10日 星期三 21时06分03秒
 **********************************************************************/
#include <stdio.h>
#include <time.h>
clock_t start,stop;
double usetime;
void print(int n)
{
	if(n)
	{
		print(n-1);
		printf("%d\n",n);
	}
}
int main()
{
	start=clock();
	int n;
	scanf("%d",&n);
	printf("\n");
	print(n);
	stop=clock();
	usetime=((double)(stop-start))/CLOCKS_PER_SEC;
	printf("所用时间是:%lf",usetime);
	return 0;
}
