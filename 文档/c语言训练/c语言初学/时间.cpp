#include <stdio.h>
int main(void)
{
	int a,b,t,s,f,v,z,sum;
	scanf("%d%d",&a,&b);
	t=a-a/100*100;
	s=b/60;
	v=s+a/100;
	z=b%60;
	if(t+z<60&&t+z>=0)
	{
		f=t+z;
		v=b/60+a/100;
	}	if(t+z<0)
	{
		f=t+z+60;
		v=b/60+a/100-1;
	}
	if(t+z>=60)
	{f=t+z-60;
	v=b/60+a/100+1;
	}
	sum=v*100+f;
	printf("%d",sum);
	return 0;
}
