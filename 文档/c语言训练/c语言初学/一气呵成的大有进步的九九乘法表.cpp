#include <stdio.h>
int main()
{
	int i,j,k,f,t;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			k=i*j;
			printf("%dx%d=%d	",i,j,k);
		}printf("\n");
	}
	return 0;
} 
