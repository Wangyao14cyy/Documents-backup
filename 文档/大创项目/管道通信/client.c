#include <ctype.h>
#include "client.h"

#define MAX_CLIENT 5

int main(int argc, char const *argv[])
{
	int server_fifo_fd,client_fifo_fd,i;
	struct data_to_pass_st my_data;
	int write_res,read_res;
	char client_fifo[256];

	client_fifo_fd=open(SERVER_FIFO_NAME,O_WRONLY);
	if(client_fifo_fd==-1)
	{
		fprintf(stderr, "error1\n" );
		exit(EXIT_FAILURE);
	}
	my_data.client_pid=getpid();
	sprintf(client_fifo,CLIENT_FIFO_NAME,my_data.client_pid);
	if(mkfifo(client_fifo,0777)==-1)
	{
		fprintf(stderr, "error2\n" );
		exit(EXIT_FAILURE);
	}
	for(i=0;i<MAX_CLIENT;i++)
	{	
		sprintf(my_data.some_data,"Hello from %d",my_data.client_pid);
		printf("%d sent:%s",my_data.client_pid,my_data.some_data);
		write_res=write(client_fifo_fd,&my_data,sizeof(my_data));
		if(write_res==-1)
		continue;
		server_fifo_fd=open(client_fifo,O_RDONLY);
		read_res=read(server_fifo_fd,&my_data,sizeof(my_data));
		if(read_res>0)		
		printf("received:%s\n",my_data.some_data);
		(void)close(server_fifo_fd);
	}(void)close(client_fifo_fd);
	unlink(CLIENT_FIFO_NAME);

	return 0;
}