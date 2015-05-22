#include <stdio.h>
#include <math.h>
	int f(int num);
	int find(int even,int time);
void prime(int n)
{
	int even=6,first,second,time=1,boole;
	for(;even<=n;even+=2)
	{
	  time=1;
	  first=find(even,time);
	  second=even-first;
	  for(;(boole=f(second))!=1;)
	{
	  time+=1;
	  first=find(even,time);
	  second=even-first;
	}
	   printf("%d = %d + %d\n",even,first,second);
	}
}
int find(int even,int time)
{	
	int odd=3,t=1,boole; 
	for(;odd<even;)
	{
		boole=f(odd);
		if(boole==1)
		{
		if(t==time)
			break;
		else
			t+=1;};
		odd+=2;
	}
	return odd;
}
int f(int num)
{
	int odd=3,remainder,boole=1;
	if(num==3||num==5||num==7)
	return boole;
	for(;odd<=sqrt(num);odd+=2)
	{
		remainder=num%odd;
		if(remainder==0)
		{
			boole=0;
			break;
		}
	}
	return boole;
}
int main()
{
	int n;
	printf("The number you want from six to fifty thousand:\n");
	scanf("%d",&n);
	prime(n);
	return 0;
}
