#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *flag;
	char *a,*b,*c,temp;
	int n=0,m=1;
	printf("Input flags!\n");
	scanf("%s",flag);
	b=a=flag;
	while(*b!='\0')
	b++;
	c=b;
	b=flag;
	while((*a)=='r'&&a!=c)
		a++;
	b=a;
	if(a==c)
	{
		printf("至少三种颜色！！！");
		exit(-1);
	}
	for(c--;*c=='b'&&c>b;c--)
	;
	if(c==b)
		if(*c=='w'&&c>b&&(++c)!='\0')
		{
		printf("%s",flag);
		return 0;
		}
		else 
		{
		printf("请输入三种颜色！");
		exit(-1);
		}
	for(;b<=c;b++)
	{	
		if(*b=='w')
		continue;
		while(*a=='r') 
		a++;
		while(*c=='b')
		c--;
		if(*b=='r')
		{
		temp=*b;
		*b=*a;
		*a=temp;
		a++;
		n++;
		}
		if(*b=='b')
		{
			temp=*b;
			*b=*c;
			*c=temp;
			n++;
			c--;
		}
		if(*b=='r')
		{
		temp=*b;
		*b=*a;
		*a=temp;
		n++;
		a++;
		}
		if(*b=='b')
		{
			temp=*b;
			*b=*c;
			*c=temp;
			n++;
			c--;
		}		
	}
	printf("all is %d",n);
	printf("\n%s",flag);
	return 0;
}
