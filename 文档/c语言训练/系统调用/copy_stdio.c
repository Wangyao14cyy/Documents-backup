/*************************************************************************
    > File Name: copy_stdio.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月11日 星期四 20时11分23秒
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc,char **argv)
{
	clock_t start,end;
	double last;
	start=clock();
	int c;
	FILE *fin,*fout;
	fin=fopen("file.in","r");
	fout=fopen("file.out","w");
	while((c=fgetc(fin))!=EOF)
		fputc(c,fout);
	end=clock();
	last=((double)(end-start))/CLOCKS_PER_SEC;
	printf("Total time is %lf",last);
	return 0;

}
