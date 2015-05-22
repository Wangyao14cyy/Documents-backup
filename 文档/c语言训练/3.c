/*************************************************************************
    > File Name: 3.c
    > Author: Wangyao
    > Mail: Yaowang.future@gmail.com 
    > Created Time: 2015年04月14日 星期二 19时20分09秒
    > Function: IP地址的转化
 ************************************************************************/
#include <stdio.h>
void count(unsigned long int ip);
void count1(int array[]);
int count2(int i);
int main()
{
	unsigned long int ip;	
	printf("Input the ip:\n");
	scanf("%ld",&ip);
	count(ip);
	return 0;
}
void count(unsigned long int ip)//十进制与二进制的转换函数
{	
	int array[32]={0};	
	int res,consult,i=0;	
	res=ip%2;	
	consult=ip/2;
	while(consult)
	{
	  ip=consult;
	  array[i++]=res;
	  res=ip%2;
	  consult=ip/2;
	}
	count1(&array[0]);
	printf(".");
	count1(&array[8]);
	printf(".");
	count1(&array[16]);
	printf(".");
	count1(&array[24]);
}
void count1(int array[])
{
	int x=0;//承载整数输出	
	int i=7;
	int t;
	for(;i>=0;i--)
	{
		t=count2(i);		
		x=x+t*array[i];
	} 
	printf("%d",x);	
}
int count2(int i)
{
	int t=1;
	while(i--)
		t*=2;
	return t;
}



