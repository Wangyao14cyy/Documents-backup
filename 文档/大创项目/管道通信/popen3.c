#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
int main(int argc, char const *argv[])
{
	FILE *read_fp;
	char buffer[BUFSIZ+1];//BUFSIZ declare in stdio.h
	int chars_read;
	memset(buffer,'\0',sizeof(buffer));
	read_fp=popen("ps ax","r");
	if(read_fp!=NULL){
		chars_read=fread(buffer,sizeof(char),BUFSIZ,read_fp);
		while(chars_read>0){
			buffer[chars_read-1]='\0';
			printf("Reading %d:-\n %s\n",BUFSIZ,buffer);
			chars_read=fread(buffer,sizeof(char),BUFSIZ,read_fp);
		}
	}
	exit(EXIT_SUCCESS);
}








