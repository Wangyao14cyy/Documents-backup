/*************************************************************************
    > File Name: user.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2014年12月15日 星期一 14时58分12秒
    > Function: 用户信息查询
 ************************************************************************/
#include <stdio.h>
#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	uid_t uid;
	gid_t gid;
	
	struct passwd *pw;
	uid=getuid();
	gid=getgid();
	
	printf("User is %s\n",getlogin());
	printf("User IDs: uid=%d,gid=%d",uid,gid);
	
	pw=getpwuid(uid);
	printf("UID passwd entry:\n name=%s,uid=%d,gid=%d,home=%s,shell=%s\n",pw->pw_name,pw->pw_uid,pw->pw_gid,pw->pw_dir,pw->pw_shell);

	pw=getpwnam("root");
	printf("root passwd entry:\n");
	printf("name=%s,uid=%d,gid=%d,home=%s,shell=%s\n",pw->pw_name,pw->pw_uid,pw->pw_gid,pw->pw_dir,pw->pw_shell);
	return 0;
}
