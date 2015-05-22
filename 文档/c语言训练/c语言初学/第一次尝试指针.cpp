#include <stdio.h>
void f(int *p,int *q,int *t);

int main()
{	void (*o)(int *p,int *q,int *t);
	o=f;
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	(*o)(&a,&b,&c);
	return 0;
}

void f(int *p,int *q,int *t)
{	
	int *z;
	if(*p<*q)
	{
		z=p;
		p=q;
		q=z;
	}
	if(*p<*t)
	{
		z=p;
		p=t;
		t=z;
	}
	if(*t>*q)
	{
		z=q;
		q=t;
		t=z;
	}
	printf("大小顺序依次输出是：");
	printf("%d  %d  %d",*p,*q,*t); 
}
