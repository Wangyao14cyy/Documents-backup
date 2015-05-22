/*************************************************************************
    > File Name: menu1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月15日 星期一 21时04分30秒
    > Function: 写一个菜单程序 
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
char *menu[]={
	"a-add new record",
	"d-delete record",
	"q-quit",
	NULL,
};
int getchoice(char *greet,char *choices[],FILE *in,FILE *out);
int main()
{
	int choice=0;
	FILE *input,*output;
	struct termios iniset,newset;
	if(!isatty(fileno(stdout))){//fileno取得文件流的文件描述符,isatty判断参数是否为一个终端,为终端则返回1，为其他文件则返回0
		fprintf(stderr,"You are not a terminal,OK!\n");
	}
	input=fopen("/dev/tty","r");// /dev/tty指向的是当前的终端与当前的登录对话
	output=fopen("/dev/tty","w");
	if(!input||!output){
	fprintf(stderr,"Unable to open /dev/tty\n");
	exit(-1);
	}//用NULL来表示
	tcgetattr(fileno(stdin),&iniset);//有疑问
	newset=iniset;
	newset.c_lflag&=~ICANON;
	newset.c_lflag&=~ECHO;
	newset.c_cc[VMIN]=1;
	newset.c_cc[VTIME]=0;
	newset.c_lflag&=~ISIG;
	if(tcsetattr(fileno(input),TCSANOW,&newset)!=0){
		fprintf(stderr,"Could not set attributes\n");
	}
	do{
		choice=getchoice("Please select an action",menu,input,output);
		printf("You have chosen:%c\n",choice);
	}while(choice!='q');
	tcsetattr(fileno(input),TCSANOW,&iniset);
	return 0;
}
int getchoice(char *greet,char *choices[],FILE *in,FILE *out)
{
	int chosen=0;
	int selected;
	char **option;
	do{
		fprintf(out,"Choice : %s\n",greet);
		option=choices;
		while(*option){
			fprintf(out,"%s\n",*option);
			option++;
		}
	do{
			selected=fgetc(in);
		}while(selected=='\n'||selected=='\r');//缓冲区控制
		option=choices;
		while(*option){ //用selected的取值来与option的第一位的值来进行比较；
			if(selected==*option[0]){
				chosen=1;
				break;
			}
		option++;
		}
		if(!chosen)
			fprintf(out,"Incorrect choice ,select again\n");
	}while(!chosen);
    return selected;
}						
