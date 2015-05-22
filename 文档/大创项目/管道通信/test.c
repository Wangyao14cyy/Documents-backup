#include <stdio.h>
void func(void *arg);
int main()
{
	int b=10;
	func((void *)b);
	return 0;
}
void func(void *arg)
{
	int a=(int)arg;
	printf("%d",a);
	
	
	
}
