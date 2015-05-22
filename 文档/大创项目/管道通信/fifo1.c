#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "sys/types.h"
#include "sys/stat.h"

int main(int argc, char const *argv[])
{
	int res=mkfifo("/tmp/mv_fifo",0777);
	if(res==0)printf("FIFO created\n");
	return 0;
}