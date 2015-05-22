#include <stdio.h>
#include <conio.h>
void textmode(int newmode);
int main()
{	int BLACK=3;
	textmode(BLACK);
	int a,b,c,d,e;
	scanf("%d %d",&a,&b);
	d=a*b;
	if(a<b)
	{
		c=a;
		a=b;
		b=c;
	}
	for(c=a%b;c!=0;a=b,b=c,c=a%b);
	printf("最大公因数是%d\n",b);
	e=d/b;
	printf("最小公倍数是%d\n",e);
	return 0;
}
