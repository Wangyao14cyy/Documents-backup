#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 
#define MAX_LENGTH 30
#define MAX_ADD 30
#define MAX_LIST 60
typedef struct team
{
	int num;
	char name[MAX_LENGTH];
	int age;
	char add[MAX_ADD];
	struct team *next;
}team;
void find_dir(void);
team *find_list(void);
team *search_list(team *head,int n,int m); 
int main(void)
{
	while(TRUE)
	find_dir();
	return 0;
}
team *find_list(void)//链表可和下面的简化 
{
	team *p1,*p2,*head;
	int num=1,L=MAX_LIST;
	p1=(team *)malloc(sizeof(team));
	p2=head=p1;
	for(;num<=L;num++)
	{
		p2=p1;
		p2->num=0;
		p2->age=0;
		p1=(team *)malloc(sizeof(team));
		p2->next=p1;
	}
	p2->next=NULL;
	return head;
} 
void find_dir(void)
{
	system("cls");
	int l=MAX_LIST,num,m=0;
	char choose='y';
	team *head,*fp,*p;
	FILE *fout;
	fp=head=find_list();
	if((fout=fopen("F:\\lol_info_table.dat","rb"))==NULL)
	 {
	 	printf("Open the file error!!!\n");
	 	exit(-1);
	 }
	while(!feof(fout))
	{
		if(fread(fp,sizeof(team)-4,1,fout)==1)//出错语句，与之前存储的方式不相同，无法进行读取。 
		m++;
		fp=fp->next;
	}
	fclose(fout);
	while(choose=='y'||choose=='Y')
	{
		printf("Input the number you want to find:\n");
		scanf("%d",&num);
		getchar();
		p=search_list(head,num,m);	
	    if(p!=NULL)
		{
	   		printf("\nThe loler's information:\n");
	   		printf("Num:%d\tName:%s\tAge:%d\tLocation:%s\n",p->num,p->name,p->age,p->add);
		}
		else 
			printf("Not find!\n");
		printf("Do you want again?\n(y\n)");
		scanf("%c",&choose);
	}
}
team *search_list(team *head,int n,int m)//查找信息 
{
	team *p=head;
	int turn=1;
	while(p->num!=n&&turn<=m&&p==NULL)
	{
		turn++;
		p=p->next;
	}
	if(p==NULL)
	return p;
	else if(p->num==n)
	return p;
		else 
		{
			p=NULL;
			return p;
		}
}	


	
