/*************************************************************************
    > File Name: gtk1.c
    > Author: Wangyao
    > Mail: Yaowang_future@163.com 
    > Created Time: 2015年03月23日 星期一 19时07分29秒
    > Function: 测试gtk函数的用法 
 ************************************************************************/
#include <gtk/gtk.h>
int main(int argc,char **argv)
{
	GtkWidget *window;
	gtk_init(&argc,&argv);
	window=gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_widget_show(window);
	gtk_main();
	return 0;
}
