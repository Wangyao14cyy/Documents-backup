#include <stdio.h>
typedef struct team
{
	int num;
	char name[30];
	int age;
	char location[30];
	struct team *next;
}feat; 
int main()
{
	unsigned a;
	a=sizeof(feat);
	printf("%d",a);
	return 0;
}
