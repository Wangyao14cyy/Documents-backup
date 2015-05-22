#include <stdio.h>
#include <stdlib.h>
int main(void)
{	
	int i,j;
	int a[15][15];
	for(i=0;i<15;i++)
	for(j=0;j<15;j++)
	a[i][j]=1;
	for(i=0;i<15;i++)
	for(j=0;j<15;j++)
	printf("%d",a[i][j]);
	system("cls");
	printf("test");
	return 0;
}
