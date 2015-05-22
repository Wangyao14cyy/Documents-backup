#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define FALSE 0
void print(int n);
int main(int argc,char **argv)
{
	int n;//total子集总数 
	printf("请输入您想要的数字：\n");
	scanf("%d",&n);
	print(n);
	return 0;
} 
void print(int n)
{	
	int total,v=2,i,turn,z,m,*d,*a;
	a=(int *)malloc((n+1)*sizeof(int));
	total=pow(v,n+1);
	total=(int)total;
	--total;
	for(i=0;i<=n;i++)
	a[i]=i;
	z=0;
	d=&z;
	while(z<=total)
	{	
		v=z;
		turn=0;
		printf("\t{");	
		for(;v>0;turn++,v/=2)
		{
			m=v%2;
			if(FALSE)
			;
			else if(m==1)
			printf("%d",a[turn]);
			if(m==1&&v!=1)
			printf(" ");
		}
		(*d)+=1;
		printf("}");
		printf("\n");
	}
	
	
}

