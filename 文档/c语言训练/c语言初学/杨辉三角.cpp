#include <stdio.h>
int main()
{   
    printf("请输入你想要的杨辉三角大小:");
	char d=' ';
	int i,j,m,n,t;
	scanf("%d",&t);
	printf("\n");
	int c[20][20]={{1},{1,1}};
	for(i=0,m=t-1;i<=t,m>=0;i++,m--)
	{
		for(n=0;n<=m;n++)
		printf("%c%c%c",d,d,d);
 		for(j=0;j<=i;j++)
		{
			if(j!=0&&j!=i)
			{  
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				printf(" %5d",c[i][j]);
			}
			else
			   {
			    c[i][j]=1;
			    printf("     1");
			   }	
		}printf("\n");
	}return 0;
}
