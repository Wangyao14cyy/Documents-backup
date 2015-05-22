/*************************************************************************
    > File Name: create.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月20日 星期五 21时26分19秒
    > Function: 创建链表 
 ************************************************************************/
#include "stud.h"

stu_list *create(stu_list *list)
{
	stu_list *ptr1,*ptr2,*head;
	int i=1;
	int choice=1;
	head=(stu_list *)malloc(sizeof(stu_list));
	for(ptr1=head;i++<=Len;)
	{
	printf("输入人名：\n");
	scanf("%s",ptr1->name);
	printf("输入学号:\n")；
	scanf("%ld",&ptr1->stud_pid);
	printf("输入语文成绩：\n");
	scanf("%d",&ptr1->Chinese_score);
	printf("输入英语成绩：\n");
	scanf("%d",&ptr1->English_score);
	printf("是否继续输入学生信息：（1为确定 or 其他为否定）？\n");
	scanf("%d",&choice);
	if(choice!=1)
	{
		ptr1->next=(char *)0;
		break;
	}
	ptr2=ptr1;
	ptr1=(stu_list *)malloc(sizeof(stu_list));
	ptr2->next=ptr1;
	}
	return(head);

}
