/**************************************************************************
    > File Name: tmpnam.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月15日 星期一 14时24分24秒
    > Function: 建立临时文件
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char tmpname[L_tmpnam];
	char *filename;
	FILE *tmpfp;
	filename=tmpnam(tmpname);
	printf("Temporary file name is: %s\n",filename);
	tmpfp=tmpfile();
	if(tmpfp)
		printf("Opened a temporaryfile OK\n");
	else
		perror("tmpfile");
	return 0;
}
