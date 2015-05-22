#include <stdio.h>
#include <math.h>
int main()
{
	int i,t,j;	
	i=2;
	if(i=2)
    printf("2	");
	for(;i<=100;i++)
	{
		for(j=2;j<=sqrt(i);j++)
		{
			t=i%j;
			if(t==0){
			break;}
		}if(j>sqrt(i))
		printf("%d	",i);
		}
	 return 0;
}
