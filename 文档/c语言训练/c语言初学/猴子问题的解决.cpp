#include <stdio.h>
int main()
{	
	int num,m,i,time,count;
	printf("input the monkey number:\n");/* ���ӵ���Ŀ */ 
	scanf("%d",&num);
	printf("input the number you want to get out the monkey:\n");/* ���ߺ��ӵĺ��� */ 
	scanf("%d",&m);	
	getchar();
	printf("\n");
	int monkey[num];
	for(i=0;i<num;i++)
	monkey[i]=1;/* �����Ӹ�ֵ */
	
	i=0;
	
	for(time=1;time<num;time++)/* ��Ƕ��ѭ���������ж� */
	{
		count=1; 
		while(count<=m)
		{
			while(monkey[i]!=1)
			{
				i++;
				if(i>=num)
				i=0;
			}
			count++;i++;		
		}
		monkey[--i]=0;
	} 
	for(i=0;i<num;i++)
	if(monkey[i]==1)
	printf("The last monkey is :\n%d",i+1);/* ������һֻ���ӵĺ��� */
	return 0;
}
