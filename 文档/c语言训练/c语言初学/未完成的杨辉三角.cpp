#include <stdio.h>
int main()
{
	int i,j;
	int c[10][10]={{1},{1,1}};
	printf("\t\t\t\t\t%d",c[0][0]);
	printf("\n\t\t\t\t%d\t\t%d\n",c[1][0],c[1][1]);
	for(i=2;i<=9;i++)
	{
		printf("1");
		for(j=1;j<=i;j++)
		{
			if(j!=i)
			{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				printf("\t%d",c[i][j]);
			}	
		}printf("\t1\n");
	}return 0;
}
