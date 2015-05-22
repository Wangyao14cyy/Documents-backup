/*************************************************************************
    > File Name: list_compare.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月10日 星期三 15时12分06秒
	>比较两个链表,数据结构20页例题2.1
 **********************************************************************/
#include <stdio.h>
#include <stdlib.h>
typedef struct name
{
	char vh;
	struct name *next;
}list;
list * make_list(list *head);
list * compare_list(list *a,list *b);
int count_list(list *head);
void output_list(list *head);
char output_char(list *head,int n);
int find_list(list *head,char ch);
int main(int argc,char **argv)
{
	list *a=NULL,*b=NULL;
	a=make_list(a);
	b=make_list(b);
	printf("The list a is:\n");
	output_list(a);
	printf("The list b is:\n");
	output_list(b);
	a=compare_list(a,b);
	printf("Finally the a is:\n");
	output_list(a);
	return 0;
}

list *make_list(list *head)
{
	list *p1,*p2;//构造链表的2个指针
	p1=(list *)malloc(sizeof(list));
	char ch='y',th;
	for(p2=head=p1;ch=='y'||ch=='Y';p2=p1)
	{
		printf("Please input the character you want:\n");
		scanf("%c",&th);
		p1->vh=th;
		p1=(list *)malloc(sizeof(list));
		p2->next=p1;
		printf("If you want to continue to input character?(y/n)\n");
		scanf("%c",&ch);
    }
	p2->next=NULL;
	return head;
}

int count_list(list *head)
{
	list *p;
	int n=0;
	for(p=head;p!=NULL;p=p->next)
	n++;
	return n;
}

void output_list(list *head)
{
	list *p;
	for(p=head;p!=NULL;p=p->next)
	printf("%c",p->vh);
	printf("\n");
}

char output_char(list *head,int n)
{
	int m=1;
	list *p;
	for(p=head;m<=n;m++)
	p=p->next;
	return p->vh;
}

int find_list(list *head,char ch)
{
	int judge=1;
	list *p=head;
	for(;p!=NULL&&p->vh!=ch;p=p->next);			
	if(p==NULL)
	judge=0;	
	return judge;	
}

list *add_list(list *head,char temp)
{
	list *p=head,*p1;
	for(;p->next==NULL;p=p->next);
		p1=p;
		p=(list *)malloc(sizeof(list));
		p1->next=p;
		p->vh=temp;	
		p->next=NULL;
	return head;
}
list *compare_list(list *a,list *b)
{
	int an,bn,m=1;//m为逐步逼近计数
	char temp;
	an=count_list(a);
	bn=count_list(b);
	for(;m<=bn;)
	{
		temp=output_char(b,m);
		if(!find_list(a,temp))
		a=add_list(a,temp);
	}
	return a;
}
