#include <stdio.h>
int main()
{	
	int num,m,i,time,count;
	printf("input the monkey number:\n");/* 猴子的数目 */ 
	scanf("%d",&num);
	printf("input the number you want to get out the monkey:\n");/* 赶走猴子的号码 */ 
	scanf("%d",&m);	
	getchar();
	printf("\n");
	int monkey[num];
	for(i=0;i<num;i++)
	monkey[i]=1;/* 给猴子赋值 */
	
	i=0;
	
	for(time=1;time<num;time++)/* 用嵌套循环来进行判断 */
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
	printf("The last monkey is :\n%d",i+1);/* 输出最后一只猴子的号码 */
	return 0;
}
