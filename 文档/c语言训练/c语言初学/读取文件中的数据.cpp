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
int main()
{
	int i;
	FILE *fp;
	fp=fopen("stu_list","rb");
	for(i=0;i<SIZE;i++)
	{
		fread(&stud[i],sizeof(struct student_type),1,fp);
		printf("%-10s%4d%4d%-15s\n",a.name,a.num,a.age,a.addr);
	}
	fclose(fp);
	return 0;
}
 
