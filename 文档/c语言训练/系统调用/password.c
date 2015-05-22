/*************************************************************************
    > File Name: password.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月17日 星期三 20时34分44秒
    > Function: 读取密码时禁止回显 
 ************************************************************************/
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#define PASSWORD_LEN 8
int main()
{
	struct termios iniset,newset;
	char passwd[PASSWORD_LEN+1];
	tcgetattr(fileno(stdin),&iniset);
	newset=iniset;
	newset.c_lflag&=~ECHO;
	printf("Enter password:");
	if(tcsetattr(fileno(stdin),TCSAFLUSH,&newset)!=0)
		fprintf(stderr,"Could not set attributes\n");
	else{
		fgets(passwd,PASSWORD_LEN,stdin);
		tcsetattr(fileno(stdin),TCSANOW,&iniset);
		fprintf(stdout,"\nYou entered %s\n",passwd);
	}
	return 0;
}
