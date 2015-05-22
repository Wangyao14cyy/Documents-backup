#include <stdio.h>
#include <math.h>

int greatest_common_divisor(int,int,int,int);

int main()
{
	int num_one,num_two,result,p1;
	printf("大数前，小数后：");
	scanf("%d%d",&num_one,&num_two);
	p1=num_one%num_two;
	if(p1!=0)
	result=greatest_common_divisor(num_one,num_two,2,0);
	else 
	result=num_two;
	printf("result is %d\n",result);
	return 0;
}

int greatest_common_divisor(int num1,int num2,int test,int divisor)
{
	if(test==num1||test==num2)
	return divisor;
	else if(num1%test!=0||num2%test!=0)
	return greatest_common_divisor(num1,num2,test+1,divisor);
	else 
		{
			divisor=test;
			return divisor;
		}
}
