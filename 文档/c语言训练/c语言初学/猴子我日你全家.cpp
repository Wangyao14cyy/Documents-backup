#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct monkey)
struct monkey
{
	int num;
	struct monkey *next;
};

struct monkey *create_list(int total)/* 建立猴子信息链表 */
{
	struct monkey *head;
	struct monkey *p1,*p2;
	int n=0;
	p1=p2=(struct monkey *)malloc(LEN);
	for(;n<total;)
	{
		n+=1;
		if(1==n)
		{
			p1->num=1;
			head=p1;
		}
		else
		{
			p1->num=n;p2=p1;			
		}
		p1=(struct monkey*)malloc(LEN);
		p2->next=p1;
	}
	p2->next=NULL;
	return(head);
}

struct monkey *del_list(struct monkey *head,int m,int total)/*表示出猴子链表的删减*/ 
{
	struct monkey *p1,*p2;
	p2=p1=head;
	int n;
	for(;total>1;total--)
	{	
		n=m;
		while(n>1)
		{
			p2=p1;
			p1=p1->next;
			if(p1==NULL)
			p1=head;
			n--;
		}
		if(p1==head)
		{
			p1=p1->next;
			head=p1;
		}
		else if(p1->next==NULL)
		{
			p1=head;
			p2->next=NULL;
		}
			else 
			{
				p1=p1->next;
				p2->next=p1;
			}
	}
	return(head);
}

void print(struct monkey *head)/*表示出猴子链表*/ 
{
	printf("The last monkey is:\n%d",head->num);
}

int main(int argc,char *argv[])
{
	int total,m;
	struct monkey *head;
	printf("Input the monkey numbe you want:\n");
	scanf("%d",&total);
	printf("Input the monkey you want to get out:\n"); 
	scanf("%d",&m);
	head=del_list(create_list(total),m,total);
	print(head);
	return 0;
}

