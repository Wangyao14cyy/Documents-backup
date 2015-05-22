#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "unistd.h"

int main(int argc, char const *argv[])
{
	int data_processed;
	int file_pipes[2];
	const char some_data[]="123";
	pid_t fork_result;
	if(pipe(file_pipes)==0){
		fork_result=fork();
		if(fork_result==-1){
			fprintf(stderr, "error!\n" );
			exit(EXIT_FAILURE);
		}else if(fork_result==0){
			close(0);
			dup(file_pipes[0]);//file_pipes[0] = stdin
			close(file_pipes[0]);
			close(file_pipes[1]);
			execlp("od","od","-c",(char *)0);	
			exit(EXIT_FAILURE);
		}else{
			close(file_pipes[0]);
			data_processed=write(file_pipes[1],some_data,strlen(some_data));
			close(file_pipes[1]);
			printf("%d - wrote %d bytes\n",getpid(),data_processed);
			exit(EXIT_SUCCESS);
		}
	}
}