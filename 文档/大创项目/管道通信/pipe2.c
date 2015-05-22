#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"
int main(int argc, char const *argv[])
{
	int data_processsd;
	int file_pipes[2];
	const char some_data[]="123";
	char buffer[BUFSIZ+1];
	pid_t fork_result;

	memset(buffer,'\0',sizeof(buffer));
	if(pipe(file_pipes)==0)
	{
		fork_result=fork();
		if(fork_result==-1)
		{
			fprintf(stderr,"error!\n");
			exit(EXIT_FAILURE);
		}
		else if(fork_result==0)
		{
			data_processsd=read(file_pipes[0],buffer,BUFSIZ);
			printf("Read %d bytes: %s\n",data_processsd,buffer);
			exit(EXIT_SUCCESS);
		}else{
			data_processsd=write(file_pipes[1],some_data,strlen(some_data));
			printf("Write %d bytes\n",data_processsd);
			exit(EXIT_SUCCESS);
		}
	}
	exit(EXIT_FAILURE);
}