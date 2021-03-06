#include "client.h"
#include <ctype.h>

int main(int argc, char const *argv[])
{
	unlink(SERVER_FIFO_NAME);
	int server_fifo_fd,client_fifo_fd;
	struct data_to_pass_st my_data;
	int read_res;
	char client_fifo[256];
	char *tmp_char_ptr;

	mkfifo(SERVER_FIFO_NAME,0777);
	server_fifo_fd=open(SERVER_FIFO_NAME,O_RDONLY);
	if(server_fifo_fd==-1)
	{
		fprintf(stderr, "error-server failed" );
		exit(EXIT_FAILURE);
	}
	sleep(10);
	do{
		read_res=read(server_fifo_fd,&my_data,sizeof(my_data));
			if(read_res>0){
			tmp_char_ptr=my_data.some_data;
			while(*tmp_char_ptr)
			{
				*tmp_char_ptr=toupper(*tmp_char_ptr);//convest c to C
				tmp_char_ptr++;
			}
			sprintf(client_fifo,CLIENT_FIFO_NAME,my_data.client_pid);
			client_fifo_fd=open(client_fifo,O_WRONLY);
			if(client_fifo_fd!=-1)
			{
				write(client_fifo_fd,&my_data,sizeof(my_data));
				(void)close(client_fifo_fd);
			}
		}
	}while(read_res>0);
		(void)close(server_fifo_fd);
		unlink(SERVER_FIFO_NAME);
	return 0;
}