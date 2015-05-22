#include <stdio.h>
int main()
{
	unsigned N,b,c;
	scanf("%u",&N);
	b=N%5;
	c=N/5;
	if(b<=3&&b!=0)
	printf("Fishing in day %u",N);
	if(b>3||b==0)
	printf("Drying in day %u",N);
	return 0;
	
}
