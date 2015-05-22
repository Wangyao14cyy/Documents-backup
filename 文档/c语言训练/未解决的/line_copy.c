/*************************************************************************
    > File Name: line_copy.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月11日 星期四 20时28分45秒
	> Function: 整行读取文件 整行输出文件
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start,end;
double last;
int main()
{
	start=clock();
	FILE *in,*out;
	char *c;
	in=fopen("file.in","r");
	out=fopen("file.out","w");			
	while(fgets(c,1024,in)!=NULL&&)
		fprintf(out,c);
	end=clock();
	last=(double)(end-start)/CLOCKS_PER_SEC;
	printf("%lf\n",last);
	return 0;
}
