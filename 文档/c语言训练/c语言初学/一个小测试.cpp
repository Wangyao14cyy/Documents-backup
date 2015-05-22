#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 
#define MAX_LENGTH 30
#define MAX_ADD 30
#define MAX_LIST 60
//m：数据个数 t：调用函数中用来表示输入的num n：调用函数中用来判断是否遍历完 
typedef struct team
{
	int num;
	char name[MAX_LENGTH];
	int age;
	char add[MAX_ADD];
	struct team *next;
}team;

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

team *create_list(int L)//创建链表head 
{
	team *p1,*p2,*head;
	int num=1;
	char ch='n';
	if((p1=(team *)malloc(sizeof(team)))==NULL)
	{
	printf("Memory error!");
	exit(-1);	
	}
	for(p2=head=p1;num<=L;num++,p2=p1)
	{	
		system("cls");
		printf("Input ID:(please not input zero)\n");
		scanf("%d",&p1->num);
		getchar();
		printf("Input Name:\n");
		scanf("%s",p1->name);//可能出错，小心点。
		getchar(); 
		printf("Input age:\n");
		scanf("%d",&p1->age);
		getchar();
		printf("Input location:\n");
		scanf("%s",p1->add);
		getchar();
		p2->next=NULL;
		printf("Are you want to continue?(y/n)\n");
		scanf("%c",&ch);
		if(ch=='y')
		{
		p1=(team *)malloc(sizeof(team));
		p2->next=p1;
		}
		else
			break;
	}
	p2->next=NULL;
	return head;
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

team *del_list(team *head,int t,int m,int *v)
{	
	if(t==0)
	{
		printf("Input error!! Please input not zero!!\n");
		return head;
	}
	team *p1,*p2;
	int n=1;
	p1=head;
	while(p1->num!=t&&n<=m)
	{	
		p2=p1;
	    n++;
		p1=p1->next;	
	}
	if(t==p1->num)
		if(p1==head)
		  {
		   head=p1->next;
		   (*v)--;
		   printf("Delete!!\n");
		   return head;		
		  }
		else 
		  {
		   p2->next=p1->next;
		   (*v)--;
		   printf("Delete!!\n");
		   return head;
		  }
	else if(n>m)
		{
		printf("The number you want to delete not found.\n");
		return head;
		}
}

team *modify_list(team *head,int t,int m)
{
	if(t==0)
	{
		printf("Input error!! Please input not zero!!\n");
		return head;
	}
	team *p1;
	int n=1;
	p1=head;
	while(p1->num!=t&&n<=m)
	{	
	    n++;
		p1=p1->next;	
	}
	if(t==p1->num)
		{
		
			printf("Input the name you want to modify:\n");
			scanf("%s",p1->name);
			getchar();
			printf("Input the age you want to modify:\n");
			scanf("%d",&p1->age);			
			getchar();
			printf("Input the location you want to modify:\n");
			scanf("%s",p1->add);
			getchar();
			printf("Succeed!\n");
			return head;
		}
	else if(n>m)
		{
		printf("The number you want to modify not found.\n");
		return head;
		}
}

team *insert_list(team *head,int t,int m,int *v)
{	
	if(t==0)
	{
		printf("Input error!! Please input not zero!!\n");
		return head;
	}	
	team *p1,*p2,*p3;
	int n=1;
	p1=head;
	for(;p1->num!=t&&n<=t;n++,p1=p1->next)
	p2=p1;
	if(p1==head)
	{
		p2=p1->next;
		p1=(team *)malloc(sizeof(team));
		printf("输入号码：\n");
		scanf("%d",&p1->num);
		getchar();
		printf("输入名字：\n");
		scanf("%s",p1->name);
		getchar();
		printf("输入年龄：\n");
		scanf("%d",&p1->age);
		getchar();
		printf("输入擅长位置：\n");
		scanf("%s",&p1->add);
		getchar();
		head->next=p1;
		p1->next=p2;
		(*v)++;
		return head;		
	}
	else if(t==p1->num)
	{	
		p3=p2->next;
		p2=p1->next;
		p1=(team *)malloc(sizeof(team));
		printf("输入号码：\n");
		scanf("%d",&p1->num);
		getchar();
		printf("输入名字：\n");
		scanf("%s",p1->name);
		getchar();
		printf("输入年龄：\n");
		scanf("%d",&p1->age);
		getchar();
		printf("输入擅长位置：\n");
		scanf("%s",&p1->add);
		getchar();
		p1->next=p2;
		p3->next=p1;
		(*v)++; 
		return head;
	}
		else if(n>m)
		{
			printf("没有找到要插入的位置");
			return head; 
		}
}

int menu(int x)
{	
	system("cls");
	printf("\t\t-----------WCG战队管理系统------------\n");
	printf("\n");
	printf("\t\t|     选择你想要的功能：   |\n");
	printf("\t\t|     0.退出系统           |\n");
	printf("\t\t|     1.录入信息   		   |\n");
	printf("\t\t|     2.查找信息   		   |\n");
	printf("\t\t|     3.删除信息   		   |\n");
	printf("\t\t|     .修改信息    	   |\n");
	printf("\t\t|     5.插入信息 	 	   |\n");
	printf("\t\t|     6.战队现有人数统计   |\n");
	printf("\t\t|     7.战队所有信息       |\n"); 
	printf("\t\t---------------------------------------\n") ;
	printf("choose (0-7):\n");
	scanf("%d",&x);
	getchar();
	return x;
}

void create_dir(void)
{	
	 system("cls");
	 FILE *fin;
	 int L=MAX_LIST;
	 team d,*head=NULL,*fp=NULL;
	 int con=1;
	 head=create_list(L);
	 if((fin=fopen("F:\\lol_info_table.dat","wb"))==NULL)
	 {
	 	printf("Open the file error!!!\n");
	 	exit(-1);
	 }
	 fp=head;
	 while(fp!=NULL)
	 {
	 	if((fwrite(fp,sizeof(team)-4,1,fin))!=1)
	 	{
	 		printf("Write error!");
	 		exit(-1);
	 	}
	 	fp=fp->next;
	}
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
		if(fread(fp,sizeof(team),1,fout)==1)
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

void del_dir(void)
{	system("cls");
	int num,m=0,*v;//用一个m来数到底有多少个数据 
	char choice;
	FILE *fout,*fin;
	team *fp,*head;
	v=&m;
	fp=head=find_list();
	if((fout=fopen("F:\\lol_info_table.dat","ab+"))==NULL)
	{
		printf("open the file error");
		exit(-1);
	}
	while(!feof(fout))
	{
		if(fread(fp,sizeof(team),1,fout)==1)
		m++;
		fp=fp->next;
	}
	fclose(fout);//fp没用了 
	while(TRUE)
	{
	printf("Input the number you want to delete:\n");
	scanf("%d",&num);
	getchar();
	head=del_list(head,num,m,v);
	printf("If you want to continue delete?(y/n)\n");
	scanf("%c",&choice);
	getchar();
	if(choice=='y'||choice=='Y')
	;
	else 
		break;
	}
	if((fin=fopen("F:\\lol_info_table.dat","wb"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);	
	}
	for(fp=head;m>0;m--)
	{
		if(fwrite(fp,sizeof(team),1,fin)!=1)
		{
		printf("can not save");
		exit(-1);
		}
		fp=fp->next;
	}
	fclose(fin);
}

void modify_dir(void)
{	system("cls");
	int num,m=0;//用一个m来数到底有多少个数据 
	char choice;
	FILE *fout,*fin;
	team *fp,*head;
	fp=head=find_list();
	if((fout=fopen("F:\\lol_info_table.dat","ab+"))==NULL)
	{
		printf("open the file error");
		exit(-1);
	}
	while(!feof(fout))
	{
		if(fread(fp,sizeof(team),1,fout)==1)
		m++;
		fp=fp->next;
	}
	fclose(fout);//fp没用了 
	while(TRUE)
	{
		printf("The num you want to modify!!!\n");
		scanf("%d",&num);
		head=modify_list(head,num,m);
		printf("If you want to continue delete?(y/n)\n");
		scanf("%c",&choice);
		getchar();
		if(choice=='y'||choice=='Y')
		;
		else 
			break;		
	}
	if((fin=fopen("F:\\lol_info_table.dat","wb"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);	
	}
	for(fp=head;m>0;m--)
	{
		if(fwrite(fp,sizeof(team),1,fin)!=1)
		{
			printf("can not save");
			exit(-1);
		}
		fp=fp->next;
	}
	fclose(fin);	
}

void insert_dir(void)
{	system("cls");
	int num,m=0,*v;
	FILE *fin,*fout;
	team *head,*fp;
	char choice;
	v=&m;
	head=fp=find_list();
	if((fout=fopen("F:\\lol_info_table.dat","ab+"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);
	}
	while(!feof(fout))
	{
		fread(fp,sizeof(team),1,fout);
		m++;
		fp=fp->next;
	}
	fclose(fout);
	while(TRUE)
	{
		printf("你想要把数据插在哪一位序号队员后面？\n");
		scanf("%d",&num);
		head=insert_list(head,num,m,v);	
		printf("If you want to continue delete?(y/n)\n");
		scanf("%c",&choice);
		getchar();
		if(choice=='y'||choice=='Y')
			;
		else 
			break;				
	}
	if((fin=fopen("F:\\lol_info_table.dat","wb"))==NULL)
	{
		printf("Open the file failed");
		exit(-1);
	}
	for(fp=head;m>0;m--)
	{
		if(fwrite(fp,sizeof(team),1,fin)!=1)
		{
			printf("Can not save");
			exit(-1);
		}
		fp=fp->next;
	}
	fclose(fin);
}

void num(void)
{	system("cls");
	int m=0;
	FILE *fout;
	team *fp;
	fp=find_list();
	if((fout=fopen("F:\\lol_info_table.dat","ab+"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);
	}	
	while(!feof(fout))//注意指向 
	{
		fread(fp,sizeof(team),1,fout);
		m++;
		fp=fp->next;
	}
	printf("The total number is:%d",m);
	fclose(fout);
}

void all(void)
{	system("cls");
	int m=0;
	FILE *fout;
	team *fp,*head;
	head=fp=find_list();
	if((fout=fopen("F:\\lol_info_table.dat","ab+"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);
	}	
	while(!feof(fout))//注意指向 
	{
		fread(fp,sizeof(team),1,fout);
		m++;
		fp=fp->next;
	}	
	fclose(fout);
	printf("		Num			Name		Age			Location	\n");	
	for(fp=head;m>0;m--)
	{
	   	printf("\t\t%d\t\t%s\t\t%d\t\t%s\n",fp->num,fp->name,fp->age,fp->add);
		fp=fp->next;
	}
	free(head);
}
int main(void)
{
	int x;
	while(TRUE)
	{
	x=menu(x);
	switch(x)
	{
		case 0:
			return 0;
		case 1:
			create_dir();break;
		case 2:
			find_dir();break;
		case 3:
			del_dir();break;
		case 4:
			modify_dir();break;
		case 5:
			insert_dir();break;
		case 6:
			num();break;	
		case 7:
			all();break;	
		default:
			exit(-1);				
	}
	}
	return 0; 
} 
