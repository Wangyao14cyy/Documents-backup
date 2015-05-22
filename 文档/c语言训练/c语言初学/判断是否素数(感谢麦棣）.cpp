#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,t;
	scanf("%d",&n);
	for(i=2;i<=sqrt(n);i=i+1)
	  {
	   t=n%i;
		if(t==0&&n!=2)
		{
		printf("%d不是素数",n);return 0;}
      }
	printf("%d是素数",n);
	return 0;
}
