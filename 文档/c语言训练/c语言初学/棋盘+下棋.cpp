#include <stdio.h>
int main()
{   
	int i,j,first,turn,t,v;
	int player=0;
	int winner=0;
	char c[15][15];
	for(i=0;i<15;i++)
	for(j=0;j<15;j++)
	c[i][j]=' ';
	for(turn=0;turn<=224&&winner!=1;turn++)
{   /* ���� */ 
	for(first=1;first<=15;first++)
        printf("%5d",first);
		printf("\n");
		for(i=0;i<=8;i++)
	{
			printf("%d",i+1);
			printf(" ");
			for(j=0;j<=14;j++)
			printf("  %c |",c[i][j]);
        	printf("\n");
        	printf("  ");
			for(j=0;j<=14;j++)
			printf("----+");
			printf("\n");
	}
		for(i=9;i<=14;i++)
	{
			printf("%d",i+1);
			for(j=0;j<=14;j++)
			printf("  %c |",c[i][j]);
        	printf("\n");
        	printf("  ");
			for(j=0;j<=14;j++)
			printf("----+");
			printf("\n");
	}  
	/* ���� */ 
	player=turn%2+1;
	do
	  { printf("\n");
	  	printf("���%d������������Ч�ķ������꣬������������뽫��� %c\n",player,(player==1) ? 'X':'O');
	  	printf("��:");scanf("%d",&i);printf("\n");
	  	printf("��:");scanf("%d",&j);printf("\n");
	  }while(i>15||j>15||i<0||j<0||c[i-1][j-1]=='X'||c[i-1][j-1]=='O');
	  c[i-1][j-1]=(player==1) ? 'X':'O';
	  t=i-1;
	  v=j-1;
	  /*  �����ж� */ 
	  if((c[t][v]==c[t][v+1]&&c[t][v+2]==c[t][v]&&c[t][v]==c[t][v+3]&&c[t][v]==c[t][v+4])||(c[t][v]==c[t][v+1]&&c[t][v]==c[t][v+2]&&c[t][v]
	  ==c[t][v+3]&&c[t][v]==c[t][v-1])||(c[t][v]==c[t][v+1]&&c[t][v]==c[t][v+2]&&c[t][v]==c[t][v-1]
	  &&c[t][v]==c[t][v-2])||(c[t][v]==c[t][v+1]&&c[t][v]==c[t][v-1]&&c[t][v]==c[t][v-2]&&c[t][v]==c[t][v-3])||(c[t][v]==c[t][v-1]&&c[t][v]==c[t][v-2]&&
	  c[t][v]==c[t][v-3]&&c[t][v]==c[t][v-4]))
	  winner=1;
	  /*  �����ж� */ 
	  if((c[t][v]==c[t+1][v]&&c[t][v]==c[t+2][v]&&c[t][v]==c[t+3][v]&&c[t+4][v]==c[t][v])||(c[t][v]==c[t+1][v]&&c[t][v]==c[t+2][v]&&c[t][v]==c[t+3][v]&&
	  c[t-1][v]==c[t][v])||(c[t][v]==c[t+1][v]&&c[t][v]==c[t+2][v]&&c[t][v]==c[t-1][v]&&c[t][v]==c[t-2][v])||(c[t][v]==c[t+1][v]&&c[t][v]==c[t-1][v]&&c[t][v]
	  ==c[t-2][v]&&c[t][v]==c[t-3][v])||(c[t][v]==c[t-1][v]&&c[t][v]==c[t-3][v]&&c[t][v]==c[t-2][v]&&c[t][v]==c[t-4][v]))
	  winner=1;
	  /*  б���ж� 1*/ 
	  if((c[t][v]==c[t+1][v+1]&&c[t][v]==c[t+2][v+2]&&c[t][v]==c[t+3][v+3]&&c[t][v]==c[t+4][v+4])|| (c[t][v]==c[t+1][v+1]&&c[t][v]==c[t+2][v+2]&&
	  c[t][v]==c[t+3][v+3]&&c[t][v]==c[t-1][v-1])||(c[t][v]==c[t+1][v+1]&&c[t][v]==c[t+2][v+2]&&c[t][v]==c[t-1][v-2]&&c[t][v]==c[t-3][v-4])||(
	  c[t][v]==c[t+1][v+1]&&c[t-2][v-2]==c[t][v]&&c[t-1][v-1]==c[t][v]&&c[t][v]==c[t-3][v-3])||(c[t][v]==c[t-1][v-1]&&c[t][v]==c[t-2][v-2]&&c[t][v]==c[t-3][v-3]&&
	  c[t][v]==c[t-4][v-4]))
	  winner=1;
	  /* б���ж� 2*/
	  if((c[t][v]==c[t+1][v-1]&&c[t][v]==c[t+2][v-2]&&c[t][v]==c[t+3][v-3]&&c[t][v]==c[t+4][v-4])||(c[t][v]==c[t+1][v-1]&&c[t][v]==c[t+2][v-2]&&
	  c[t][v]==c[t+3][v-3]&&c[t][v]==c[t-1][v+1])||(c[t][v]==c[t+1][v-1]&&c[t][v]==c[t+2][v-2]&&c[t][v]==c[t-1][v+1]&&c[t][v]==c[t-2][v+2])||(
	  c[t][v]==c[t+1][v-1]&&c[t][v]==c[t-1][v+1]&&c[t][v]==c[t-2][v+2]&&c[t][v]==c[t-3][v+3])||(c[t][v]==c[t-1][v+1]&&c[t][v]==c[t-2][v+2]&&
	  c[t][v]==c[t-3][v+3]&&c[t][v]==c[t-4][v+4]))
	  winner=1;
	  if(winner==1)break;
	  if(turn>224)break;
}
     if(winner==1)
	{
    printf("��ʤ��������ΰ������%d����ʹ�õ������ǵ�%c��\n\n\n",player,(player==1) ? 'X':'O');
    printf("����ҵĻ�ʤͼ���ǣ�\n\n\n\n");
	}	
	if(turn>224) 
    {
    printf("��������ĶԾ�����Ȼ��û��Ӯ,��������2�������µ���");}	
	
	for(first=1;first<=15;first++)
        printf("%5d",first);
		printf("\n");  
		for(i=0;i<=8;i++)
	{
			printf("%d",i+1);
			printf(" ");
			for(j=0;j<=14;j++)
			printf("  %c |",c[i][j]);
        	printf("\n");
        	printf("  ");
			for(j=0;j<=14;j++)
			printf("----+");
			printf("\n");
	}
		for(i=9;i<=14;i++)
	{
			printf("%d",i+1);
			for(j=0;j<=14;j++)
			printf("  %c |",c[i][j]);
        	printf("\n");
        	printf("  ");
			for(j=0;j<=14;j++)
			printf("----+");
			printf("\n");
	}  
	return 0;
}
