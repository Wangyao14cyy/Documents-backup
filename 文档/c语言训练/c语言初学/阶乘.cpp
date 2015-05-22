#include <stdio.h>
int main()
{
	int a[8915],mid,i;
	int *b;
	b=a;
	int n=2;
    for(i=0;i<=8914;i++)
    *(b++)=0;
    a[0]=1;
	for(;n<=10000;n++)
	{   	mid=0;
		b=a;
		for(i=0;i<=8914;i++,b++)
		{   
			*b=*b*n+mid;
			mid=*b/10000;
			*b%=10000;
		}
	}
	for(i=8914,b=&a[8914];i>=0;i--)
	printf("%d",*(b--));
	return 0;
}
