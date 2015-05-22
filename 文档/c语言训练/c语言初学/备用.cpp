#include <stdio.h>
#include <stdlib.h>
#define TRUE 1 
#define MAX_LENGTH 30
#define MAX_ADD 30
#define MAX_LIST 60
typedef struct pink
{
	int num;
	char name[MAX_LENGTH];
	int year;
	char add[MAX_ADD];
	struct pink *next;
}room;
int menu(int x)
{	
	system("cls");
	printf("\t\t----------- ���ز�����ϵͳ------------\n");
	printf("\n");
	printf("\t\t     ѡ������Ҫ�Ĺ��ܣ�   			   \n");
	printf("\t\t     0.�˳�ϵͳ           			   \n");
	printf("\t\t     1.¼����Ϣ   		   			   \n");
	printf("\t\t     2.������Ϣ   		   			   \n");
	printf("\t\t     3.ɾ����Ϣ   		   			   \n");
	printf("\t\t     4.�޸���Ϣ    	   	   		       \n");
	printf("\t\t     5.������Ϣ 	 	   			   \n");
	printf("\t\t     6.¥������ͳ��   			       \n");
	printf("\t\t     7.¥��������Ϣ       			   \n"); 
	printf("\t\t---------------------------------------\n") ;
	printf("choose (0-7):\n");
	scanf("%d",&x);
	getchar();
	return x;
}
room *find_list(void)//����ɺ�����ļ� 
{
	room *p1,*p2,*head;
	int num=1,L=MAX_LIST;
	p1=(room *)malloc(sizeof(room));
	p2=head=p1;
	for(;num<=L;num++)
	{
		p2=p1;
		p2->num=0;
		p2->year=0;
		p1=(room *)malloc(sizeof(room));
		p2->next=p1;
	}
	p2->next=NULL;
	return head;
}

room *insert_list(room *head,int t,int m,int *v)
{	
	if(t==0)
	{
		printf("Input error!! Please input not zero!!\n");
		return head;
	}	
	room *p1,*p2,*p3;
	int n=1;
	p1=head;
	for(;p1->num!=t&&n<=t;n++,p1=p1->next)
	p2=p1;
	if(p1==head)
	{
		p2=p1->next;
		p1=(room *)malloc(sizeof(room));
		printf("������룺\n");
		scanf("%d",&p1->num);
		getchar();
		printf("�������֣�\n");
		scanf("%s",p1->name);
		getchar();
		printf("�������䣺\n");
		scanf("%d",&p1->year);
		getchar();
		printf("�����ó�λ�ã�\n");
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
		p1=(room *)malloc(sizeof(room));
		printf("����¥�̺ţ�\n");
		scanf("%d",&p1->num);
		getchar();
		printf("���룺\n");
		scanf("%s",p1->name);
		getchar();
		printf("���뷿�����֣�\n");
		scanf("%d",&p1->year);
		getchar();
		printf("���룺\n");
		scanf("%s",&p1->add);
		getchar();
		p1->next=p2;
		p3->next=p1;
		(*v)++; 
		return head;
	}
		else if(n>m)
		{
			printf("û���ҵ�Ҫ�����λ��");
			return head; 
		}
}
void insert_dir(void)
{	system("cls");
	int num,m=0,*v;
	FILE *fin,*fout;
	room *head,*fp;
	char choice;
	v=&m;
	head=fp=find_list();
	if((fout=fopen("F:\\room_info_table.dat","ab+"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);
	}
	while(!feof(fout))
	{
		fread(fp,sizeof(room)-4,1,fout);
		m++;
		fp=fp->next;
	}
	fclose(fout);
	while(TRUE)
	{
		printf("����Ҫ�����ݲ�����һ��¥�̺��棿\n");
		scanf("%d",&num);
		head=insert_list(head,num,m,v);	
		printf("If you want to continue?(y/n)\n");
		scanf("%c",&choice);
		getchar();
		if(choice=='y'||choice=='Y')
			;
		else 
			break;				
	}
	if((fin=fopen("F:\\room_info_table.dat","wb"))==NULL)
	{
		printf("Open the file failed");
		exit(-1);
	}
	for(fp=head;m>0;m--)
	{
		if(fwrite(fp,sizeof(room)-4,1,fin)!=1)
		{
			printf("Can not save");
			exit(-1);
		}
		fp=fp->next;
	}
	fclose(fin);
}
void all(void)
{	system("cls");
	int m=0;
	FILE *fout;
	room *fp,*head;
	head=fp=find_list();
	if((fout=fopen("F:\\room_info_table.dat","ab+"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);
	}	
	while(!feof(fout))//ע��ָ�� 
	{
		fread(fp,sizeof(room)-4,1,fout);
		m++;
		fp=fp->next;
	}	
	fclose(fout);
	printf("		room ID		Name		year		Location	\n");	
	for(fp=head;m>1;m--)
	{
	   	printf("\t\t%d\t\t%s\t\t%d\t\t%s\n",fp->num,fp->name,fp->year,fp->add);
		fp=fp->next;
	}
	free(head);
	system("pause");
}
room *modify_list(room *head,int t,int m)
{
	if(t==0)
	{
		printf("Input error!! Please input not zero!!\n");
		return head;
	}
	room *p1;
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
			printf("Input the year you want to modify:\n");
			scanf("%d",&p1->year);			
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
void modify_dir(void)
{	system("cls");
	int num,m=0;//��һ��m���������ж��ٸ����� 
	char choice;
	FILE *fout,*fin;
	room *fp,*head;
	fp=head=find_list();
	if((fout=fopen("F:\\room_info_table.dat","ab+"))==NULL)
	{
		printf("open the file error");
		exit(-1);
	}
	while(!feof(fout))
	{
		if(fread(fp,sizeof(room)-4,1,fout)==1)
		m++;
		fp=fp->next;
	}
	fclose(fout);//fpû���� 
	while(TRUE)
	{
		printf("The num you want to modify!!!\n");
		scanf("%d",&num);
		head=modify_list(head,num,m);
		printf("If you want to continue?(y/n)\n");
		scanf("%c",&choice);
		getchar();
		if(choice=='y'||choice=='Y')
		;
		else 
			break;		
	}
	if((fin=fopen("F:\\room_info_table.dat","wb"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);	
	}
	for(fp=head;m>0;m--)
	{
		if(fwrite(fp,sizeof(room)-4,1,fin)!=1)
		{
			printf("can not save");
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
	room *fp;
	fp=find_list();
	if((fout=fopen("F:\\room_info_table.dat","ab+"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);
	}	
	while(!feof(fout))//ע��ָ�� 
	{
		fread(fp,sizeof(room)-4,1,fout);
		m++;
		fp=fp->next;
	}
	printf("The total number is:%d\n",m-1);
	fclose(fout);
	system("pause");
}
room *del_list(room *head,int t,int m,int *v)
{	
	if(t==0)
	{
		printf("Input error!! Please input not zero!!\n");
		return head;
	}
	room *p1,*p2;
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
void del_dir(void)
{	
	system("cls");
	int num,m=0,*v;//��һ��m���������ж��ٸ����� 
	char choice;
	FILE *fout,*fin;
	room *fp,*head;
	v=&m;
	fp=head=find_list();
	if((fout=fopen("F:\\room_info_table.dat","ab+"))==NULL)
	{
		printf("open the file error");
		exit(-1);
	}
	while(!feof(fout))
	{
		if(fread(fp,sizeof(room)-4,1,fout)==1)
		m++;
		fp=fp->next;
	}
	fclose(fout);//fpû���� 
	while(TRUE)
	{
	printf("Input the number you want to delete:\n");
	scanf("%d",&num);
	getchar();
	head=del_list(head,num,m,v);
	printf("If you want to continue?(y/n)\n");
	scanf("%c",&choice);
	getchar();
	if(choice=='y'||choice=='Y')
	;
	else 
		break;
	}
	if((fin=fopen("F:\\room_info_table.dat","wb"))==NULL)
	{
		printf("Open the file failed!\n");
		exit(-1);	
	}
	for(fp=head;m>0;m--)
	{
		if(fwrite(fp,sizeof(room)-4,1,fin)!=1)
		{
		printf("can not save");
		exit(-1);
		}
		fp=fp->next;
	}
	fclose(fin);
}

room *search_list(room *head,int n,int m)//������Ϣ 
{
	room *p=head;
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
void find_dir(void)
{
	system("cls");
	int l=MAX_LIST,num,m=0;
	char choose='y';
	room *head,*fp,*p;
	FILE *fout;
	fp=head=find_list();
	if((fout=fopen("F:\\room_info_table.dat","rb"))==NULL)
	 {
	 	printf("Open the file error!!!\n");
	 	exit(-1);
	 }
	while(!feof(fout))
	{
		if(fread(fp,sizeof(room)-4,1,fout)==1)
		m++;
		fp=fp->next;
	}
	fclose(fout);
	while(choose=='y'||choose=='Y')
	{	
		 system("cls"); 
		printf("Input the room ID you want to find:\n");
		scanf("%d",&num);
		getchar();
		p=search_list(head,num,m);	
	    if(p!=NULL)
		{
	   		printf("\nThe loler's information:\n");
	   		printf("room ID:%d\tName:%s\tyear:%d\tLocation:%s\n",p->num,p->name,p->year,p->add);
		}
		else 
			printf("Not find!\n");
		printf("Do you want again?\n(y\\n)\n");
		scanf("%c",&choose);
	}
}
room *create_list(int L)//��������head 
{
	room *p1,*p2=NULL,*head;
	int num=1;
	char ch;
	if((p1=(room *)malloc(sizeof(room)))==NULL)
	{
	printf("Memory error!");
	exit(-1);	
	}
	for(p2=head=p1;num<=L;num++,p2=p1)
	{	
		system("cls");
		printf("Input room ID:(please not input zero)\n");
		scanf("%d",&p1->num);
		getchar();
		printf("Input room owner:\n");
		scanf("%s",p1->name);
		getchar(); 
		printf("Input year:\n");
		scanf("%d",&p1->year);
		getchar();
		printf("Input location:\n");
		scanf("%s",p1->add);
		getchar();
		fflush(stdin);
		printf("Are you want to continue?(y/n)\n");
		scanf("%c",&ch);
		if(ch=='y')
		{
		p1=(room *)malloc(sizeof(room));
		p2->next=p1;
		}
		else
		{
			p2->next=NULL;
			return head;
		}
	}
	p2->next=NULL;
	return head;
}
void create_dir(void)
{	
	 system("cls");
	 FILE *fin;
	 int L=MAX_LIST;
	 room *head=NULL,*fp=NULL;
	 head=create_list(L);
	 if((fin=fopen("F:\\room_info_table.dat","wb"))==NULL)
	 {
	 	printf("Open the file error!!!\n");
	 	exit(-1);
	 }
	 fp=head;
	 while(fp!=NULL)
	 {
	 	if((fwrite(fp,sizeof(room)-4,1,fin))!=1)
	 	{
	 		printf("Write error!");
	 		exit(-1);
	 	}
	 	fp=fp->next;
	}
	fflush(stdout);
	fflush(stdin);
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
     


