#include <stdio.h>
int main(int argc,char **argv)
{	
	int n,i,m,t,d,v,*a,*p,*b;//m����λ��  nΪ�������  iΪ�ƽ�n��ֵ temp��ʾʵ��������� a,bΪ��̬���� 
	printf("Input n:\n");
	scanf("%d",&n);
	if(a=malloc((n+1)*sizeof(int)))==NULL)
	exit(-1);//ʹ�ö�̬�����������ڴ� 
	if(b=malloc((n+1)*sizeof(int)))==NULL))
	exit(-1);
	if(n<0)
	{
	printf("please input positive.");
	exit(-1);
	}
	for(p=a,i=0;p<=p[n];p++,i++)
	*p=i;//��ѭ���Զ�̬���鸳ֵ
	for(p=b;p<=p[n];p++)
	*p=-1;//����2������ 
	printf("{}\n");
	for(i=0;i<=n;i++)
	  for(m=0;m<=i;m++)
	    for(t=0,v=m;t<=m;t++)
		{	
			if(m==0)
			 printf("{%d}\n",a[i]);
			 
			
			
		}
