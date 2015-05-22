/*************************************************************************
    > File Name: 多项式运行时间比较.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月11日 星期四 22时38分36秒
    > Function:比较两个多项式运行时间 
 ************************************************************************/
#include <stdio.h>
#include <time.h>
#include <math.h>
#define MAXN 100
#define MAXK 1000
clock_t start,stop;
double last;
void f1(double x);
void f2(double x);
int main()
{
    double x;
    printf("Please input the :\n");
    scanf("%lf",&x);
    f1(x);
	f2(x);
	return 0;
}
void f1(double x)
{
	start=clock();
	int i,turn=1;
	double p;
	for(;turn<=MAXK;turn++)
		for(i=1,p=0;i<=MAXN;i++)
			p=pow(x,i)/i;
		printf("The final is :%lf\n",p+1);
	stop=clock();
	last=(double)(stop-start)/CLOCKS_PER_SEC;
	printf("Time is %lf",last);
}
void f2(double x)
{
	start=clock();
	int i,turn=1;
	double p;
	for(;turn<=MAXK;turn++)
	for(i=MAXN-1,p=1/MAXN;i>=1;i--)
	p=p*x+1/i;
	printf("The final is :%lf\n",p*x+1);
	stop=clock();		
	last=(double)(stop-start)/CLOCKS_PER_SEC;
	printf("Time is %lf",last);
}

