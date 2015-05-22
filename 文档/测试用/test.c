/*************************************************************************
    > File Name: test.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月19日 星期四 21时51分30秒
    > Function: 了解c程序的过程 
 ************************************************************************/
#include <stdio.h>
#include <math.h>
int main()
{
	float a,b,c,t,area,s;
	printf("Input three edge of the triangle\n");
	scanf("%f%f%f",&a,&b,&c);
	s=(a+b+c)/2;
	t=s*(s-a)*(s-b)*(s-c);
	area=sqrt(t);
	printf("Area=%f\n",area);
	return 0;
	

}
