#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 20
#define MAX_ADD 3
typedef struct team
{
	int num;
	char name[MAX_LENGTH];
	int age;
	char add[MAX_ADD];
	struct team *next;
}team;
int main(int argc,char *argv[])
{
	int number,mode;
	char answer;
	printf("��ѡ������Ҫʵ�ֵĹ��ܣ�\n");
	printf("1.ս����Ϣ�������������ݱ������ı��ļ�c��\\lol.txt ��)\n");
	printf("2.ս����Ϣ��ȡ\n");
	printf("3.ս����Ϣ�޸�\n");
	printf("\n\n����������Ҫ���еĴ��ţ�\n");
	scanf("%d",&mode);
	while(mode!=1||mode!=2||mode!=3)
	{
		printf("����������ȷ�Ĵ���\n");
		scanf("%d",&mode);
	} 
	if(mode==1)
	  {
	     printf("���ڱ���ˮƽ���ޣ�ֻ�ܴ洢%d��ս����Ϣ",MAX_LENGTH); 
	     create_list();//���д���������ļ��Ĳ��� 
	     printf("���Ƿ������������(Y or N)\n");
		 scnaf("%c",&answer);
		 while(answer!='Y'||answer!='N')
		 {
		 	printf("error!���������룺\n");
		 	scanf("%c",&answer);
		 } 
		 if(answer=='N')
		 return 0;
	  }
	if(mode==2)
	  {
	  	 read_list(void);//��ȡ���� 
	  	 printf("���Ƿ������������(Y or N)\n");
		 scnaf("%c",&answer);
		 while(answer!='Y'||answer!='N')
		 {
		 	printf("error!���������룺\n");
		 	scanf("%c",&answer);
		 } 
		 if(answer=='N')
		 return 0;
	 }
	 if(mode==3)
	 {	
	 	int pig;
	 	printf("��ѡ������Ҫ���еĲ�����\n");
	 	printf("1.ɾ������				2.�������			3.�޸�����\n");
		for(scanf("%d",&pig);pig!=1||pig!=2||pig!=3;scanf("%d",&pig));
		switch(pig)
		{
			case 1:del();break;
			case 2:add();break;
			case 3:change();break;
			default :return 1;
		}
		return 0;
	}  
	return 0;
}
void create_list(void)//�����ļ�����Ӧ���� 
{
	FILE *fp;
	team *p1,*p2;
	fp=fopen(C:\LOLteam.dat,"w");
	if(NULL==fp)
	{
		printf("Error occur when open the file");
		exit(1);
	}
	
	
	
	
}

