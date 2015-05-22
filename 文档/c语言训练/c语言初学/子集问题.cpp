#include <stdio.h>
int main(int argc,char **argv)
{	
	int n,i,m,t,d,v,*a,*p,*b;//m控制位数  n为输入的数  i为逼近n的值 temp表示实际数组序号 a,b为动态数组 
	printf("Input n:\n");
	scanf("%d",&n);
	if(a=malloc((n+1)*sizeof(int)))==NULL)
	exit(-1);//使用动态数组来分配内存 
	if(b=malloc((n+1)*sizeof(int)))==NULL))
	exit(-1);
	if(n<0)
	{
	printf("please input positive.");
	exit(-1);
	}
	for(p=a,i=0;p<=p[n];p++,i++)
	*p=i;//用循环对动态数组赋值
	for(p=b;p<=p[n];p++)
	*p=-1;//建立2个数组 
	printf("{}\n");
	for(i=0;i<=n;i++)
	  for(m=0;m<=i;m++)
	    for(t=0,v=m;t<=m;t++)
		{	
			if(m==0)
			 printf("{%d}\n",a[i]);
			 
			
			
		}
