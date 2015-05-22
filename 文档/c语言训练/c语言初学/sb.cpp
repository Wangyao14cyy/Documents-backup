#include <stdio.h>
#define SIZE 4
#define a stud[i]
struct student_type
{
	char name[10];
	int num;
	int age;
	char addr[15];
}stud[SIZE];

void save()
{	
	FILE *ft;
	int i;
	if((ft=fopen("stu_list","wb"))==NULL)
	{
		printf("cannot open the file");
		return;
	}
	for(i=0;i<SIZE;i++)
	if(fwrite(&stud[i],sizeof(struct student_type),1,ft)!=1)
	printf("file write error");
	fclose(ft);
}
int main()
{

	int i;
	for(i=0;i<SIZE;i++)
	scanf("%s%d%d%s",a.name,&a.num,&a.age,a.addr);
	save();
	return 0;
}
