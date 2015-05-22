/*************************************************************************
    > File Name: stud.h
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月19日 星期四 21时25分48秒
    > Function: 学生管理系统的头文件
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define Len 60

void menu(void);

typedef struct list{
	char *name;
	long int stud_pid;
	int Chinese_score;
	int English_score;
	struct list *next;
}stu_list;

stu_list *insert(stu_list *list);
stu_list *create(void);
void *find(stu_list *list);
void *browse(stu_list *list);
stu_list *delete(stu_list *list);
stu_list *rank(stu_list *list);
