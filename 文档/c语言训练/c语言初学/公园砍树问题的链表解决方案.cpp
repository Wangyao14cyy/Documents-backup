#include <stdio.h>
#include <stdlib.h>
typedef	struct tree
{
	int mark;
	struct tree *next;
}node;
node *create(int L)
{	
	int num=0;
	node *head,*p1,*p2;
	p1=(node *)malloc(sizeof(node));
	if(p1==NULL)
	exit(1);
	head=p1;
	for(;num<=L;num++)
	{	
		p2=p1;
		p1->mark=num;
		p1=(node *)malloc(sizeof(node));
		if(p1==NULL)
			exit(1);
		p2->next=p1;
	}
	p2->next=NULL;
	return head;
}
node *del(node *head,int begin,int end)
{
	node *p1,*p2,*p3,*p4;
	for(p1=head;p1!=NULL&&p1->mark!=begin;)
	{	
		p2=p1;
		p1=p1->next;
	}
	for(p3=head;p3!=NULL&&p3->mark!=end;)
	{	
		p4=p3;
		p3=p3->next;
		
	}
	if(p1==head)
	   if(p3==head)
		{
		 head=p1->next;
		 return head;
		}
		else if(p3==NULL||p3->next==NULL)
		{
			head=NULL;
			return head;
		}
			else
			{
				p4=p3->next;
				head=p4;
				return head;
			}		 	
	 else if(p3==NULL||p3->next==NULL)
	    	{
	    	p2->next=NULL;
	    	return head;}
		  else 
		  	{
		  		p4=p3->next;
		  		p2->next=p4;
		  		return head;
		  	}
		return head;
}
int count(node *head)
{
	int n=0;
	node *p1;
	p1=head;
	for(;p1!=NULL;p1=p1->next)
		n+=1;
	return n;
}
int main()
{	
	int L,M,i,begin=0,end=0,num=0;
	printf("The L you want£º\n");
	scanf("%d",&L); 
	if(L==1)
	{
	 printf("num=0");
	 return 0;
	}
	node *list_head=create(L);
	printf("The total delete you want:\n");
	scanf("%d",&M);
	for(i=1;i<=M;i++)
	{
		scanf("%d %d",&begin,&end);
		list_head=del(list_head,begin,end);
	}	
	num=count(list_head);
	printf("The tree remain:%d",num);
	return 0;
}
