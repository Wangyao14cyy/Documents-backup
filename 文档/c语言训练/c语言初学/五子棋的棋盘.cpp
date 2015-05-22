#include <stdio.h>
int main()
{
	int i,j,first;
	char c[15][15]={{' '}};
	for(first=1;first<=15;first++)
	printf("%5d",first);
	printf("\n");
	for(i=0;i<=8;i++)
	{
		printf("%d",i+1);
		printf(" ");
		for(j=0;j<=14;j++)
		printf("  %c |",c[i][j]);
        printf("\n");
        printf("  ");
		for(j=0;j<=14;j++)
		printf("----+");
		printf("\n");
	}
		for(i=9;i<=14;i++)
	{
		printf("%d",i+1);
		for(j=0;j<=14;j++)
		printf("  %c |",c[i][j]);
        printf("\n");
        printf("  ");
		for(j=0;j<=14;j++)
		printf("----+");
		printf("\n");
	}   return 0;
}
