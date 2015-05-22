#include "unistd.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, char const *argv[])
{
	FILE *read_fp;
	char buffer[BUFSIZ+1];
	int chars_read;
	memset(buffer,'\0',sizeof(buffer));//buffer pointer to cast to '\0'
	read_fp=popen("uname -a","r");
	if(read_fp!=NULL){
		chars_read=fread(buffer,sizeof(char),BUFSIZ,read_fp);
		if(chars_read>0)
			printf("Output was:-\n%s\n",buffer );
	}
	pclose(read_fp);
	return 0;
}