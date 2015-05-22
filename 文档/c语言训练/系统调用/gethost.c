/*************************************************************************
    > File Name: gethost.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月15日 星期一 15时29分08秒
    > Function: 
 ************************************************************************/
#include <sys/utsname.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char computer[256];
	struct utsname uts;
	
	if(gethostname(computer,255)!=0||uname(&uts)<0){
		fprintf(stderr,"Could not get host information!");
		exit(-1);
	}
	printf("Computer host name is %s\n",computer);
	printf("System is %s on %s hardware\n",uts.sysname,uts.machine);
	printf("Nodename is %s\n",uts.nodename);
	printf("Version is %s,%s\n",uts.release,uts.version);
	return 0;







}
