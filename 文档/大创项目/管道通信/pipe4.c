r#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int main(int argc, char const *argv[])
{
	int data_processed;
	char buffer[BUFSIZ+1];
	int file_descripter;

	memset(buffer,'\0',sizeof(buffer));

	sscanf(argv[1],"%d",&file_descripter);
	data_processed=read(file_descripter,buffer,BUFSIZ);

	printf("%d - read %d bytes:%s\n",getpid(),data_processed,buffer);
	exit(EXIT_SUCCESS);
}