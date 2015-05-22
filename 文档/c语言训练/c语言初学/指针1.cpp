#include <stdio.h>
void pig(int *a[2])
{
	printf("%d",**a);
}
int main()
{	
	int x=1,y=2;
	int *a[2];
	a[0]=&x;
	a[1]=&y;
	pig(a);
	return 0;
}








