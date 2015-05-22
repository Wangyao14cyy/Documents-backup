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
	printf("请选择您想要实现的功能：\n");
	printf("1.战队信息创建（创建内容保存于文本文件c：\\lol.txt 下)\n");
	printf("2.战队信息读取\n");
	printf("3.战队信息修改\n");
	printf("\n\n请输入您想要进行的代号：\n");
	scanf("%d",&mode);
	while(mode!=1||mode!=2||mode!=3)
	{
		printf("请您输入正确的代号\n");
		scanf("%d",&mode);
	} 
	if(mode==1)
	  {
	     printf("由于本人水平有限，只能存储%d条战队信息",MAX_LENGTH); 
	     create_list();//进行创建链表和文件的操作 
	     printf("您是否还想继续操作？(Y or N)\n");
		 scnaf("%c",&answer);
		 while(answer!='Y'||answer!='N')
		 {
		 	printf("error!请重新输入：\n");
		 	scanf("%c",&answer);
		 } 
		 if(answer=='N')
		 return 0;
	  }
	if(mode==2)
	  {
	  	 read_list(void);//读取链表 
	  	 printf("您是否还想继续操作？(Y or N)\n");
		 scnaf("%c",&answer);
		 while(answer!='Y'||answer!='N')
		 {
		 	printf("error!请重新输入：\n");
		 	scanf("%c",&answer);
		 } 
		 if(answer=='N')
		 return 0;
	 }
	 if(mode==3)
	 {	
	 	int pig;
	 	printf("请选择您想要进行的操作：\n");
	 	printf("1.删除数据				2.添加数据			3.修改数据\n");
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
void create_list(void)//创建文件及对应链表 
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

