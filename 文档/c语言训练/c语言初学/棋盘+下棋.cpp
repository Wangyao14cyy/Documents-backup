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
{   /* 棋盘 */ 
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
	/* 下棋 */ 
	player=turn%2+1;
	do
	  { printf("\n");
	  	printf("玩家%d，请您输入有效的方格坐标，在那里你的输入将变成 %c\n",player,(player==1) ? 'X':'O');
	  	printf("行:");scanf("%d",&i);printf("\n");
	  	printf("列:");scanf("%d",&j);printf("\n");
	  }while(i>15||j>15||i<0||j<0||c[i-1][j-1]=='X'||c[i-1][j-1]=='O');
	  c[i-1][j-1]=(player==1) ? 'X':'O';
	  t=i-1;
	  v=j-1;
	  /*  横行判定 */ 
	  if((c[t][v]==c[t][v+1]&&c[t][v+2]==c[t][v]&&c[t][v]==c[t][v+3]&&c[t][v]==c[t][v+4])||(c[t][v]==c[t][v+1]&&c[t][v]==c[t][v+2]&&c[t][v]
	  ==c[t][v+3]&&c[t][v]==c[t][v-1])||(c[t][v]==c[t][v+1]&&c[t][v]==c[t][v+2]&&c[t][v]==c[t][v-1]
	  &&c[t][v]==c[t][v-2])||(c[t][v]==c[t][v+1]&&c[t][v]==c[t][v-1]&&c[t][v]==c[t][v-2]&&c[t][v]==c[t][v-3])||(c[t][v]==c[t][v-1]&&c[t][v]==c[t][v-2]&&
	  c[t][v]==c[t][v-3]&&c[t][v]==c[t][v-4]))
	  winner=1;
	  /*  竖行判定 */ 
	  if((c[t][v]==c[t+1][v]&&c[t][v]==c[t+2][v]&&c[t][v]==c[t+3][v]&&c[t+4][v]==c[t][v])||(c[t][v]==c[t+1][v]&&c[t][v]==c[t+2][v]&&c[t][v]==c[t+3][v]&&
	  c[t-1][v]==c[t][v])||(c[t][v]==c[t+1][v]&&c[t][v]==c[t+2][v]&&c[t][v]==c[t-1][v]&&c[t][v]==c[t-2][v])||(c[t][v]==c[t+1][v]&&c[t][v]==c[t-1][v]&&c[t][v]
	  ==c[t-2][v]&&c[t][v]==c[t-3][v])||(c[t][v]==c[t-1][v]&&c[t][v]==c[t-3][v]&&c[t][v]==c[t-2][v]&&c[t][v]==c[t-4][v]))
	  winner=1;
	  /*  斜行判定 1*/ 
	  if((c[t][v]==c[t+1][v+1]&&c[t][v]==c[t+2][v+2]&&c[t][v]==c[t+3][v+3]&&c[t][v]==c[t+4][v+4])|| (c[t][v]==c[t+1][v+1]&&c[t][v]==c[t+2][v+2]&&
	  c[t][v]==c[t+3][v+3]&&c[t][v]==c[t-1][v-1])||(c[t][v]==c[t+1][v+1]&&c[t][v]==c[t+2][v+2]&&c[t][v]==c[t-1][v-2]&&c[t][v]==c[t-3][v-4])||(
	  c[t][v]==c[t+1][v+1]&&c[t-2][v-2]==c[t][v]&&c[t-1][v-1]==c[t][v]&&c[t][v]==c[t-3][v-3])||(c[t][v]==c[t-1][v-1]&&c[t][v]==c[t-2][v-2]&&c[t][v]==c[t-3][v-3]&&
	  c[t][v]==c[t-4][v-4]))
	  winner=1;
	  /* 斜行判定 2*/
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
    printf("获胜者是我们伟大的玩家%d，他使用的是我们的%c。\n\n\n",player,(player==1) ? 'X':'O');
    printf("该玩家的获胜图像是：\n\n\n\n");
	}	
	if(turn>224) 
    {
    printf("两个废物的对决。竟然都没有赢,这是你们2个渣渣下的棋");}	
	
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
